#include <iostream>
using namespace std;

void f(int) {
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main() {
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}

//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	// auto 这种方式来去改变变量 e 的内容 我们需要用到引用，即在 auto 后面加上 & 。
//	for (auto& e : array)
//		e *= 2;
//	for (auto e : array)
//		cout << e << " ";//2 4 6 8 10
//}

//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//		cout << *p << endl; //2 4 6 8 10
//}
//
//int main(){
//	TestFor();
//	return 0;
//}

//void TestAuto()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同 
//}
//int main() {
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;//int *
//	cout << typeid(b).name() << endl;//int *
//	cout << typeid(c).name() << endl;//int
//
//	*a = 20;//x == *a == *b == c == 20
//	*b = 30;//x == *a == *b == c == 30
//	c = 40; //x == *a == *b == c == 40
//	return 0;
//}

//int TestAuto(){
//	return 10;
//}
//
//int main() {
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//
//	 //typeid(变量名).name() 可以输出变量的类型
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	//auto e; //无法通过编译，使用auto定义变量时必须对其进行初始化
//	return 0;
//}


//int main() {
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	int* pa = &a;
//	*pa = 20;
//	return 0;
//}

//int main() {
//	int a = 10;
//	int& ra = a;
//	cout << "&a = " << &a << endl;
//	cout << "&ra = " << &ra << endl;
//	return 0;
//}

//struct A {
//	int a[10000];
//};
//A a;
//A TestFunc1()
//{
//	return a;
//}
//A& TestFunc2()
//{
//	return a;
//}
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl; 
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//// 测试运行10次，值和引用作为返回值效率方面的区别 
//int main()
//{
//	for (int i = 0; i < 10; ++i)
//		TestReturnByRefOrValue();
//	return 0; 
//}
//引用效率高

//struct A {
//	int a[10000];
//};
//
//void TestFunc1(A a)
//{}
//
//void TestFunc2(A& a)
//{}
//
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
//}
//
//// 运行多次，检测值和引用在传参方面的效率区别 
//int main()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		TestRefAndValue();
//	}
//	return 0; 
//}
//引用效率高

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