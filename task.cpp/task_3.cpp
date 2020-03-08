#include <iostream>
using namespace std;

//删除字符串首尾空格，中间的连续空格只留一个，原来字符串的顺序不变。

void Deblank(char * str) {
	int flag = 0;	//代表没开始处理空格
	int p = 0;
	int i = 0;
	while (str[i]) {
		//遇到空格 还没开始处理
		if (!flag && str[i] == ' ') {
			i++;
		}
		//遇到不是空格 还没开始处理
		else if (!flag && str[i] != ' ') {
			flag = 1;
			str[p++] = str[i++];
		}
		//遇到空格 开始处理了
		else if (flag && str[i] == ' ') {
			flag = 0;
			str[p++] = str[i++];
		}
		//遇到不是空格 开始处理了
		else //if(flag && str[i] != ' ')
		{
			flag = 1;
			str[p++] = str[i++];
		}
	}

	if (str[p - 1] == ' ') {
		str[p - 1] = '\0';
	}
	else
		str[p] = '\0';
}

int main() {
	char array[] = "  asadad   q    ";

	Deblank(array);
	cout << array << endl;

	return 0;
}