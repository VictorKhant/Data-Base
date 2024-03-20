#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iostream>
#include <iomanip>
#include "assert.h"
#include "constants.h"
#include <cstring>
using namespace std;
class SToken
{
public:
    SToken();
    SToken(string str, int type);
    friend ostream &operator<<(ostream &outs, const SToken &t);
    int type() const;
    string type_string() const;
    string token_str() const;

private:
    string _token;
    int _type;
};
#endif