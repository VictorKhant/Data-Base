#ifndef MAP_H
#define MAP_H
#include <iostream>

#include "bplustree.h"
using namespace std;

template <typename K, typename V>
struct Pair
{
    K key;
    V value;

    Pair(const K &k = K(), const V &v = V())
    {
        key = k;
        value = v;
    }
    friend ostream &operator<<(ostream &outs, const Pair<K, V> &print_me)
    {
        outs << print_me.key << ":" << print_me.value;
        return outs;
    }
    friend bool operator==(const Pair<K, V> &lhs, const Pair<K, V> &rhs)
    {
        return lhs.key == rhs.key;
    }
    friend bool operator<(const Pair<K, V> &lhs, const Pair<K, V> &rhs)
    {
        return lhs.key < rhs.key;
    }
    friend bool operator>(const Pair<K, V> &lhs, const Pair<K, V> &rhs)
    {
        return lhs.key > rhs.key;
    }
    friend bool operator<=(const Pair<K, V> &lhs, const Pair<K, V> &rhs)
    {
        return !(lhs > rhs);
    }
    friend Pair<K, V> operator+(const Pair<K, V> &lhs, const Pair<K, V> &rhs)
    {
        return rhs;
    }
};

template <typename K, typename V>
class Map
{
public:
    typedef BPlusTree<Pair<K, V>> map_base;
    class Iterator
    {
    public:
        friend class Map;
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
        Pair<K, V> operator*()
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

    Map()
    {
        map = BPlusTree<Pair<K, V>>(true);
        key_count = 0;
    }
    //  Iterators
    Iterator begin()
    {
        return Iterator(map.begin());
    }
    Iterator end()
    {
        return Iterator(map.end());
    }

    //  Capacity
    int size() const
    {
        return map.size();
    }
    bool empty() const
    {
        return map.empty();
    }

    //  Element Access

    V &at(const K &key)
    {
        return map.get(key).value;
    }
    const V &at(const K &key) const
    {
        return map.get(key).value;
    }
    V &operator[](const K &key)
    {
        return at(key);
    }

    //  Modifiers
    void insert(const K &k, const V &v)
    {
        map.insert(Pair<K, V>(k, v));
    }
    void erase(const K &key)
    {
        map.remove(key);
    }
    void clear()
    {
        map.clear_tree();
    }
    V get(const K &key)
    {
        return map.get(key).value;
    }

    //  Operations:
    Iterator find(const K &key)
    {
        return Iterator(map.find(key));
    }
    bool contains(const Pair<K, V> &target) const
    {
        return map.contains(target);
    }

    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:
    int count(const K &key)
    {
        return map.size();
    }
    Iterator lower_bound(const K &key)
    {
        return map.lower_bound(key);
    }

    Iterator upper_bound(const K &key)
    {
        return map.upper_bound(key);
    }
    bool is_valid() { return map.is_valid(); }

    friend ostream &operator<<(ostream &outs, const Map<K, V> &print_me)
    {
        outs << print_me.map << endl;
        return outs;
    }

private:
    int key_count;
    BPlusTree<Pair<K, V>> map;
};

#endif