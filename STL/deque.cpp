#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

void printDeque(const deque<double> &d) {
    for (deque<double>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << endl;
    }
}

bool myCompare(double a, double b){
    return a > b;
}
int main() {
    deque<double> d;
    d.push_back(1.1);
    d.push_front(1.2);
    d.push_front(1.3);
    d.push_front(1.4);
    d.push_front(1.5);
    d.push_back(1.6);
    d.pop_front();
    d.pop_front();
    
    sort(d.begin(), d.end(), myCompare);
    printDeque(d);
    return 0;
}
