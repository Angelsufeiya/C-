#include <iostream>
#include <time.h>
using namespace std;





struct A {
	int a[10000];
};

void TestFunc1(A a)
{}

void TestFunc2(A& a)
{}

void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
}

// 运行多次，检测值和引用在传参方面的效率区别 
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		TestRefAndValue();
	}
	return 0; 
}


//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main() {
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;// 7
//	return 0;
//}

//void TestRef()
//{
//	int a = 10;
//	// int& ra;
//	int& ra = a;
//	int& rra = a;
//	printf("%p  %p  %p\n", &a, &ra, &rra);
//}
//
//void TestConstRef()
//{
//	const int a = 10;
//	//int& ra = a; // 该语句编译时会出错，a为常变量 
//	const int& ra = a;
//	//int& b = 10; // 该语句编译时会出错，10为常量 
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同 
//	const int& rd = d;	//	rd = 12 (: 从“double”转换到“const int”，丢失数据)
//}
//
//int main(){
//	TestRef();
//	TestConstRef();
//
//	return 0;
//}