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


//class A
//{
//public:
//    A() { 
//        ++_scount; 
//    }
//    A(const A& t) { 
//        ++_scount; 
//    }
//    static int GetACount() { 
//        return _scount; 
//    }
//private:
//    static int _scount;
//};
//
//int A::_scount = 0;
//
//int main() {
//    cout << A::GetACount() << endl;
//    A a1, a2;
//    A a3(a1);
//
//    cout << A::GetACount() << endl;
//
//    return 0;
//}


//class Date
//{
//public:
//    friend ostream& operator<<(ostream& cout, const Date& d);
//    friend istream& operator>>(istream& cin, Date& d);
//    Date(int year, int month, int day)
//        : _year(year)
//        , _month(month)
//        , _day(day)
//    {}
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//ostream& operator<<(ostream& cout, const Date& d)
//{
//    cout << d._year << "-" << d._month << "-" << d._day;
//    return cout;
//}
//
//istream& operator>>(istream& cin, Date& d)
//{
//    cin >> d._year;
//    cin >> d._month;
//    cin >> d._day;
//    return cin;
//}
//
//int main() {
//    Date d(2017, 12, 24);
//    cout << d << endl;
//    cin >> d;
//    cout << d << endl;
//    return 0;
//}

//class Date; // 前置声明 
//class Time
//{
//    friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//    Time(int hour = 14, int minute= 20, int second = 10)
//        : _hour(hour)
//        , _minute(minute)
//        , _second(second)
//    {}
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//class Date
//{
//public:
//    Date (int year = 2000, int month = 01, int day = 16)
//        : _year(year)
//        , _month(month)
//        , _day(day)   
//    {
//    }
//
//    void SetTimeOfDate(int hour, int minute, int second)
//    {
//        // 直接访问时间类私有的成员变量 
//        _t._hour = hour;
//        _t._minute = minute; 
//        _t._second = second;
//    }
//
//    void print() {
//        cout << _year << '-' << _month << '-' << _day << ' ';
//        cout << _t._hour << ':' << _t._minute << ':' << _t._second << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//    Time _t;
//};
//
//int main() {
//    Date d;
//    d.print(); // 输出 2020-1-16 14:20:10
//
//    return 0;
//}

class A
{
private:
    static int k;
    int h = 10;
public:
    class B
    {
    public:
        void foo(const A& a)
        {
            cout << k << endl;  // 输出 1
            cout << a.h << endl;// 输出 10
        }
    };
};

int A::k = 1;

int main() {
    A::B b;
    b.foo(A());
    return 0;
}