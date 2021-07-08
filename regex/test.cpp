#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(){
    string str = "word1 = \"abc\", word2 = \"de\" ";
    cout << "str: " << str << endl;

    regex re(R"(\"(\w+)\")");
    sregex_iterator start(str.cbegin(), str.cend(), re);
    sregex_iterator end;

    for(auto it = start; it != end; ++it){
        smatch m = *it;
        cout << m[1].str() << endl;
    }
    return 0;
}