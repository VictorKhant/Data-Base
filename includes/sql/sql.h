#ifndef SQL_H
#define SQL_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <algorithm>
#include "../parser/parser.h"
using namespace std;

class SQL
{
public:
    SQL();
    void run();
    Table command(string str);
    vector_l select_recnos();
    void drop_table(string table_name);
    void batch(string filename);

private:
    Table insert(string table_name, vectorstr values);
    Table select(string table_name, vectorstr fields_names, vectorstr condition);
    Table create_table(string table_name, vectorstr fields);

    bool get_sql_command(mmap_ss &ptree, string command);

    Map<string, Table> _table;
    vector<long> recnos;
    Table t;
    // mmap_ss _ptree;
};
#endif