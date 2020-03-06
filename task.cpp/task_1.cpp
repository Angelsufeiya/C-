#include <iostream>
using namespace std;

//编写一个加密解密程序实现凯撒密码

//凯撒密码加密解密
void KaiSa(char * str, int k) {
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

int main_1() {
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