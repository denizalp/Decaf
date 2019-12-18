
#pragma once

#include <list>

using namespace std;
using namespace llvm;

/// SymbolTable ///
class Scope
{
public:
    map<string, tuple<string, Value*>> localSymbols;

    Scope() {};
    bool hasSymbol(string name);
    bool isPrivate(string name);
    string getClass();
    Value* getValue(string name);
    void declareVar(string name, Value* value);
    void setValue(string name, Value* value);
    void Print(string s) {
        cout << s << endl;
    }
};

class SymbolTable
{
private:
    list<Scope *> scopes;
    map<string, tuple<string, Function*>> functions;
    string className;
    Value *classValue;
public:
    SymbolTable(string cn):  className(cn) {};

    // Set value of symbol in current scope.
    void setLocal(string name, Value* value);
    void addMethod(string funcName, string modifier, Function* func) {functions->insert({funcName, make_tuple(modifier,func)}); }
    Function *getMethod(string name) { if(get<0>(functions[name]) == "public")
    {
        return get<1>(functions[name]);
    }
    else
    {
        LogErrorV("Function is private.")
    }
}
    Function *getMethodLocally(string name) { return get<1>(functions[name]);};
    void setGlobal(string name, Value* value);
    //Check if a symbol is in current scope
    bool isLocal(string name);

    // Get the value of symbol in current scope
    Value* getLocal(string name);

    // Declare symbol in current scope
    void declareLocal(string name, string modifier, Value* value);

    // Check if value is declared in any scope
    bool isGlobal(string name);

    //returns value for the symbol closest to the current scope
    Value * getGlobal(string name);

    Value *getCurrentClass() { return classValue; }

    void enterScope();

    void leaveScope();

    void Print(string s) {
        cout << s << endl;
    }

};

class GlobalTable
{
private:
    map<string, SymbolTable *> scopes;
    string currentClass;
public:
    GlobalTable() {};
    void setCurrentClass(string className) {currentClass = className; }
    void addMethod(string className, string functionName, string modifier, Function* func) { scopes[className]->addMethod(functionName, modifier, func)} ;
    void declareClass(string className) {scopes.insert({className, new SymbolTable(className)}); };
    Function* getLocalMethod(string name) { return scopes[currentClass]->getMethodLocally(name);}
    // Set value of symbol in current scope.
    void setLocal(string name, Value* value) { scopes[currentClass]->setLocal(name, value); };

    void *setOther(string className, string varName, Value* value) { scopes[className]->setGlobal(varName, value); }

    //Check if a symbol is in current scope
    bool isLocal(string name) { return scopes[currentClass]->isLocal(name);};

    // Get the value of symbol in current scope
    Value* getLocal(string name) { return scopes[currentClass]->getLocal(name); };

    Value *getOther(string className, string varName) { return scopes[className]->getGlobal(varName); }

    // Declare symbol in current scope
    void declareLocal(string name, string modifier ,Value* value) { scopes[currentClass]->declareLocal(name, modifier, value); };

    Value *getCurrentClass() { return scopes[currentClass]->getCurrentClass(); }

    string getCurrentName() { return currentClass; }

    void Print(string s) {
        cout << s << endl;
    }
};
