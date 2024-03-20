#ifndef VECTOR_UTILITIES_H
#define VECTOR_UTILITIES_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
ostream &operator<<(ostream &outs, const vector<T> &list); // print vector list

template <typename T>
vector<T> &operator+=(vector<T> &list, const T &addme); // list.push_back addme

template <typename T>
vector<T> vec_union(vector<T> &list1, vector<T> &list2); // two vectors union

template <typename T>
vector<T> vec_intersect(vector<T> &list1, vector<T> &list2); // two vectors intersect

template <typename T>
ostream &operator<<(ostream &outs, const vector<T> &list)
{
    for (int i = 0; i < list.size(); i++)
    {
        outs << list[i] << " ";
    }
    outs << "\n";
    return outs;
} // print vector list

template <typename T>
vector<T> &operator+=(vector<T> &list, const T &addme)
{
    list.push_back(addme);
    return list;
} // list.push_back addme
template <typename T>
vector<T> &operator+=(vector<T> &list1, const vector<T> list2)
{
    for (int i = 0; i < list2.size(); i++)
        list1.push_back(list2[i]);
    return list1;
} // list.push_back addme

template <typename T>
vector<T> vec_union(vector<T> &list1, vector<T> &list2)
{
    vector<T> result;
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    set_union(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(result));
    return result;
}

template <typename T>
vector<T> vec_intersect(vector<T> &list1, vector<T> &list2)
{
    vector<T> result;
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    set_intersection(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(result));
    return result;
}
#endif