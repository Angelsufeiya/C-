#include "date.h"

static _uint getMonthDay(int y, _uint m) {
	if (m > 12 || m == 0) {
		return 0;
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
	else if (m == 2) {
		return 28 + (((y % 100) && !(y % 4)) || !(y % 400));
	}
	else
		return 31;
}

//得到闰年个数(优化算法）
int getLeapNum(int sy, int ey) {
	int count = 0;
	while (sy <= ey) {
		if (((sy % 4 == 0) && (sy % 100)) || (sy % 400 == 0)) {
			++count;
		}
		++sy;
	}
	return count;
}

Date Date::operator + (_uint delay) const {
	Date res = *this;
	_uint tmp;

#if 1
	//优化算法
	int num_y = delay / 365;
	int num_d = delay % 365;
	int flag = 0;

	if (res.m_month > 2) {
		flag = 1;
	}
	
	int leapNum = getLeapNum(res.m_year + flag, res.m_year + num_y);

	while (num_d < leapNum){
		--num_y;
		leapNum = getLeapNum(res.m_year + flag, res.m_year + num_y);
		num_d += 365;
	}
	num_d -= leapNum;

	res.m_year += num_y;
	delay = num_d;
#endif
	tmp = getMonthDay(res.m_year, res.m_month);
	while (delay >= tmp) {
		delay -= tmp;
		res.m_month++;
		if (res.m_month > 12) {
			res.m_month = 1;
			res.m_year++;
		}
		tmp = getMonthDay(res.m_year, res.m_month);
	}

	res.m_day += delay;

	//不用if是因为存在1月31号，加30天这种特殊情况
	while (res.m_day > tmp) {
		res.m_day -= tmp;
		res.m_month++;
		tmp = getMonthDay(res.m_year, res.m_month);

		if (res.m_month > 12) {
			res.m_month = 1;
			res.m_year++;
		}
	}
	return res;
}

Date Date::operator - (_uint delay) const {
	Date res = *this;
	_uint tmp;

	//存在3月31号，-30天这种特殊情况
	if (delay < res.m_day) {
		res.m_day -= delay;
		return res;
	}

	if (res.m_month == 1) {
		res.m_year--;
		res.m_month = 12;
	}
	else {
		res.m_month--;
	}

	tmp = getMonthDay(res.m_year, res.m_month);
	while (delay >= tmp) {
		delay -= tmp;

		if (res.m_month == 1) {
			res.m_year--;
			res.m_month = 12;
		}
		else {
			res.m_month--;
		}

		tmp = getMonthDay(res.m_year, res.m_month);
	}

	int tmpday = res.m_day - delay;

	if (tmpday <= 0) {
		tmpday += tmp;
	} 
	else {
		res.m_month++;

		if (res.m_month > 12) {
			res.m_month = 1;
			res.m_year++;
		}
	}
	res.m_day = tmpday;

	return res;
}

_uint Date::getDayOfYear() {
	_uint i, days = 0;

	for (i = 1; i < m_month; i++) {
		days += getMonthDay(m_year, i);
	}

	return days + m_day;
}

int Date::operator - (const Date& d) const {
	Date bigger = *this;
	Date smaller = d;
	int flag = 1;
	if (*this < d) {
		bigger = d;
		smaller = *this;
		flag = -1;
	}
	int years = bigger.m_year - smaller.m_year;
	int days = years * 365 + getLeapNum(smaller.m_year, bigger.m_year - 1);

	days = days - smaller.getDayOfYear() + bigger.getDayOfYear();
	return days * flag;
}

ostream & operator << (ostream & os, const Date & d) {
	os << d.m_year << '-' << d.m_month << '-' << d.m_day;
	return os;
}

bool Date:: operator > (const Date& d) const {
	if (m_year > d.m_year) {
		return true;
	}
	if (m_year == d.m_year && m_month > d.m_month) {
		return true;
	}
	if (m_year == d.m_year && m_month == d.m_month && m_day > d.m_day) {
		return true;
	}
	return false;
}

bool Date:: operator < (const Date& d) const {
	if (m_year < d.m_year) {
		return true;
	}
	if (m_year == d.m_year && m_month < d.m_month) {
		return true;
	}
	if (m_year == d.m_year && m_month == d.m_month&& m_day < d.m_day) {
		return true;
	}
	return false;
}

bool Date:: operator >= (const Date& d) const {
	return !(*this < d);
}

bool Date:: operator <= (const Date& d) const {
	return !(*this > d);
}

bool Date:: operator != (const Date& d) const {
	return (*this > d) || (*this < d);
}

bool Date:: operator == (const Date& d) const {
	return !(*this != d);
}
