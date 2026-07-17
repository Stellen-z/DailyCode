#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <assert.h>

auto func()
{
	return 0;
}

void test_auto()
{
	// error C3531: “x”: 类型包含“auto”的符号必须具有初始值设定项
	//auto x;

	int a = 1;
	auto p = &a;
	auto* pa = &a;
	//auto声明引用类型时必须加上&
	auto& ra = a;

	//auto做函数返回值
	std::cout << func() << std::endl;

	//error C3538: 在声明符列表中，“auto”必须始终推导为同一类型
	//auto x = 3, d = 3.3;

	//error C3318: “auto []”: 数组不能具有其中包含“auto”的元素类型
	//auto arr[] = { 1,2,3,4,5 };

}

void test_for()
{
	int arr[] = { 1,2,3,4,5 };

	//修改数据+遍历
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		arr[i] += 2;
	}

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	//使用范围for
	for (auto& e : arr)
	{
		e += 2;
	}

	for (const auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

}

void test_constructor()
{
	//默认构造函数
	std::string s1;
	std::cout << s1 << std::endl;

	//通过字符指针构造
	std::string s2("hello world!");
	std::cout << s2 << std::endl;

	//通过n个字符c构造
	std::string s3(5,'x');
	std::cout << s3 << std::endl;

	//拷贝构造
	std::string s4(s2);
	std::cout << s4 << std::endl;
}

void test_operator()
{
	std::string s1,s2,s3;
	s1 = "Test string";    //char* s
	std::cout << s1 << std::endl;

	s2 = 'x';             //char c 
	std::cout << s2 << std::endl;

	std::string s("hello world!");
	s3 = s;               //string
	std::cout << s3 << std::endl;

}

void test_capacity()
{
	std::string s("hello world!");

	std::cout << s.size() << std::endl;
	std::cout << s.length()<< std::endl;
	std::cout << s.capacity() << std::endl;
	std::cout << s.empty() << std::endl;

	s.clear();
	std::cout << s << std::endl;

	s.reserve(20);//预留空间

	s.resize(13, '$');
	std::cout << s << std::endl;

}


void test_index()
{
	std::string s("hello world");
	std::cout << s << std::endl;

	//修改+遍历
	for (int i = 0; i < s.size(); i++)
	{
		s[i] += 2;
	}

	for (int i = 0; i < s.size(); i++)
	{
		std::cout << s[i];
	}
	std::cout << std::endl;

}

void test_iterator()
{
	std::string s("hello world");

	//使用迭代器遍历
	for (auto it = s.begin(); it != s.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test_trverse()
{
	std::string s("hello world");

	//1.下标 + []
	for (int i = 0; i < s.size(); i++)
	{
		std::cout << s[i];
	}
	std::cout << std::endl;

	//2.迭代器
	for (auto it = s.begin(); it != s.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

	//反向迭代器 -> 逆序遍历
	for (auto it = s.rbegin(); it != s.rend(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

	//3.范围for
	for (auto ch : s)
	{
		std::cout << ch;
	}
	std::cout << std::endl;
}

void test_modify1()
{
	std::string s("hello world");
	std::cout << s << std::endl;

	//尾插单个字符
	//void push_back(char c);
	s.push_back('*');
	std::cout << s << std::endl;

	//尾插字符串
	//string(1)
	//	string& append(const string & str);
	//substring(2)
	//	string& append(const string & str, size_t subpos, size_t sublen);
	//c - string(3)
	//	string & append(const char* s);
	//buffer(4)
	//	string& append(const char* s, size_t n);
	//fill(5)
	//	string& append(size_t n, char c)
	s.append("$$$$$$$$");
	std::cout << s << std::endl;

	//+=字符串
	//string(1)
	//	string& operator+= (const string & str);
	//c - string(2)
	//	string & operator+= (const char* s);
	//character(3)
	//	string& operator+= (char c);
	s += "######";
	std::cout << s << std::endl;
	
}

void test_modify2()
{
	std::string s("hello world");
	std::cout << s << std::endl;

	//返回起始指针
	//const char* c_str() const;
	std::cout << s.c_str() << std::endl;

	//从pos开始向后找第一次出现'o'的位置并返回
	//string(1)
	//	size_t find(const string & str, size_t pos = 0) const;
	//c - string(2)
	//	size_t find(const char* s, size_t pos = 0) const;
	//buffer(3)
	//	size_t find(const char* s, size_t pos, size_t n) const;
	//character(4)
	//	size_t find(char c, size_t pos = 0) const;
	size_t pos = s.find('o');
	std::cout << pos << std::endl;

	//从后向前找第一次出现'o'的位置并返回
	//string(1)
	//	size_t find(const string & str, size_t pos = 0) const;
	//c - string(2)
	//	size_t find(const char* s, size_t pos = 0) const;
	//buffer(3)
	//	size_t find(const char* s, size_t pos, size_t n) const;
	//character(4)
	//	size_t find(char c, size_t pos = 0) const;
	size_t rpos = s.rfind('o');
	std::cout << rpos << std::endl;

	//从pos开始向后截取len个字符
	//string substr (size_t pos = 0, size_t len = npos) const;
	std::cout << s.substr(0, 5) << std::endl;

}

void test_nonmemberfunc()
{
	//string(1)
	//	string operator+ (const string & lhs, const string & rhs);
	//c - string(2)
	//	string operator+ (const string & lhs, const char* rhs);
	//string operator+ (const char* lhs, const string & rhs);
	//character(3)
	//	string operator+ (const string & lhs, char rhs);
	//string operator+ (char lhs, const string & rhs);

	std::string ss1("hello");
	std::string ss2("world");
	std::string s = ss1 + ss2;
	std::cout << s << std::endl;

	//getline
	std::string s1;
	std::getline(std::cin,s1);
	std::cout << s1;

}

void Test01()
{
	test_auto();
	test_for();
	test_constructor();
	test_operator();
	test_capacity();
	test_index();
	test_iterator();
	test_trverse();
	test_modify1();
	test_modify2();
	test_nonmemberfunc();
}



void Test02()
{
	class String
	{
	public:
		String(const char* str = "")
		{
			if (str == nullptr)
			{
				assert(false);
				return;
			}
			size_t len = strlen(str);
			_str = new char[len + 1];
			strcpy(_str, str);
		}
		//拷贝构造
		String(const String& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		~String()
		{
			delete[] _str;
			_str = nullptr;
		}
	private:
		char* _str;
	};

	String s1("hello world!");
	String s2(s1);
}

//*******************************************************
#include "string.h"

namespace stl
{
	void test_memeberfunc()
	{
		string s("hello world");
		string s1("xxx");
		string s2("***");

		string ss(s);//hello world

		s1 = s2;//s1 = s2 = "***"
	}

	void test_capacity()
	{
		string s("hello world");

		std::cout << "size = " << s.size() << std::endl;
		std::cout << "length = " << s.length() << std::endl;
		std::cout << "capacity = " << s.capacity() << std::endl;

		std::cout << std::endl;

		std::cout << s.empty() << std::endl;
		s.claer();
		std::cout << s.empty() << std::endl;

		std::cout << std::endl;

		string ss("hello cpp");

		std::cout << "扩容前容量大小: " << ss.capacity() << std::endl;
		ss.reserve(10);
		std::cout << "扩容后容量大小: " << ss.capacity() << std::endl;
			
		std::cout << "填充字符前size大小: " << ss.size() << std::endl;
		ss.resize(15, '#');
		std::cout << "填充字符后size大小: " << ss.size() << std::endl;

	}

	void test_iterate()
	{
		string s("hello world");

		//1.下标遍历
		for (int i = 0; i < s.size(); i++)
		{
			std::cout << s[i] << " ";
		}
		std::cout << std::endl;

		//2.迭代器
		for (auto it = s.begin(); it != s.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		//3.范围for
		for (auto ch : s)
		{
			std::cout << ch << " ";
		}
		std::cout << std::endl;
	}

}




int main()
{
	//Test01();
	//Test02();

	//stl::test_memeberfunc();
	//stl::test_capacity();
	stl::test_iterate();

	return 0;
}