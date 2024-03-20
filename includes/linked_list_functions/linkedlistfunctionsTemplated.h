#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <iomanip>
#include "../node/node.h"
#include "assert.h"
using namespace std;
// Linked List General Functions:
template <typename T>
void _print_list(node<T> *head);

// recursive fun! :)
template <typename T>
void _print_list_backwards(node<T> *head);

// return ptr to key or NULL
template <typename T>
node<T> *_search_list(node<T> *head,
                      T key);

template <typename T>
node<T> *_insert_head(node<T> *&head,
                      T insert_this);

// insert after ptr: insert head if marker null
template <typename T>
node<T> *_insert_after(node<T> *&head,
                       node<T> *after_this,
                       T insert_this);

// insert before ptr: insert head if marker null
template <typename T>
node<T> *_insert_before(node<T> *&head,
                        node<T> *before_this,
                        T insert_this);

// ptr to previous node
template <typename T>
node<T> *_previous_node(node<T> *prev_to_this);

// delete, return item
template <typename T>
T _delete_node(node<T> *&head, node<T> *delete_this);

// duplicate the list...
template <typename T>
node<T> *_copy_list(node<T> *head);

// duplicate the list, return pointer to last node in dest...
//      use this function in your queue big three
template <typename T>
node<T> *_copy_list(node<T> *&dest, node<T> *src);

// delete all the nodes
template <typename T>
void _clear_list(node<T> *&head);

//_item at this position
template <typename T>
T &_at(node<T> *head, int pos);

template <typename T>
void _print_list(node<T> *head)
{
    cout << "H->";
    node<T> *ptr = head;
    while (ptr != nullptr)
    {
        cout << *ptr;
        ptr = ptr->_next;
    }
    cout << "|||" << endl;
}

// recursive fun! :)
template <typename T>
void _print_list_backwards(node<T> *head)
{
    node<T> *ptr = head;

    if (ptr != nullptr)
    {
        _print_list_backwards(ptr->_next);
        cout << *ptr;
        if (ptr->_prev == nullptr)
        {
            cout << "H\n";
        }
    }
    if (ptr == nullptr)
    {
        cout << "|||->";
    }
}

// return ptr to key or NULL
template <typename T>
node<T> *_search_list(node<T> *head,
                      T key)
{
    node<T> *ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->_item == key)
        {
            return ptr;
        }
        ptr = ptr->_next;
    }
    return nullptr;
}

template <typename T>
node<T> *_insert_head(node<T> *&head,
                      T insert_this)
{
    node<T> *ptr = new node<T>(insert_this, head);
    if (head != nullptr)
    {
        head->_prev = ptr;
    }
    head = ptr;
    return head;
}

// insert after ptr: insert head if marker null
template <typename T>
node<T> *_insert_after(node<T> *&head,
                       node<T> *after_this,
                       T insert_this)
{
    if (head == nullptr)
    {
        return _insert_head(head, insert_this);
    }
    node<T> *nodeptr = new node<T>(insert_this, after_this->_next, after_this);
    if (after_this->_next != nullptr)
    {
        after_this->_next->_prev = nodeptr;
    }
    after_this->_next = nodeptr;
    return nodeptr;
}

// insert before ptr: insert head if marker null
template <typename T>
node<T> *_insert_before(node<T> *&head,
                        node<T> *before_this,
                        T insert_this)
{
    assert(before_this != nullptr);
    if (head == nullptr || before_this->_prev == nullptr)
    {
        _insert_head(head, insert_this);
        return head;
    }
    return _insert_after(head, before_this->_prev, insert_this);
}

// ptr to previous node
template <typename T>
node<T> *_previous_node(node<T> *prev_to_this)
{
    return prev_to_this->_prev;
}

// delete, return item
template <typename T>

T _delete_node(node<T> *&head, node<T> *delete_this)
{
    T deleted;

    if (head == nullptr || delete_this == nullptr)
    {
        return T();
    }

    if (head == delete_this)
    {
        deleted = delete_this->_item;
        head = delete_this->_next;
        if (head != nullptr)
        {
            head->_prev = nullptr;
        }
        delete delete_this;
        return deleted;
    }
    deleted = delete_this->_item;
    node<T> *before = delete_this->_prev;
    node<T> *after = delete_this->_next;
    before->_next = after;
    if (after != nullptr)
    {
        after->_prev = before;
    }
    delete delete_this;
    return deleted;
}

// duplicate the list...
template <typename T>
node<T> *_copy_list(node<T> *head)
{
    node<T> *newHead = nullptr;
    _copy_list(newHead, head);
    return newHead;
}

// duplicate the list, return pointer to last node in dest...
//      use this function in your queue big three
template <typename T>
node<T> *_copy_list(node<T> *&dest, node<T> *src)
{
    _clear_list(dest);
    node<T> *temp2 = dest;
    for (node<T> *temp = src; temp != nullptr; temp = temp->_next)
    {
        temp2 = _insert_after(dest, temp2, temp->_item);
    }
    return temp2;
}

// delete all the nodes
template <typename T>
void _clear_list(node<T> *&head)
{
    node<T> *w1 = head;
    node<T> *w2 = head;
    while (w2 != nullptr)
    {
        w2 = w2->_next;
        delete w1;
        w1 = w2;
    }
    head = nullptr;
}

//_item at this position
template <typename T>
T &_at(node<T> *head, int pos)
{
    assert(pos >= 0);
    node<T> *walker = head;
    int i = 0;
    while (walker != nullptr && i < pos)
    {
        walker = walker->_next;
        i++;
    }
    assert(walker != nullptr);
    T *ptr = &(walker->_item);
    return *ptr;
}
#endif
