#ifndef TOKEN_CHILD_H
#define TOKEN_CHILD_H
#include <iostream>
#include <string.h>
#include "token.h"
using namespace std;

class TokenStr : public Token
{
public:
    TokenStr() { value = ""; }

    TokenStr(string v) { value = v; }

    void Print(ostream &outs = cout) const { outs << "[" << value << "]"; }
    TOKEN_TYPES TypeOf() { return TOKENSTR; }
    string TokenStrOnly() { return value; } // example of a function present in a child
private:
    string value;
};
class Logical : public Token
{
public:
    Logical() { value = ""; }

    Logical(string v) { value = v; }
    int precedence()
    {
        if (value == "and")
            return 2;
        else if (value == "or")
            return 1;
        return -1;
    }
    void Print(ostream &outs = cout) const { outs << "[" << value << "]"; }
    TOKEN_TYPES TypeOf() { return LOGICAL; }
    string LogicalOnly() { return value; } // example of a function present in a child
private:
    string value;
};
class Relational : public Token
{
public:
    Relational() { value = ""; }

    Relational(string v) { value = v; }

    void Print(ostream &outs = cout) const { outs << "[" << value << "]"; }
    TOKEN_TYPES TypeOf() { return RELATIONAL; }
    string RelationalOnly() { return value; } // example of a function present in a child
private:
    string value;
};

class LeftParen : public Token
{
public:
    LeftParen() {}
    void Print(ostream &outs = cout) const { outs << "("; }
    TOKEN_TYPES TypeOf() { return LEFTPAREN; }
    string LeftParenOnly() { return "("; }
};

class RightParen : public Token
{
public:
    RightParen() {}
    void Print(ostream &outs = cout) const { outs << ")"; }
    TOKEN_TYPES TypeOf() { return RIGHTPAREN; }
    string RighitParenOnly() { return ")"; }
};

// bool is_smaller(Token *t1, Token *t2)
// {
//     int token1 = static_cast<Logical *>(t1)->precedence();
//     int token2 = static_cast<Logical *>(t2)->precedence();
//     if (token1 < token2)
//         return true;
//     return false;
// }
#endif