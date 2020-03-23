// 计算字符串最后一个单词的长度，单词以空格隔开。

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int len = str.rfind(' ');
    if (len == 0) {
        cout << str.size() - 1 << endl;
    }
    else
        cout << str.size() - len - 1 << endl;

    return 0;
}

