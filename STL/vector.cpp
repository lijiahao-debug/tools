#include <iostream>
#include <vector>

using namespace std;
void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }
}
void vectorConstructor() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    vector<int> v2(v1.begin(), v1.begin() + 5);
    printVector(v2);
    vector<int> v3;
    v3.assign(v1.begin() + 5, v1.end());
    printVector(v3);

    v2.swap(v3);

    cout << v1.front() << "  " << v1.back() << endl;

    v1.insert(v1.begin(), 2, 100);
    v1.clear();
}

void deMem() {
    vector<int> v;
    for (int i = 0; i < 1000; i++) {
        v.push_back(i);
    }
    cout << v.capacity() << endl;
    v.resize(100);
    cout << v.capacity() << endl;
    vector<int>(v).swap(v);
    cout << v.capacity() << endl;
}

int main() {
    // vectorConstructor();
    deMem();
    return 0;
}