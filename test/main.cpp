#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    // bool operator==(Date* this, const Date& d2)
//    // 这里需要注意的是，左操作数是this指向的调用函数的对象 
//    bool operator==(const Date& d2)const
//    {
//        return _year == d2._year && _month == d2._month && _day == d2._day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//void Test() {
//    Date d1(2018, 9, 26);
//    Date d2(2018, 9, 27);
//    cout << (d1 == d2) << endl;
//}
//
//int main() {
//    Test();	// 输出 0
//
//    return 0;
//}


class A
{
public:
    A() { 
        ++_scount; 
    }
    A(const A& t) { 
        ++_scount; 
    }
    static int GetACount() { 
        return _scount; 
    }
private:
    static int _scount;
};

int A::_scount = 0;

int main() {
    cout << A::GetACount() << endl;
    A a1, a2;
    A a3(a1);

    cout << A::GetACount() << endl;

    return 0;
}
