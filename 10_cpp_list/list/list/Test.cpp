#include <iostream>
#include <list>
#include <algorithm>


using namespace std;

void test1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}

	//不支持非随机迭代器
	//sort(lt.begin(), lt.end());

	string s("ackjhls");
	sort(s.begin(), s.end());
	cout << s << endl;

}


void test2()
{
	list<double> lt1;
	lt1.push_back(1.1);
	lt1.push_back(2.1);
	lt1.push_back(3.1);
	lt1.push_back(4.1);

	list<double> lt2;
	lt1.push_back(1.3);
	lt1.push_back(2.3);
	lt1.push_back(3.3);
	lt1.push_back(4.3);
	
	lt1.sort();
	lt2.sort();

	lt1.merge(lt2);

	for (auto& e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

}

void TEST()
{
	//test1();
	test2();
}

#include "list.h"

namespace stl
{
	void test_push_back()
	{
		list<int> lt;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(4);


		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		Print_Container(lt);

	}


	void test_operator()
	{
		list<AA> lta;

		lta.push_back(AA());
		lta.push_back(AA());
		lta.push_back(AA());
		lta.push_back(AA());


		list<AA>::iterator it = lta.begin();
		while (it != lta.end())
		{
			cout << it->_a1 << " " << it->_a2 << endl;;
			++it;
		}
		cout << endl;
	}


}



int main()
{

	stl::test_push_back();
	stl::test_operator();

	return 0;
}