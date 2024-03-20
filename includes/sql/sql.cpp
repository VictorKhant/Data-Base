#include "sql.h"

SQL::SQL()
{
}
void SQL::run()
{
    SQL sql;
    string str = "";
    string temp = "";
    while (temp != "exit")
    {
        int ran = 0;
        cout << "command > ";
        do
        {
            cin >> temp;
            str += temp;
            ran = cin.get();
            if (ran == ' ')
                str += " ";
        } while (ran != '\n');
        if (str == "exit")
            break;
        cout << sql.command(str) << endl;
        str = "";
    }
}

Table SQL::command(string str)
{
    // cout << "god pls\n\n\n\n\n\n\n";
    mmap_ss ptree;

    bool is_valid = get_sql_command(ptree, str);
    if (is_valid)
    {
        vectorstr table_n = ptree["table_name"];
        vectorstr fields;
        if (ptree["command"][0] == "make")
            return create_table(table_n[0], ptree["col"]);
        else if (ptree["command"][0] == "select")
        {
            if (ptree.contains("condition"))
            {
                fields = ptree["fields"];
                return select(table_n[0], fields, ptree["condition"]);
            }
            else
            {
                fields = ptree["fields"];
                cout << "There is no condition\n";
                t = Table(table_n[0]);
                return t.select_all(fields);
            }
        }
        else if (ptree["command"][0] == "insert")
        {
            fields = ptree["values"];
            return insert(table_n[0], fields);
        }
        else
            is_valid = false;
    }
    if (!is_valid)
        cout << "invalid command" << endl;
    return Table();
}

vector_l SQL::select_recnos()
{
    return t.select_recnos();
}

Table SQL::insert(string table_name, vectorstr values)
{
        t = Table(table_name);
        t.insert_into(values);
        return t;
}

Table SQL::select(string table_name, vectorstr fields_names, vectorstr condition)
{
        t = Table(table_name);
        return t.select(fields_names, condition);
}

Table SQL::create_table(string table_name, vectorstr fields)
{
        cout << "create table" << endl;
        t = Table(table_name, fields);
        return t;
}

void SQL::drop_table(string table_name)
{
        remove(table_name.c_str());
        remove((table_name + "_field").c_str());
}
bool SQL::get_sql_command(mmap_ss &ptree, string command)
{
    char s[300];
    strcpy(s, command.c_str());
    Parser parser(s);
    ptree = parser.parse_tree();
    return !parser.fail();
}

void SQL::batch(string filename)
{
    Table t;
    ifstream f;
    f.open(filename);
    string str = "";
    if (!f.is_open())
    {
        cout << "input file opening failed.\n";
    }
    while (!f.eof())
    {
        getline(f, str);

        if (str != "")
        {
            if (str.find("make") == 0 || str.find("insert") == 0 || str.find("select") == 0)
            {
                cout << str << endl;
                t = command(str);
            }
            else
                cout << str << endl;
            if (str.find("select") == 0)
            {
                cout << t << endl;
                cout << "selected recnos:" << select_recnos() << endl;
            }
        }
    }
}