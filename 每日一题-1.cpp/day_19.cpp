//题目：汽水瓶 (牛客网测试没有通过）
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print(int a){
	int count = 0;
	int lid = a;
	int tmp;
	while (lid >= 2){
		tmp =lid / 3;
		count += tmp;
		lid = tmp + lid % 3;
		if (lid == 2){
			count++;
			break;
		}
	}
	printf("%d\n", count);
}

int main_190(){
	int i, input;
	int count = 0;
	char str[20] = { 0 };
	do{
		scanf("%d", &input);
		str[count] = input;
		count++;
		if(count == 12){
			break;
		}
	} while (input);
	for (i = 0; i < count - 1; i++){
		print(str[i]);
	}
	return 0;
}

//题目：查找两个字符串a,b中的最长字符串

int main_19(){
	char str1[1000] = { 0 };
	char str2[1000] = { 0 };
	scanf("%s%s", str1, str2);

	return 0;
}