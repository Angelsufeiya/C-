#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    // bool operator==(Date* this, const Date& d2)
//    // ������Ҫע����ǣ����������thisָ��ĵ��ú����Ķ��� 
//    bool operator==(const Date& d2)const
//    {
//        return _year == d2._year && _month == d2._month && _day == d2._day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//void Test() {
//    Date d1(2018, 9, 26);
//    Date d2(2018, 9, 27);
//    cout << (d1 == d2) << endl;
//}
//
//int main() {
//    Test();	// ��� 0
//
//    return 0;
//}

class Date {
public:
	Date(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d) {
		_year = d._year;
	}
	//void display() const {     // �൱�� void display(const Date* const this)
	//	cout << _year << "display() const" << endl; // �ɶ�
	//}

	void display() {
		cout << _year << "display()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main() {
	Date d1(2019, 4, 1);             // ��ͨ����
	const Date d2(2019, 3, 31);      // const����
	d1.display();
	d2.display();

	return 0;
}

