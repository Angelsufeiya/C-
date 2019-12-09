#include <iostream>//iostream 是输入/输出流库标准文件 
using namespace std;

// 默认构造函数 
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

// 以下测试函数能通过编译吗? 
void Test()
{
	Date d1;//类Date 中包含多个默认构造函数
}


//// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//	void f1(){}
//private:
//	int _a;
//};
//// 类中仅有成员函数 
//class A2 { public:
//void f2() {}
//};
//// 类中什么都没有---空类 
//class A3
//{};
//
//int main(){
//	cout << sizeof(A1) << ' ' << sizeof(A2) << ' ' << sizeof(A3) << endl;
//	return 0;
//}

// 1.下面程序能编译通过吗?
// 2.下面程序会崩溃吗?在哪里崩溃 
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void Show() {
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	A* p = NULL;
//	p->PrintA();
//	p->Show();
//}
