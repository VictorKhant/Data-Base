#include "parser.h"

int Parser::_table[MAX_ROWS][MAX_COLUMNS];
Parser::Parser(char *s)
{
    make_table();
    build_keyword_list();
    set_string(s);
}
Parser::Parser()
{
    make_table();
    build_keyword_list();
}
bool Parser::get_parse_tree(int start_state)
{
    int state = start_state;
    string token = "";
    int column;
    for (int i = 0; i < _inputq.size() && state != -1; i++)
    {
        token = _inputq[i];
        column = get_column(token);
        state = _table[state][column];
        switch (state)
        {
        case MAKE:
        case INSERT:
        case SELECT:
            _ptree["command"] += token;
            break;
        case FIELDS:
            _ptree["fields"] += token;
            break;
        case COL:
            // cout << "token2:" << token << endl;
            _ptree["col"] += token;
            break;
        // case 22:
        case TABLENAME:
            // cout << "token3:" << token << endl;
            _ptree["table_name"] += token;
            break;
        case WHERE:
            token = "yes";
            _ptree["where"] += token;
            break;
        case VALUES:
            _ptree["values"] += token;
            break;
        // case LPAREN:
        // case RPAREN:
        case CONDITION:
            // case AND:
            // case OR:
            // case RELATION:
            // case 23:
            _ptree["condition"] += token;
            break;
        default:
            // cout << "freaking default:" << token << endl;
            break;
        }
    }
    if (_table[state][0] == 1)
        return true;
    return false;
}
void Parser::make_table()
{

    init_table(_table);
    for (int i = 0; i < MAX_ROWS; i++)
        mark_fail(_table, i);

    // for make command
    mark_cell(0, _table, MAKE, MAKE);
    mark_cell(MAKE, _table, TABLE, TABLE);
    mark_cell(TABLE, _table, SYMBOL, TABLENAME);
    mark_cell(TABLENAME, _table, FIELDS, COLNAME);
    mark_cell(COLNAME, _table, SYMBOL, COL);
    mark_cell(COL, _table, SYMBOL, COL);
    mark_success(_table, COL);

    // for insert
    mark_cell(0, _table, INSERT, INSERT);
    mark_cell(INSERT, _table, INTO, INTO);
    mark_cell(INTO, _table, SYMBOL, TABLENAME);
    mark_cell(TABLENAME, _table, VALUES, VALUESNAME);
    mark_cell(VALUESNAME, _table, SYMBOL, VALUES);
    mark_cell(VALUES, _table, SYMBOL, VALUES);
    mark_success(_table, VALUES);

    // for select
    // mark_cell(0, _table, SELECT, SELECT);
    // mark_cell(SELECT, _table, STAR, FIELDS);
    // mark_cell(SELECT, _table, SYMBOL, FIELDS);
    // mark_cell(FIELDS, _table, SYMBOL, FIELDS);
    // mark_cell(FIELDS, _table, FROM, FROM);
    // mark_cell(FROM, _table, SYMBOL, 22);
    // mark_cell(22, _table, WHERE, WHERE);
    // mark_cell(WHERE, _table, SYMBOL, 23);
    // // mark_cell(WHERE, _table, SYMBOL, CONDITION);
    // mark_cell(WHERE, _table, LPAREN, LPAREN);
    // mark_cell(LPAREN, _table, LPAREN, LPAREN);
    // mark_cell(RPAREN, _table, RPAREN, RPAREN);
    // mark_cell(LPAREN, _table, SYMBOL, 23);
    // mark_cell(23, _table, RELATION, RELATION);
    // mark_cell(RELATION, _table, SYMBOL, CONDITION);
    // mark_cell(CONDITION, _table, RPAREN, RPAREN);
    // // mark_cell(CONDITION, _table, SYMBOL, CONDITION);
    // // mark_cell(RPAREN, _table, SYMBOL, CONDITION);
    // // mark_cell(CONDITION, _table, LPAREN, LPAREN);
    // mark_success(_table, RPAREN);
    // mark_success(_table, 22);
    // mark_success(_table, CONDITION);

    // mark_cell(CONDITION, _table, AND, AND);
    // mark_cell(AND, _table, LPAREN, LPAREN);
    // mark_cell(OR, _table, LPAREN, LPAREN);
    // mark_cell(AND, _table, SYMBOL, 23);
    // mark_cell(OR, _table, SYMBOL, 23);
    // mark_cell(CONDITION, _table, OR, OR);
    // mark_cell(RPAREN, _table, AND, AND);
    // mark_cell(RPAREN, _table, OR, OR);
    mark_cell(0, _table, SELECT, SELECT);
    mark_cell(SELECT, _table, STAR, FIELDS);
    mark_cell(SELECT, _table, SYMBOL, FIELDS);
    mark_cell(FIELDS, _table, SYMBOL, FIELDS);
    mark_cell(FIELDS, _table, FROM, FROM);
    mark_cell(FROM, _table, SYMBOL, TABLENAME);
    mark_cell(TABLENAME, _table, WHERE, WHERE);
    mark_cell(WHERE, _table, SYMBOL, CONDITION);
    mark_cell(CONDITION, _table, SYMBOL, CONDITION);

    mark_success(_table, CONDITION);
    mark_success(_table, TABLENAME);
}

void Parser::set_string(string s)
{
    strcpy(_buffer, s.c_str());
    STokenizer stk(_buffer);
    SToken t;

    if (!_ptree.empty())
        _ptree.clear();
    _inputq.clear();
    while (stk.more())
    {
        stk >> t;
        string type = t.type_string();
        if (type == "STRING")
        {
            string str = t.token_str();
            str.erase(str.begin());
            str.erase(str.end() - 1);
            _inputq.push_back(str);
        }
        else if (type != "UNKNOWN" && type != "SPACE")
            _inputq.push_back(t.token_str());
    }
    if (!get_parse_tree(0))
        _fail = true;
    else
        _fail = false;
}

void Parser::build_keyword_list()
{
    vector<string> temp = {"col", "table_name", "make", "table", "insert", "select", "*", "from", "into", "where", "symbol", "fields", "values", "values_name", "col_name"};
    //, "(", ")", "condition", "and", "or"
    for (int i = 0; i < temp.size(); i++)
    {
        _keywords.insert(temp[i], i + 1);
    }
}

int Parser::get_column(string str)
{
    if (_keywords.contains(str))
    {
        return _keywords[str];
    }
    // else if (str == "<" || str == "<=" || str == ">" || str == ">=" || str == "=")
    //     return RELATION;
    return SYMBOL;
}