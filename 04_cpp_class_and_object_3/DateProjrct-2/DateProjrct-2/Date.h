#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
	//友元函数声明
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		if (!CheckDate())
		{
			cout << "日期非法" << endl;
		}
	}

	void Print() const;

	int GetMonthDay(int year, int month) const
	{
		int MonthArr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((month == 2) &&
			((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}

		return MonthArr[month];
	}

	bool CheckDate();

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;


	//+=
	Date& operator+=(int day);

	//-=
	Date& operator-=(int day);

	//++
	Date& operator++();
	Date operator++(int);
		
	//--
	Date& operator--();
	Date operator--(int);


	//天数 - 天数
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);