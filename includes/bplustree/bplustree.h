#ifndef BPLUS_H
#define BPLUS_H
#include <iostream>
#include <iomanip>
#include <assert.h>
#include "btree_array_funcs.h"
#include "../stl_utils/vector_utilities.h"
using namespace std;
template <class T>
class BPlusTree
{
public:
    class Iterator
    {
    public:
        friend class BPlusTree;
        Iterator(BPlusTree<T> *_it = NULL, int _key_ptr = 0) : it(_it), key_ptr(_key_ptr) {}

        T operator*()
        {
            return it->data[key_ptr];
        }

        Iterator operator++(int un_used)
        {
            Iterator hold(it, key_ptr);
            this->operator++();
            return hold;
        }
        Iterator operator++()
        {
            assert(it);
            if (key_ptr < it->data_count - 1)
                key_ptr++;
            else
            {
                key_ptr = 0;
                it = it->next;
            }
            return *this;
        }
        friend bool operator==(const Iterator &lhs, const Iterator &rhs)
        {
            return (lhs.it == rhs.it) && (lhs.key_ptr == rhs.key_ptr);
        }
        friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
        {
            return !(lhs == rhs);
        }
        void print_Iterator()
        {
            if (it)
            {
                cout << "iterator: ";
                print_array(it->data, it->data_count, key_ptr);
            }
            else
            {
                cout << "iterator: NULL, key_ptr: " << key_ptr << endl;
            }
        }
        bool is_null() { return !it; }
        void info()
        {
            cout << endl
                 << "Iterator info:" << endl;
            cout << "key_ptr: " << key_ptr << endl;
            cout << "it: " << *it << endl;
        }

    private:
        BPlusTree<T> *it;
        int key_ptr;
    };

    BPlusTree(bool dups = false)
    {
        dups_ok = dups;
        data_count = 0;
        child_count = 0;
        next = nullptr;
    }
    BPlusTree(T *a, int size, bool dups = false)
    {
        dups_ok = dups;
        data_count = 0;
        child_count = 0;
        next = nullptr;
        for (int i = 0; i < size; i++)
        {
            insert(a[i]);
        }
    }

    // big three:
    BPlusTree(const BPlusTree<T> &other)
    {
        data_count = 0;
        child_count = 0;
        dups_ok = other.dups_ok;
        next = nullptr;
        copy_tree(other);
    }

    ~BPlusTree()
    {
        clear_tree();
    }

    BPlusTree<T> &operator=(const BPlusTree<T> &RHS)
    {
        if (this == &RHS)
        {
            return *this;
        }
        clear_tree();
        copy_tree(RHS);
        return *this;
    }

    void copy_tree(const BPlusTree<T> &other); // copy other into this object
    void copy_tree(const BPlusTree<T> &other, BPlusTree<T> *&last_node);

    void insert(const T &entry); // insert entry into the tree
    void remove(const T &entry); // remove entry from the tree
    void clear_tree();           // clear this object (delete all nodes etc.)

    bool contains(const T &entry) const; // true if entry can be found
    T &get(const T &entry);              // return a reference to entry
    const T &get(const T &entry) const;  // return a reference to entry
    T &get_existing(const T &entry);     // return a reference to entry
    Iterator find(const T &key);         // return an iterator to this key.
                                         //      NULL if not there.
    Iterator lower_bound(const T &key);  // return first that goes NOT BEFORE
                                         //  key entry or next if does not
                                         //  exist: >= entry
    Iterator upper_bound(const T &key);  // return first that goes AFTER key
                                         // exist or not, the next entry  >entry

    int size() const; // count the number of elements

    bool empty() const { return (data_count == 0 && child_count == 0); } // true if the tree is empty

    void print_tree(int level = 0,
                    ostream &outs = cout) const;
    friend ostream &operator<<(ostream &outs,
                               const BPlusTree<T> &print_me)
    {
        print_me.print_tree(0, outs);
        return outs;
    }

    bool is_valid();
    string in_order();
    string pre_order();
    string post_order();

    Iterator begin();
    Iterator end();
    ostream &list_keys(Iterator from = NULL, Iterator to = NULL)
    {
        if (from == NULL)
            from = begin();
        if (to == NULL)
            to = end();
        for (Iterator it = from; it != to; it++)
            cout << *it << " ";
        return cout;
    }

private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    bool dups_ok;                   // true if duplicate keys are allowed
    int data_count;                 // number of data elements
    T data[MAXIMUM + 1];            // holds the keys
    int child_count;                // number of children
    BPlusTree *subset[MAXIMUM + 2]; // subtrees
    BPlusTree *next;
    bool is_leaf() const
    {
        return child_count == 0;
    } // true if this is a leaf node

    T *find_ptr(const T &entry); // return a pointer to this key.
                                 //  NULL if not there.

    // insert element functions
    void loose_insert(const T &entry); // allows MAXIMUM+1 data elements in
                                       //    the root
    void fix_excess(int i);            // fix excess in child i

    // remove element functions:
    void loose_remove(const T &entry); // allows MINIMUM-1 data elements
                                       //   in the root

    BPlusTree<T> *fix_shortage(int i); // fix shortage in child i
    // and return the smallest key in this subtree
    BPlusTree<T> *get_smallest_node();
    void get_smallest(T &entry);                 // entry := leftmost leaf
    void get_biggest(T &entry);                  // entry := rightmost leaf
    void remove_biggest(T &entry);               // remove the biggest child of tree->entry
    void transfer_left(int i);                   // transfer one element LEFT from child i
    void transfer_right(int i);                  // transfer one element RIGHT from child i
    BPlusTree<T> *merge_with_next_subset(int i); // merge subset i with  i+1
};

//--------------------------------------------------------------------------------------------
// Functions definitions
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
// Find related functions
template <typename T>
bool BPlusTree<T>::contains(const T &entry) const
{
    int i = first_ge(data, data_count, entry);
    if (i < data_count && !(entry < data[i]))
    {
        if (is_leaf())
            return true;
        else
            return subset[i + 1]->contains(entry);
    }

    if (is_leaf())
    {
        return false;
    }
    return subset[i]->contains(entry);
} // true if entry can be found
template <typename T>
T *BPlusTree<T>::find_ptr(const T &entry)
{
    int i = first_ge(data, data_count, entry);

    if (i < data_count && !(entry < data[i]))
    {
        if (is_leaf())
            return &data[i];
        else
            return subset[i + 1]->find_ptr(entry);
    }

    if (is_leaf())
    {
        return nullptr;
    }
    return subset[i]->find_ptr(entry);
} // return a pointer to this key.
  //  NULL if not there.
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::find(const T &key)
{
    int i = first_ge(data, data_count, key);

    if (i < data_count && !(key < data[i]))
    {
        if (is_leaf())
            return Iterator(this, i);
        else
            return subset[i + 1]->find(key);
    }

    if (is_leaf())
    {
        return Iterator();
    }
    return subset[i]->find(key);
} // return an iterator to this key.
//      NULL if not there.

//--------------------------------------------------------------------------------------------
// Copy related functions
template <typename T>
void BPlusTree<T>::copy_tree(const BPlusTree<T> &other)
{
    BPlusTree<T> *temp = nullptr;
    copy_tree(other, temp);
} // copy other into this object
template <typename T>
void BPlusTree<T>::copy_tree(const BPlusTree<T> &other, BPlusTree<T> *&last_node)
{
    dups_ok = other.dups_ok;
    copy_array(data, other.data, data_count, other.data_count);
    child_count = other.child_count;
    next = nullptr;
    for (int i = 0; i < other.child_count; i++)
    {
        subset[i] = new BPlusTree<T>(other.dups_ok);
        subset[i]->copy_tree(*other.subset[i], last_node);
    }
    if (other.is_leaf())
    {
        if (last_node)
            last_node->next = this;
        last_node = this;
    }
}

//--------------------------------------------------------------------------------------------
// Clear functions
template <typename T>
void BPlusTree<T>::clear_tree()
{
    for (int i = 0; i < child_count; i++)
    {
        subset[i]->clear_tree();
        delete subset[i];
    }
    data_count = 0;
    child_count = 0;
    next = nullptr;
} // clear this object (delete all nodes etc.)

//--------------------------------------------------------------------------------------------
// Insert related functions
template <typename T>
void BPlusTree<T>::insert(const T &entry)
{
    loose_insert(entry);
    if (data_count > MAXIMUM)
    {

        BPlusTree<T> *newt = new BPlusTree(dups_ok);
        copy_array(newt->data, data, newt->data_count, data_count);
        copy_array(newt->subset, subset, newt->child_count, child_count);
        data_count = 0;
        child_count = 1;
        subset[0] = newt;

        fix_excess(0);
    }
} // insert entry into the tree
template <typename T>
void BPlusTree<T>::loose_insert(const T &entry)
{
    int i = first_ge(data, data_count, entry);
    // cout << "i" << i << endl;
    if (is_leaf())
    {
        if (i < data_count && entry == data[i])
        {
            if (dups_ok)
            {
                data[i] = data[i] + entry;
            }
        }
        else
        {
            insert_item(data, i, data_count, entry);
        }
    }
    else
    {
        if (i < data_count && entry == data[i])
        {
            subset[i + 1]->loose_insert(entry);
            if (subset[i + 1]->data_count > MAXIMUM)
                fix_excess(i + 1);
        }
        else
        {
            subset[i]->loose_insert(entry);
            if (subset[i]->data_count > MAXIMUM)
                fix_excess(i);
        }
    }

} // allows MAXIMUM+1 data elements in
  //    the root
template <typename T>
void BPlusTree<T>::fix_excess(int i)
{
    T entry;
    assert(i < child_count);
    BPlusTree<T> *newt = new BPlusTree<T>(dups_ok);

    split(subset[i]->data, subset[i]->data_count, newt->data, newt->data_count);
    split(subset[i]->subset, subset[i]->child_count, newt->subset, newt->child_count);

    detach_item(subset[i]->data, subset[i]->data_count, entry);

    insert_item(data, i, data_count, entry);
    insert_item(subset, i + 1, child_count, newt);
    if (subset[i]->is_leaf())
    {
        insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, entry);
        subset[i + 1]->next = subset[i]->next;
        subset[i]->next = subset[i + 1];
    }
} // fix excess in child i

//--------------------------------------------------------------------------------------------
// Remove related functions
template <typename T>
void BPlusTree<T>::remove(const T &entry)
{
    loose_remove(entry);
    if (data_count < MINIMUM && child_count == 1)
    {

        BPlusTree<T> *ptr = subset[0];
        copy_array(data, ptr->data, data_count, ptr->data_count);
        copy_array(subset, ptr->subset, child_count, ptr->child_count);
        ptr->data_count = 0;
        ptr->child_count = 0;
        delete ptr;
    }
} // remove entry from the tree
template <typename T>
void BPlusTree<T>::loose_remove(const T &entry)
{
    T deleted;
    int i = first_ge(data, data_count, entry);
    // cout << "i:" << i << endl;
    if (is_leaf())
    {
        // cout << "god help" << endl;
        // cout << "data:" << data[i] << endl;
        if (i < data_count && entry == data[i])
        {

            delete_item(data, i, data_count, deleted);
        }
    }
    else
    {
        if (i < data_count && entry == data[i])
        {
            subset[i + 1]->loose_remove(entry);
            if (subset[i + 1]->data_count < MINIMUM)
            {
                BPlusTree<T> *newt = fix_shortage(i + 1);
                int n = first_ge(newt->data, newt->data_count, entry);
                if (n < newt->data_count && newt->data[n] == entry)
                {
                    newt->subset[n + 1]->get_smallest(newt->data[n]);
                }

                // int m = first_ge(data, data_count, entry);
                // int n = first_ge(subset[i]->data, subset[i]->data_count, entry);
                // int o = first_ge(subset[i + 1]->data, subset[i + 1]->data_count, entry);
                // cout << "dead here" << n
                //      << endl;
                // if (m + 1 < child_count && m < data_count && data[m] == entry)
                // {
                //     cout << "1" << endl;
                //     subset[m + 1]->get_smallest(data[m]);
                // }
                // else if (i < child_count && n < subset[i]->data_count && n + 1 < subset[i]->child_count && subset[i]->data[n] == entry)
                // {
                //     cout << "2" << endl;
                //     subset[i]->subset[n + 1]->get_smallest(subset[i]->data[n]);
                // }
                // else if (i + 1 < child_count && o < subset[i + 1]->data_count && o + 1 < subset[i + 1]->child_count && subset[i + 1]->data[o] == entry)
                // {
                //     cout << "3" << endl;
                //     subset[i + 1]->subset[o + 1]->get_smallest(subset[i + 1]->data[o]);
                // }
            }
            else if (i < data_count && data[i] == entry)
            {
                subset[i + 1]->get_smallest(data[i]);
            }
            // for (int j = 0; j < data_count; j++)
            // {
            //     if (data[j] == entry)
            //         subset[j + 1]->get_smallest(data[j]);
            // }
            // for (int k = 0; k < subset[i]->data_count; k++)
            // {
            //     if (subset[i]->data[k] == entry)
            //         subset[i]->subset[k + 1]->get_smallest(subset[i]->data[k]);
            // }
            // for (int k = 0; k < subset[i + 1]->data_count; k++)
            // {
            //     if (subset[i + 1]->data[k] == entry)
            //         subset[i + 1]->subset[k + 1]->get_smallest(subset[i + 1]->data[k]);
            // }
        }
        else
        {
            subset[i]->loose_remove(entry);

            if (subset[i]->data_count < MINIMUM)
            {
                fix_shortage(i);
            }
        }
    }
} // allows MINIMUM-1 data elements
//   in the root
template <typename T>
void BPlusTree<T>::remove_biggest(T &entry)
{
    if (!is_leaf())
    {
        subset[child_count - 1]->remove_biggest(entry);
        if (subset[child_count - 1]->data_count < MINIMUM)
        {
            fix_shortage(child_count - 1);
        }
    }
    else
    {
        detach_item(data, data_count, entry);
    }
} // remove the biggest child of tree->entry
template <typename T>
void BPlusTree<T>::transfer_left(int i)
{
    T detached = T();
    if (subset[i]->is_leaf())
    {
        delete_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, detached);
        attach_item(subset[i]->data, subset[i]->data_count, detached);
        data[i] = subset[i + 1]->data[0];
    }
    else
    {
        delete_item(data, i, data_count, detached);
        insert_item(subset[i]->data, 0, subset[i]->data_count, detached);
        delete_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, detached);
        insert_item(data, i, data_count, detached);
        BPlusTree<T> *newt = new BPlusTree<T>(dups_ok);
        delete_item(subset[i + 1]->subset, 0, subset[i + 1]->child_count, newt);
        attach_item(subset[i]->subset, subset[i]->child_count, newt);
    }
} // transfer one element LEFT from child i
template <typename T>
void BPlusTree<T>::transfer_right(int i)
{
    T detached = T();
    if (subset[i]->is_leaf())
    {
        detach_item(subset[i - 1]->data, subset[i - 1]->data_count, detached);
        insert_item(subset[i]->data, 0, subset[i]->data_count, detached);
        data[i - 1] = subset[i]->data[0];
    }
    else
    {
        delete_item(data, i - 1, data_count, detached);
        insert_item(subset[i]->data, 0, subset[i]->data_count, detached);

        detach_item(subset[i - 1]->data, subset[i - 1]->data_count, detached);
        insert_item(data, i - 1, data_count, detached);
        BPlusTree<T> *newt = new BPlusTree<T>(dups_ok);
        detach_item(subset[i - 1]->subset, subset[i - 1]->child_count, newt);
        insert_item(subset[i]->subset, 0, subset[i]->child_count, newt);
    }
} // transfer one element RIGHT from child i
template <typename T>
BPlusTree<T> *BPlusTree<T>::merge_with_next_subset(int i)
{
    T item;
    delete_item(data, i, data_count, item);
    if (!subset[i]->is_leaf())
        attach_item(subset[i]->data, subset[i]->data_count, item);

    merge(subset[i]->data, subset[i]->data_count, subset[i + 1]->data, subset[i + 1]->data_count);
    merge(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset, subset[i + 1]->child_count);
    BPlusTree<T> *temp = nullptr;
    delete_item(subset, i + 1, child_count, temp);
    if (subset[i]->is_leaf())
        subset[i]->next = temp->next;
    delete temp;
    // cout << "after_merging:" << endl;
    // print_tree();
    // cout << endl;
    return subset[i];
} // merge subset i with  i+1
template <typename T>
BPlusTree<T> *BPlusTree<T>::fix_shortage(int i)
{
    if (i > 0 && subset[i - 1]->data_count > MINIMUM)
    {
        transfer_right(i);
    }
    else if (i < child_count - 1 && subset[i + 1]->data_count > MINIMUM)
    {

        transfer_left(i);
    }
    else if (i > 0 && subset[i - 1]->data_count == MINIMUM)
    {
        return merge_with_next_subset(i - 1);
    }
    else if (i < child_count - 1 && subset[i + 1]->data_count == MINIMUM)
    {
        return merge_with_next_subset(i);
    }
    return subset[i];
} // fix shortage in child i
  // and return the smallest key in this subtree

//--------------------------------------------------------------------------------------------
// Get related functions
template <typename T>
BPlusTree<T> *BPlusTree<T>::get_smallest_node()
{
    if (!is_leaf())
        return subset[0]->get_smallest_node();
    return this;
}
template <typename T>
void BPlusTree<T>::get_smallest(T &entry)
{
    if (!is_leaf())
        subset[0]->get_smallest(entry);
    else
        entry = data[0];

} // entry := leftmost leaf
template <typename T>
void BPlusTree<T>::get_biggest(T &entry)
{
    if (!is_leaf())
        subset[child_count - 1]->get_biggest(entry);
    else
        entry = data[data_count - 1];
} // entry := rightmost leaf

template <typename T>
T &BPlusTree<T>::get(const T &entry)
{
    if (!contains(entry))
    {
        insert(entry);
    }

    return get_existing(entry);

} // return a reference to entry
template <typename T>
const T &BPlusTree<T>::get(const T &entry) const
{
    assert(contains(entry));

    const bool debug = false;
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);
    if (is_leaf())
    {
        if (found)
        {
            return &data[i];
        }
        else
        {
            if (debug)
                cout << "get_existing was called with nonexistent entry" << endl;
            assert(found);
        }
    }
    if (found) // inner node
        return subset[i + 1]->get(entry);
    // or just return true?
    else // not found yet...
        return subset[i]->get(entry);
} // return a reference to entry
template <typename T>
T &BPlusTree<T>::get_existing(const T &entry)
{
    assert(contains(entry));

    const bool debug = false;
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);
    if (is_leaf())
    {
        if (found)
        {
            return data[i];
        }
        else
        {
            if (debug)
                cout << "get_existing was called with nonexistent entry" << endl;
            assert(found);
        }
    }
    if (found) // inner node
        return subset[i + 1]->get_existing(entry);
    // or just return true?
    else // not found yet...
        return subset[i]->get_existing(entry);
} // return a reference to entry

//--------------------------------------------------------------------------------------------
// Bound functions
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::lower_bound(const T &key)
{

    int i = first_ge(data, data_count, key);
    if (is_leaf())
    {
        Iterator start(begin());

        while (start != end() && *start < key)
        {
            ++start;
        }
        return start;
    }
    else
    {
        if (i < data_count && key == data[i])
        {
            return subset[i + 1]->lower_bound(key);
        }
        else
        {
            return subset[i]->lower_bound(key);
        }
    }

} // return first that goes NOT BEFORE
//  key entry or next if does not
//  exist: >= entry
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::upper_bound(const T &key)
{
    int i = first_ge(data, data_count, key);
    if (is_leaf())
    {
        Iterator start(begin());

        while (start != end() && *start <= key)
            ++start;
        return start;
    }
    else
    {
        if (i < data_count && key == data[i])
        {
            return subset[i + 1]->upper_bound(key);
        }
        else
        {
            return subset[i]->upper_bound(key);
        }
    }

} // return first that goes AFTER key
  // exist or not, the next entry  >entry

//--------------------------------------------------------------------------------------------
// other functions
template <typename T>
int BPlusTree<T>::size() const
{
    int counter = data_count;
    for (int i = 0; i < child_count; i++)
        counter += subset[i]->size();
    return counter;
} // count the number of elements
template <typename T>
void BPlusTree<T>::print_tree(int level,
                              ostream &outs) const
{
    int times = 6;
    for (int i = data_count; i >= 0; i--)
    {
        if (i < data_count)
        {
            if (i == data_count - 1)
            {
                if (next)
                    outs << "| " << string(times * level, ' ') << "^" << endl;
                outs << "| " << string(times * level, ' ') << "⎴" << endl;
            }
            outs << "| " << string(times * level, ' ') << data[i] << endl;
            if (i == 0)
                outs << "| " << string(times * level, ' ') << "⎵" << endl;
        }
        if (!is_leaf())
        {
            subset[i]->print_tree(level + 1, outs);
        }
    }
}
template <typename T>
bool BPlusTree<T>::is_valid()
{
    return true;
}
template <typename T>
string BPlusTree<T>::in_order()
{
    string result = "";
    for (int i = 0; i <= data_count; i++)
    {
        if (!is_leaf())
            result += subset[i]->in_order();

        if (i < data_count)
            result += to_string(data[i]) + "|";
    }
    return result;
}
template <typename T>
string BPlusTree<T>::pre_order()
{
    string result = "";
    for (int i = 0; i <= data_count; i++)
    {
        if (i < data_count)
            result += to_string(data[i]) + "|";

        if (!is_leaf())
            result += subset[i]->pre_order();
    }
    return result;
}
template <typename T>
string BPlusTree<T>::post_order()
{
    string result = "";
    for (int i = 0; i <= data_count; i++)
    {
        if (!is_leaf())
            result += subset[i]->post_order();
        if (i - 1 >= 0)
            result += to_string(data[i - 1]) + "|";
    }
    return result;
}
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::begin()
{
    return Iterator(get_smallest_node());
}
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::end()
{
    return Iterator(NULL);
}
#endif