#include <iostream>

#include "List.cpp"
#include "List.h"

/*
 * Nick Voss
 * 1/24/2022
 * IT279
 * Assignment 1 part 1
 */

using namespace std;

template<typename Object>

void printList(const string&, List<Object> pList) {
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

    printList("The created list is: ", list);

    List<int>::iterator theIterator = list.find(list.begin(), list.end(), 7);
    cout << "\nThe found node value: " << *theIterator << endl;

    list.erase(list.begin(), theIterator.operator++());

    printList("the following node values: ", list);
    cout << "\n--------------------------------------------" << endl;
    return 0;
}
