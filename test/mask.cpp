// �����ַ������һ�����ʵĳ��ȣ������Կո������

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

