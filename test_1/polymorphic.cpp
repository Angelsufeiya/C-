#include <iostream>
using namespace std;

class Person {
public:
	virtual void BuyTicket() { 
		cout << "��Ʊ-ȫ��" << endl; 
	}
};
class Student : public Person {
public:
	virtual void BuyTicket() { 
		cout << "��Ʊ-���" << endl; 
	} 
	//ע��:����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���ʱ����ȻҲ���Թ�����д
	//(��Ϊ�̳к������麯�����̳������������������ɱ����麯������)
	//���Ǹ���д�����Ǻܹ淶(��������Ķ��ϰ�)�����Բ���������ʹ�� 
	//void BuyTicket() { 
	//	cout << "��Ʊ-���" << endl; 
	//}
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main_10() {
	Person ps;
	Student st;
	Func(ps);
	Func(st);

	return 0;
}

//class Person {
//public:
//	virtual ~Person() { 
//		cout << "~Person()" << endl; 
//	}
//};
//class Student : public Person {
//public:
//	virtual ~Student() { 
//		cout << "~Student()" << endl; 
//	}
//};
//
//// ֻ��������Student������������д��Person�����������������delete��������������������ܹ��� 
//// ��̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
//int main_11()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};
//
//int main_13() {
//	Car* pBenz = new Benz;
//	pBenz->Drive();	// Benz-����
//	Car* pBMW = new BMW;
//	pBMW->Drive();	// BMW - �ٿ�
//	return 0;
//}


// ���ﳣ��һ��������:sizeof(Base)�Ƕ���? 
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};

//int main_12() {
//	cout << sizeof(Base);	// 8
//	return 0;
//}

// �������Ĵ��������������¸���
// 1.��������һ��������Deriveȥ�̳�Base
// 2.Derive����дFunc1
// 3.Base������һ���麯��Func2��һ����ͨ����Func3 
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};

//int main_13() {
//	Base b;
//	Derive d;
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//}; 
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main_14() {
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}


class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};

typedef void(*VFPTR) ();

void PrintVTable(VFPTR vTable[])
{
	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ����� 
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]); 
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

int main() {
	Base b;
	Derive d;
	// ˼·:ȡ��b��d�����ͷ4bytes����������ָ�룬ǰ������˵���麯��������һ�����麯��ָ���ָ�����飬
	//   ���������������һ��nullptr
	// 1.��ȡb�ĵ�ַ��ǿת��һ��int*��ָ��
	// 2.�ٽ�����ȡֵ����ȡ����b����ͷ4bytes��ֵ�����ֵ����ָ������ָ��
	// 3.��ǿת��VFPTR*����Ϊ������һ����VFPTR����(�麯��ָ������)�����顣
	// 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���
	// 5.��Ҫ˵�����������ӡ���Ĵ��뾭�����������Ϊ��������ʱ�����Ĵ����ɾ���
	//   ��������û�з�nullptr������Խ�磬���Ǳ����������⡣
	//   ����ֻ��Ҫ��Ŀ¼���� - ���� - �������������ٱ���ͺ��ˡ� 
	VFPTR * vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	return 0;
}