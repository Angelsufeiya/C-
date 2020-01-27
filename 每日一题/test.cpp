//标题:替换空格
//请实现一个函数，将一个字符串中的每个空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
	void replaceSpace(char *str, int length) { // 计算空格的个数
		int space_num = 0;
		for (int i = 0; i < length; ++i)
		{
			if (str[i] == ' ')
				space_num++;
		}
		// 从后往前，依次挪动字符，遇到空格替换为%20 
		for(int i = length-1; i >= 0; --i)
		{
			if (str[i] == ' ')
			{
				space_num--;
				str[i + space_num * 2] = '%';
				str[i + space_num * 2 + 1] = '2';
				str[i + space_num * 2 + 2] = '0';
			}
			else
			{
				str[i + space_num * 2] = str[i];
			} 
		}
	}
};
