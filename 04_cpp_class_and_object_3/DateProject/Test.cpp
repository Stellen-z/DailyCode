#include "Date.h"

using namespace std;

void TestDate1()
{
	Date d1(2026, 6, 11);
	Date d2 = d1 + 100;

	d1.Print();
	d2.Print();

	d1 += 200;
	d1.Print();

}


void TestDate2()
{
	Date d1(2026, 6, 11);
	d1.Print();

	d1 -= 1000;
	d1.Print();
}


void TestDate3()
{
	Date d1, d2;
	cin >> d1 >> d2;
	cout << d1 << d2;
}


int main()
{
	//TestDate1();
	//TestDate2();

	TestDate3();

	//Date d1(2026, 6, 10);
	//Date d2(2026, 9, 18);

	//Date d3 = d2 - d1;
	//d3.Print();
	


	

	//Date d1(2026, 6, 11);

	//d1++;
	//d1.Print();

	//++d1;
	//d1.Print();

	//Date d2(2026, 6, 11);


	//d2--;
	//d2.Print();

	//--d2;
	//d2.Print();

	return 0;
}

