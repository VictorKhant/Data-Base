#include "token.h"
using namespace std;

SToken::SToken()
{
    _token = "";
    _type = 0;
}
SToken::SToken(string str, int type)
{
    _token = str;
    _type = type;
}
ostream &operator<<(ostream &outs, const SToken &t)
{
    outs << "|" << t._token << "|";
    return outs;
}
int SToken::type() const
{
    return _type;
}
string SToken::type_string() const
{
    switch (_type)
    {
    case 7:
        return "NUMBER";
        break;
    case TOKEN_ALPHA:
        return "ALPHA";
        break;
    case TOKEN_SPACE:
        return "SPACE";
        break;
    case TOKEN_OPERATOR:
        return "OPERATOR";
        break;
    case TOKEN_PUNC:
        return "PUNC";
        break;
    case TOKEN_UNKNOWN:
        return "UNKNOWN";
        break;
    case TOKEN_END:
        return "END";
        break;
    case 6:
        return "DOUBLE";
        break;
    case TOKEN_QUOTE:
        return "STRING";
        break;
    default:
        break;
    }
    return "UNKNOWN";
}
string SToken::token_str() const
{
    return _token;
}