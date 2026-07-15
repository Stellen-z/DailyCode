#include "string.h"

namespace stl
{
	void test01()
	{
		string s("hello world");

		cout << s.c_str() << endl;

	}

	void test02()
	{
		string s("hello world!");
		s.reserve(20);

		//s.push_back('x');
		//cout << s.c_str() << endl;

		//s += '**';
		//cout << s.c_str() << endl;

		s.append("hhhhhhh");
		cout << s.c_str() << endl;

		s += "kskbl";
		cout << s.c_str() << endl;

		//s.resize(10);
		//cout << s.c_str() << endl;

		s.resize(30, '*');
		cout << s.c_str() << endl; 
	}

	void test03()
	{
		string s("hello world!");

		size_t find = s.find('r');
		s.insert(find, '$');
		cout << s.c_str() << endl;

	}

}



int main()
{
	//stl::test01();
	//stl::test02();
	stl::test03();

	return 0;
}