#include "Date.h"

bool Date::CheckDate()
{
	if (_month < 1 || _month > 12
		|| _day < 1 || _day > GetMonthDay(_year, _month))
		return false;

	return true;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if (!CheckDate())
	{
		cout << "非法日期：" << endl;
		Print();
	}
}

void Date::Print()
{
	cout << _year << " " << _month << " " << _day << endl;
}

bool Date::operator<(const Date & d) const
{
	if (_year != d._year) return _year < d._year;
	if (_month != d._month) return _month < d._month;
	return _day < d._day;
}
bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}
bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d) const
{
	return *this > d || *this == d;
}
bool Date::operator==(const Date& d) const
{
	return _year == d._year &&
		_month == d._month &&
		_day == d._day;
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

//d1 += 天数
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
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

Date Date::operator+(int day) const
{
	//调用拷贝构造
	Date tmp = *this;

	tmp += day;

	return tmp;
}


//d1 -= 天数
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}

	while (_day <= day)
	{
		//_month--;
		--_month;
		if (_month == 0) 
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}

	_day -= day;

	return *this;

	//if(_day > GetMonthDay(_year, _month))
	//{
	//	_day -= GetMonthDay(_year, _month);
	//	_month++;
	//	if (_month == 13)
	//	{
	//		_year++;
	//		_month = 1;
	//	}
	//}


	//*this = *this - day;
	//return *this;
}


Date Date::operator-(int day) const
{
	Date tmp = *this;

	tmp -= day;

	return tmp;
}

//d1 - d2
int Date::operator-(const Date& d) const
{
	//Date tmp1(_year);
	//Date tmp2(d._year);

	//int numsday = 0;

	////计算月份天数
	//for (int i = _year; i <= d._year; i++)
	//{
	//	numsday += 365;

	//	if ((_month == 2) &&
	//		((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)))
	//		numsday++;
	//}

	//while (tmp1 < *this)
	//{
	//	numsday += GetMonthDay(tmp1._year, tmp1._month);
	//	tmp1._month++;
	//}

	//while (tmp2 < d)
	//{
	//	numsday += GetMonthDay(tmp2._year, tmp2._month);
	//	tmp2._month++;
	//}

	//return numsday;

	int flag = 1;
	Date min = d, max = *this;
	if (*this < d)
	{
		min = *this;
		max = d;
		flag = -1;
	}

	int numsday = 0;
	while (min != max)
	{
		++min;
		++numsday;
	}

	return numsday * flag;
}


//++d1
Date& Date::operator++() 
{
	//++_day;
	//if (_day > GetMonthDay(_year, _month))
	//{
	//	_month++;
	//	if (_month == 13)
	//	{
	//		_year++;
	//		_month = 1;
	//	}
	//	_day = 1;
	//}

	//return *this;

	*this += 1;

	return *this;
}

//d1++
Date Date::operator++(int)
{
	Date tmp = *this;

	++(*this);

	return tmp;

}


//--d1
Date& Date::operator--()
{
	//--_day;
	//if (_day == 0)
	//{
	//	_month--;
	//	if (_month == 0)
	//	{
	//		_year--;
	//		_month = 12;
	//	}
	//	_day = GetMonthDay(_year, _month);
	//}

	//return *this;


	*this -= 1;

	return *this;
}

//d1--
Date Date::operator--(int)
{
	Date tmp = *this;

	--(*this);

	return tmp;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;

	return out;

}

istream& operator>>(istream& in, Date& d)
{
	cout << "请输入年月日：" << endl;
	in >> d._year >> d._month >> d._day;

	return in;
}