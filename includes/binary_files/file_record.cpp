#include "file_record.h"

long FileRecord::write(fstream &outs)
{
    // r.write(f); //take the Record r and write it into file f
    //   and return the record number of this Record

    // write to the end of the file.
    outs.seekg(0, outs.end);
    long pos = outs.tellp(); // retrieves the current position of the
                             //       file pointer
    outs.write(&_record[0][0], sizeof(_record));
    recno = pos / sizeof(_record);
    return recno;
}

long FileRecord::read(fstream &ins, long recno)
{
    // returns the number of bytes read.
    //     r.read(f, 6);
    //     cout<<r<<endl;
    long pos = recno * sizeof(_record);
    ins.seekg(pos, ios_base::beg);

    ins.read(&_record[0][0], sizeof(_record));

    // ins.read(_record, sizeof(_record));
    // don't you want to mark the end of  the cstring with null?
    //_record[] => [zero'\0'trash trash trash trash]
    // don't need the null character, but for those of us with OCD and PTSD:
    for (int i = 0; i < MAX && _record[i][0] != '\0'; i++)
    {
        used_rows = i + 1;
    }
    return ins.gcount();
}

ostream &operator<<(ostream &outs,
                    const FileRecord &r)
{
    for (int i = 0; i < r.used_rows; i++)
    {
        outs << right << setw(25) << r._record[i];
    }
    return outs;
}
