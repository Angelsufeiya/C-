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

int main() {
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