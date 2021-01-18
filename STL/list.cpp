#include <iostream>
#include <list>

using namespace std;

void printList(list<int> &L) {
    for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << endl;
    }
}
void reversePrintList(list<int> &L) {
    for (list<int>::reverse_iterator it = L.rbegin(); it != L.rend(); it++) {
        cout << *it << endl;
    }
}

void listConstructor() {
    list<int> L;
    for (int i = 0; i < 5; i++) {
        L.push_back(i);
    }
    L.insert(L.begin(), 100);
    L.remove(3);
    L.sort();
    printList(L);
}

int main() {
    listConstructor();
    return 0;
}