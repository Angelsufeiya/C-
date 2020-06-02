//����:iNOC��Ʒ�� - ������ǵı���
//	1
//	1 1 1
//	1 2 3 2 1
//	1 3 6 7 6 3 1
//	1 4 10 16 19 16 10 4 1
//	���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ� ����3����֮��(���������ĳ��������Ϊ��������0)��
//	���n�е�һ��ż�����ֵ�λ�á����û��ż��������� - 1����������3, �����2������4�����3��
//	����n(n <= 1000000000)
//��������: ����һ��int����
//  ������� : ������ص�intֵ
//	 ʾ��1 :
//   ���� 4
//	   ��� 3
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
	// �˴��Ȳ�����ԭ�򣬵�lambda���ʽ�ײ�ʵ��ԭ����󣬴�Ҿ������ 
	//f1 = f2; // ����ʧ��--->��ʾ�Ҳ���operator=()
	// ����ʹ��һ��lambda���ʽ��������һ���µĸ���
	auto f3(f2);
	f3();
	// ���Խ�lambda���ʽ��ֵ����ͬ���͵ĺ���ָ�� 
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
		sum++; // ԭ�Ӳ���
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
//   ����:�������������
//	 �����һ���㷨������������������ļӷ���
//	  �ӿ�˵��
//	  /*
//	  �����һ���㷨������������������ļӷ��� �������:
//	  String addend:����
//	  String augend:������
//	  ����ֵ:�ӷ����
//	  */
//	  public String AddLongInteger(String addend, String augend) {
//		  /*������ʵ�ֹ���*/
//		  return null;
//	  }
//��������:
//   ���������ַ�������
//   ������� : �����Ӻ�Ľ����string��
//	  ʾ��1 :
//   ���� 99999999999999999999999999999999999999999999999999 1
//	   ���
//	   100000000000000000000000000000000000000000000000000