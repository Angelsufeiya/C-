#include <iostream>
using namespace std;

//对字符串进行RLE压缩，将相邻的相同字符，用计数值和字符值来代替。
//例如：aaabccccccddeee，则可用3a1b6c2d3e来代替。

void Compress(char *str) {
	int count = 1;
	while (*str) {
		if (*str == *(str + 1)) {
			++count;
			str++;
		}
		else {
			cout << count << *str;
			count = 1;
			str++;
		}
	}
}


int main_2() {
	char array[1000] = { 0 };

	cout << "请输入您要压缩的字符串：";
	cin >> array;
	Compress(array);

	return 0;
}