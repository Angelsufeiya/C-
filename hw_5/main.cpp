//���һ�������࣬�������¹��ܣ�
//1��ֻ��ͨ�����������ճ�ʼ����
//2�����Լ���һ������n������һ�������ں���n��֮������ڡ�


#include "date.h"

int main_30() {
	//int year, delay;
	//_uint month, day;

	//cout << "�����뿪ʼ���ꡢ�¡���" << endl;
	//cin >> year >> month >> day;

	//Date test(year, month, day);

	//cout << "��������������" << endl;
	//cin >> delay;
	//cout << "���յ��ꡢ�¡���Ϊ��" << endl;
	//if (delay >= 0) {
	//	cout << (test + delay) << endl;
	//}
	//else {
	//	delay *= -1;
	//	cout << test - delay << endl;
	//}

	int year_1, year_2;
	_uint month_1, day_1, month_2, day_2;
	cout << "�����뿪ʼ���ꡢ�¡���" << endl;
	cin >> year_1 >> month_1 >> day_1;
	Date test_1(year_1, month_1, day_1);
	cout << "������������ꡢ�¡���" << endl;
	cin >> year_2 >> month_2 >> day_2;
	Date test_2(year_2, month_2, day_2);

	cout << "�ܹ������" << (test_1 - test_2) << "��" << endl;

	return 0;
}


int main_0() {
	char* pa = new char[1024];
	size_t size = 0;

	Date* pd = new(pa + size)Date(2020, 01, 16);

	pd->~Date();
	delete pa;

	return 0;
}