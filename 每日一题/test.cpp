//标题:替换空格
//请实现一个函数，将一个字符串中的每个空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//using namespace std;
//#include <string>

//class Solution {
//public:
//	void replaceSpace(char *str, int length) { // 计算空格的个数
//		int space_num = 0;
//		for (int i = 0; i < length; ++i)
//		{
//			if (str[i] == ' ')
//				space_num++;
//		}
//		// 从后往前，依次挪动字符，遇到空格替换为%20 
//		for(int i = length-1; i >= 0; --i)
//		{
//			if (str[i] == ' ')
//			{
//				space_num--;
//				str[i + space_num * 2] = '%';
//				str[i + space_num * 2 + 1] = '2';
//				str[i + space_num * 2 + 2] = '0';
//			}
//			else
//			{
//				str[i + space_num * 2] = str[i];
//			} 
//		}
//	}
//};

//输入一个字符串，求出该字符串包含的字符集合
//输入描述 :
//每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。
//输出描述 :
//每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
//
//#include <iostream>
//using namespace std;

//int main_0() {
//	string s;
//	cin >> s;
//	char str[256] = { 0 };
//
//	for (int i = 0; i < s.size(); ++i) {
//		if (!str[s[i]]) {
//			cout << s[i];
//		}
//		str[s[i]] = 1;
//	}
//
//	return 0;
//}

//有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，
//例如，原数组为[1, 2, 3, 4, 5, 6]，向左移位5个位置即变成了[6, 1, 2, 3, 4, 5], 
//现在对于移位后的数组，需要查找某个元素的位置。请设计一个复杂度为log级别的算法完成这个任务。
//给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，
//请返回x的位置(位置从零开始)。保证数组中元素互异。



#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	multiset<int> data;

	int sum = 0;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		data.insert(tmp);
	}
	while (data.size() > 1)
	{
		tmp = 0;
		tmp += *data.begin();
		data.erase(data.begin());
		tmp += *data.begin();
		data.erase(data.begin());
		data.insert(tmp);
		sum += tmp;
	}
	cout << sum;
	return 0;
}


#include <iostream>
#include <set>

using namespace std;
int luogu1090()
{
	int n;
	cin >> n;
	multiset<int> data;
	multiset<int>::iterator is;
	int sum = 0;
	int i;
	int tmp;
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		data.insert(tmp);
	}
	while (data.size() > 1)
	{
		tmp = 0;
		is = data.begin();
		tmp += *is;
		data.erase(is);
		is = data.begin();
		tmp += *is;
		data.erase(is);
		data.insert(tmp);
		sum += tmp;
	}
	cout << sum;
	return 0;
}
