//标题:Fibonacci数列
//Fibonacci数列是这样定义的 : 
//F[0] = 0 , F[1] = 1
//for each i ≥ 2 : F[i] = F[i - 1] + F[i - 2]
//因此，Fibonacci数列就形如 : 0, 1, 1, 2, 3, 5, 8, 13, ...，
//在Fibonacci数列中的数我们称为Fibonacci数。
//给你一 个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，
//现在给你一个数N求最少 需要多少步可以变为Fibonacci数。
//输入描述 :
//输入为一个正整数N(1 ≤ N ≤ 1, 000, 000) 
//输出描述 : 
//输出一个最小的步数变为Fibonacci数
//示例1:
//输入
//15
//输出
//2
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

int fib(int n){
	if (n < 2){
		return 1;
	}
	else{
		return fib(n - 1) + fib(n - 2);
	}
}
int main_0(){
	int input = 0;
	int n = 2;
	scanf("%d", &input);
	while (1){
		if (input > fib(n - 1) && input <= fib(n)){
			printf("%d\n", input - fib(n - 1) > fib(n) - input ? fib(n) - input : input - fib(n - 1));
			break;
		}
		else {
			n++;
		}
	}
	return 0;
}

int main__0() {
	int num = 0;
	scanf("%d", &num);
	int f1 = 0, f2 = 1, f3 = f1 + f2;
	while (1)
	{
		if (f2 == num)
		{
			printf("%d\n", 0);
			break;
		}
		else if (f2 > num)
		{
			if (abs(f2 - num) > abs(f1 - num))
			{
				printf("%d\n", abs(f1 - num));
			}
			else
			{
				printf("%d\n", abs(f2 - num));
			}
			break;
		}
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}
	return 0;
}

//编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数

int OneCountBinary(unsigned int n){
	int count = 0;
	while(n){
		if (n & 1){
			++count;
		}
		n = n >> 1;
	}
	return count;
}

int main_01(){
	int input;
	scanf("%d", &input);
	printf("%d", OneCountBinary(input));

	return 0;
}

//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

void reverseString(char* str, int size){
	int i;
	for (i = 0; i < size / 2; i++){
		char tmp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = tmp;
	}
}

int main_02(){
	char str[] = "hello";
	int len = strlen(str);
	
	reverseString(str, len);
	printf("%s", str);

	return 0;
}

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

void quickSort(int * a, int left, int right){
	int i, j, tmp, t;
	if (left > right){
		return;
	}
	tmp = a[left];
	i = left;
	j = right;
	while (i != j){
		while (a[j] >= tmp && i < j)
			--j;
		while (a[i] <= tmp && i < j)
			++i;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	a[left] = a[j];
	a[j] = tmp;
	quickSort(a, left, j - 1);
	quickSort(a, j + 1, right);
}

void quickSort_0(int * a, int left, int right){
	if (left > right)
		return;
	int key = a[left];
	int begin = left;
	int end = right;

	while (begin != end){
		while (begin < end && a[end] >= key)
			--end;
		a[begin] = a[end];
		while (begin < end && a[begin] <= key)
			++begin;
		a[end] = a[begin];
	}
	a[begin] = key;
	quickSort(a, left, end - 1);
	quickSort(a, end + 1, right);
}

int checkIsMoreThanHalf(int * arr, int result, int len){
	int i;
	int count = 0;
	
	for (i = 0; i < len; i++){
		if (arr[i] == result)
			++count;
	}
	if (count >(len - 1) / 2)
		return 1;
	else
		return 0;
}

int checkMoreThanHalf(int * arr){
	int len = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, len - 1);
	int mid = len / 2;
	int result = arr[mid];
	if (!checkIsMoreThanHalf(arr, result, len))
	{
		result = 0;
	}
	return result;
}

int MAX_Arry(int* arr, int sz)
{
	int MAX = arr[0];
	int sum = arr[0];
	int i = 1;

	//题目描述：数组里有正数也有负数（最少有两个数）
	if (arr == NULL || sz <= 1)
		return 0;
	for (i = 1; i < sz; i++)
	{
		if (sum < 0)
			sum = arr[i];
		else
		{
			sum += arr[i];
		}
		if (sum > MAX)
			MAX = sum;
	}
	return MAX; 
}
int main11() {
	int arr[] = { 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", MAX_Arry(arr, len));
	return 0;
}

#include<stdio.h> 

int main_13()
{
	int a;
	float b, c;

	scanf("%2d%3f%4f", &a, &b, &c);

	//printf("%d", printf("%d", a));
	printf("1: a=%d,c=%f\n", a, c);

	printf("2: a=%d,b=%d,c=%f\n", a, b, c);

	printf("3: a=%d,b=%.0f,c=%f\n", a, b, c);

	return 0;
}


//用户访问唯一实例的方法只有GetInstance()成员函数。
//如果不通过这个函数，任何创建实例的尝试都将失败，因为类的构造函数是私有的。
//GetInstance()使用 懒惰初始化，也就是说它的返回值是当这个函数首次被访问时被创建的 。
//这是一种防弹设计——所有GetInstance()之后的调用都返回相同实例的指针