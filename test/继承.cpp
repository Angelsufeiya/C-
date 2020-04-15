#include <iostream>
using namespace std;

//class Person
//{
//public:
//    void Print()
//    {
//        cout << "name:" << _name << endl;
//        cout << "age:" << _age << endl;
//    }
//protected:
//    string _name = "peter"; // 姓名 
//    int _age = 18; // 年龄
//};
//
//// 继承后父类的Person的成员(成员函数+成员变量)都会变成子类的一部分。
//// 这里体现出了 Student和 Teacher复用了Person的成员。
//// 下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。
//// 调用 Print可以看到成员函数的复用。
//
//class Student : public Person
//{
//protected:
//    int _stuid; // 学号 
//};
//
//class Teacher : public Person
//{
//protected:
//    int _jobid; // 工号 
//};
//
//int main_j() {
//    Student s;
//    Teacher t;
//    s.Print();
//    t.Print();
//
//    return 0;
//}

//class Person
//{
//protected:
//    string _name; // 姓名 
//    string _sex; // 性别 
//    int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//    int _No; // 学号 
//};
//
//int main() {
//    Student sobj;
//
//    // 1.子类对象可以赋值给父类对象/指针/引用 
//    Person pobj = sobj;
//    Person* pp = &sobj;
//    Person& rp = sobj;
//
//    // 2.基类对象不能赋值给派生类对象 
//    //sobj = pobj;
//
//    // 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//    pp = &sobj;
//    Student* ps1 = (Student*)pp; // 这种情况转换是可以的。 
//    ps1->_No = 10;
//
//    pp = &pobj;
//    Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//    ps2->_No = 10;
//
//    return 0;
//}

//// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆 
//class Person
//{
//protected:
//    string _name = "小李子"; // 姓名
//    int _num = 111; // 身份证号 
//};
//
//class Student : public Person
//{
//public:
//    void Print()
//    {
//        cout << " 姓名:" << _name << endl;
//        cout << " 身份证号:" << Person::_num << endl;
//        cout << " 学号:" << _num << endl;
//    }
//protected:
//    int _num = 999; // 学号 
//};
//
//int main() {
//    Student s1;
//    s1.Print();
//
//    return 0;
//};

//// B中的fun和A中的fun不构成重载，因为不在同一作用域
//// B中的fun和A中的fun构成隐藏，因为成员函数满足函数名相同就构成隐藏。 
//class A
//{
//public:
//    void fun() {
//        cout << "func()" << endl;
//    }
//};
//
//class B : public A
//{
//public:
//    void fun(int i)
//    {
//        A::fun();
//        cout << "func(int i)->" << i << endl;
//    }
//};
//
//int main() {
//    B b;
//    b.fun(10);
//
//    return 0;
//};
//

//class Person
//{
//public:
//    Person(const char* name = "peter")
//        : _name(name)
//    {
//        cout << "Person()" << endl;
//    }
//
//    Person(const Person& p)
//        : _name(p._name)
//    {
//        cout << "Person(const Person& p)" << endl;
//    }
//
//    Person& operator=(const Person& p)
//    {
//        cout << "Person operator=(const Person& p)" << endl;
//        if (this != &p)
//            _name = p._name;
//        return *this;
//    }
//
//    ~Person() 
//    {
//        cout << "~Person()" << endl;
//    }
//protected:
//    string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//    Student(const char* name, int num)
//        : Person(name)
//        , _num(num) 
//    {
//        cout << "Student()" << endl;
//    }
//
//    Student(const Student& s)
//        : Person(s)
//        , _num(s._num)
//    {
//        cout << "Student(const Student& s)" << endl;
//    }
//
//    Student& operator = (const Student& s)
//    {
//        cout << "Student& operator= (const Student& s)" << endl;
//        if (this != &s)
//        {
//            Person::operator =(s);
//
//            _num = s._num;
//        }
//        return *this;
//    }
//
//    ~Student() {
//        cout << "~Student()" << endl;
//    }
//protected:
//    int _num; //学号
//};
//
//int main()
//{
//    Student s1("jack", 18);
//    Student s2(s1);
//    Student s3("rose", 17);
//    s1 = s3;
//
//    return 0;
//}

//Person()
//Student()
//Person(const Person& p)
//Student(const Student& s)
//Person()
//Student()
//Student& operator= (const Student& s)
//Person operator=(const Person& p)
//~Student()
//~Person()
//~Student()
//~Person()
//~Student()
//~Person()


//class Student;
//
//class Person
//{
//public:
//    friend void Display(const Person& p, const Student& s);
//protected:
//    string _name; // 姓名 
//};
//    
//class Student : public Person
//{ 
//protected:
//    int _stuNum; // 学号 
//};
//    
//void Display(const Person& p, const Student& s)
//{
//    cout << p._name << endl;
//    cout << s._stuNum << endl;
//}
//
//int main() {
//    Person p;
//    Student s;
//    Display(p, s);
//
//    return 0;
//}

//class Person
//{
//public:
//    Person() 
//    { 
//        ++_count; 
//    }
//
//    static int _count; // 统计人的个数。 
//protected:
//    string _name; // 姓名 
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//    int _stuNum; // 学号 
//};
//
//class Graduate : public Student
//{
//protected:
//    string _seminarCourse; // 研究科目 
//};
//
//int main()
//{
//    Student s1;
//    Student s2;
//    Student s3;
//    Graduate s4;
//    cout << " 人数 :" << Person::_count << endl; 
//    Student::_count = 0;
//    cout << " 人数 :" << Person::_count << endl;
//
//    return 0;
//}

// 人数 :4
// 人数 :0

//class Person
//{
//public:
//    string _name; // 姓名 
//};
//
//class Student : public Person
//{
//protected:
//    int _num; //学号 
//};
//class Teacher : public Person
//{
//protected:
//    int _id; // 职工编号 
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//    string _majorCourse; // 主修课程 
//};
//
//void Test() {
//    // 这样会有二义性无法明确知道访问的是哪一个 
//    Assistant a ;
//    a._name = "peter";
//    // 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决 
//    a.Student::_name = "xxx";
//    a.Teacher::_name = "yyy";
//}


//class Person
//{
//public:
//    string _name; // 姓名 
//};
//
//class Student : virtual public Person
//{
//protected:
//    int _num; //学号 
//};
//class Teacher : virtual public Person
//{
//protected:
//    int _id; // 职工编号 
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//    string _majorCourse; // 主修课程 
//};
//
//void Test() {
//    Assistant a;
//    a._name = "peter";
//}

//class A
//{
//public:
//    int _a;
//};
//
//// class B : public A
//class B : virtual public A
//{
//public:
//    int _b;
//};
//// class C : public A
//class C : virtual public A
//{
//public:
//    int _c;
//};
//
//class D : public B, public C
//{
//public:
//    int _d;
//};
//
//int main() {
//    D d;
//    d.B::_a = 1;
//    d.C::_a = 2;
//    d._b = 3;
//    d._c = 4;
//    d._d = 5;
//
//    return 0;
//}
//
//// 有童鞋会有疑问为什么D中B和C部分要去找属于自己的A?
//// 那么大家看看当下面的赋值发生时，d是不是要 去找出B/C成员中的A才能赋值过去?
//D d;
//B b = d;
//C c = d;


//// Car和BMW Car和Benz构成is-a的关系 
//class Car{
//protected:
//    string _colour = "白色"; // 颜色
//    string _num = "陕ABIT00"; // 车牌号 
//};
//
//class BMW : public Car {
//public:
//    void Drive() { cout << "好开-操控" << endl; }
//};
//class Benz : public Car {
//public:
//    void Drive() { cout << "好坐-舒适" << endl; }
//};
//
//// Tire和Car构成has-a的关系
//class Tire {
//protected:
//    string _brand = "Michelin"; // 品牌
//    size_t _size = 17;  // 尺寸
//};
//
//class Car {
//protected:
//    string _colour = "白色";  // 颜色
//    string _num = "陕ABIT00"; // 车牌号
//    Tire _t;    // 轮胎
//};

//class Base1 {
//public:
//	int _b1;
//};
//
//class Base2 {
//public:
//    int _b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//    int _d;
//};
//
//int main() {
//    // A. p1 == p2 == p3
//    // B. p1 < p2 < p3
//    // C. p1 == p3 != p2
//    // D. p1 != p2 != p3
//    Derive d;
//    Base1* p1 = &d;
//    Base2* p2 = &d;
//    Derive* p3 = &d;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//class TestBase
//{
//public:
//	virtual void func()
//	{
//		cout << "I'm TestBase!" << endl;
//	}
//};
//
//class TestBase2 : public TestBase
//{
//public:
//	void func()
//	{
//		cout << "I'm TestBase2!" << endl;
//	}
//};
//
//class TestBase3 : public TestBase2
//{
//public:
//	void func()
//	{
//		cout << "I'm TestBase3!" << endl;
//	}
//};
//
//int main()
//{
//	/*
//	TestBase tb;
//	Test t;
//	TestBase * ptb = &t;
//	ptb->func();
//	tb.func();
//	t.func();*/
//
//#if 0
//	TestBase3 t3;
//	TestBase2* pt2 = &t3;
//	TestBase* pt = pt2;
//
//	t3.func();
//	pt2->func();
//	pt->func();
//#else
//	TestBase2 t2;
//	TestBase* pt = &t2;
//	t2.func();
//	pt->func();
//#endif
//	return 0;
//}

class Base1 {
public:
    int _b1;
};

class Base2 {
public:
    int _b2;
};

class Derive : public Base1, public Base2 {
public:
    int _d;
};

int main() {
    Derive d;
    Base1* p1 = &d;
    Base2* p2 = &d;
    Derive* p3 = &d;

    // 地址的输出不一定每次相同，但是 p1 == p3 != p2 不变
    cout << p1 << endl; // 00AFFC54
    cout << p2 << endl; // 00AFFC58
    cout << p3 << endl; // 00AFFC54

    if (p2 == p3)
        cout << "p2 == p3" << endl; // p2 == p3
    else
        cout << "p2 != p3" << endl;

    return 0;
}

// A. p1 == p2 == p3
// B. p1 < p2 < p3
// C. p1 == p3 != p2
// D. p1 != p2 != p3

// 答案为：C