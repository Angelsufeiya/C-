#include <iostream>
using namespace std;

//1��дһ���������ӿڣ�����ɶ�������С�������� 
//2���ӿ��жഫ��һ��ȱʡ�����������ָ�����Ͳ���A����ʽ�����ָ���ˣ��Ͱ�����ѡ���������ʽ�����ٰ������֣���
//3���������Ļ����ϣ���ɶԽṹ�������ͨ�������жϴ�С�ĺ�����ʵ�֡�


void InsertSort(int* src, int n) {
	int i, j;
	int tmp;

	for (i = 1; i < n; i++) {
		tmp = src[i];
	}
	for (j = i; j < n; j++) {

	}
}

void sort(int* src, int n, int flag = 0) {
	switch (flag) {
	case 0:
		InsertSort(src, n);
		break;
	case 1:
		break;
	case 2:
		break;
	}
}

int main_() {
	int a[5] = { 5, 1, 4, 2, 3 };
	float b[5] = { 1.2, 5.7, 3.2, 2.6, 2.8 };

	sort(a, 5);
	return 0;
}
