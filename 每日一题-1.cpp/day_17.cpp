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
//			//第一列和最后一列都为1
//			dp[i][0] = dp[i][2*i] = 1;
//
//			for (int j = 1; j < 2*i; j++) {
//				if (j == 1) {
//					// 第二列，只是前两个元素之和
//					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//				}
//				else {
//					// 第i,j元素等于上一行第j - 2,j - 1,j三列元素之和
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

//题目描述：
//给出你n条长度不一的边，请你从中选择四条边，组成一个最大的平行四边形。
//
//请你输出最大的平行四边形的面积。



//输入描述
//输入第一行包含一个正整数n，表示边的数量。(4 <= n <= 50000)
//
//输入第二行包含n个正整数，表示n条边的长度，边的长度不会超过10 ^ 9。
//
//输出描述
//输出仅包含一个正整数，即最大的平行四边形的面积，无解则输出 - 1。

//#include <iostream>
//#include <vector>
//using namespace std;

//void getMaxArea(vector<int> v) {
//	int len = 0, wid = 0, flag = 0;
//	
//	for (int i = v.size() - 1; i > 0; i--) {
//		if (flag && v[i] == v[i - 1]) {
//			wid = v[i];
//			break;
//		}
//		if (v[i] == v[i - 1] && flag == 0) {
//			len = v[i];
//			flag = 1;
//		}
//	}
//	cout << wid * len;
//}
//
//void quicksort(vector<int> a, int left, int right) {
//	int i, j, t, temp;
//	if (left > right)
//		return;
//	temp = a[left]; //temp中存的就是基准数
//	i = left;
//	j = right;
//
//	while (i != j) { //顺序很重要，要先从右边开始找
//		while (a[j] >= temp && i < j)//符合条件，往左继续找
//			j--;
//		while (a[i] <= temp && i < j)//符合条件，往右继续找
//			i++;
//		if (i < j)//交换两个数在数组中的位置
//		{
//			t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//		}
//	}
//	//最终将基准数归位
//	a[left] = a[i];
//	a[i] = temp;
//	quicksort(a, left, i - 1);//继续处理左边的，这里是一个递归的过程
//	quicksort(a, i + 1, right);//继续处理右边的 ，这里是一个递归的过程
//}

//题目描述：
//有一种排序算法定义如下，该排序算法每次只能把一个元素提到序列的开头，例如2，1，3，4，只需要一次操作把1提到序列起始位置就可以使得原序列从小到大有序。
//
//现在给你个乱序的1 - n的排列，请你计算最少需要多少次操作才可以使得原序列从小到大有序。



/*输入描述
输入第一行包含一个正整数n ，表示序列的长度。(1 <= n <= 100000)

接下来一行有n个正整数，表示序列中的n个元素，中间用空格隔开。(1 <= a_i <= n)

输出描述
输出仅包含一个整数，表示最少的操作次数。*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void getCount(vector<int> v) {
//	int count = 0;
//	while (1) {
//		int flag = 1;
//		for (int i = 0; i < v.size() - 1; i++) {
//			if (v[i] > v[i + 1]) {
//				int tmp = v[0];
//				v[0] = v[i + 1];
//				v[i + 1] = tmp;
//				count++;
//				flag = 0;
//				break;
//			}
//		}
//		if (flag)
//			break;
//	}
//	cout << count;
//}
//
//int main() {
//	int n;
//	while (cin >> n) {
//		vector<int> v;
//		v.resize(n);
//		int num;
//		for (int i = 0; i < n; i++) {
//			cin >> num;
//			v[i] = num;
//		}
//		getCount(v);
//	}
//
//	return 0;
//}

//题目描述：
//在一个2D横版游戏中，所有的怪物都是在X轴上的，每个怪物有两个属性X和HP，分别代表怪物的位置和生命值。
//
//玩家控制的角色有一个AOE（范围攻击）技能，玩家每次释放技能可以选择一个位置x，技能会对[x - y, x + y]范围内的所有怪物造成1点伤害，请问，玩家最少需要使用多少次技能，才能杀死所有怪物，怪物血量清0即视为被杀死。
//
//输入描述
//输入第一行包含一个两个正整数n和y，分别表示怪物的数量和技能的范围。（1 <= n <= 100000）
//
//接下来有n行，每行有两个正整数x和hp分别表示一只怪物的位置和血量。(1 <= x, hp <= 10 ^ 9)
//
//输出描述
//输出仅包含一个整数，表示最少使用的技能次数。
//
//
//样例输入
//3 5
//1 10
//10 5
//22 3
//样例输出
//13



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
//	// 当前位相加的结果
//	int add = 0;
//	while (i >= 0 || j >= 0) {
//		if (i >= 0) {
//			add += s1[i] - '0';
//		}
//		if (j >= 0) {
//			add += s2[j] - '0';
//		}
//		// 当前位最大值不能大于0；
//		result += (char)(add % 10 + '0');
//		// 如果大于10，进1
//		add /= 10;
//		i--, j--;
//	}
//	//整体逆置
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
		// 初始化堆
		for (int i = len / 2 - 1; i >= 0; i--) {
			HeapAdjustDown(input, i, len - 1);
		}
		for (; k > 0; k--) {
			result.push_back(input[0]);
			int temp = input[len - 1];
			input[len - 1] = input[0];
			input[0] = temp;

			len--;
			//将arr[0...i-1]重新调整为最大堆
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
	char b;	// b 就是 a[0]
}tmp;

int main() {
	tmp.a = 1;
	if (tmp.b == 1) {
		cout << "计算机是小端字节序\n";
	}
	else {
		cout << "计算机是大端字节序\n";
	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

//凯撒密码加密解密算法（解密其实就是对加密过程中的密钥取负号，再次加密）
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

	cout << "请输入您想要加密的凯撒密码:\n";
	cin >> array;
	cout << "请输入您设置凯撒密码的移位间隔：\n";
	cin >> k;

	if (k > 25 || k < -25) {
		k %= 26;
	}
	KaiSa(array, k);
	cout << "进行凯撒加密后的密码为：\n";
	cout << array << endl;
	KaiSa(array, -k);
	cout << "进行凯撒解密后的密码为：\n";
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

