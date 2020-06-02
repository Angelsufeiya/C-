//标题:iNOC产品部 - 杨辉三角的变形
//	1
//	1 1 1
//	1 2 3 2 1
//	1 3 6 7 6 3 1
//	1 4 10 16 19 16 10 4 1
//	以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的 数，3个数之和(如果不存在某个数，认为该数就是0)。
//	求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。例如输入3, 则输出2，输入4则输出3。
//	输入n(n <= 1000000000)
//输入描述: 输入一个int整数
//  输出描述 : 输出返回的int值
//	 示例1 :
//   输入 4
//	   输出 3
//
// 

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	while (cin >> n) {
		int m = 2 * n + 1;
		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[0][0] = 1;

		for (int i = 1; i < n; i++) {
			dp[i][0] = 1;
			
		}

	}


	return 0;




#if 0
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

void (*PF)();
int main()
{
	auto f1 = [] {cout << "hello world" << endl; };
	auto f2 = [] {cout << "hello world" << endl; };
	// 此处先不解释原因，等lambda表达式底层实现原理看完后，大家就清楚了 
	//f1 = f2; // 编译失败--->提示找不到operator=()
	// 允许使用一个lambda表达式拷贝构造一个新的副本
	auto f3(f2);
	f3();
	// 可以将lambda表达式赋值给相同类型的函数指针 
	PF = f2;
	PF();

	cout << typeid(f1).name() << endl;	// class <lambda_1ec5592de10118e452907b5329e9d8fb>
	cout << typeid(f2).name() << endl;	// class <lambda_6c39677baa7253626f0848c76a9ffef5>
	cout << typeid(f3).name() << endl;	// class <lambda_6c39677baa7253626f0848c76a9ffef5>
	cout << typeid(PF).name() << endl;	// void(__cdecl*)(void)

	return 0;
}

#endif

#include <iostream>
#include <thread>
using namespace std;

#if 0
void func(int i, int j)
{
	cout << "I am thread." << i << ' ' << j << endl;
}

int main()
{
	thread t1(func, 2, 5);
	thread t2(func, 3, 8);

	t1.join();
	t2.join();

	cout << "I am main thread." << endl;
	return 0;
}


int main()
{
	int n1 = 500;
	int n2 = 600;

	thread t([&](int addNum) {
		n1 += addNum;
		n2 += addNum;
		}, 500);
	t.join();

	std::cout << n1 << ' ' << n2 << std::endl;	// 1000 1100
	return 0;
}


void foo() {
	this_thread::sleep_for(std::chrono::seconds(1));
}

int main() {
	thread t(foo);
	cout << "before join, joinable=" << t.joinable() << std::endl;

	t.join();
	cout << "after join, joinable=" << t.joinable() << endl;
	return 0;
}

#include <iostream>
using namespace std;
#include <thread>

unsigned long sum = 0L;

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
		sum++;
}
int main() {
	cout << "Before joining,sum = " << sum << std::endl;	// 0

	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	t1.join();
	t2.join();

	cout << "After joining,sum = " << sum << std::endl;		// 20000000
	return 0;
}


#include <iostream>
using namespace std;
#include <thread>
#include <mutex>
std::mutex m;

unsigned long sum = 0L;

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		m.lock();
		sum++;
		m.unlock();
	}
}

int main() {
	cout << "Before joining,sum = " << sum << std::endl;// 0

	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	t1.join();
	t2.join();

	cout << "After joining,sum = " << sum << std::endl;	// 20000000
	return 0;
}

#include <iostream>
using namespace std;
#include <thread>
#include <atomic>

atomic_long sum{ 0 };

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
		sum++; // 原子操作
}

int main() {
	cout << "Before joining, sum = " << sum << std::endl;	// 0

	thread t1(fun, 1000000);
	thread t2(fun, 1000000);
	t1.join();
	t2.join();

	cout << "After joining, sum = " << sum << std::endl;	// 2000000
	return 0;
}
#endif

//
//
//
//   标题:超长正整数相加
//	 请设计一个算法完成两个超长正整数的加法。
//	  接口说明
//	  /*
//	  请设计一个算法完成两个超长正整数的加法。 输入参数:
//	  String addend:加数
//	  String augend:被加数
//	  返回值:加法结果
//	  */
//	  public String AddLongInteger(String addend, String augend) {
//		  /*在这里实现功能*/
//		  return null;
//	  }
//输入描述:
//   输入两个字符串数字
//   输出描述 : 输出相加后的结果，string型
//	  示例1 :
//   输入 99999999999999999999999999999999999999999999999999 1
//	   输出
//	   100000000000000000000000000000000000000000000000000