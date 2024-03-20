#ifndef PARSER_H
#define PARSER_H
#include "typedefs.h"
#include "../table/table.h"
#include "../tokenizer/stokenize.h"
#include "../tokenizer/state_machine_functions.h"
class Parser
{
public:
    Parser();
    Parser(char *s);
    void set_string(string s);
    int get_column(string str);
    bool get_parse_tree(int start_state = 0); // to get the table name e.g. student

    void build_keyword_list(); //
    void make_table();

    bool fail() { return _fail; }
    mmap_ss parse_tree() const { return _ptree; }

private:
    mmap_ss _ptree;
    map_sl _keywords;
    static int _table[MAX_ROWS][MAX_COLUMNS];
    vector<string> _inputq;
    int _pos;
    char _buffer[MAX_BUFFER]; // idk why he put in his code
    bool _fail;
    // only commands have enums
    enum keys
    {
        ZERO,
        COL,
        TABLENAME,
        MAKE,
        TABLE,
        INSERT,
        SELECT,
        STAR,
        FROM,
        INTO,
        WHERE,
        SYMBOL,
        FIELDS,
        VALUES,
        VALUESNAME,
        COLNAME,
        LPAREN,
        RPAREN,
        CONDITION,
        AND,
        OR,
        RELATION
    };
};
#endif