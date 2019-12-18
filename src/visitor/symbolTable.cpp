
#include "symbolTable.h"
#include <tuple>

bool Scope::hasSymbol(string name)
{
    auto it = localSymbols.find(name);
    return localSymbols.end() != it;
}
bool Scope::isPrivate(string name)
{
    return get<0>(localSymbols[name]) == "private"
}
Value* Scope::getValue(string name)
{
    if (hasSymbol(name))
    {
        return get<1>(localSymbols[name]);
    }
    else
    {
        cout << "Variable not in scope" << endl;
        return nullptr;
    }
}
void Scope::declareVar(string name, string modifier, Value* value)
{
    localSymbols.insert({name, make_tuple(modifier, value)});
}

void Scope::setValue(string name, Value* value)
{
    if (hasSymbol(name))
    {
        get<1>(localSymbols[name]) = value;
    }
    else
    {
        fprintf(stderr, "Variable %s not in scope.\n", name.c_str());
    }
}

// Set value of symbol in current scope.
void SymbolTable::setLocal(string name, Value* value)
{
    this->scopes.front()->setValue(name, value);
}

// Set value of symbol in current scope.
void SymbolTable::setGlobal(string name, Value* value)
{
        this->scopes.front()->setValue(name, value);
}

//Check if a symbol is in current scope
bool SymbolTable::isLocal(string name)
{
    return this->scopes.front()->hasSymbol(name);
}
// Get the value of symbol in current scope
Value* SymbolTable::getLocal(string name)
{
    return this->scopes.front()->getValue(name);
}
// Declare symbol in current scope
void SymbolTable::declareLocal(string name, string modifier, Value* value) {
    if (!isLocal(name))
    {
        this->scopes.front()->declareVar(name, modifier, value);
    }
    else
    {
        fprintf(stderr, "Variable %s already declared!\n", name.c_str());
    }
}
// Check if value is declared in any scope
bool SymbolTable::isGlobal(string name)
{
    for(auto scope : scopes)
    {
        if (scope->hasSymbol(name) && !scope->isPrivate(name))
        {
            return true;
        }
    }
    return false;
}
//returns value for the symbol closest to the current scope
Value * SymbolTable::getGlobal(std::string name)
{
    for(auto scope : scopes)
    {
        if (scope->hasSymbol(name) && !scope->isPrivate(name) )
        {
            return scope->getValue(name);
        }
    }
    return nullptr;
}

void SymbolTable::enterScope() {
    this->scopes.push_front(new Scope());
}
void SymbolTable::leaveScope() {
    this->scopes.pop_front();
}
