#include "stokenize.h"
using namespace std;

int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

STokenizer::STokenizer()
{
    make_table(_table);
    _pos = 0;
}

STokenizer::STokenizer(char str[]) // make table, set pos to zero and copy str into buffer
{
    make_table(_table);
    _pos = 0;
    // cout << "len" << strlen(_buffer);
    strcpy(_buffer, str);
    // set_string(str);
    //  cout << "after:" << strlen(_buffer);
}

bool STokenizer::done()
{
    return (_pos > strlen(_buffer));
    // return (_buffer[_pos] == '\0');
}

bool STokenizer::more()
{
    return !done();
}

STokenizer &operator>>(STokenizer &s, SToken &t)
{
    string str = ""; // empty the string
    int type = -1;
    // if ((!s.get_token(type, str)) && (s.more())) // if no token, pass the string at _pos and increment _pos
    // {
    //     if (s._pos < strlen(s._buffer))
    //         str = s._buffer[s._pos];
    //     //  type = -1;
    //     s._pos++;
    //     // cout << "pos:" << s._pos;
    // }
    s.get_token(type, str);
    t = SToken(str, type); // Changed t into new token
    return s;
}

void STokenizer::set_string(char str[])
{
    // cout << "len of str:" << strlen(str);
    // for (int i = 0; i < strlen(str); i++)
    // {
    //     _buffer[i] = str[i];
    // }
    for (int i = 0; i < strlen(_buffer); i++)
    {
        _buffer[i] = '\0';
    }
    strcpy(_buffer, str);

    _pos = 0;
}

void STokenizer::make_table(int _table[][MAX_COLUMNS])
{
    init_table(_table);   // initialize table with -1
    mark_fail(_table, 0); // set state 0 to unsuccess state
    mark_fail(_table, 1); // set state 1 to unsuccess state
    for (int i = 2; i < MAX_ROWS; i++)
    {
        mark_success(_table, i); // set other state to success state
    }

    // changing states according to the type of token
    mark_cells(0, _table, ALFA, 2);
    mark_cells(0, _table, PUNC, 5);
    mark_cells(0, _table, OPERATORS, 4);
    mark_cells(0, _table, SPACES, 3);
    mark_cells(0, _table, DIGITS, 7);
    mark_cells(1, _table, DIGITS, 6);
    mark_cells(2, _table, ALFA, 2);
    mark_cells(3, _table, SPACES, 3);
    mark_cells(4, _table, OPERATORS, 4);
    // mark_cells(5, _table, PUNC, 5);
    mark_cells(5, _table, DIGITS, 6);
    mark_cells(6, _table, DIGITS, 6);
    mark_cells(6, _table, '.', '.', 1);
    mark_cells(7, _table, DIGITS, 7);
    mark_cells(7, _table, '.', '.', 1);
    mark_cells(0, _table, QUOTE, 8);
    mark_cells(8, _table, ALFA, 8);
    mark_cells(8, _table, SPACES, 8);
    mark_cells(8, _table, PUNC, 8);
    mark_cells(8, _table, '\"', '\"', 9);
    mark_success(_table, 9);
}

bool STokenizer::get_token(int &end_state, string &token)
{
    int step = 0, i = 0, last_success = 0;
    token = "";
    if (int(_buffer[_pos]) > MAX_COLUMNS || int(_buffer[_pos]) < 1)
    {
        end_state = -1;
        token += _buffer[_pos];
        _pos++;
        return false;
    }
    // Looping until it fails
    while ((step != -1) && (i + _pos < strlen(_buffer)))
    {
        int col = int(_buffer[i + _pos]);
        // changing steps after every charactors

        step = _table[step][col];
        // reset the last_success and end_state if the state is success

        if (is_success(_table, step) && step != -1)
        {
            last_success = -1;
            end_state = step;
        }
        last_success++;
        i++;
    }

    // return false if there is no success case
    if (i - last_success == 0)
    {
        _pos++;
        return false;
    }

    // passing new token into token string
    for (int j = 0; j < i - last_success; j++)
    {
        token += _buffer[j + _pos];
    }

    // changing _pos for next token
    _pos += i - last_success;
    return true;
}