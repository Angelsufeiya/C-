#include <iostream>
using namespace std;

//��дһ�����ܽ��ܳ���ʵ�ֿ�������

//����������ܽ���
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

	cout << "����������Ҫ���ܵĿ�������:\n";
	cin >> array;
	cout << "�����������ÿ����������λ�����\n";
	cin >> k;

	if (k > 25 || k < -25) {
		k %= 26;
	}
	KaiSa(array, k);
	cout << "���п������ܺ������Ϊ��\n";
	cout << array << endl;
	KaiSa(array, -k);
	cout << "���п������ܺ������Ϊ��\n";
	cout << array << endl;

	return 0;
}