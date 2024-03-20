#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "../node/node.h"
#include "../linked_list_functions/linkedlistfunctionsTemplated.h"
using namespace std;

template <typename T>
class Stack
{
public:
    class Iterator
    {
    public:
        friend class Stack;                // give access to list to access _ptr
        Iterator() { _ptr = NULL; }        // default ctor
        Iterator(node<T> *p) { _ptr = p; } // Point Iterator to where
                                           //   p is pointing to
        T operator*()
        {
            assert(_ptr != nullptr);
            return _ptr->_item;
        }                                       // dereference operator
        bool is_null() { return _ptr == NULL; } // true if _ptr is NULL
        friend bool operator!=(const Iterator &left,
                               const Iterator &right) // true if left != right
        {
            return left._ptr != right._ptr;
        }

        friend bool operator==(const Iterator &left,
                               const Iterator &right) // true if left == right
        {
            return left._ptr == right._ptr;
        }

        Iterator &operator++()
        { // member operator:++it
            //  or ++it = new_value
            _ptr++;
            return *this;
        }

        friend Iterator operator++(Iterator &it,
                                   int unused)
        { // friend operator: it++
            assert(it._ptr != NULL);
            Iterator hold = it;
            it._ptr = it._ptr->_next;
            return hold;
        }

    private:
        node<T> *_ptr; // pointer being encapsulated
    };

    Stack();
    Stack(const Stack<T> &copyMe);
    ~Stack();
    Stack<T> &operator=(const Stack<T> &RHS);
    T top() { return _top->_item; }
    bool empty() { return (_top == nullptr); }
    void push(T item)
    {
        _insert_head(_top, item);
        _size++;
    }
    T pop()
    {
        if (_size > 0)
            _size--;
        return _delete_node(_top, _top);
    }
    template <typename U>
    friend ostream &operator<<(ostream &outs, const Stack<U> &printMe);
    Iterator begin() const { return Iterator(_top); }  // Iterator to the head node
    Iterator end() const { return Iterator(nullptr); } // Iterator to NULL
    int size() const { return _size; }

private:
    node<T> *_top;
    int _size;
};

template <typename T>
Stack<T>::Stack()
{
    _top = nullptr;
    _size = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &copyMe)
{
    if (_top != nullptr)
    {
        _clear_list(_top);
    }
    _top = _copy_list(copyMe._top);
    _size = copyMe._size;
}

template <typename T>
Stack<T>::~Stack()
{
    _clear_list(_top);
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &RHS)
{
    if (this == &RHS)
    {
        return *this;
    }
    _clear_list(_top);
    _top = _copy_list(RHS._top);
    _size = RHS._size;
    return *this;
}

template <typename U>
ostream &operator<<(ostream &outs, const Stack<U> &printMe)
{
    node<U> *walker = printMe._top;
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