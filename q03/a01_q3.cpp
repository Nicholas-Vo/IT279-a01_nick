/*
 * Nick Voss
 * 1/24/2022
 * IT279
 * Assignment 1 part 3
 */

#include <iostream>
#include <list>
#include <stack>

using namespace std;

void printList(const string& msg, list<int> pList) {
    typename list<int>::const_iterator pIter;
    for (pIter = pList.begin(); pIter != pList.end(); pIter++) {
        cout << *pIter << " ";
    }
}

int main() {
    list<int> randomList;

    for (int i = 0; i < 10; i++) {
        randomList.push_back(rand() % 100 + 1);
    }

    cout << "--------------------------------------------" << endl;
    cout << "IT 279 Assignment 01: Q03 Nick Voss" << endl;

    printList("Original list: ", randomList);

    randomList.sort();

    stack<int> stack;

    for (int num: randomList) {
        stack.push(num);
    }

    cout << "\nSorted list: ";
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << "\n--------------------------------------------" << endl;
    return 0;
}
