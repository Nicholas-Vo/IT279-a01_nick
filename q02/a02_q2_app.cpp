/*
 * Nick Voss
 * 1/24/2022
 * IT279
 * Assignment 1 part 2
 */

#include "List.h"
#include "List.cpp"
#include <iostream>

using namespace std;

// Assumes both input lists are sorted
// This function is used as a reference
template<typename Object>
List<Object> intersection(const List<Object> &L1, const List<Object> &L2) {
    List<Object> intersect;
    typename List<Object>::const_iterator iterL1 = L1.begin();
    typename List<Object>::const_iterator iterL2 = L2.begin();

    while (iterL1 != L1.end() && iterL2 != L2.end()) {
        if (*iterL1 == *iterL2) {
            intersect.push_back(*iterL1);
            iterL1++;
            iterL2++;
        }
        else if (*iterL1 < *iterL2) iterL1++;
        else iterL2++;
    }
    return intersect;
}


template<typename Object>
void printList(const string& msg, List<Object> pList) {
    typename List<Object>::const_iterator pIter;
    for (pIter = pList.begin(); pIter != pList.end(); pIter++) {
        cout << *pIter << " ";
    }
}

// Assumes both input lists are sorted
template<typename Object>
List<Object> listUnion(const List<Object> &L1, const List<Object> &L2) {
    typename List<Object>::const_iterator iterL1 = L1.begin();
    typename List<Object>::const_iterator iterL2 = L2.begin();
    List<Object> theUnion;

    while (iterL1 != L1.end() && iterL2 != L2.end()) {
        if (*iterL1 > *iterL2) {
            theUnion.push_back(*iterL2);
            theUnion.push_back(*iterL1);
            *iterL1++;
            *iterL2++;
        }
        if (*iterL1 < *iterL2) {
            theUnion.push_back(*iterL1);
            theUnion.push_back(*iterL2);
            *iterL1++;
            *iterL2++;
        } else {
            theUnion.push_back(*iterL1);
            *iterL1++;
            *iterL2++;
        }

    }

    /*
     * account for cases where a list is longer than the other
     */
    while (iterL1 != L1.end()) theUnion.push_back(*iterL1++);
    while (iterL2 != L2.end()) theUnion.push_back(*iterL2++);

    return theUnion;
}

int main() {
    cout << "--------------------------------------------" << endl;
    cout << "IT 279 Assignment 01: Q02 Nick Voss" << endl;
    int data1[] = {2, 4, 5, 7, 8, 15};
    int data2[] = {1, 4, 6, 7};

    List<int> list1;
    for (int num : data1) list1.push_back(num);

    printList("List 1: ", list1);

    List<int> list2;
    for (int num : data2) list2.push_back(num);

    printList("\nList 2: ", list2);

    printList("\nThe union: ", listUnion(list1, list2));
    cout << "\n--------------------------------------------" << endl;
    return 0;
}
