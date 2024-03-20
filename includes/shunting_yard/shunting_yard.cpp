#include "shunting_yard.h"

ShuntingYard::ShuntingYard()
{
}
ShuntingYard::ShuntingYard(const Queue<Token *> &other)
{
    _input = other;
}
ShuntingYard::ShuntingYard(const vector<string> &other)
{
    for (int i = 0; i < other.size(); i++)
    {
        string str = other[i];
        if (str == "(")
            _input.push(new LeftParen());
        else if (str == ")")
            _input.push(new RightParen());
        else if (str == "<" || str == "<=" || str == ">" || str == ">=" || str == "=")
            _input.push(new Relational(str));
        else if (str == "and" || str == "or")
            _input.push(new Logical(str));
        else
            _input.push(new TokenStr(str));
    }
}
void ShuntingYard::infix(const Queue<Token *> &other)
{
    _input = other;
}

Queue<Token *> ShuntingYard::postfix(const Queue<Token *> &other)
{
    _input = other;
    return postfix();
}

Queue<Token *> ShuntingYard::postfix()
{
    Stack<Token *> stack;
    Queue<Token *> result;
    Token *walker;

    while (_input.begin() != nullptr)
    {
        int value1 = 0;
        int value2 = 0;
        walker = _input.pop();
        switch (walker->TypeOf())
        {
        case TOKENSTR:
            result.push(walker);
            break;
        case RIGHTPAREN:
            while (!stack.empty() && stack.top()->TypeOf() != LEFTPAREN)
            {
                result.push(stack.pop());
            }
            if (!stack.empty())
                stack.pop();
            break;
        case LEFTPAREN:
            stack.push(walker);
            break;
        case LOGICAL:
            // if (!stack.empty() && stack.top()->TypeOf() == LOGICAL)
            // {
            //     value1 = static_cast<Logical *>(stack.top())->precedence();
            //     value2 = static_cast<Logical *>(walker)->precedence();
            // }
            // if ((stack.empty()) || (stack.top()->TypeOf() == LEFTPAREN) || (stack.top()->TypeOf() != RELATIONAL) || ((stack.top()->TypeOf() == LOGICAL) && (value1 < value2)))
            //     stack.push(walker);
            // else if (stack.top()->TypeOf() == RELATIONAL || (stack.top()->TypeOf() == LOGICAL && (value1 >= value2)))
            // {
            //     while (stack.top()->TypeOf() == RELATIONAL || (stack.top()->TypeOf() == LOGICAL && (value1 >= value2)))
            //     {
            //         result.push(stack.pop());
            //         if (stack.empty())
            //             break;
            //         if (stack.top()->TypeOf() == LEFTPAREN)
            //             break;
            //     }
            //     stack.push(walker);
            // }
            while (!stack.empty() && stack.top()->TypeOf() != LEFTPAREN && compare(walker, stack.top()))
            {
                result.push(stack.pop());
            }
            stack.push(walker);
            break;
        case RELATIONAL:
            // if ((!stack.empty()) && (stack.top()->TypeOf() == RELATIONAL))
            // {
            //     result.push(stack.pop());
            // }
            stack.push(walker);
            break;
        default:
            break;
        }
    }
    while (stack.begin() != nullptr)
    {
        result.push(stack.pop());
    }
    return result;
}
bool ShuntingYard::compare(Token *t1, Token *t2)
{
    if (t1->TypeOf() > t2->TypeOf())
    {
        return true;
    }
    else if (t1->TypeOf() == t2->TypeOf())
    {
        if (static_cast<Logical *>(t1)->precedence() > static_cast<Logical *>(t2)->precedence())
            return false;
    }
    return true;
}
