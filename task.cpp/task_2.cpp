#include <iostream>
using namespace std;

//���ַ�������RLEѹ���������ڵ���ͬ�ַ����ü���ֵ���ַ�ֵ�����档
//���磺aaabccccccddeee�������3a1b6c2d3e�����档

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

	cout << "��������Ҫѹ�����ַ�����";
	cin >> array;
	Compress(array);

	return 0;
}