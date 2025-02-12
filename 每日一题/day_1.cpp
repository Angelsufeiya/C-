//标题:组队竞赛
//牛牛举办了一次编程比赛, 参加比赛的有3*n个选手, 每个选手都有一个水平值a_i.
//现在要将这些选手进行组队, 一 共组成n个队伍, 即每个队伍3人.
//牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
//例如 :
//一个队伍三个队员的水平值分别是3, 3, 3.那么队伍的水平值是3 
//一个队伍三个队员的水平值分别是3, 2, 3.那么队伍的水平值是3 
//一个队伍三个队员的水平值分别是1, 5, 2.那么队伍的水平值是2 
//为了让比赛更有看点, 牛牛想安排队伍使所有队伍的水平值总和最大。 如样例所示 :
//如果牛牛把6个队员划分到两个队伍
//如果方案为 :
//team1 : {1, 2, 5}, team2 : {5, 5, 8}, 这时候水平值总和为7.
//而如果方案为 :
//team1 : {2, 5, 8}, team2 : {1, 5, 5}, 这时候水平值总和为10.
//输入描述 :
//	 输入的第一行为一个正整数n(1 ≤ n ≤ 10 ^ 5)
//	 第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10 ^ 9), 表示每个参赛选手的水平值.
//输出描述 :
//	 输出一个整数表示所有队伍的水平值总和最大值.
//示例1 :
//	 输入
//	 2 
//	 5 2 8 5 1 5 
//	 输出
//	 10
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main_0() {
	int n;

	while (cin >> n) {
		int i;
		long long sum = 0;
		vector<int> a_i;
		a_i.resize(3 * n);
		for (i = 0; i < 3 * n; i++) {
			cin >> a_i[i];
		}

		std::sort(a_i.begin(), a_i.end());

		for (i = n; i < 3 * n; i += 2)
		{
			sum += a_i[n];
		}
		cout << sum << endl;
	}
	return 0;
}


//标题:删除公共字符
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，
//则删除之后的第一个字符串变成”Thy r stdnts.”
//输入描述 :
//每个测试输入包含2个字符串 
//输出描述 : 输出删除后的字符串
//示例1 :
//输入
//They are students.
//aeiou
//输出
//Thy r stdnts.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;

	getline(cin, s1);
	getline(cin, s2);

	// 使用哈希映射思想先str2统计字符出现的次数
	char arr[256] = { 0 };

	for (auto i : s2) {
		arr[i] = 1;
	}
	string str;
	//注意这里最好不要str1.erases(i) (因为边遍历，边erase，容易出错。)
	for (auto i : s1) {
		if (!arr[i]) {
			str += i;
		}
	}

	cout << str;

	return 0;
}
