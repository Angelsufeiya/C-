#include <vector>
#include <queue>
#include <functional> // greater算法的头文件
#include <iostream>
using namespace std;

namespace bit
{
    template <class T, class Sequence = vector<T>, class Compare = less<T> >
    class priority_queue
    {
    public:
        priority_queue() : c()
        {}

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
            : c(first, last)
        {
            make_heap(c.begin(), c.end(), comp);
        }

        bool empty() const 
        { 
            return c.empty(); 
        }

        size_t size() const 
        { 
            return c.size(); 
        }

        T& top() const 
        { 
            return c.front(); 
        }

        void push(const T & x)
        {
            c.push_back(x);
            push_heap(c.begin(), c.end(), comp);
        }

        void pop() {
            pop_heap(c.begin(), c.end(), comp);
            c.pop_back();
        }
    private:
        Sequence c;
        Compare comp;
    };
}

namespace bit {
#include<deque>
    template<class T, class Con = deque<T>>
    class queue
    {
    public:
        queue() 
        {}

        void push(const T& x) 
        { 
            _c.push_back(x); 
        }

        void pop() 
        { 
            _c.pop_front(); 
        }

        T& back() 
        { 
            return _c.back(); 
        }

        const T& back()const 
        { 
            return _c.back(); 
        }

        T& front() 
        { 
            return _c.front(); 
        }
        
        const T& front()const 
        { 
            return _c.front(); 
        }

        size_t size()const 
        { 
            return _c.size(); 
        }

        bool empty()const 
        { 
            return _c.empty(); 
        }
    private:
        Con _c;
    };
}

namespace bit
{
#include<deque>
    template<class T, class Con = deque<T>>
    class stack
    {
    public:
        stack() 
        {}

        void push(const T& x) 
        { 
            _c.push_back(x); 
        }

        void pop() 
        { 
            _c.pop_back(); 
        }

        T& top() 
        { 
            return _c.back(); 
        }

        const T& top()const 
        { 
            return _c.back(); 
        }

        size_t size()const 
        { 
            return _c.size(); 
        }

        bool empty()const 
        { 
            return _c.empty(); 
        }
    private:
        Con _c;
    };
}

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

void TestPriorityQueue1()
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