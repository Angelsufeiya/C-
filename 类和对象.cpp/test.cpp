#include <iostream>//iostream ������/��������׼�ļ� 
using namespace std;

// Ĭ�Ϲ��캯�� 
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

// ���²��Ժ�����ͨ��������? 
void Test()
{
	Date d1;//��Date �а������Ĭ�Ϲ��캯��
}


//// ���м��г�Ա���������г�Ա����
//class A1 {
//public:
//	void f1(){}
//private:
//	int _a;
//};
//// ���н��г�Ա���� 
//class A2 { public:
//void f2() {}
//};
//// ����ʲô��û��---���� 
//class A3
//{};
//
//int main(){
//	cout << sizeof(A1) << ' ' << sizeof(A2) << ' ' << sizeof(A3) << endl;
//	return 0;
//}

// 1.��������ܱ���ͨ����?
// 2.�������������?��������� 
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void Show() {
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	A* p = NULL;
//	p->PrintA();
//	p->Show();
//}
