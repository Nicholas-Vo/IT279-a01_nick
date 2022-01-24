#include <iostream>

#include "List.cpp"
#include "List.h"

using namespace std;

template<typename Object>

void printList(List<Object> pList) {
    typename List<Object>::const_iterator pIter;

    for (pIter = pList.begin(); pIter != pList.end(); pIter++) {
        cout << *pIter << " ";
    }
}

int main() {
    cout << "--------------------------------------------" << endl;
    cout << "IT 279 Assignment 01: Q01 Nick Voss" << endl;

    List<int> list;

    // Load our list with the values via an array
    for (auto num : {2, 4, 5, 7, 8, 1, 7, 15}) {
        list.push_back(num);
    }

    cout << "The created list is: ";
    printList(list);

    List<int>::iterator theIterator = list.find(list.begin(), list.end(), 7);
    cout << "\nThe found node value: " << *theIterator << endl;

    list.erase(list.begin(), theIterator.operator++());
    cout << "the following node values: ";
    printList(list);
    cout << "\n--------------------------------------------" << endl;
    return 0;
}
