#ifndef FILE_RECORD_H
#define FILE_RECORD_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include "utilities.h"

using namespace std;

class FileRecord
{
public:
    // when you construct a FileRecord, it's either empty or it
    //   contains a word
    FileRecord()
    {
        // _record[0] = NULL;
        for (int i = 0; i < MAX; i++)
            _record[i][0] = '\0';

        recno = -1;
        used_rows = 0;
        //['\0'|  | G | a | r | b | a   |  g  |  e |    ]
    }
    long get_recno() const
    {
        return recno;
    }
    int get_rows() const
    {
        return used_rows;
    }
    vector<string> get_vector() const
    {
        vector<string> result;
        for (int i = 0; i < used_rows; i++)
        {
            result.push_back(_record[i]);
        }
        return result;
    }
    // FileRecord(char str[])
    // {
    //     // strncpy(_record, str, MAX);
    //     strncpy(_record2[0], str, MAX);
    // }
    FileRecord(vector<string> vec)
    {
        used_rows = vec.size();
        for (int i = 0; i < vec.size(); i++)
        {
            strncpy(_record[i], vec[i].c_str(), MAX);
        }
        _record[vec.size()][0] = '\0';
    }
    // FileRecord(string s)
    // {
    //     // strncpy(_record, s.c_str(), MAX);
    //     strncpy(_record2[0], s.c_str(), MAX);
    // }

    long write(fstream &outs);           // returns the record number
    long read(fstream &ins, long recno); // returns the number of bytes
                                         //       read = MAX, or zero if
                                         //       read passed the end of file

    friend ostream &operator<<(ostream &outs, const FileRecord &r);
    char _record[101][101]; // empty vector
private:
    static const int MAX = 100;
    long recno;
    int used_rows;
    // char _record[MAX + 1];           // NULL char
};

#endif