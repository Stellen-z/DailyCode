#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date& d)" << endl;
	}

	void Print()
	{
		cout << _year << ":" << _month << ":" << _day;
		cout << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void test1()
{
	Date d1(2026, 9, 14);
	Date d2{ 2026,9,15 };

	d1.Print();
	d2.Print();

}


int main()
{
	test1();
	return 0;
}