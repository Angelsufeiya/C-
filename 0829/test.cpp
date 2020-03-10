#include <iostream>
#include <cstring>
using namespace std;

//д���������ú������صķ�ʽ��д����ͳ�Ƴ�һ���������ṹΪ��׼�Ľṹ�������У�
//1������ΪX�ĳ����˶��ٴ�
//2������ΪX�ĳ����˶��ٴ�
//3���༶ΪX�ĳ����˶��ٴ�
//4���Ա��X�ĳ����˶��ٴ�

struct student {
	char name[32];
	int age;
	int classid;
	bool sex;
};

bool cmpEql(student a, student b) {
	return a.age == b.age;
}

//����ΪX�Ŀ�����������������(tip:���Կ�����ȱʡ�����ķ�ʽ�����߻ص������ķ�ʽʵ�֡�)
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
