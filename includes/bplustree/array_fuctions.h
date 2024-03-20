#ifndef guard
#define guard
#include <iostream>
#include <iomanip>
#include <string>

const int MINIMUM_CAPACITY = 3;
using namespace std;

template <class T>
T *allocate(int capacity = 5); // allocate 'capacity'
                               //       elements.
                               //   return array

template <class T>
T *reallocate(T *a, int &size, int capacity); // take array, resize it
                                              //   return new array.
                                              //   delete old array

// template <class T>
// void print_array(T *a, int size,
//                  int capacity = 0, ostream &outs = cout); // prints
//                                                           //   (size/capacity)
//                                                           //   for debugging

// template <class T>
// void print(T *a, unsigned int how_many,
//            ostream &outs = cout); // print array

template <class T>
T *search_entry(T *a, int size, const T &find_me); // search for 'find me'

template <class T>
int search(T *a, int size, const T &find_me); // search for 'find_me'

template <class T>
void shift_left(T *a, int &size, int shift_here); // shift left @ pos:
                                                  //     erases @ pos

template <class T>
void shift_left(T *a, int &size, T *shift_here); // shift left @ pos:
                                                 //     erases @ pos

template <class T>
void shift_right(T *a, int &size, int shift_here); // shift right:
                                                   //       make a hole

template <class T>
void shift_right(T *a, int &size, T *shift_here); // shift right:
                                                  //    make a hole

template <class T>
string array_string(const T *a, int size); // return array
                                           //   as a string

template <typename T>
void _append(T *a, int &size, T append_me);

//----------------------------------------------------------------------------

template <class T>
T *allocate(int capacity)
{
    const bool debug = false;
    if (debug)
        cout << "allocate: capacity: " << capacity << endl;
    return new T[capacity];
}

template <class T>
T *reallocate(T *a, int &size, int capacity)
{
    T *p, *walker, *walker2;
    p = new T[capacity];
    walker = p;
    walker2 = a;
    copy_array(walker, walker2, size);
    delete[] a;
    return p;
}

// template <class T>
// void print_array(T *a, int size, int capacity, ostream &outs)
// {
//     T *walker;
//     walker = a;
//     cout << "( " << setw(2) << size;
//     if (capacity != 0)
//     {
//         cout << "/" << setw(2) << capacity;
//     }
//     cout << " ) [";
//     print(a, size, outs);
//     cout << "]" << endl;
// }

// template <class T>
// void print(T *a, unsigned int how_many, ostream &outs)
// {
//     T *walker;
//     walker = a;
//     for (int i = 0; i < how_many; i++, walker++)
//     {
//         cout << setw(4) << *walker << " ";
//     }
// }

template <class T>
T *search_entry(T *a, int size, const T &find_me)
{
    T *walker;
    walker = a;
    for (int i = 0; i < size; i++, walker++)
    {
        if (*walker == find_me)
        {
            return walker;
        }
    }
    return nullptr;
}

template <class T>
int search(T *a, int size, const T &find_me)
{
    T *mark = search_entry(a, size, find_me);
    if ((mark != nullptr) && (*mark == find_me))
    {
        return mark - a;
    }
    return -1;
}

template <class T>
void shift_left(T *a, int &size, int shift_here)
{
    T *p;
    p = a + shift_here;
    T *from_here = p + 1;
    for (int i = shift_here; i < size - 1; i++, p++, from_here++)
    {
        *p = *from_here;
    }
    size--;
}

template <class T>
void shift_left(T *a, int &size, T *shift_here)
{
    int i = shift_here - a;
    shift_left(a, size, i);
}

template <class T>
void shift_right(T *a, int &size, int shift_here)
{
    T *to_here = a + size;
    T *from_here = to_here - 1;
    for (int i = size; i > shift_here; i--, to_here--, from_here--)
    {
        *to_here = *from_here;
    }
    size++;
}

template <class T>
void shift_right(T *a, int &size, T *shift_here)
{
    int i = shift_here - a + 1;
    shift_right(a, size, i);
}

template <class T>
string array_string(const T *a, int size)
{
    string str = {"["};
    const T *walker;
    walker = a;
    for (int i = 0; i < size; i++, a++)
    {
        str += to_string(*walker);
        str += " ";
        walker++;
    }
    str += "] [";
    str += to_string(size);
    str += "]";
    return str;
    ;
}

template <typename T>
void _append(T *a, int &size, T append_me)
{
    T *walker = a + size;
    *walker = append_me;
    size++;
}

#endif