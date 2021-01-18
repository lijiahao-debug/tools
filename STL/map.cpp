#include <iostream>
#include <map>

using namespace std;

void test() {
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(make_pair(2, 20));
}
int main() {
    return 0;
}