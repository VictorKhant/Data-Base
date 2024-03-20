#ifndef MULTIMAP_H
#define MULTIMAP_H
#include <iostream>
#include "bplustree.h"
using namespace std;

template <typename K, typename V>
struct MPair
{
    K key;
    vector<V> value_list;

    //--------------------------------------------------------------------------------
    /*      MPair CTORs:
     *  must have these CTORs:
     *  - default CTOR / CTOR with a key and no value: this will create an empty vector
     *  - CTOR with a key AND a value: pushes the value into the value_list
     *  _ CTOR with a key and a vector of values (to replace value_list)
     */
    //--------------------------------------------------------------------------------
    MPair(const K &k = K())
    {
        key = k;
    }
    MPair(const K &k, const V &v)
    {
        key = k;
        value_list.push_back(v);
    }
    MPair(const K &k, const vector<V> &vlist)
    {
        key = k;
        if (value_list.size() != 0)
            value_list.clear();
        for (int i = 0; i < vlist.size(); i++)
            value_list.push_back(vlist[i]);
    }
    //--------------------------------------------------------------------------------

    // You'll need to overlod << for your vector:
    friend ostream &operator<<(ostream &outs, const MPair<K, V> &print_me)
    {
        outs << right << setw(10) << print_me.key << " :    ";
        for (int i = 0; i < print_me.value_list.size(); i++)
        {
            outs << print_me.value_list[i] << " ";
        }
        return outs;
    }

    friend bool operator==(const MPair<K, V> &lhs, const MPair<K, V> &rhs)
    {
        return lhs.key == rhs.key;
    }
    friend bool operator<(const MPair<K, V> &lhs, const MPair<K, V> &rhs)
    {
        return lhs.key < rhs.key;
    }
    friend bool operator<=(const MPair<K, V> &lhs, const MPair<K, V> &rhs)
    {
        return lhs.key <= rhs.key;
    }
    friend bool operator>(const MPair<K, V> &lhs, const MPair<K, V> &rhs)
    {
        return lhs.key > rhs.key;
    }
    friend MPair<K, V> operator+(const MPair<K, V> &lhs, const MPair<K, V> &rhs)
    {
        MPair<K, V> newm(lhs.key, lhs.value_list);
        for (int i = 0; i < rhs.value_list.size(); i++)
        {
            newm.value_list.push_back(rhs.value_list[i]);
        }
        return newm;
    }
};

template <typename K, typename V>
class MMap
{
public:
    typedef BPlusTree<MPair<K, V>> map_base;
    class Iterator
    {
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it = typename map_base::Iterator()) { _it = it; }
        Iterator operator++(int unused)
        {
            Iterator hold = _it;
            ++_it;
            return hold;
        }
        Iterator operator++()
        {
            ++_it;
            return *this;
        }
        MPair<K, V> operator*()
        {
            return *_it;
        }
        friend bool operator==(const Iterator &lhs, const Iterator &rhs)
        {
            return lhs._it == rhs._it;
        }
        friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
        {
            return !(lhs == rhs);
        }

    private:
        typename map_base::Iterator _it;
    };

    MMap() { mmap = BPlusTree<MPair<K, V>>(true); }

    //  Iterators
    Iterator begin()
    {
        return Iterator(mmap.begin());
    }
    Iterator end()
    {
        return Iterator(mmap.end());
    }

    //  Capacity
    int size() const
    {
        return mmap.size();
    }
    bool empty() const
    {
        return mmap.empty();
    }

    //  Element Access
    const vector<V> &operator[](const K &key) const
    {
        return mmap.get(key).value_list;
    }
    vector<V> &operator[](const K &key)
    {
        return at(key);
    }

    vector<V> &at(const K &key)
    {
        return mmap.get(key).value_list;
    }
    const vector<V> &at(const K &key) const
    {
        return mmap.get(key).value_list;
    }
    //  Modifiers
    void insert(const K &k, const V &v)
    {
        mmap.insert(MPair<K, V>(k, v));
    }
    void erase(const K &key)
    {
        mmap.remove(key);
    }
    void clear()
    {
        mmap.clear_tree();
    }

    //  Operations:
    bool contains(const K &key) const
    {
        return mmap.contains(key);
    }
    vector<V> &get(const K &key)
    {
        return mmap.get(key).value_list;
    }

    Iterator find(const K &key)
    {
        return Iterator(mmap.find(key));
    }
    int count(const K &key)
    {
        return mmap.size();
    }
    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:
    Iterator lower_bound(const K &key)
    {
        return mmap.lower_bound(key);
    }

    Iterator upper_bound(const K &key)
    {
        return mmap.upper_bound(key);
    }

    bool is_valid()
    {
        return mmap.is_valid();
    }

    friend ostream &operator<<(ostream &outs, const MMap<K, V> &print_me)
    {
        outs << print_me.mmap << endl;
        return outs;
    }
    void print_lookup()
    {
        for (Iterator it = begin(); it != end(); it++)
            cout << *it << endl;
    }

private:
    BPlusTree<MPair<K, V>> mmap;
};
#endif