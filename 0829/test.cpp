#include <iostream>
#include <cstring>
using namespace std;

//写出函数，用函数重载的方式编写程序，统计出一个以上述结构为基准的结构体数组中：
//1、名字为X的出现了多少次
//2、年龄为X的出现了多少次
//3、班级为X的出现了多少次
//4、性别的X的出现了多少次

struct student {
	char name[32];
	int age;
	int classid;
	bool sex;
};

bool cmpEql(student a, student b) {
	return a.age == b.age;
}

//名字为X的可以是这样的声明：(tip:可以考虑用缺省参数的方式，或者回调函数的方式实现。)
int countName(student* src, int n, student Value, bool(*cmp)(student, student) = cmpEql) {
	int i;
	int count = 0;

	for (i = 0; i < n; i++) {
		if (cmp(src[i], Value)) {
			++count;
		}
	}

	return count;
}

bool cmpEqlname(student a, student b) {
	return strcmp(a.name, b.name) ? false : true;
}

bool cmpEqlsex(student a, student b) {
	//return a.sex == b.sex;
	return !(a.sex ^ b.sex);
}

int main_0() {
	student st[] = { {"libing", 21, 1, true},
					{"qiaobiluo", 58, 0, false},
					{"yangli", 21, 1, true},
					{"wujidong", 20, 1, true},
					{"caixukun", 24, 0, true},
					{"lubenwei", 32, 0 ,true},
					{"luhan", 24, 0, true}
	};

	student test = { "caixukun", 24, 0, true };

	cout << countName(st, 7, test, cmpEqlsex) << endl;

	return 0;
}
