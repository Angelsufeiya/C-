#include <vector>
#include <queue>
#include <functional> // greater算法的头文件
#include <iostream>
using namespace std;

void TestPriorityQueue1()
{
    // 默认情况下，创建的是大堆，其底层按照小于号比较 
    vector<int> v{3,2,7,6,0,4,1,9,8,5}; 
    priority_queue<int> q1;
    for (auto& e : v)
        q1.push(e);
    cout << q1.top() << endl;   // 9
    // 如果要创建小堆，将第三个模板参数换成greater比较方式
    priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end()); 
    cout << q2.top() << endl;   // 0
}

class Date
{
    int _year;
    int _month;
    int _day;
public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {}

    bool operator<(const Date& d)const
    {
        return (_year < d._year) ||
            (_year == d._year && _month < d._month) ||
            (_year == d._year && _month == d._month && _day < d._day);
    }

    bool operator>(const Date& d)const
    {
        return (_year > d._year) ||
            (_year == d._year && _month > d._month) ||
            (_year == d._year && _month == d._month && _day > d._day);
    }

    friend ostream& operator<<(ostream& _cout, const Date& d)
    {
        _cout << d._year << "-" << d._month << "-" << d._day;
        return _cout;
    } 
};

void TestPriorityQueue()
{
    // 大堆，需要用户在自定义类型中提供<的重载 
    priority_queue<Date> q1; 
    q1.push(Date(2018, 10, 29)); 
    q1.push(Date(2018, 10, 28)); 
    q1.push(Date(2018, 10, 30));
    cout << q1.top() << endl;   // 2018, 10, 30
    // 如果要创建小堆，需要用户提供>的重载 
    priority_queue<Date, vector<Date>, greater<Date>> q2; 
    q2.push(Date(2018, 10, 29));
    q2.push(Date(2018, 10, 28));
    q2.push(Date(2018, 10, 30));
    cout << q2.top() << endl;   // 2018, 10, 28
}

class Less
{
public:
    bool operator()(const Date* pLeft, const Date* pRight)
    {
        return *pLeft < *pRight;
    }
};

void TestPriorityQueue()
{
    // 自己定制比较的规则
    priority_queue<Date*, vector<Date*>, Less> q; 
    q.push(&Date(2018, 10, 29)); 
    q.push(&Date(2018, 10, 28)); 
    q.push(&Date(2018, 10, 30));
    cout << *q.top() << endl;   // 2018, 10, 30
}