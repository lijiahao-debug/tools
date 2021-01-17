#include <iostream>
// file header
#include <fstream>
#include <string>
using namespace std;

void writeFile(ofstream &f) {
    if (!f.is_open()) {
        cout << "failed to open file" << endl;
    }
    f << "hello world" << endl;
    f << "hello world" << endl;
    f << "hello world" << endl;
}

void readFile(ifstream &i) {
    if (!i.is_open()) {
        cout << "failed to open file" << endl;
    }
    // char buf[1024] = {0};
    // while (i.getline(buf, 1024)) {
    //     cout << buf << endl;
    // }

    string buf;
    while (getline(i, buf)) {
        cout << buf << endl;
    }
}

int main() {
    string path = "./test.txt";

    ofstream ofs(path, ios::out | ios::trunc);
    writeFile(ofs);
    ofs.close();

    ifstream ifs;
    ifs.open(path, ios::in);
    readFile(ifs);
    ifs.close();

    return 0;
}
