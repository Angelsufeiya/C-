//标题:计算糖果
//A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上具体有多少个糖果,
//但是我们知道 以下的信息 :
//A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
//现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。
//这里保证最多只有一组整数A, B, C满足所 有题设条件。
//输入描述 :
//输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 
//范围均在 - 30到30之间(闭区间)。
//输出描述 :
//输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。
//如果不存在 这样的整数A，B，C，则输出No
//示例1 :
//输入
//1 -2 3 4
//输出
//2 1 3

#include<iostream>
using namespace std;

int main_40() {
	int num1, num2, num3, num4;
	cin >> num1 >> num2 >> num3 >> num4;

	int A, B, C;
	//num1 + num2 == num3 - num4;
	A = (num1 + num3) / 2;
	B = (num2 + num4) / 2;
	C = B - num2;
	if (A - B == num1 && B - C == num2 && A + B == num3 && B + C == num4)
		cout << A << ' ' << B << ' ' << C << endl;
	else
		cout << "No";

	return 0;
}


//标题 : 进制转换
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
//输入描述 :
//输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
//输出描述 :
//为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制
//(比如，10 用A表示，等等)
//示例1 :
//输入
//7 2
//输出
//111

#include <iostream>
#include <string>
using namespace std;

int main() {
	string res, table = "0123456789ABCDEF";
	int M, N;
	cin >> M >> N;

	if (M < 0) {
		cout << '-';
		M = 0 - M;
	}
	while (M) {
		res.push_back(table[M % N]);
		M /= N;
	}

	for (auto i = res.size(); i > 0; i--) {
		cout << res[i - 1];
	}

	return 0;
}

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main1()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;

	bool flag = false;
	// 如果是负数，则转成正数，并标记一下 
	if(m < 0)
	{
		m = 0 - m;
		flag = true; }
	// 按进制换算成对应的字符添加到s 
	while(m)
	{
		s += table[m % n];
		m /= n; 
	}
	if (flag)
		s += '-';

	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}