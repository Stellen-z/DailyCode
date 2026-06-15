#include "Date.h"

void Test01()
{
	Date d1(2022, 6, 7);
	Date d2(2022, 6, 7);

	d1 += 100;
	d1.Print();

	d2 -= 200;
	d2.Print();
}

void Test02()
{
	Date d1(2022, 6, 7);
	Date d2(2022, 6, 7);

	d1++;
	d1.Print();

	++d1;
	d1.Print();

	--d2;
	d2.Print();

	d2--;
	d2.Print();
}

void Test03()
{
	Date d1(2022, 10, 1);
	Date d2(2022, 6, 7);

	cout << d1 - d2 << endl;
}



int main()
{
	//Test01();
	//Test02();
	Test03();
	return 0;
}