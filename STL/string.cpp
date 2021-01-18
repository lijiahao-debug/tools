#include <iostream>
#include <string>

using namespace std;

void atException() {
    string s = "abc";
    s.at(4);
    try {
        s.at(4);
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }
}

void stringFind() {
    string str = "abcdef";
    str.find("de");
    //reverse
    str.rfind("de");
}

void strReplace() {
    string str = "abcdef";
    str.replace(1, 3, "111111");
}
void test() {
    string str = "aaa.bb.cccc.dd";
    int pos = 0;
    int next = 0;
    while (true) {
        next = str.find('.', pos);
        if (next == -1) {
            cout << str.substr(pos, str.size() - pos) << endl;
            break;
        }
        cout << str.substr(pos, next - pos) << endl;
        pos = next + 1;
    }
}
int main() {
    // atException();
    test();

    const char *str = "abcd";
    string s(str);
    const char *str2 = s.c_str();
    str = "bcd";
    cout << str << endl;
    return 0;
}