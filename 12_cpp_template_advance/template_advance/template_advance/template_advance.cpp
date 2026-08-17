#include <iostream>
#include <string>
	
#include "template_advance.h"

namespace stl
{
	//void test_template_value()
	//{
	//	//通过传入的N的大小来控制底层的_a
	//	Stack<> st0;
	//	Stack<5> st1;
	//	Stack<10> st2;
	//}


	void test_array()
	{
		array<int,1> a1;
		for (int i = 0; i < 1; i++)
		{
			a1[i] = i;
			std::cout << a1[i] << " ";
		}
		std::cout << std::endl;

		array<int,5> a2;
		for (int i = 0; i < 5; i++)
		{
			a2[i] = i;
			std::cout << a2[i] << " ";
		}
		std::cout << std::endl;

		array<int> a3;
		for (int i = 0; i < 10; i++)
		{
			a3[i] = i;
			std::cout << a3[i] << " ";
		}
		std::cout << std::endl;

	}

	void test_compare()
	{
		int a = 1;
		int b = 2;
		std::cout << less(a, b) << std::endl;

		std::string s1 = "hello";
		std::string s2 = "world";
		std::cout << less(s1, s2) << std::endl;

		std::string* p1 = &s1;
		std::string* p2 = &s2;
		//此时比较的是什么？
		std::cout << less(p1, p2) << std::endl;

	}

	void test_specialize()
	{
		example<char, char> e1;       //模板
		example<int, char> e2;        //全特化
		example<std::string, int> e3; //偏特化

		example<int*, int*> e4;       //偏特化
		example<char*, char*> e5;     //偏特化
		example<int&, int&> e6(1,2);  //偏特化

	}

	//Add函数定义
	template<class T>
	T Add(const T& x, const T& y)
	{
		return x + y;
	}

	void test_add()
	{
		std::cout << Add(1, 2) << std::endl;
		std::cout << Add(1.1, 2.2) << std::endl;

	}


}







int main()
{
	//stl::test_template_value();
	//stl::test_array();
	//stl::test_compare();
	//stl::test_specialize();
	stl::test_add();

	return 0;
}