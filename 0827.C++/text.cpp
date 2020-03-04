#include <iostream>
using namespace std;

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

int main_0() {
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	return 0;
}

void func(int& a, int& b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}


int main_1()
{
	const int a = 10;
	const int& ra = a;
	double b = 1.23;
	const double& rb = b;

//	int ming = 5;
//	int &xiaoming = ming;
//	cout << &ming << endl;
//	cout << &xiaoming << endl;
//	cout << xiaoming << endl;
//	int a = 5, b = 6;;
//	func(a, b);
//	printf("%d %d\n", a, b);

	return 0;
}

//#include “F.h"
//
//int main()
//{
//	f(10);
//	return 0;
//}

// inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到。

int TestAuto() {
	return 10;
}

void TestAutoa()
{
	int a[] = { 1,2,3 };
	//auto b[] = { 4,5,6 };//auto不能直接用来声明数组
}

int main() {
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	cout << typeid(b).name() << endl;//int
	cout << typeid(c).name() << endl;//char
	cout << typeid(d).name() << endl;//int

	//auto e; //无法通过编译，使用auto定义变量时必须对其进行初始化
	return 0;
}




