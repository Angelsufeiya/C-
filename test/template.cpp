#include <iostream>
using namespace std;


template<class T>
bool IsEqual(T& left, T& right)
{
    return left == right;
}

int main() {
    const char* p1 = "hello";
    const char* p2 = "world";
    if (IsEqual(p1, p2))
        cout << p1 << endl;
    else
        cout << p2 << endl; //  world

    return 0;
}