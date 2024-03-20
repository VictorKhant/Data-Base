#include "table.h"
long Table::serial = 0;
Table::Table()
{
    // serial = 0;
    _name = "";
    _empty = true;
    _recno = -1;
}
Table::Table(const string &str, const vectorstr fields)
{
    serial++;
    _name = str;
    set_field(fields);

    _empty = true;
    _recno = -1;
    fstream f;
    open_fileW(f, str.c_str());
    f.close();
    open_fileW(f, (_name + "_field").c_str());
    FileRecord r;

    r = FileRecord(_field_vector);
    r.write(f);
    f.close();
}
Table::Table(const string &str)
{
    // serial = 0;

    _name = str;
    fstream f;
    open_fileRW(f, (_name + "_field").c_str());
    FileRecord r;
    r.read(f, 0);
    set_field(r.get_vector());
    f.close();
    open_fileRW(f, _name.c_str());
    int k = -1;

    long byte = r.read(f, k + 1);

    while (byte > 0)
    {

        reindex(r.get_vector(), k + 1);
        k++;
        byte = r.read(f, k + 1);
    }
    _recno = k;
    if (_recno >= 0)
        _empty = false;

    f.close();
}

Table::~Table()
{
    // cout << "destructor called" << endl;
    for (int i = 1; i <= serial; ++i)
    {
        string str = _name + "_" + to_string(i);
        std::remove(str.c_str());
        std::remove((str + "_field").c_str());
    }
}
void Table::insert_into(vectorstr values)
{
    // cout << "here" << endl;
    _empty = false;
    fstream f;
    open_fileRW(f, _name.c_str());

    FileRecord r;
    r = FileRecord(values);

    _recno = r.write(f);
    reindex(values, _recno);
    f.close();
}
ostream &operator<<(ostream &outs, const Table &t)
{
    if (t._name != "")
    {
        fstream f;
        FileRecord r;
        outs << "Table name: " << t._name << ", records:" << t._recno + 1 << endl;
        open_fileRW(f, (t._name + "_field").c_str());
        r.read(f, 0);
        outs << right << setw(25) << "record" << r << endl
             << endl;
        f.close();
        open_fileRW(f, t._name.c_str());
        int i = 0;
        long bytes = r.read(f, i);
        while (bytes > 0)
        {
            outs << right << setw(25) << i << r << endl;
            i++;
            bytes = r.read(f, i);
        }
        f.close();
    }
    return outs;
}
void Table::set_field(vectorstr field_names)
{
    for (int i = 0; i < field_names.size(); i++)
    {
        _field_vector.push_back(field_names[i]);
        _map.insert(field_names[i], i);
        _indices.push_back(MMap<string, long>());
    }
}
void Table::reindex(vectorstr vec, long rno)
{
    for (int i = 0; i < vec.size(); i++)
    {
        // cout << _indices[i];
        _indices[i].insert(vec[i], rno);
    }
}

Table Table::select(vectorstr fields_names, const string field, const string oper, const string item)
{
    _rec_vec = get_recnos(oper, field, item);
    return select_records(fields_names, _rec_vec);
}

Table Table::select(vectorstr fields_names, vectorstr condition)
{
    ShuntingYard sy(condition);
    _input = sy.postfix();
    // cout << "postfix" << _input << endl;
    return select(fields_names, _input);
}

Table Table::select(vectorstr fields_names, const Queue<Token *> &queue)
{
    _input = queue;
    return select_records(fields_names, rpn());
}
vector<long> Table::select_recnos()
{
    return _rec_vec;
}

Table Table::select_all(vectorstr fields_names)
{
    vector<long> temp;
    for (int i = 0; i <= _recno; i++)
    {
        temp.push_back(i);
    }
    return select_records(fields_names, temp);
}

vector<long> Table::get_recnos(const string &oper, const string &field, const string &item)
{
    int index = _map[field];
    MMap<string, long>::Iterator it;
    vector<long> result;
    if (oper == "=")
        result = _indices[index][item];
    else if (oper == ">")
    {
        for (it = _indices[index].upper_bound(item); it != _indices[index].end(); ++it)
            result += (*it).value_list;
    }
    else if (oper == ">=")
    {
        for (it = _indices[index].lower_bound(item); it != _indices[index].end(); ++it)
            result += (*it).value_list;
    }
    else if (oper == "<")
    {
        for (it = _indices[index].begin(); it != _indices[index].lower_bound(item); ++it)
            result += (*it).value_list;
    }
    else if (oper == "<=")
    {
        // cout << _indices << endl;
        // cout << *_indices[index].upper_bound(item) << endl;
        for (it = _indices[index].begin(); it != _indices[index].upper_bound(item); ++it)
            result += (*it).value_list;
    }
    else
    {
        cout << "how did you get there??" << endl;
    }
    // cout << "result in get recno:" << result << endl;
    return result;
}

Table Table::select_records(vectorstr fields_names, vector<long> records)
{
    vectorstr fields;
    if (fields_names[0] == "*")
        fields = _field_vector;
    else
        fields = fields_names;
    // serial++;
    Table t(_name + "_" + to_string(serial), fields);

    // cout << _map << endl;
    // for (int i = 0; i < fields.size(); i++)
    //     if (!_map.contains(fields[i]))
    //     {
    //         cout << fields[i] << " is an invalid field name" << endl;
    //         return Table();
    //     }

    fstream f;
    _rec_vec = records;
    t._rec_vec = records;
    open_fileRW(f, _name.c_str());
    FileRecord r;
    for (int i = 0; i < _rec_vec.size(); i++)
    {
        r.read(f, _rec_vec[i]);
        vectorstr temp = r.get_vector();
        vectorstr result;
        for (int j = 0; j < fields.size(); j++)
        {
            result.push_back(temp[_map[fields[j]]]);
        }
        t.insert_into(result);
    }
    f.close();
    return t;
}

vector<long> Table::rpn()
{
    Stack<Token *> stack;
    Stack<vector<long>> st;
    Token *walker;
    string value1;
    string value2;
    string relation;
    vector<long> temp;
    vector<long> temp1;

    while (_input.begin() != nullptr)
    {
        walker = _input.pop();
        switch (walker->TypeOf())
        {
        case TOKENSTR:
            stack.push(walker);
            break;
        case RELATIONAL:
            value1 = static_cast<TokenStr *>(stack.pop())->TokenStrOnly();
            value2 = static_cast<TokenStr *>(stack.pop())->TokenStrOnly();
            relation = static_cast<Relational *>(walker)->RelationalOnly();
            st.push(get_recnos(relation, value2, value1));
            break;
        case LOGICAL:
            value1 = static_cast<Logical *>(walker)->LogicalOnly();
            temp = st.pop();
            temp1 = st.pop();
            if (value1 == "and")
            {
                // cout << "and logical\n";
                temp = vec_intersect(temp, temp1);
                // cout << "after intersect:" << temp << endl;
            }
            else
            {
                // cout << "or logical\n";
                temp = vec_union(temp, temp1);
                // cout << "after union:" << temp << endl;
            }
            st.push(temp);
            break;
        default:
            break;
        }
    }
    return st.pop();
}