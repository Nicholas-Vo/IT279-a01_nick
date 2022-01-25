/*
 * Nick Voss
 * 1/24/2022
 * IT279
 * Assignment 1 part 4
 */


#include <iostream>
#include <list>

using namespace std;

void printList(const string& message, list<int> pList) {
    typename list<int>::const_iterator pIter;
    cout << message;
    for (pIter = pList.begin(); pIter != pList.end(); pIter++) {
        cout << *pIter << " ";
    }
}

template<typename Object>
int removeSmallestObject(list<Object> *ls) {
    int smallest = ls->front(); // front == 45

    typename list<int>::const_iterator iter;

    for (iter = ls->begin(); iter != ls->end(); iter++) {
        if (*iter < smallest) {
            smallest = *iter;
        }
    }

    ls->remove(smallest); // call remove() function which removes all smallest values
    return smallest;
}

int main() {
    list<int> list;
    for (int num: {45, 25, 35, 10, 20, 30, 20, 10}) {
        list.push_back(num);
    }

    cout << "----------------------------------------------------------" << endl;
    cout << "IT 279 Assignment 01: Q03 Nick Voss" << endl;

    printList("The original list: ", list);

    cout << "\nSmallest value: " << removeSmallestObject(&list) << endl;

    printList("List after removing smallest element(s): ", list);
    cout << "\n----------------------------------------------------------" << endl;
    return 0;
}