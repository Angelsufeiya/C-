#pragma once

#include <iostream>
using namespace std;

typedef unsigned int _uint;

// .h�ļ��������������.cpp�ļ��������ʵ��
class Date {
	int m_year;
	_uint m_month;
	_uint m_day;
public:
	Date(int y, _uint m, _uint d) :
		m_year(y),
		m_month(m),
		m_day(d)
	{
	}

	Date operator + (_uint delay) const;

	bool operator > (const Date & d) const;
	bool operator < (const Date & d) const;
	bool operator >= (const Date & d) const;
	bool operator <= (const Date & d) const;
	bool operator == (const Date & d) const;
	bool operator != (const Date & d) const;

	friend ostream & operator << (ostream & os, const Date & d);
};