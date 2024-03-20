#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <iomanip>
#include "assert.h"
#include "../node/node.h"
#include "../linked_list_functions/linkedlistfunctionsTemplated.h"
using namespace std;
template <typename T>
class Queue
{
public:
    class Iterator
    {
    public:
        friend class Queue;                // give access to list to access _ptr
        Iterator() { _ptr = NULL; }        // default ctor
        Iterator(node<T> *p) { _ptr = p; } // Point Iterator to where
                                           //   p is pointing to
        T operator*()
        {
            assert(_ptr != nullptr);
            return _ptr->_item;
        }                                            // dereference operator
        bool is_null() { return (_ptr == nullptr); } // true if _ptr is NULL
        friend bool operator!=(const Iterator &left,
                               const Iterator &right) // true if left != right
        {
            return (left._ptr != right._ptr);
        }

        friend bool operator==(const Iterator &left,
                               const Iterator &right) // true if left == right
        {
            return (left._ptr == right._ptr);
        }

        Iterator &operator++()
        { // member operator:++it
            //  or ++it = new_value
            _ptr = _ptr->_next;
            return *this;
        }

        friend Iterator operator++(Iterator &it,
                                   int unused)
        { // friend operator: it++
            assert(it._ptr != nullptr);
            Iterator hold = it;
            it._ptr = it._ptr->_next;
            return hold;
        }

    private:
        node<T> *_ptr; // pointer being encapsulated
    };

    Queue();

    Queue(const Queue<T> &copyMe);
    ~Queue();
    Queue &operator=(const Queue<T> &RHS);

    bool empty() { return (_front == nullptr); }
    T front() { return _front->_item; }
    T back() { return _rear->_item; }

    void push(T item)
    {
        _rear = _insert_after(_front, _rear, item);
        _size++;
    }
    T pop();

    Iterator begin() const; // Iterator to the head node
    Iterator end() const;   // Iterator to NULL
    void print_pointers();
    int size() const { return _size; }
    template <typename TT>
    friend ostream &operator<<(ostream &outs, const Queue<TT> &printMe);

private:
    node<T> *_front;
    node<T> *_rear;
    int _size;
};

template <typename T>
Queue<T>::Queue()
{
    _front = nullptr;
    _rear = nullptr;
    _size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T> &copyMe)
{
    _front = nullptr;
    _rear = _copy_list(_front, copyMe._front);
    _size = copyMe._size;
}

template <typename T>
Queue<T>::~Queue()
{
    _clear_list(_front);
    _rear = nullptr;
}
template <typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &RHS)
{
    if (this == &RHS)
    {
        return *this;
    }
    _clear_list(_front);
    _rear = _copy_list(_front, RHS._front);
    _size = RHS._size;
    return *this;
}

template <typename T>
T Queue<T>::pop()
{
    T item = _delete_node(_front, _front);
    if (item != T())
    {
        assert(_size > 0);
        _size--;
    }
    if (_front == nullptr)
    {
        _rear = _front;
    }
    return item;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() const
{
    return Iterator(_front);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::end() const
{
    return Iterator(_rear);
}

template <typename T>
void Queue<T>::print_pointers()
{
    node<T> *walker = _front;
    cout << "Head->";
    while (walker != nullptr)
    {
        cout << *walker->_item << "->";
        walker = walker->_next;
    }
    cout << "|||" << endl;
}

template <typename TT>
ostream &operator<<(ostream &outs, const Queue<TT> &printMe)
{
    node<TT> *walker = printMe._front;
    outs << "Head->";
    while (walker != nullptr)
    {
        outs << *walker;
        walker = walker->_next;
    }
    outs << "|||" << endl;
    return outs;
}

#endif