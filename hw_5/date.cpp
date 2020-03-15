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

Date Date::operator + (_uint delay) const {
	Date res = *this;
	_uint tmp;

#if 0
	int num_y = delay / 365;
	int num_d = delay % 365;
	int flag = 0;

	if (res.m_month > 2) {
		flag = 1;
	}
	
	int leapNum = getLeapNum(res.m_year + 1, res.m_year + num_y);

	while (num_d < leapNum){
		--num_y;
		leapNum = getLeapNum(res.m_year + 1, res.m_year + num_y);
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
	if (res.m_day > tmp) {
		res.m_day -= tmp;
		res.m_month++;

		if (res.m_month > 12) {
			res.m_month = 1;
			res.m_year++;
		}
	}
	return res;
}

ostream & operator << (ostream & os, const Date & d) {
	os << d.m_year << '-' << d.m_month << '-' << d.m_day;
	return os;
}

//得到闰年个数（目前本方法百年会有问题）
int getLeapNum(int sy, int ey) {
	//将sy处理为包括自身之后的第一个闰年
	int tmp = sy % 4;
	if (tmp) {
		sy += 4 - tmp;
	}
	return (ey - sy) / 4 + 1 ;
	/*int count = 0;
	while (sy <= ey) {
		if (((sy % 4 == 0) && (sy % 100)) || (sy % 400 == 0)) {
			++count;
		}
		++sy;
	}*/
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
