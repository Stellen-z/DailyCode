#include "Date.h"


bool Date::CheckDate()
{
	if (_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month))
		return false;

	return true;
}

void Date::Print() const
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month) return true;
		else if (_month == d._month && _day < d._day) return true;
		else return false;
	}
	return false;
}
bool Date::operator<=(const Date& d) const
{
	return (*this < d) || (*this == d);
}
bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}
bool Date::operator==(const Date& d) const
{
	return this->_year == d._year &&
		this->_month == d._month &&
		this->_day == d._day;
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

//+=
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

//-=
Date& Date::operator-=(int day)
{
	while (_day < day)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}

	_day -= day;

	return *this;
}

//++
Date& Date::operator++()
{
	*this += 1;

	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;

	++(*this);

	return tmp;
}

//--
Date& Date::operator--()
{
	*this -= 1;

	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;

	--(*this);

	return tmp;
}

//天数 - 天数
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int cnt = 0;
	while (min != max)
	{
		++min;
		++cnt;
	}

	return cnt * flag;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" <<  d._day << "日" << endl;

	return out;
}
istream& operator>>(istream& in, Date& d)
{
	cout << "请输入日期" << endl;

	in >> d._year >> d._month >> d._day;
	if (!d.CheckDate())
	{
		cout << "日期非法" << endl;
	}

	return in;
}
