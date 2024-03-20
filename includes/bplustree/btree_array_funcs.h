#ifndef BTREE_FUNC_H
#define BTREE_FUNC_H
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <algorithm>
#include "array_fuctions.h"
using namespace std;

template <class T>
T maximal(const T &a, const T &b); // return the larger of the two items

template <class T>
void swap(T &a, T &b); // swap the two items

template <class T>
int index_of_maximal(T data[], int n); // return index of the largest item in data

template <class T>
void ordered_insert(T data[], int &n, T entry); // insert entry into the sorted array
                                                // data with length n

template <class T>
int first_ge(const T data[], int n, const T &entry); // return the first element in data that is
                                                     // not less than entry

template <class T>
void attach_item(T data[], int &n, const T &entry); // append entry to the right of data

template <class T>
void insert_item(T data[], int i, int &n, T entry); // insert entry at index i in data

template <class T>
void detach_item(T data[], int &n, T &entry); // remove the last element in data and place
                                              // it in entry

template <class T>
void delete_item(T data[], int i, int &n, T &entry); // delete item at index i and place it in entry

template <class T>
void merge(T data1[], int &n1, T data2[], int &n2); // append data2 to the right of data1

template <class T>
void split(T data1[], int &n1, T data2[], int &n2); // move n/2 elements from the right of data1
                                                    // and move to data2

template <class T>
void copy_array(T dest[], const T src[],
                int &dest_size, int src_size); // copy src[] into dest[]

template <class T>
void print_array(const T data[], int n, int pos = -1); // print array data

template <class T>
bool is_gt(const T data[], int n, const T &item); // item > all data[i]

template <class T>
bool is_le(const T data[], int n, const T &item); // item <= all data[i]

//-------------- Vector Extra operators: ---------------------

// template <typename T>
// ostream &operator<<(ostream &outs, const vector<T> &list); // print vector list

// template <typename T>
// vector<T> &operator+=(vector<T> &list, const T &addme); // list.push_back addme

// template <typename T>
// vector<T> vec_union(vector<T> &list1, vector<T> &list2); // two vectors union

// template <typename T>
// vector<T> vec_intersect(vector<T> &list1, vector<T> &list2); // two vectors intersect

//-------------------------------------------------------------------------------------------------------
// Function definitions
template <class T>
T maximal(const T &a, const T &b)
{
    if (a > b)
        return a;
    return b;
} // return the larger of the two items

template <class T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
} // swap the two items

template <class T>
int index_of_maximal(T data[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (data[i] > data[max])
            max = i;
    }
    return max;
} // return index of the largest item in data

template <class T>
void ordered_insert(T data[], int &n, T entry)
{
    bool inserted = false;
    for (int i = 0; i < n; i++)
    {
        if (data[i] > entry)
        {
            shift_right(data, n, i);
            data[i] = entry;
            inserted = true;
            break;
        }
    }
    if (!inserted)
        data[n++] = entry;
} // insert entry into the sorted array
  // data with length n

template <class T>
int first_ge(const T data[], int n, const T &entry)
{
    for (int i = 0; i < n; i++)
    {
        // cout << "data:" << data[i] << endl;
        // cout << "entry:" << entry << endl;
        // if (data[i] < entry)
        //     cout << "fuck this" << endl;
        if (!(data[i] < entry))
            return i;
    }
    return n;
} // return the first element in data that is
  // not less than entry

template <class T>
void attach_item(T data[], int &n, const T &entry)
{
    data[n] = entry;
    n++;
} // append entry to the right of data

template <class T>
void insert_item(T data[], int i, int &n, T entry)
{
    shift_right(data, n, i);
    data[i] = entry;
} // insert entry at index i in data

template <class T>
void detach_item(T data[], int &n, T &entry)
{
    entry = data[n - 1];
    n--;
} // remove the last element in data and place
  // it in entry

template <class T>
void delete_item(T data[], int i, int &n, T &entry)
{
    if (i < n)
    {
        entry = data[i];
        shift_left(data, n, i);
    }
    else
        entry = T();

} // delete item at index i and place it in entry

template <class T>
void merge(T data1[], int &n1, T data2[], int &n2)
{

    for (int i = 0; i < n2; i++)
    {
        data1[n1 + i] = data2[i];
    }
    n1 += n2;
    n2 = 0;
} // append data2 to the right of data1

template <class T>
void split(T data1[], int &n1, T data2[], int &n2)
{
    for (int i = n1 / 2, j = 0; i > 0; i--, j++)
    {
        data2[j] = data1[n1 - i];
    }
    n2 = n1 / 2;
    n1 -= n1 / 2;

} // move n/2 elements from the right of data1
  // and move to data2

template <class T>
void copy_array(T dest[], const T src[],
                int &dest_size, int src_size)
{
    for (int i = 0; i < src_size; i++)
    {
        dest[i] = src[i];
    }
    dest_size = src_size;
} // copy src[] into dest[]

template <class T>
void print_array(const T data[], int n, int pos)
{
    cout << "( " << n << " ) [ ";
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << "]" << endl;
} // print array data

template <class T>
bool is_gt(const T data[], int n, const T &item)
{
    for (int i = 0; i < n; i++)
    {
        if (item <= data[i])
            return false;
    }
    return true;

} // item > all data[i]

template <class T>
bool is_le(const T data[], int n, const T &item)
{
    for (int i = 0; i < n; i++)
    {
        if (item > data[i])
            return false;
    }
    return true;
} // item <= all data[i]

//-------------- Vector Extra operators: ---------------------

// template <typename T>
// ostream &operator<<(ostream &outs, const vector<T> &list)
// {
//     for (int i = 0; i < list.size(); i++)
//     {
//         outs << list[i] << " ";
//     }
//     outs << "\n";
//     return outs;
// } // print vector list

// template <typename T>
// vector<T> &operator+=(vector<T> &list, const T &addme)
// {
//     list.push_back(addme);
//     return list;
// } // list.push_back addme
// template <typename T>
// vector<T> &operator+=(vector<T> &list1, const vector<T> list2)
// {
//     for (int i = 0; i < list2.size(); i++)
//         list1.push_back(list2[i]);
//     return list1;
// } // list.push_back addme

// template <typename T>
// vector<T> vec_union(vector<T> &list1, vector<T> &list2)
// {
//     vector<T> result;
//     // for (int i = 0; i < list2.size(); i++)
//     // {
//     //     bool contain = false;
//     //     for (int j = 0; j < list1.size(); j++)
//     //     {
//     //         if (result[j] == list2[i])
//     //             contain = true;
//     //     }
//     //     if (!contain)
//     //         result.push_back(list2[i]);
//     // }
//     sort(list1.begin(), list1.end());
//     sort(list2.begin(), list2.end());
//     set_union(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(result));
//     return result;
// }

// template <typename T>
// vector<T> vec_intersect(vector<T> &list1, vector<T> &list2)
// {
//     vector<T> result;
//     // for (int i = 0; i < list1.size(); i++)
//     // {
//     //     bool contain = false;
//     //     for (int j = 0; j < list2.size(); j++)
//     //     {
//     //         if (list1[i] == list2[j])
//     //             contain = true;
//     //     }
//     //     if (contain)
//     //         result.push_back(list1[i]);
//     // }
//     sort(list1.begin(), list1.end());
//     sort(list2.begin(), list2.end());
//     set_intersection(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(result));
//     return result;
// }

#endif