//设计一个日期类，包含以下功能：
//1、只能通过传入年月日初始化。
//2、可以加上一个数字n，返回一个该日期后推n天之后的日期。


#include "date.h"

int main_30() {
	//int year, delay;
	//_uint month, day;

	//cout << "请输入开始的年、月、日" << endl;
	//cin >> year >> month >> day;

	//Date test(year, month, day);

	//cout << "请输入间隔的天数" << endl;
	//cin >> delay;
	//cout << "最终的年、月、日为：" << endl;
	//if (delay >= 0) {
	//	cout << (test + delay) << endl;
	//}
	//else {
	//	delay *= -1;
	//	cout << test - delay << endl;
	//}

	int year_1, year_2;
	_uint month_1, day_1, month_2, day_2;
	cout << "请输入开始的年、月、日" << endl;
	cin >> year_1 >> month_1 >> day_1;
	Date test_1(year_1, month_1, day_1);
	cout << "请输入截至的年、月、日" << endl;
	cin >> year_2 >> month_2 >> day_2;
	Date test_2(year_2, month_2, day_2);

	cout << "总共间隔了" << (test_1 - test_2) << "天" << endl;

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