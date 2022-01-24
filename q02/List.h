#ifndef LIST_H
#define LIST_H

#include <algorithm>

using namespace std;

template<typename Object>
class List {
private:
    // The basic doubly linked list node.
    // Nested inside of List, can be public
    // because the Node is itself private
    struct Node {
        Object data;
        Node *prev;
        Node *next;

        Node(const Object &d = Object{}, Node *p = nullptr, Node *n = nullptr)
                : data{d}, prev{p}, next{n} {}

        Node(Object &&d, Node *p = nullptr, Node *n = nullptr)
                : data{std::move(d)}, prev{p}, next{n} {}
    };

public:
    class const_iterator;

    class iterator;

public:
    List();

    List(int arr[], int size);

    ~List();

    List(const List &rhs);

    List &operator=(const List &rhs);

    List(List &&rhs);

    List &operator=(List &&rhs);

    // Return iterator representing beginning of list.
    // Mutator version is first, then accessor version.
    iterator begin();

    const_iterator begin() const;

    // Return iterator representing endmarker of list.
    // Mutator version is first, then accessor version.
    iterator end();

    const_iterator end() const;

    // Return number of elements currently in the list.
    int size() const;

    // Return true if the list is empty, false otherwise.
    bool empty() const;

    void clear();

    // front, back, push_front, push_back, pop_front, and pop_back
    // are the basic double-ended queue operations.
    Object &front();

    const Object &front() const;

    Object &back();

    const Object &back() const;

    void push_front(const Object &x);

    void push_back(const Object &x);

    void push_front(Object &&x);

    void push_back(Object &&x);

    void pop_front();

    void pop_back();

    // Insert x before itr.
    iterator insert(iterator itr, const Object &x);

    // Insert x before itr.
    iterator insert(iterator itr, Object &&x);

    // Erase item at itr.
    iterator erase(iterator itr);

    iterator erase(iterator from, iterator to);

private:
    int theSize;
    Node *head;
    Node *tail;

    void init();
};

#endif
