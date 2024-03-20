#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <string.h>
#include <iomanip>
#include <set>
#include <vector>
#include <cmath>
#include "typedefs.h"
#include "../binary_files/file_record.h"
#include "../queue/MyQueue.h"
#include "../bplustree/multimap.h"
#include "../bplustree/map.h"
#include "../token/token.h"
#include "../token/token_child.h"

#include "../shunting_yard/shunting_yard.h"
using namespace std;
class Table
{
public:
    Table make_table();
    Table();
    Table(const string &str, const vectorstr fields);
    Table(const string &str);
    ~Table();
    void insert_into(vectorstr values);
    void set_field(vectorstr field_names);
    Table select(vectorstr fields_names, const string field, const string oper, const string item);
    Table select(vectorstr fields_names, const Queue<Token *> &queue);
    Table select(vectorstr fields_names, vectorstr condition);
    Table select_all(vectorstr fields_names);

    friend ostream &operator<<(ostream &outs, const Table &t);

    void reindex(vectorstr vec, long rno);
    vector<long> select_recnos();
    vector<long> get_recnos(const string &oper, const string &field, const string &item);
    vector<long> rpn();
    bool is_empty() const { return _empty; }

private:
    Table select_records(vectorstr fields_names, vector<long> records); // gather records at record number and return as a new table
    long _recno;
    string _name;
    vectorstr _field_vector;
    bool _empty;
    Map<string, long> _map;
    vector<MMap<string, long>> _indices;
    vector<long> _rec_vec;
    Queue<Token *> _input;
    static long serial;
};

#endif