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

//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//	int n, len;
//	while (cin >> n) {
//		len = 2 * n - 1;
//		vector<vector<int>> dp(n, vector<int>(len, 0));
//		dp[0][0] = 1;
//		for (int i = 1; i < n; i++) {
//			//��һ�к����һ�ж�Ϊ1
//			dp[i][0] = dp[i][2*i] = 1;
//
//			for (int j = 1; j < 2*i; j++) {
//				if (j == 1) {
//					// �ڶ��У�ֻ��ǰ����Ԫ��֮��
//					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//				}
//				else {
//					// ��i,jԪ�ص�����һ�е�j - 2,j - 1,j����Ԫ��֮��
//					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
//				}
//			}
//		}
//
//		int k;
//		for (k = 0; k < len; k++) {
//			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0) {
//				cout << k + 1 << endl;
//				break;
//			}
//		}
//		if (k == len)
//			cout << -1 << endl;
//	}
//	return 0;
//}




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
//
//#include <string>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//string addStrings(string s1, string s2) {
//	int i = s1.size() - 1;
//	int j = s2.size() - 1;
//	string result = "";
//
//	// ��ǰλ��ӵĽ��
//	int add = 0;
//	while (i >= 0 || j >= 0) {
//		if (i >= 0) {
//			add += s1[i] - '0';
//		}
//		if (j >= 0) {
//			add += s2[j] - '0';
//		}
//		// ��ǰλ���ֵ���ܴ���0��
//		result += (char)(add % 10 + '0');
//		// �������10����1
//		add /= 10;
//		i--, j--;
//	}
//	//��������
//	reverse(result.begin(), result.end());
//	return result;
//}
//
//int main() {
//	string str1, str2;
//	while (cin >> str1 >> str2) {
//		cout << addStrings(str1, str2) << endl;
//	}
//	return 0;
//}


#if 0

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	void HeapAdjustDown(vector<int>& arr, int start, int end) {
		int temp = arr[start];
		int i = start * 2 + 1;
		while (i <= end) {
			if (i + 1 <= end && arr[i + 1] < arr[i]) {
				i++;
			}
			if (arr[i] > temp) {
				break;
			}
			arr[start] = arr[i];
			start = i;
			i = start * 2 + 1;
		}
		arr[start] = temp;
	}
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> result;
		if (input.size() == 0 || k == 0 || k > input.size()) {
			return result;
		}

		int len = input.size();
		// ��ʼ����
		for (int i = len / 2 - 1; i >= 0; i--) {
			HeapAdjustDown(input, i, len - 1);
		}
		for (; k > 0; k--) {
			result.push_back(input[0]);
			int temp = input[len - 1];
			input[len - 1] = input[0];
			input[0] = temp;

			len--;
			//��arr[0...i-1]���µ���Ϊ����
			HeapAdjustDown(input, 0, len - 1);
		}
		return result;
	}
};

int main() {
	Solution s;
	int n, k;
	cin >> n >> k;
	vector<int> v, re;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	re = s.GetLeastNumbers_Solution(v, k);
	for (int i = 0; i < re.size(); i++) {
		cout << re[i] << ',';
	}
	return 0;
}


#endif

#if 0
#include <iostream>
#include <math.h>
using namespace std;

bool Isprime(int n) {
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (!(n % i)) {
			return false;
		}
	}
	return true;
}

int main() {
	int input, flag = 0;
	while (cin >> input) {
		for (int i = 2; i < input; i++) {
			if (i % 10 == 1) {
				if (Isprime(i)) {
					cout << i << ' ';
					flag = 1;
				}
			}
		}
		if (!flag) {
			cout << "-1";
		}
	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

union tmp {
	int a;
	char b;	// b ���� a[0]
}tmp;

int main() {
	tmp.a = 1;
	if (tmp.b == 1) {
		cout << "�������С���ֽ���\n";
	}
	else {
		cout << "������Ǵ���ֽ���\n";
	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

//����������ܽ����㷨��������ʵ���ǶԼ��ܹ����е���Կȡ���ţ��ٴμ��ܣ�
void KaiSa(char* str, int k) {
	while (*str) {
		if ((*str + k <= 'z' && *str + k >= 'a') && (*str <= 'z' && *str >= 'a')) {
			*str++ = *str + k;
		}
		else if ((*str + k <= 'Z' && *str + k >= 'A') && (*str <= 'Z' && *str >= 'A')) {
			*str++ = *str + k;
		}
		else if (k >= 0) {
			*str++ = *str + k - 26;
		}
		else if (k < 0) {
			*str++ = *str + k + 26;
		}
	}
}

int main() {
	char array[1000] = { 0 };
	int k;

	cout << "����������Ҫ���ܵĿ�������:\n";
	cin >> array;
	cout << "�����������ÿ����������λ�����\n";
	cin >> k;

	if (k > 25 || k < -25) {
		k %= 26;
	}
	KaiSa(array, k);
	cout << "���п������ܺ������Ϊ��\n";
	cout << array << endl;
	KaiSa(array, -k);
	cout << "���п������ܺ������Ϊ��\n";
	cout << array << endl;

	return 0;
}
#endif

#if 0
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

#endif


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

