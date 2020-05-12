//标题:另类加法
//	请编写一个函数，将两个数字相加。不得使用 + 或其他算数运算符。
//
//	1, 2
//返回 : 3
//

#include <iostream>
using namespace std;

int main_1() {
	int A, B;
	cin >> A >> B;

	cout << A + B << endl;

	int sum = 0, carry = 0;
	while (B != 0) {
		//对应位的和
		sum = A ^ B;
		//对应位和的进位，既然是进位，就要整体左移一位 
		carry = (A & B) << 1;
		A = sum;
		B = carry;
	}
	cout << sum;
	return 0;
}


class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0, carry = 0;
		while (B != 0) {
			//对应位的和
			sum = A ^ B;
			//对应位和的进位，既然是进位，就要整体左移一位 
			carry = (A & B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};


//
// 标题:201301 JAVA 题目2 - 3级
//	请编写一个函数(允许增加子函数)，计算n x m的棋盘格子(n为横向的格子数，m为竖向的格子数)沿着各 
//自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，
//即 : 只能往右和往下走，不能往左 和往上走。
//输入描述 :
//   输入两个正整数
//   输出描述 : 返回结果
//	  示例1 :
//   输入
//	   2
//	   2
//	   输出
//	   6


#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> vv;

	int n, m;
	cin >> n >> m;
	vv.resize(m+1);
	for (auto& a : vv) {
		a.resize(n+1, 1);
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			vv[i][j] = vv[i - 1][j] + vv[i][j - 1];
		}
	}

	cout << vv[m][n] << endl;

	return 0;
}

#include<iostream>
using namespace std;

int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		//递归
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1))) 
		//终止条件
		return n + m;
	else
		//格子为0时， 路径为0
		return 0;
}
int main() {
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathNum(n, m) << endl;
	}
	return 0;
}