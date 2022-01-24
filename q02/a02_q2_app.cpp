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
void printList(List<Object> pList) {
    typename List<Object>::const_iterator pIter;
    for (pIter = pList.begin(); pIter != pList.end(); pIter++) {
        cout << *pIter << " ";
    }
}

//void doUnion(const list<int>& list1, const list<int>& list2, list<int>& l) {
//    list<int>::const_iterator iter1 = list1.begin();
//    list<int>::const_iterator iter2 = list2.begin();
//    set<int> mySet;
//
//    while (iter1 != list1.end()) {
//        mySet.insert(*iter1);
//        iter1++;
//    }
//    while (iter2 != list2.end()) {
//        mySet.insert(*iter2);
//        iter2++;
//    }
//    set<int>::iterator it;
//    for (it = mySet.begin(); it != mySet.end(); it++) {
//        l.push_back(*it);
//    }
//}

// Assumes both input lists are sorted
template<typename Object>
List<Object> listUnion(const List<Object> &L1, const List<Object> &L2) {
    typename List<Object>::const_iterator iterL1 = L1.begin();
    typename List<Object>::const_iterator iterL2 = L2.begin();
    List<Object> theUnion;
    List<Object> list;

    while (iterL1 != L1.end()) {
        list.push_back(*iterL1);
        iterL1++;
    }

    while (iterL2 != L2.end()) {
        list.push_back(*iterL2);
        iterL2++;
    }

    typename List<Object>::iterator anIt;

    for (anIt = list.begin(); anIt != list.end(); anIt++) {
        theUnion.push_back(*anIt);
    }

    return theUnion;
}

int main() {
    cout << "--------------------------------------------" << endl;
    cout << "IT 279 Assignment 01: Q02 Nick Voss" << endl;
    int data1[] = {2, 4, 5, 7, 8, 15};
    int data2[] = {1, 4, 6, 7};

    List<int> list1;
    for (int num : data1) list1.push_back(num);

    cout << "List 1: ";
    printList(list1);

    List<int> list2;
    for (int num : data2) list2.push_back(num);

    cout << "\nList 2: ";
    printList(list2);

    cout << "\nThe union: ";
    printList(listUnion(list1, list2));
    cout << "\n--------------------------------------------" << endl;
    return 0;
}
