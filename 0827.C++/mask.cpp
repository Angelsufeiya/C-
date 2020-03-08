//1���ֱ�ʹ�����úͺ���ɽ���������ʹ�������������������ͬ
#define Swap1(a,b) {a=a+b;b=a-b;a=a-b;}

void Swap2(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

//2������ָ���ĺ�����������ɺ�����

//��һ���ַ���ת��Ϊ���֣�����ֵ����У��ת���Ƿ�ɹ�
#include <iostream>
using namespace std;

bool strtoi(const char* str, int& res) {
	if (!str) {
		return false;
	}
	while (*str < ' ') {
		str++;
	}

	int flag = 1;

	if (*str == '-') {
		flag = -1;
		str++;
	}

	if ((*str > '9') || (*str < '0')) {
		return false;
	}

	int sum = 0;
	int i, tmp;
	for (i = 0; str[i] <= '9' && str[i] >= '0'; i++) {
		tmp = str[i] - '0';
		sum = sum * 10 + tmp;
	}

	res = sum * flag;
	return true;
}

//b����һ������ͨ��ָ�����ư�λ����ֱ�Ӹ���ԭ����
void sysReverse(int &num, int hex) {
	int i;
	int tmp, sum = 0;
	for (i = num; i; i /= hex) {
		tmp = i % hex;
		sum = sum * hex + tmp;
	}
	num = sum;
}

int main_30() {
	int num = 20;//10100
	int res;

	sysReverse(num, 2);
	cout << num << endl;

	if (strtoi("-1a27", res)) {
		cout << res << endl;
	}
	else {
		cout << "false\n" << endl;
	}

	return 0;
}