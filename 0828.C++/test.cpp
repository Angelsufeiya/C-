#include <iostream>
using namespace std;
//�ṹ��Ƕ��

struct A1{
	int a;
	double b;
};
//�ṹ�� 16
struct A2{
	A1 a;
	char b;
};
//�ṹ�� 24

class ct{
	int a;
public:
	double b;
	char c;

	void changeA(int i){
		i = 5;
	}
	void printA(){ //��Ա�����п���ֱ��ʹ���Լ��ĳ�Ա����
		printf("%d\n", a);
	}

	void printB();
};

struct A3{
	int a;
	double b;
	char c;

	void printA(){ //��Ա�����п���ֱ��ʹ���Լ��ĳ�Ա����
		printf("%d\n", a);
	}

	void printB();
};
//�ṹ�� 24

void A3::printB(){
	printf("%.21f\n", b);
}

struct A4{
	int a;
	char c;
	double b;
};
//�ṹ�� 16 ��int + char < double)
//�ṹ�����д �����С������ߴӴ�С����

int main0(){
	printf("%d %d %d %d", sizeof(A1), sizeof(A2), sizeof(A3), sizeof(A4));

	A3 test;
	printf("%p %p %p", test.a, test.b, test.c);

	test.a = 5;
	test.printA();
	test.b = 3.14;
	test.printB();

	return 0;
};

int main(){
	ct c;

	c.changeA = 4;
	c.printA();

	return 0;
}