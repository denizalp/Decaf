#include "codeGenV.h"
#include <deque>
#include "llvm/IR/DerivedTypes.h"

void CodeGenV::visit(StrLitA* a) {
    a->setReg(Builder.CreateGlobalStringPtr(StringRef(a->getValue())));
}
void CodeGenV::visit(CharLitA* a) {
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue()));

}
void CodeGenV::visit(IntLitA* a) {
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue()));
}

void CodeGenV::visit(BoolLitA* a) {
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue()));
}

void CodeGenV::visit(NullLitA* a) {
    indent(a->getDepth()); cout << "NullLitA\n";
    a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), 0));
}

//Initially we declared the case number of NameA but then it became unecessary.
void CodeGenV::visit(NameA* a) {
    string name = a->getName();
    a->setReg(currSymTab->getGlobal(name));
    }
}

void CodeGenV::visit(TypeA* a) {
    indent(a->getDepth()); cout << "TypeA" << "\n";
}

void CodeGenV::visit(PrimTypeA* a) {
    indent(a->getDepth()); cout << "PrimTypeA: " << a->getName()->getName() << "\n";
    // a->getName()->accept(*this);
    string name = a->getName()->getName();
    if (name == "int") {
        a->setIRType(Type::getInt64Ty(TheContext));
        a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), 0));
    } else if (name == "void") {
        a->setIRType(Type::getVoidTy(TheContext));
    } else if (name == "char") {
        a->setIRType(Type::getInt64Ty(TheContext));
        a->setReg(ConstantInt::get(Type::getInt64Ty(TheContext), 32));  // space
    } else {
        Print("type unimplemented: " + name);
    }
}

void CodeGenV::visit(ArrayTypeA* a)
{
    a->getType()->accept(*this);
}

void CodeGenV::visit(ClassTypeA* a)
{
    a->getName()->accept(*this);
}

// void CodeGenV::visit(StatementA* a)
// {
//
// }

void CodeGenV::visit(PrimaryExprA* a)
{
}

// void CodeGenV::visit(ExpressionA* a)
// {
//     a->setReg()
// }

void CodeGenV::visit(ListA* a) {
    deque<AST *> asts = a->getASTs();
    for (AST *a2 : asts) {
        a2->accept(*this);
    }
}
void CodeGenV::visit(StartA* a) {
    currStart = a;

    // Include runtime libraries directly by hardcoding them.
    // build IO object
    ClassA *IO = new ClassA("IO", new SuperA("Object"));
    currSymTab->addMethod("IO", "putChar", "public", PutCharFunction);
    currSymTab->addMethod("IO", "putInt", "public", PutIntFunction);
    currSymTab->addMethod("IO", "putString", "public", PutStringFunction);
    currSymTab->addMethod("IO", "peek", "public", PeekFunction));
    currSymTab->addMethod("IO", "getChar", "public", GetCharFunction);
    currSymTab->addMethod("IO", "getInt", "public",  GetIntFunction);
    currSymTab->addMethod("IO", "getLine", "public", GetLineFunction);

    a->getList()->accept(*this);

    // build _Decaf$Main in global scope which just calls the unique main method
    Type *mainReturnType = Type::getVoidTy(TheContext);
    std::vector<Type*> mainArgTypes;
    FunctionType *mainFT = FunctionType::get(mainReturnType, mainArgTypes, false);

    Function *MainFunction = Function::Create(mainFT, Function::ExternalLinkage, "_$DecafMain", TheModule.get());


    BasicBlock *BB = BasicBlock::Create(TheContext, "entry", MainFunction);
    Builder.SetInsertPoint(BB);

    std::vector<Value *> ArgsV; // no args
    Builder.CreateCall(a->getMain()->getFunc(), ArgsV, "calltmp");  // call main
    Builder.CreateRet(nullptr); // c++ nullptr = llvm void
    verifyFunction(*MainFunction);

}

void CodeGenV::visit(SuperA* a)
{

}

void CodeGenV::visit(ClassA* a)
{
    currSymTab->declareClass(a->getName());
    a->getSuperClass()->accept(*this);
    a->getMembers()->accept(*this);
}

void CodeGenV::visit(MethodBodyA* a) {
    Function* TheFunction = a->getParent()->getFunc();

    deque<AST*> formals = a->getFormalList()->getASTs();


    // Set names for all arguments.
    unsigned Idx = 0;
    for (auto &Arg : TheFunction->args())
    {
        Arg.setName(dynamic_cast<FormalA*> (formals[Idx++])->getName());
    }

    BasicBlock *BB = BasicBlock::Create(TheContext, "entry", TheFunction);
    Builder.SetInsertPoint(BB);

    // Record the function arguments in the NamedValues map.

    for (auto &Arg : TheFunction->args())
        currSymTab->declareLocal(Arg.getName(),  &Arg);

    Builder.CreateRet(nullptr); // c++ nullptr = llvm void
    a->getBlock()->accept(*this);
    if (Value *RetVal = a->getBlock()->getReg())
    {
        // Finish off the function.
        Builder.CreateRet(RetVal);

        // Validate the generated code, checking for consistency.
        verifyFunction(*TheFunction);

        // Run the optimizer on the function.
        TheFPM->run(*TheFunction);

        a->setFunc(TheFunction);
    }
    else
    {
        // Error reading body, remove function.
        TheFunction->eraseFromParent();
        LogErrorV("The function body has a mistake.")
    }


}


void CodeGenV::visit(VarDeclA* a) {
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    Value *reg = a->getExpression()->getReg();
    currSymTab->setLocal(a->getName(), reg);
}

void CodeGenV::visit(FieldA* a) {
    indent(a->getDepth()); cout << "FieldA\n";
    a->getModifers()->accept(*this);
    a->getType()->accept(*this);
    a->getVar()->accept(*this);
}

void CodeGenV::visit(ModifierA* a)
{
    //not nessecary
}

// NOTE: All function implemented as public even though symbol table can handle privacy constraint because I am not sure how to deal with static functions vs. non-static functions.
void CodeGenV::visit(MethodA* a) {
    currSymTab->enterScope();

    a->getModifiers()->accept(*this);

    // return type
    a->getType()->accept(*this);
    Type *returnType = a->getType()->getIRType();

    // arg types
    std::vector<Type*> argTypes;
    currArgTypes = argTypes;
    a->getArgs()->accept(*this);    // populates currArgTypes
    FunctionType *FT = FunctionType::get(returnType, currArgTypes, false);

    // make TheFunction
    string fname = a->getClass()->getName() + "." + a->getName();   // avoid name collision across classes
    Function *TheFunction = Function::Create(FT, Function::ExternalLinkage, fname, TheModule.get());

    a->setFunc(TheFunction);

    currSymTab->addMethod(a->getClass()->getName(), a->getName(), "public", TheFunction);
    // build method
    a->getMethodBody()->accept(*this);

    // Runs optimizations
    TheFPM->run(*TheFunction);
}

void CodeGenV::visit(ConstructorA* a) {
    a->getType()->accept(*this);
    a->getModifers()->accept(*this);
    a->getMethodBody()->accept(*this);
}

void CodeGenV::visit(FormalA* a) {
    a->getType()->accept(*this);
    if (a->getType()->getReg() != nullptr) {
        currSymTab->declareLocal(a->getName(), a->getType()->getReg());
    }
    else
    {
        LogErrorV("Type Error");
    }
}

void CodeGenV::visit(DeclStatementA* a) {
    a->getType()->accept(*this);
    currType = a->getType()->getIRType();
    a->getLocalList()->accept(*this);
}

void CodeGenV::visit(IfStatementA* a) {
    indent(a->getDepth()); cout << "IfStatementA\n";

    // Emit cond value.
    a->getExpression()->accept(*this);
    Value* CondV = a->getExpression()->getReg();
    CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Type::getInt64Ty(TheContext), 0), "ifcond");
    // current function
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    // Create blocks for the then and else cases.  Insert the 'then' block at the
    // end of the function.
    BasicBlock *ThenBB = BasicBlock::Create(TheContext, "then", TheFunction);
    BasicBlock *ElseBB = BasicBlock::Create(TheContext, "else");
    BasicBlock *MergeBB = BasicBlock::Create(TheContext, "ifcont");
    Builder.CreateCondBr(CondV, ThenBB, ElseBB);

    // Emit then value.
    Builder.SetInsertPoint(ThenBB);
    a->getStatement1()->accept(*this);
    // Value *ThenV = a->getStatement1()->getReg();
    Builder.CreateBr(MergeBB);
    // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
    ThenBB = Builder.GetInsertBlock();

    // Emit else block.
    TheFunction->getBasicBlockList().push_back(ElseBB);
    Builder.SetInsertPoint(ElseBB);
    a->getStatement2()->accept(*this);
    // Value *ElseV = a->getStatement2()->getReg();
    Builder.CreateBr(MergeBB);
    // codegen of 'Else' can change the current block, update ElseBB for the PHI.
    ElseBB = Builder.GetInsertBlock();

    // Emit merge block.
    TheFunction->getBasicBlockList().push_back(MergeBB);
    Builder.SetInsertPoint(MergeBB);

}

void CodeGenV::visit(WhileStatementA* a)
{

    // Emit cond value.
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *CondBB = BasicBlock::Create(TheContext, "cond", TheFunction);
    Builder.CreateBr(CondBB);
    Builder.SetInsertPoint(CondBB);
    a->getExpression()->accept(*this);
    Value* CondV = a->getExpression()->getReg();
    CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Type::getInt64Ty(TheContext), 0), "ifcond");
    // Create blocks for the then and else cases.  Insert the 'then' block at the
    // end of the function.
    BasicBlock *ThenBB = BasicBlock::Create(TheContext, "then", TheFunction);
    BasicBlock *ElseBB = BasicBlock::Create(TheContext, "whilecond");
    Builder.CreateCondBr(CondV, ThenBB, ElseBB);

    // Emit then value.
    Builder.SetInsertPoint(ThenBB);
    a->getStatement()->accept(*this);
    Builder.CreateBr(CondBB);
    // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
    ThenBB = Builder.GetInsertBlock();

    // Emit else block.
    TheFunction->getBasicBlockList().push_back(ElseBB);
    Builder.SetInsertPoint(ElseBB);


}

void CodeGenV::visit(ReturnStatementA* a)
{
    a->getExpression()->accept(*this);
    Builder.CreateRet(a->getExpression()->getReg());
}
void CodeGenV::visit(ContinueStatementA* a)
{
    // Code help source: https://github.com/harry-7/Decaf-Compiler
    llvm::Value *V = llvm::ConstantInt::get(TheContext->Context, llvm::APInt(32, 1));
    loopInfo *currentLoop = TheContext->loops->top();
    Expression *condition = nullptr;
    string var = currentLoop->getLoopVariable();
    AllocaInst *Alloca = TheContext->NamedValues[var];
    Value *step_val = ConstantInt::get(TheContext->Context, APInt(32, 1));
    Value *cur = TheContext->Builder->CreateLoad(Alloca, var);
    Value *next_val = TheContext->Builder->CreateAdd(cur, step_val, "NextVal");
    TheContext->Builder->CreateStore(next_val, Alloca);
    llvm::Value *cond = TheContext->Builder->CreateICmpULE(next_val, currentLoop->getCondition(),
                                                                   "loopcondition");
    BasicBlock *loopEndBlock = TheContext->Builder->GetInsertBlock();
    TheContext->Builder->CreateCondBr(cond, currentLoop->getCheckBlock(), currentLoop->getAfterBlock());
    a->setReg(V);
}
void CodeGenV::visit(BreakStatementA* a)
{
    // Code help source: https://github.com/harry-7/Decaf-Compiler
    llvm::Value *V = llvm::ConstantInt::get(TheContext->Context, llvm::APInt(32, 1));
    loopInfo *currentLoop = TheContext->loops->top();
    TheContext->Builder->CreateBr(currentLoop->getAfterBlock());
    a->setReg(V);
}

void CodeGenV::visit(BlockA* a)
{
    currSymTab->enterScope();
    a->getStatementList()->accept(*this);
    currSymTab->leaveScope();
}


void CodeGenV::visit(EmptyStatementA* a)
{
    a->setReg(nullptr);
}

// Done
void CodeGenV::visit(NewArrayA* a)
{
    a->getType()->accept(*this);
    a->getDimList()->accept(*this);
    Type * lastType;
    deque<AST*> dimensions = a->getDimList()->getASTs();
    a->setReg(ArrayType::get(a->getType()->getIRType()));
    for(auto dynamic_cast<DimensionA*> dim : dimensions)
    {
        a->setReg(ArrayType::ArrayType(a->getReg(), dim->getDim()->getReg()));
    }

}

void CodeGenV::visit(DimensionA* a)
{
    //not needed
}

// Done, NOTE: Need to check higher dimensions.
void CodeGenV::visit(ArrayRefA* a)
{
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    a->getDim()->accept(*this);
    Value * V = currSymTab->getLocal(a->getName()->getName());
    a->setReg(Builder.CreateExtractValue(V, a->getDim()->getDim()));
}


// Done
void CodeGenV::visit(NonArrayPrimaryA* a)
{
    a->getExpression()->accept(*this);
    a->setReg(a->getExpression()->getReg());
}


// TODO
void CodeGenV::visit(SuperStatementA* a)
{
    a->getArgs()->accept(*this);

}

// Done
void CodeGenV::visit(OpExpressionA* a)
{
    ExpressionA *e1 = a->getExpression1();
    ExpressionA *e2 = a->getExpression2();

    if (a->getArity() == 2)
    {
        e1->accept(*this);
        Value *L = e1->getReg();
        e2->accept(*this);
        Value *R = e2->getReg();

        string op = a->getOp();

        if (!L || !R)
        {
            LogErrorV("Missing operand for binary operator");
        }
        else if ( op == "+")
        {
            a->setReg(Builder.CreateAdd(L, R, "addtmp"));
        }
        else if (op == "-")
        {
            a->setReg(Builder.CreateSub(L, R, "subtmp"));
        }
        else if (op == "*")
        {
            a->setReg(Builder.CreateMul(L, R, "multmp"));
        }
        else if (op == "/")
        {
            a->setReg(Builder.CreateFDiv(L, R, "divtmp"));
        }
        else if (op == "%")
        {
            a->setReg(Builder.CreateSRem(L, R, "modtmp"));
        }
        else if (op == ">")
        {
            a->setReg(Builder.CreateICmpUGT(L, R, "gcmptmp"));
        }
        else if (op == ">=")
        {
            a->setReg(Builder.CreateICmpUGE(L, R, "geqcmptmp"));
        }
        else if (op == "<")
        {
            a->setReg(Builder.CreateICmpULT(L, R, "lcmptmp"));
        }
        else if (op == "<=")
        {
            a->setReg(Builder.CreateICmpULE(L, R, "leqcmptmp"));
        }
        else if (op == "!=")
        {
            a->setReg(Builder.CreateICmpNE(L, R, "neqcmptmp"));
        }
        else if (op == "==")
        {
            a->setReg(Builder.CreateICmpEQ(L, R, "eqcmptmp"));
        }
        else if (op == "&&")
        {
            a->setReg(Builder.CreateAnd(L, R, "landtmp"));
        }
        else if (op == "||")
        {
            a->setReg(Builder.CreateOr(L, R, "lortmp"));
        }
        else if (op == "=")
        {
            LogErrorV("Variable mutation is unimplemented");
        //     // a->setReg(Builder.CreateOr(L, R, "lortmp"));
        //     // cout << L << endl;
        //     // cout << R << endl;
        //     // FIXME: partial hack:
        //     // currSymTab->setLocal(e1->getName()->getName(), R);
        }

        else
        {
            LogErrorV("invalid binary operator");
        }

    }
    else
    {
        e1->accept(*this);
        Value *E = e1->getReg();
        string op = a->getOp();
        if ( op == "-" )
        {
            a->setReg(Builder.CreateNeg(E, "neg"));
        }
        else if (op == "!")
        {
            a->setReg(Builder.CreateNot(E, "not"));
        }
        else
        {
            LogErrorV("invalid unary operator");
        }
    }
}

// Done
void CodeGenV::visit(ThisExprA* a)
{
    a->setReg(currSymTab->getCurrentClass());
}

// Done
void CodeGenV::visit(NewObjExprA* a) {
    indent(a->getDepth()); cout << "NewObjExprA\n";
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
}

// Done
void CodeGenV::visit(ThisCallExprA* a) {
    indent(a->getDepth()); cout << "ThisCallExprA\n";
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);

    Function* F = currSymTab->getLocalMethod(a->getName()->getName());
    std::vector<Value *> args;
    for(FormalA* dynamic_cast<FormalA*>(arg) : a->getArgs()->getASTs())
    {
        args.push_back(arg->getReg());
    }

    a->setReg(Builder.CreateCall(F, args, currSymTab->getCurrentName() + "."+ a->getName()->getName()));
}

// Done
void CodeGenV::visit(MethodCallExprA* a) {
    indent(a->getDepth()); cout << "MethodCallExprA\n";
    a->getType()->accept(*this);
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);

    // Hard-Coded calls for base library functions.
    if (a->getName()->getName() == "putChar")
    {
        std::vector<Value *> putCharArgsV(1, a->getArgs()->getASTs().front()->getReg());
        a->setReg(Builder.CreateCall(PutCharFunction, putCharArgsV, "putchartmp"));
    }
    else if (a->getName()->getName() == "putInt")
    {
        std::vector<Value *> putIntArgsV(1, a->getArgs()->getASTs().front()->getReg());
        a->setReg(Builder.CreateCall(PutIntFunction, putIntArgsV, "putinttmp"));
    }
    else if (a->getName()->getName() == "putString")
    {
        std::vector<Value *> putStringArgsV(1, a->getArgs()->getASTs().front()->getReg());
        a->setReg(Builder.CreateCall(PutStringFunction, putStringArgsV, "putstringtmp"));
    }
    else if (a->getName()->getName() == "peek")
    {
        std::vector<Value *> peekArgsV;
        a->setReg(Builder.CreateCall(PeekFunction, peekArgsV, "peektmp"));
    }
    else if (a->getName()->getName() == "getChar")
    {
        std::vector<Value *> getCharArgsV;
        a->setReg(Builder.CreateCall(GetCharFunction, getCharArgsV, "getchartmp"));
    }
    else if (a->getName()->getName() == "getInt")
    {
        std::vector<Value *> getIntArgsV;
        a->setReg(Builder.CreateCall(GetIntFunction, getIntArgsV, "getinttmp"));
    }
    else if (a->getName()->getName() == "getLine")
    {
        std::vector<Value *> getLineArgsV;
        a->setReg(Builder.CreateCall(GetLineFunction, getLineArgsV, "getlinetmp"));
    }
    else
    {
        Value* V = = a->getType()->getReg();
        Function* F = currSymTab->getOther(V->getName(), a->getName()->getName());
        std::vector<Value *> args;
        for(FormalA* dynamic_cast<FormalA*>(arg) : a->getArgs()->getASTs())
        {
            args.push_back(arg->getReg());
        }

        a->setReg(Builder.CreateCall(F, args, V->getName() + "."+ a->getName()->getName()));
    }
}

// TODO
void CodeGenV::visit(SuperCallExprA* a) {
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
}

// Done
void CodeGenV::visit(FieldExprA* a) {
    a->getType()->accept(*this);
    a->getName()->accept(*this)
    Value* V = = a->getType()->getReg();
    Value* F = currSymTab->getOther(V->getName(), a->getName()->getName());
    a->setReg(F);
}
// TODO
void CodeGenV::visit(SuperFieldExprA* a) {
    a->getName()->accept(*this);
}
