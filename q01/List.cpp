#include "List.h"

#include <algorithm>
#include <iostream>

using namespace std;

template<typename Object>
List<Object>::List() {
    init();
}

template<typename Object>
List<Object>::~List() {
    clear();
    delete head;
    delete tail;
}

template<typename Object>
List<Object>::List(const typename List<Object>::List &rhs) {
    init();
    for (auto &x: rhs) push_back(x);
}

template<typename Object>
typename List<Object>::List &List<Object>::operator=(
        const typename List<Object>::List &rhs) {
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
}

template<typename Object>
List<Object>::List(List &&rhs)
        : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail} {
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

template<typename Object>
typename List<Object>::List &List<Object>::operator=(
        typename List<Object>::List &&rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);

    return *this;
}

template<typename Object>
class List<Object>::iterator : public List<Object>::const_iterator {
public:
    // Public constructor for iterator.
    // Calls the base-class constructor.
    // Must be provided because the private constructor
    // is written; otherwise zero-parameter constructor
    // would be disabled.
    iterator() {}

    Object &operator*() { return const_iterator::retrieve(); }

    // Return the object stored at the current position.
    // For iterator, there is an accessor with a
    // const reference return type and a mutator with
    // a reference return type. The accessor is shown first.
    const Object &operator*() const { return const_iterator::operator*(); }

    iterator &operator++() {
        this->current = this->current->next;
        return *this;
    }

    iterator operator++(int) {
        iterator old = *this;
        ++(*this);
        return old;
    }

    iterator &operator--() {
        this->current = this->current->prev;
        return *this;
    }

    iterator operator--(int) {
        iterator old = *this;
        --(*this);
        return old;
    }

protected:
    // Protected constructor for iterator.
    // Expects the current position.
    iterator(Node *p) : const_iterator{p} {}

    friend class List<Object>;
};

// assignment 01: question 01

// & == reference. Cannot be null. Object is NOT copied

// Implement the find function that returns the iterator containing the first
// occurrence of x in the range that begins at start and extends up to but not
// including end. If x is not found, end is returned.
template<typename Object>
typename List<Object>::iterator List<Object>::find(iterator start, iterator end, const Object &x) {

    while (start != end) {
        if (*start == x) {
            return start;
        }
        start++;
    }
    return end;
}

// Return iterator representing beginning of list.
// Mutator version is first, then accessor version.
template<typename Object>
typename List<Object>::iterator List<Object>::begin() {
    return iterator(head->next);
}

template<typename Object>
typename List<Object>::const_iterator List<Object>::begin() const {
    return const_iterator(head->next);
}

// Return iterator representing endmarker of list.
// Mutator version is first, then accessor version.
template<typename Object>
typename List<Object>::iterator List<Object>::end() {
    return iterator(tail);
}

template<typename Object>
typename List<Object>::const_iterator List<Object>::end() const {
    return const_iterator(tail);
}

// Return number of elements currently in the list.
template<typename Object>
int List<Object>::size() const {
    return theSize;
}

// Return true if the list is empty, false otherwise.
template<typename Object>
bool List<Object>::empty() const {
    return size() == 0;
}

template<typename Object>
void List<Object>::clear() {
    while (!empty()) pop_front();
}

// front, back, push_front, push_back, pop_front, and pop_back
// are the basic double-ended queue operations.
template<typename Object>
Object &List<Object>::front() {
    return *begin();
}

template<typename Object>
const Object &List<Object>::front() const {
    return *begin();
}

template<typename Object>
Object &List<Object>::back() {
    return *--end();
}

template<typename Object>
const Object &List<Object>::back() const {
    return *--end();
}

template<typename Object>
void List<Object>::push_front(const Object &x) {
    insert(begin(), x);
}

template<typename Object>
void List<Object>::push_back(const Object &x) {
    insert(end(), x);
}

template<typename Object>
void List<Object>::push_front(Object &&x) {
    insert(begin(), std::move(x));
}

template<typename Object>
void List<Object>::push_back(Object &&x) {
    insert(end(), std::move(x));
}

template<typename Object>
void List<Object>::pop_front() {
    erase(begin());
}

template<typename Object>
void List<Object>::pop_back() {
    erase(--end());
}

// Insert x before itr.
template<typename Object>
typename List<Object>::iterator List<Object>::insert(iterator itr,
                                                     const Object &x) {
    Node *p = itr.current;
    ++theSize;

    Node *newNode = new Node{x, p->prev, p};
    p->prev->next = newNode;
    p->prev = newNode;
    return iterator(p->prev);

    return iterator(p->prev = p->prev->next = new Node{x, p->prev, p});
}

// Insert x before itr.
template<typename Object>
typename List<Object>::iterator List<Object>::insert(iterator itr, Object &&x) {
    Node *p = itr.current;
    ++theSize;
    return iterator(p->prev = p->prev->next = new Node{std::move(x), p->prev, p});
}

// Erase item at itr.
template<typename Object>
typename List<Object>::iterator List<Object>::erase(iterator itr) {
    Node *p = itr.current;
    iterator retVal(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;

    return retVal;
}

template<typename Object>
typename List<Object>::iterator List<Object>::erase(iterator from, iterator to) {
    for (iterator itr = from; itr != to;) {
        itr = erase(itr);
    }

    return to;
}

template<typename Object>
void List<Object>::init() {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

template<typename Object>
class List<Object>::const_iterator {
public:
    // Public constructor for const_iterator.
    const_iterator() : current{nullptr} {}

    // Return the object stored at the current position.
    // For const_iterator, this is an accessor with a
    // const reference return type.
    const Object &operator*() const { return retrieve(); }

    const_iterator &operator++() {
        current = current->next;
        return *this;
    }

    const_iterator operator++(int) {
        const_iterator old = *this;
        ++(*this);
        return old;
    }

    const_iterator &operator--() {
        current = current->prev;
        return *this;
    }

    const_iterator operator--(int) {
        const_iterator old = *this;
        --(*this);
        return old;
    }

    bool operator==(const const_iterator &rhs) const {
        return current == rhs.current;
    }

    bool operator!=(const const_iterator &rhs) const { return !(*this == rhs); }

protected:
    Node *current;

    // Protected helper in const_iterator that returns the object
    // stored at the current position. Can be called by all
    // three versions of operator* without any type conversions.
    Object &retrieve() const { return current->data; }

    // Protected constructor for const_iterator.
    // Expects a pointer that represents the current position.
    const_iterator(Node *p) : current{p} {}

    // Friend Class A friend class can access private and protected members of
    // other class in which it is declared as friend. It is sometimes useful to
    // allow a particular class to access private members of other class.

    friend class List<Object>;
};
