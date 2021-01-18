#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> &s) {
    for (int i : s) {
        cout << i << endl;
    }
}
int main() {
    set<int> s1;
    pair<set<int>::iterator, bool> p1 =  s1.insert(3);
    s1.insert(2);
    s1.insert(1);
    s1.insert(4);
    printSet(s1);

    set<int>::iterator it = s1.find(3);
    int count = s1.count(1);

    pair<set<int>::iterator, set<int>::iterator> p = s1.equal_range(3);
    return 0;
}