#include <iostream>
using namespace std;

//1、写一个排序函数接口，能完成对整数和小数的排序。 
//2、接口中多传入一个缺省参数，如果不指定，就采用A排序方式，如果指定了，就按他的选择决定排序方式（至少包含三种）。
//3、在上述的基础上，完成对结构体的排序。通过传入判断大小的函数来实现。

//void InsertSort(int* src, int n) {
//	int i, j;
//	int tmp;
//
//	for (i = 1; i < n; i++) {
//		tmp = src[i];
//		for (j = i; j > 0 && src[j - 1] > tmp; j--) {
//			src[j] = src[j - 1];
//		}
//		src[j] = tmp;
//	}
//	
//}

void InsertSort(double* src, int n) {
	int i, j;
	double tmp;

	for (i = 1; i < n; i++) {
		tmp = src[i];
		for (j = i; j > 0 && src[j - 1] > tmp; j--) {
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}

}

bool cmpnum(int a, int b) {
	return a < b;
}
bool cmpwaytest(int a, int b)
{
	return a > b;
}

void InsertSort(int* src, int n, bool(*cmp)(int, int)) {
	int i, j;
	int tmp;

	for (i = 1; i < n; i++) {
		tmp = src[i];
		for (j = i; j > 0 && cmp(tmp, src[j - 1]); j--) {
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}

}

void sort(int* src, int n, int flag = 0) {
	switch (flag) {
	case 0:
		InsertSort(src, n, cmpnum);
		break;
	case 1:
		break;
	case 2:
		break;
	}
}

int main_1() {
	int a[5] = { 5, 1, 4, 2, 3 };
	double b[5] = { 1.2, 5.5, 3.2, 2.6, 2.8 };

	InsertSort(a, 5, cmpnum);
	InsertSort(b, 5);

	for (auto i : a) {
		cout << i << endl;
	}
	for (auto i : b) {
		cout << i << endl;
	}

	return 0;
}