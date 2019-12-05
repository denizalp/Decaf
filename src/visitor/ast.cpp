
#include "ast.h"
#include <iostream>
#include <vector>

using namespace std;

/// Main ///

// int main() {
//     vector<AST*> asts{
//         new ClassA("Aaa"),
//         new ClassA("Bbb"),
//         new ClassA("Ccc")
//     };
//     ListA *list = new ListA(asts);
//     StartA *start = new StartA(list);

//     start->accept(*(new CounterV()));
//     start->accept(*(new PrinterV()));
// 	return 0;
// }

/// Accept Functions for PrinterV ///

void StartA::accept(Visitor& v) { v.visit(this); }
void ListA::accept(Visitor& v) { v.visit(this); }
void ClassA::accept(Visitor& v) { v.visit(this); }
void SuperA::accept(Visitor& v) { v.visit(this); }
void MethodBodyA::accept(Visitor& v) { v.visit(this); }
void FieldDeclA::accept(Visitor& v) { v.visit(this); }
void FieldA::accept(Visitor& v) { v.visit(this); }
void MethodA::accept(Visitor& v) { v.visit(this); }
void ConstructorA::accept(Visitor& v) { v.visit(this); }
void FormalA::accept(Visitor& v) { v.visit(this); }
void DeclStatementA::accept(Visitor& v) { v.visit(this); }
void LocalA::accept(Visitor& v) { v.visit(this); }
void IfStatementA::accept(Visitor& v) { v.visit(this); }
void ExpressionStatementA::accept(Visitor& v) { v.visit(this); }
void WhileStatementA::accept(Visitor& v) { v.visit(this); }
void ReturnStatementA::accept(Visitor& v) { v.visit(this); }
void ContinueStatementA::accept(Visitor& v) { v.visit(this); }
void BreakStatementA::accept(Visitor& v) { v.visit(this); }
void BlockStatementA::accept(Visitor& v) { v.visit(this); }
void BlockA::accept(Visitor& v) { v.visit(this); }
void SuperStatementA::accept(Visitor& v) { v.visit(this); }
void CallA::accept(Visitor& v) { v.visit(this); }
void OpExpressionA::accept(Visitor& v) { v.visit(this); }
void NewArrayA::accept(Visitor& v) { v.visit(this); }
void ArrayRefA::accept(Visitor& v) { v.visit(this); }
void VarDeclA::accept(Visitor& v) { v.visit(this); }
void TypeA::accept(Visitor& v) { v.visit(this); }
void PrimTypeA::accept(Visitor& v) { v.visit(this); }
void ArrayTypeA::accept(Visitor& v) { v.visit(this); }
void ClassTypeA::accept(Visitor& v) { v.visit(this); }
void PrimaryExprA::accept(Visitor& v) { v.visit(this); }
void ExpressionA::accept(Visitor& v) { v.visit(this); }
void InitializerA::accept(Visitor& v) { v.visit(this); }
void StatementA::accept(Visitor& v) { v.visit(this); }
void NameA::accept(Visitor& v) { v.visit(this); }
void StrLitA::accept(Visitor& v) { v.visit(this); }
void IntLitA::accept(Visitor& v) { v.visit(this); }
void DimensionA::accept(Visitor& v) { v.visit(this); }
void FieldExprA::accept(Visitor& v) { v.visit(this); }
void NewObjExprA::accept(Visitor& v) { v.visit(this); }
void PrimaryArrayA::accept(Visitor& v) { v.visit(this); }
void ThisCallExprA::accept(Visitor& v) { v.visit(this); }
void SuperCallExprA::accept(Visitor& v) { v.visit(this); }
void EmptyStatementA::accept(Visitor& v) { v.visit(this); }
void MethodCallExprA::accept(Visitor& v) { v.visit(this); }
void SuperFieldExprA::accept(Visitor& v) { v.visit(this); }
void NonArrayPrimaryA::accept(Visitor& v) { v.visit(this); }
void BoolLitA::accept(Visitor& v) { v.visit(this); }
void CharLitA::accept(Visitor& v) { v.visit(this); }
void NullLitA::accept(Visitor& v) { v.visit(this); }
void ModifierA::accept(Visitor& v) { v.visit(this); }
void ThisExprA::accept(Visitor& v) { v.visit(this); }

// Accept Functions for CodeGenV

Value* StartA::accept(CodeGenV& v) { return v.visit(this); }
Value* ListA::accept(CodeGenV& v) { return v.visit(this); }
Value* ClassA::accept(CodeGenV& v) { return v.visit(this); }
Value* SuperA::accept(CodeGenV& v) { return v.visit(this); }
Value* MethodBodyA::accept(CodeGenV& v) { return v.visit(this); }
Value* FieldDeclA::accept(CodeGenV& v) { return v.visit(this); }
Value* FieldA::accept(CodeGenV& v) { return v.visit(this); }
Value* MethodA::accept(CodeGenV& v) { return v.visit(this); }
Value* ConstructorA::accept(CodeGenV& v) { return v.visit(this); }
Value* FormalA::accept(CodeGenV& v) { return v.visit(this); }
Value* DeclStatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* LocalA::accept(CodeGenV& v) { return v.visit(this); }
Value* IfStatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* ExpressionStatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* WhileStatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* ReturnStatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* ContinueStatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* BreakStatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* BlockStatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* BlockA::accept(CodeGenV& v) { return v.visit(this); }
Value* SuperStatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* CallA::accept(CodeGenV& v) { return v.visit(this); }
Value* OpExpressionA::accept(CodeGenV& v) { return v.visit(this); }
Value* NewArrayA::accept(CodeGenV& v) { return v.visit(this); }
Value* ArrayRefA::accept(CodeGenV& v) { return v.visit(this); }
Value* VarDeclA::accept(CodeGenV& v) { return v.visit(this); }
Value* TypeA::accept(CodeGenV& v) { return v.visit(this); }
Value* PrimTypeA::accept(CodeGenV& v) { return v.visit(this); }
Value* ArrayTypeA::accept(CodeGenV& v) { return v.visit(this); }
Value* ClassTypeA::accept(CodeGenV& v) { return v.visit(this); }
Value* PrimaryExprA::accept(CodeGenV& v) { return v.visit(this); }
Value* ExpressionA::accept(CodeGenV& v) { return v.visit(this); }
Value* InitializerA::accept(CodeGenV& v) { return v.visit(this); }
Value* StatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* NameA::accept(CodeGenV& v) { return v.visit(this); }
Value* StrLitA::accept(CodeGenV& v) { return v.visit(this); }
Value* IntLitA::accept(CodeGenV& v) { return v.visit(this); }
Value* DimensionA::accept(CodeGenV& v) { return v.visit(this); }
Value* FieldExprA::accept(CodeGenV& v) { return v.visit(this); }
Value* NewObjExprA::accept(CodeGenV& v) { return v.visit(this); }
Value* PrimaryArrayA::accept(CodeGenV& v) { return v.visit(this); }
Value* ThisCallExprA::accept(CodeGenV& v) { return v.visit(this); }
Value* SuperCallExprA::accept(CodeGenV& v) { return v.visit(this); }
Value* EmptyStatementA::accept(CodeGenV& v) { return v.visit(this); }
Value* MethodCallExprA::accept(CodeGenV& v) { return v.visit(this); }
Value* SuperFieldExprA::accept(CodeGenV& v) { return v.visit(this); }
Value* NonArrayPrimaryA::accept(CodeGenV& v) { return v.visit(this); }
Value* BoolLitA::accept(CodeGenV& v) { return v.visit(this); }
Value* CharLitA::accept(CodeGenV& v) { return v.visit(this); }
Value* NullLitA::accept(CodeGenV& v) { return v.visit(this); }
Value* ModifierA::accept(CodeGenV& v) { return v.visit(this); }
Value* ThisExprA::accept(CodeGenV& v) { return v.visit(this); }

/// Codegen: Visitors ///

Value* CodeGenV::visit(StrLitA* a)
{

}
Value* CodeGenV::visit(CharLitA* a)
{
    return ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue());
}
Value* CodeGenV::visit(IntLitA* a)
{
    return ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue());
}

Value* CodeGenV::visit(BoolLitA* a)
{
    return ConstantInt::get(Type::getInt64Ty(TheContext), a->getValue());
}

Value* CodeGenV::visit(NullLitA* a)
{
    return ConstantInt::get(Type::getInt64Ty(TheContext), 0);
}

Value* CodeGenV::visit(NameA* a)
{

}

Value* CodeGenV::visit(TypeA* a)
{

}

Value* CodeGenV::visit(PrimTypeA* a)
{
    a->getName()->accept(*this);

}

Value* CodeGenV::visit(ArrayTypeA* a)
{
    a->getType()->accept(*this);

}

Value* CodeGenV::visit(ClassTypeA* a)
{
    a->getName()->accept(*this);

}

Value* CodeGenV::visit(StatementA* a)
{

}

Value* CodeGenV::visit(PrimaryExprA* a)
{

}

Value* CodeGenV::visit(ExpressionA* a)
{

}

Value* CodeGenV::visit(ListA* a)
{

    deque<AST *> asts = a->getASTs();
    for (AST *a2 : asts) {
        a2->accept(*this);
    }

}
Value* CodeGenV::visit(StartA* a)
{
    a->getList()->accept(*this);

}

Value* CodeGenV::visit(SuperA* a)
{
    a->getName()->accept(*this);

}

Value* CodeGenV::visit(ClassA* a)
{
    a->getName()->accept(*this);
    a->getSuperClass()->accept(*this);
    a->getMembers()->accept(*this);

}

Value* CodeGenV::visit(MethodBodyA* a)
{
    // a->getFormalList()->accept(*this); // repeated in MethodA
    a->getStatementList()->accept(*this);

}

// IGNORE BELOW FOR THE MOMENT
Value* CodeGenV::visit(FieldDeclA* a)
{
    a->getFieldList()->accept(*this);
    // TODO
    // for(auto var:this->var_declaration_list)
    // {
    //     if(data_type=="int")
    //     {
    //         type_func temp={var->getname(),"GLOBAL"};
    //         var_map[temp]=0;
    //     }
    //     if(data_type=="boolean")
    //     {
    //         type_func temp={var->getname(),"GLOBAL"};
    //         var_map[temp]=1;
    //     }
    // }

}

Value* CodeGenV::visit(VarDeclA* a)
{
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);

}

Value* CodeGenV::visit(FieldA* a)
{
    a->getModifers()->accept(*this);
    a->getType()->accept(*this);
    a->getVar()->accept(*this);

}

Value* CodeGenV::visit(ModifierA* a)
{

}

Value* CodeGenV::visit(MethodA* a)
{
    a->getName()->accept(*this);
    a->getModifiers()->accept(*this);
    a->getType()->accept(*this);
    a->getArgs()->accept(*this);
    a->getMethodBody()->accept(*this);

}

Value* CodeGenV::visit(ConstructorA* a)
{
    a->getType()->accept(*this);
    a->getModifers()->accept(*this);
    a->getMethodBody()->accept(*this);

}

Value* CodeGenV::visit(FormalA* a)
{
    a->getType()->accept(*this);
    a->getVarDecl()->accept(*this);

}

Value* CodeGenV::visit(DeclStatementA* a)
{
    a->getType()->accept(*this);
    a->getLocalList()->accept(*this);

}

Value* CodeGenV::visit(LocalA* a)
{
    a->getExpression()->accept(*this);

}

Value* CodeGenV::visit(IfStatementA* a)
{
    a->getExpression()->accept(*this);
    a->getStatement1()->accept(*this);
    a->getStatement2()->accept(*this);

}
Value* CodeGenV::visit(ExpressionStatementA* a)
{
    a->getExpression()->accept(*this);

}

Value* CodeGenV::visit(WhileStatementA* a)
{
    a->getExpression()->accept(*this);
    a->getStatement()->accept(*this);

}

Value* CodeGenV::visit(ReturnStatementA* a)
{
    a->getExpression()->accept(*this);

}
Value* CodeGenV::visit(ContinueStatementA* a)
{

}
Value* CodeGenV::visit(BreakStatementA* a)
{

}

Value* CodeGenV::visit(BlockA* a)
{
    a->getStatementList()->accept(*this);

}

Value* CodeGenV::visit(BlockStatementA* a)
{
    a->getBlock()->accept(*this);

}

Value* CodeGenV::visit(EmptyStatementA* a)
{

}

Value* CodeGenV::visit(NewArrayA* a)
{
    a->getType()->accept(*this);
    a->getDimList()->accept(*this);

}

Value* CodeGenV::visit(DimensionA* a)
{

}

Value* CodeGenV::visit(ArrayRefA* a)
{
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    a->getDim()->accept(*this);

}

Value* CodeGenV::visit(PrimaryArrayA* a)
{
    a->getArray()->accept(*this);

}

Value* CodeGenV::visit(NonArrayPrimaryA* a)
{
    a->getExpression()->accept(*this);

}

Value* CodeGenV::visit(CallA* a)
{
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);

}

Value* CodeGenV::visit(SuperStatementA* a)
{
    a->getArgs()->accept(*this);

}

// NOTE: Make sure lhs and rhs are pf the same type.

Value* CodeGenV::visit(OpExpressionA* a)
{
    if (a->getArity() == 2)
    {
        Value *L = a->getExpression1()->accept(*this);
        Value *R = a->getExpression2()->accept(*this);

        if (!L || !R)
        {
          return LogErrorV("Missing operand for binary operator");
        }
        string op = a->getOp();
        if ( op == "+")
        {
          return Builder.CreateFAdd(L, R, "addtmp");
        }
        else if (op == "-")
        {
          return Builder.CreateFSub(L, R, "subtmp");
        }
        else if (op == "*")
        {
          return Builder.CreateFMul(L, R, "multmp");
        }
        else if (op == "/")
        {
            return Builder.CreateFDiv(L, R, "divtmp");
        }
        else if (op == "%")
        {
            return Builder.CreateSRem(L, R, "modtmp");
        }
        else if (op == ">")
        {
            return Builder.CreateFCmpUGT(L, R, "gcmptmp");
        }
        else if (op == ">=")
        {
            return Builder.CreateFCmpUGE(L, R, "geqcmptmp");
        }
        else if (op == "<")
        {
          return Builder.CreateFCmpULT(L, R, "lcmptmp");
        }
        else if (op == "<=")
        {
            return Builder.CreateFCmpULE(L, R, "leqcmptmp");
        }
        else if (op == "!=")
        {
            return Builder.CreateICmpNE(L, R, "neqcmptmp");
        }
        else if (op == "==")
        {
            return Builder.CreateICmpEQ(L, R, "neqcmptmp");
        }

        else if (op == "&&")
        {
             return Builder.CreateAnd(L, R, "landtmp");
        }
        else if (op == "||")
        {
            return Builder.CreateOr(L, R, "landtmp");
        }

        else
        {
          return LogErrorV("invalid binary operator");
        }

    }
    else
    {
        Value *E = a->getExpression1()->accept(*this);
        string op = a->getOp();
        if ( op == "-" )
        {
            return Builder.CreateNeg(E, "neg");
        }
        else if (op == "!")
        {
            return Builder.CreateNot(E, "not");
        }
        else
        {
            return LogErrorV("invalid unary operator");
        }
    }

}

Value* CodeGenV::visit(ThisExprA* a)
{

}

Value* CodeGenV::visit(NewObjExprA* a)
{
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);

}

Value* CodeGenV::visit(ThisCallExprA* a)
{
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);

}

Value* CodeGenV::visit(MethodCallExprA* a)
{
    a->getType()->accept(*this);
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);

}

Value* CodeGenV::visit(SuperCallExprA* a)
{
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);

}

Value* CodeGenV::visit(FieldExprA* a)
{
    a->getType()->accept(*this);
    a->getName()->accept(*this);

}

Value* CodeGenV::visit(SuperFieldExprA* a)
{
    a->getName()->accept(*this);

}

Value* CodeGenV::visit(InitializerA* a)
{

}




/// Printer: Visitors ///
void PrinterV::visit(StrLitA* a) {
    indent();
    cout << "StrLitA: " << a->getValue() << "\n";
    ++d;
    --d;
}
void PrinterV::visit(CharLitA* a) {
    indent();
    cout << "CharLitA: " << a->getValue() << endl ;
    ++d;
    --d;
}
void PrinterV::visit(IntLitA* a) {
    indent();
    cout << "IntLitA: " << a->getValue() << "\n";
    ++d;
    --d;
}

void PrinterV::visit(BoolLitA* a) {
    indent();
    cout << "BoolLitA: " << a->getValue() << endl;
    ++d;
    --d;
}

void PrinterV::visit(NullLitA* a) {
    indent();
    cout << "NullLitA\n";
    ++d;
    --d;
}

void PrinterV::visit(NameA* a) {
    indent();
    cout << "NameA: " << a->getName() << endl;
    ++d;
    --d;
}

void PrinterV::visit(TypeA* a) {
    indent();
    cout << "TypeA" << "\n";
    ++d;
    --d;
}

void PrinterV::visit(PrimTypeA* a) {
    indent();
    cout << "PrimTypeA" << "\n";
    ++d;
    a->getName()->accept(*this);
    --d;
}

void PrinterV::visit(ArrayTypeA* a) {
    indent();
    cout << "ArrayTypeA: dim " << a->getDim() << "\n";
    ++d;
    a->getType()->accept(*this);
    --d;
}

void PrinterV::visit(ClassTypeA* a) {
    indent();
    cout << "ClassTypeA: " << a->getName() << "\n";
    ++d;
    a->getName()->accept(*this);
    --d;
}

void PrinterV::visit(StatementA* a) {
    indent();
    cout << "StatementA\n";
    ++d;
    --d;
}

void PrinterV::visit(PrimaryExprA* a) {
    indent();
    cout << "PrimaryExprA\n";
    ++d;
    --d;
}

void PrinterV::visit(ExpressionA* a) {
    indent();
    cout << "ExpressionA\n";
    ++d;
    --d;
}

void PrinterV::visit(ListA* a) {
    indent();
    cout << "ListA\n";
    ++d;
    deque<AST *> asts = a->getASTs();
    for (AST *a2 : asts) {
        a2->accept(*this);
    }
    --d;
}
void PrinterV::visit(StartA* a) {
    indent();
    cout << "StartA\n";
    ++d;
    a->getList()->accept(*this);
    --d;
}

void PrinterV::visit(SuperA* a) {
    indent();
    cout << "SuperA\n";
    ++d;
    a->getName()->accept(*this);
    --d;
}

void PrinterV::visit(ClassA* a) {
    indent();
    cout << "ClassA\n" ;
    ++d;
    a->getName()->accept(*this);
    a->getSuperClass()->accept(*this);
    a->getMembers()->accept(*this);
    --d;
}

void PrinterV::visit(MethodBodyA* a) {
    indent();
    cout << "MethodBodyA\n";
    ++d;
    // a->getFormalList()->accept(*this); // repeated in MethodA
    a->getStatementList()->accept(*this);
    --d;
}

void PrinterV::visit(FieldDeclA* a) {
    indent();
    cout << "FieldDeclA\n";
    ++d;
    a->getFieldList()->accept(*this);
    --d;
}

void PrinterV::visit(VarDeclA* a) {
    indent();
    cout << "VarDeclA\n";
    ++d;
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    --d;
}

void PrinterV::visit(FieldA* a) {
    indent();
    cout << "FieldA\n";
    ++d;
    a->getModifers()->accept(*this);
    a->getType()->accept(*this);
    a->getVar()->accept(*this);
    --d;
}

void PrinterV::visit(ModifierA* a) {
    indent();
    cout << "ModifierA: " << a->getModifier() << endl;
    ++d;
    --d;
}

void PrinterV::visit(MethodA* a) {
    indent();
    cout << "MethodA\n";
    ++d;
    a->getName()->accept(*this);
    a->getModifiers()->accept(*this);
    a->getType()->accept(*this);
    a->getArgs()->accept(*this);
    a->getMethodBody()->accept(*this);
    --d;
}

void PrinterV::visit(ConstructorA* a) {
    indent();
    cout << "ConstructorA\n";
    ++d;
    a->getType()->accept(*this);
    a->getModifers()->accept(*this);
    a->getMethodBody()->accept(*this);
    --d;
}

void PrinterV::visit(FormalA* a) {
    indent();
    cout << "FormalA\n";
    ++d;
    a->getType()->accept(*this);
    a->getVarDecl()->accept(*this);
    --d;
}

void PrinterV::visit(DeclStatementA* a) {
    indent();
    cout << "DeclStatementA\n";
    ++d;
    a->getType()->accept(*this);
    a->getLocalList()->accept(*this);
    --d;
}

void PrinterV::visit(LocalA* a) {
    indent();
    cout << "LocalA\n";
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void PrinterV::visit(IfStatementA* a) {
    indent();
    cout << "IfStatementA\n";
    ++d;
    a->getExpression()->accept(*this);
    a->getStatement1()->accept(*this);
    a->getStatement2()->accept(*this);
    --d;
}
void PrinterV::visit(ExpressionStatementA* a) {
    indent();
    cout << "ExpressionStatementA\n";
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void PrinterV::visit(WhileStatementA* a) {
    indent();
    cout << "WhileStatementA\n";
    ++d;
    a->getExpression()->accept(*this);
    a->getStatement()->accept(*this);
    --d;
}

void PrinterV::visit(ReturnStatementA* a) {
    indent();
    cout << "ReturnStatementA\n";
    ++d;
    a->getExpression()->accept(*this);
    --d;
}
void PrinterV::visit(ContinueStatementA* a) {
    indent();
    cout << "ContinueStatementA\n";
    ++d;
    --d;
}
void PrinterV::visit(BreakStatementA* a) {
    indent();
    cout << "BreakStatementA\n";
    ++d;
    --d;
}

void PrinterV::visit(BlockA* a) {
    indent();
    cout << "BlockA\n";
    ++d;
    a->getStatementList()->accept(*this);
    --d;
}

void PrinterV::visit(BlockStatementA* a) {
    indent();
    cout << "BlockStatementA\n";
    ++d;
    a->getBlock()->accept(*this);
    --d;
}

void PrinterV::visit(EmptyStatementA* a) {
    indent();
    cout << "EmptyStatementA\n";
    ++d;
    --d;
}

void PrinterV::visit(NewArrayA* a) {
    indent();
    cout << "NewArrayA\n";
    ++d;
    a->getType()->accept(*this);
    a->getDimList()->accept(*this);
    --d;
}

void PrinterV::visit(DimensionA* a) {
    indent();
    cout << "DimensionA" << a->getDim() << endl;
    ++d;
    --d;
}

void PrinterV::visit(ArrayRefA* a) {
    indent();
    cout << "ArrayRefA\n";
    ++d;
    a->getName()->accept(*this);
    a->getExpression()->accept(*this);
    a->getDim()->accept(*this);
    --d;
}

void PrinterV::visit(PrimaryArrayA* a) {
    indent();
    cout << "PrimaryArrayA\n";
    ++d;
    a->getArray()->accept(*this);
    --d;
}

void PrinterV::visit(NonArrayPrimaryA* a) {
    indent();
    cout << "NonArrayPrimaryA\n";
    ++d;
    a->getExpression()->accept(*this);
    --d;
}

void PrinterV::visit(CallA* a) {
    indent();
    cout << "CallA: " << a->getName() << "\n";
    ++d;
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
    --d;
}

void PrinterV::visit(SuperStatementA* a) {
    indent();
    cout << "SuperStatementA\n";
    ++d;
    a->getArgs()->accept(*this);
    --d;
}

void PrinterV::visit(OpExpressionA* a) {
    indent();
    cout << "OpExpressionA: " << a->getOp() << " (" << a->getArity() << ")\n";
    ++d;
    a->getExpression1()->accept(*this);
    a->getExpression2()->accept(*this);
    --d;
}

void PrinterV::visit(ThisExprA* a) {
    indent();
    cout << "ThisExprA\n";
    ++d;
    --d;
}

void PrinterV::visit(NewObjExprA* a) {
    indent();
    cout << "NewObjExprA\n";
    ++d;
    a->getName()->accept(*this);
    a->getExpressionList()->accept(*this);
    --d;
}

void PrinterV::visit(ThisCallExprA* a) {
    indent();
    cout << "ThisCallExprA\n";
    ++d;
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
    --d;
}

void PrinterV::visit(MethodCallExprA* a) {
    indent();
    cout << "MethodCallExprA\n";
    ++d;
    a->getType()->accept(*this);
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
    --d;
}

void PrinterV::visit(SuperCallExprA* a) {
    indent();
    cout << "SuperCallExprA\n";
    ++d;
    a->getName()->accept(*this);
    a->getArgs()->accept(*this);
    --d;
}

void PrinterV::visit(FieldExprA* a) {
    indent();
    cout << "FieldExprA\n";
    ++d;
    a->getType()->accept(*this);
    a->getName()->accept(*this);
    --d;
}

void PrinterV::visit(SuperFieldExprA* a) {
    indent();
    cout << "SuperFieldExprA\n";
    ++d;
    a->getName()->accept(*this);
    --d;
}

void PrinterV::visit(InitializerA* a) {
    indent();
    cout << "InitializerA\n";
    ++d;
    --d;
}











// void CounterV::visit(StartA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ListA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ClassA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(SuperA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(MethodBodyA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(FieldDeclA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(FieldA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(MethodA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ConstructorA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(FormalA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(DeclStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(LocalA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(IfStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ExpressionStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(WhileStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ReturnStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ContinueStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(BreakStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(BlockStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(BlockA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(SuperStatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(CallA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(OpExpressionA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(NewArrayA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ArrayRefA* a) { cout << this->c++ << "\n"; }

// void CounterV::visit(PrimTypeA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ArrayTypeA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(ClassTypeA* a) { cout << this->c++ << "\n"; }

// void CounterV::visit(ExpressionA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(InitializerA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(StatementA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(NameA* a) { cout << this->c++ << "\n"; }
// void CounterV::visit(StrLitA* a) { cout << this->c++ << "\n"; }
