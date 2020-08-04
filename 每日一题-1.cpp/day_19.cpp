//题目：汽水瓶
#if 0
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
#endif

//题目：查找两个字符串a,b中的最长字符串
#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string bestLongString(string s1, string s2) {
	// 短的字符串为s1
	if (s1.size() > s2.size()) {
		swap(s1, s2);
	}

	int len1 = s1.size(), len2 = s2.size();
	int start = 0, max = 0;

	vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 0; i < len1; ++i) {
		for (int j = 0; j < len2; ++j) {
			if (s1[i] == s2[j]) {
				MCS[i + 1][j + 1] = MCS[i][j] + 1;
			}
			//如果有更长的公共子串，更新长度
			if (MCS[i + 1][j + 1] > max) {
				max = MCS[i + 1][j + 1];
				//以i结尾的最大长度为max, 则子串的起始位置为i - max
				start = i - max;
			}
		}
	}
	return s1.substr(start, max);
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		cout << bestLongString(s1, s2) << endl;
	}
	return 0;
}
#endif