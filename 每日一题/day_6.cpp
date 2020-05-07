//标题:不要二
//二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。
//每个格子至多可以放一 块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为 
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。 
//输入描述 :
//每组数组包含网格长宽W, H，用空格分割.(1 ≤ W、H ≤ 1000) 
//输出描述 :
//输出一个最多可以放的蛋糕数
//示例1: 
//输入 
//3 2 
//输出
//4

#include<iostream>
#include<vector>
using namespace std;

int main_1(){
	int W, H, res = 0;
	cin >> W >> H;	// H 表示行， W 表示列

	// 直接暴力计算，默认所有蛋糕的位置标记成1,不能放的地方标记成0
	vector<vector<int>> vv;
	vv.resize(H);
	for (auto& e : vv)
		e.resize(W, 1);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (vv[i][j] == 1)
			{
				res++;
				// 标记不能放蛋糕的位置 
				if ((i + 2) < H)
					vv[i + 2][j] = 0;
				if ((j + 2) < W)
					vv[i][j + 2] = 0;
			}
		}
	}
	cout << res;
	
	return 0;
}

// 默认所有蛋糕的位置标记成1,不能放的地方标记成0 
// 1 1 0 0 1 1
// 1 1 0 0 1 1
// 0 0 1 1 0 0
// 0 0 1 1 0 0

#include <iostream>
using namespace std;

int main_2()
{
	int a, b;

	cin >> a >> b;

	int x, y;

	int suba = 4 - (a % 4 ? a % 4 : 4);	// 长差 suba 为4的倍数
	int subb = 4 - (b % 4 ? b % 4 : 4);	// 宽差 subb 为4的倍数
	x = a + suba;	// 使 x 在加上suba后为4的倍数
	y = b + subb;	// 使 y 在加上subb后为4的倍数

	int sum = x * y / 2;	// 计算长宽都扩容至4的倍数后sum的大小

	sum -= suba * (x / 2) + subb * (y / 2);	// 减去增容的长与宽的一半，但这样会造成多减去蛋糕数量

	if (suba == 0 || subb == 0)	// 长或者宽只要有一个是4的倍数，经过上面算式后，可直接输出
	{
		//do nothing
	}
	else if (suba == 1 && subb == 1)
	{
		sum++;	// 示例 长宽皆为3，
	}
	else if (suba == 1 || subb == 1)
	{
		sum += 2;	// 示例 长3，宽2
	}
	else if (suba == 3 && subb == 3)
	{
		sum += 5;	// 示例 长1，宽1
	}
	else 
	{
		sum += 4;
	}

	cout << sum;

	return 0;
}



//标题:把字符串转换成整数
//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
//但是string不符合数字要求时返回0)，要求 不能使用字符串转换整数的库函数。 
//数值为0或者字符串不是一个合法的数值则返回0。
//输入描述: 
//输入一个字符串, 包括数字字母符号, 可以为空 
//输出描述 : 
//如果是合法的数值表达则返回该数字，否则返回0 
//示例1 :
//输入
//+2147483647
//1a33
//输出
//2147483647
//0

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;

		int symbol;
		if (str[0] == '+') {
			symbol = 1;
			str[0] = '0';
		}

		if (str[0] == '-') {
			symbol = -1;
			str[0] = '0';
		}

		int res = 0;
		if (str[0] >= '0' && str[0] <= '9') {
			for (auto e : str) {
				if (e < '0' || e > '9') {
					return 0;
				}
				else {
					res = res * 10 + e - '0';
				}
			}
		}

		return symbol * res;
	}
};

int main_3() {
	Solution s;
	string ss;
	cin >> ss;
	s.StrToInt(ss);

	return 0;
}