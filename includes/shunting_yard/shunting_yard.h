#ifndef SHUNTING_YARD
#define SHUNTING_YARD

#include <iostream>
#include <iomanip>
using namespace std;
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/token_child.h"
#include <vector>
// #include "../token/integer.h"
// #include "../token/operator.h"
// #include "../token/function.h"
// #include "../token/leftparen.h"
// #include "../token/rightparen.h"
class ShuntingYard
{
public:
    ShuntingYard();
    ShuntingYard(const Queue<Token *> &other);
    ShuntingYard(const vector<string> &other);
    void infix(const Queue<Token *> &other);
    Queue<Token *> postfix();
    Queue<Token *> postfix(const Queue<Token *> &other);
    bool compare(Token *t1, Token *t2);

private:
    Queue<Token *> _input;
};
#endif