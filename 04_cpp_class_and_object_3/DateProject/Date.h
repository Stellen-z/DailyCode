#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
public:
	friend ostream& operator<<(ostream& out,const Date& d);
	friend istream& operator>>(istream& in, Date& d);

	//全缺省构造函数
	Date(int year = 1000, int month = 1, int day = 1);
	void Print();

	//定义在类里面的默认就是内联函数
	int GetMonthDay(int year,int month)
	{
		assert(month > 0 && month < 13);

		static int MonthDayArr[] = { -1,31,28,31,30,31,30,
			                         31,31,30,31,30,31 };

		if ((month == 2) &&
			((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return MonthDayArr[month];
	}

	bool CheckDate();

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	//d1 += 天数
	Date& operator+=(int day);
	Date operator+(int day) const;
	
	//d1 -= 天数
	Date& operator-=(int day);
	Date operator-(int day) const;

	//d1 - d2
	int operator-(const Date& d) const;

	//++d1
	Date& operator++();

	//d1++
	Date operator++(int);

	//--d1
	Date& operator--();

	//d1--
	Date operator--(int);



private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);

istream& operator>>(istream& in, Date& d);
