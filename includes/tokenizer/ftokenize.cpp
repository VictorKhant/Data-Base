#include "ftokenize.h"
#include <string>
FTokenizer::FTokenizer(char *fname)
{
    char _buffer[MAX_BUFFER];
    // char *ptr;
    // ptr = _buffer;
    _f.open(fname);
    if (!_f.is_open())
    {
        cout << "input file opening failed.\n";
    }
    _more = true;
    get_new_block();
    // cout << "alen:" << std::char_traits<char>::length(_buffer);
    // for (int i = 0; i < strlen(_buffer); i++)
    // {
    //     cout << _buffer[i];
    // }
    //_stk.set_string(_buffer);
    _pos = 0;
    _blockPos = 0;
}

SToken FTokenizer::next_token()
{
    return SToken();
}

bool FTokenizer::more()
{
    return _more;
}

int FTokenizer::pos()
{
    return _pos;
}

int FTokenizer::block_pos()
{
    return _blockPos;
}
FTokenizer &operator>>(FTokenizer &f, SToken &t)
{
    t = SToken();
    if (f._stk.done())
    {
        if (!f.get_new_block())
        {
            f._more = false;
            return f;
        }
    }
    f._stk >> t;
    return f;
}
bool FTokenizer::get_new_block()
{
    if (_f.eof())
    {
        cout << "*** END OF FILE ***";
        _more = false;
        return false;
    }

    char _buffer[MAX_BUFFER];
    _f.read(_buffer, MAX_BUFFER - 1);
    cout << "----- New Block ---------------------[" << _f.gcount() << "] bytes" << endl;
    _buffer[_f.gcount()] = '\0';
    _stk.set_string(_buffer);
    _more = true;
    _pos = 0;
    _blockPos = 0;
    return true;
}