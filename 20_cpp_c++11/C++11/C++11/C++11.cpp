#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<assert.h>
#include<string.h>
#include<algorithm>
#include <list>

#include "list.h"
#include "string.h"

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

namespace stl
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)-构造" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 拷贝构造" << endl; reserve(s._capacity);
			for (auto ch : s)
			{
				push_back(ch);
			}
		}
		// 移动构造​
		//string(string&& s)
		//{
		//	cout << "string(string&& s) -- 移动构造" << endl;
		//	swap(s);
		//}
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 拷贝赋值" <<
				endl;
			if (this != &s)
			{
				_str[0] = '\0';
				_size = 0;
				reserve(s._capacity);
				for (auto ch : s)
				{
					push_back(ch);
				}
			}
			return *this;
		}
		// 移动赋值​
		//string& operator=(string&& s)
		//{
		//	cout << "string& operator=(string&& s) -- 移动赋值" << endl;
		//	swap(s);
		//	return *this;
		//}

		//~string()
		//{
		//	cout << "~string() -- 析构" << endl;
		//	delete[] _str;
		//	_str = nullptr;
		//}
	
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				if (_str)
				{
					strcpy(tmp, _str);
					delete[] _str;
				}
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity *
					2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
		size_t size() const
		{
			return _size;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};

	string addStrings(string num1, string num2)
	{
		string str;
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		int next = 0;
		while (end1 >= 0 || end2 >= 0)
		{
			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
			int ret = val1 + val2 + next;
			next = ret / 10;
			ret = ret % 10;
			str += ('0' + ret);
		}
		if (next == 1)
			str += '1';
		reverse(str.begin(), str.end());
		//cout << "******************************" << endl;
		return str;
	}
}

template<class T>
void Function(T&& t)
{
	int a = 0;
	T x = a;
	//x++;
	cout << &a << endl;
	cout << &x << endl << endl;
}

void test2()
{
	//stl::string ret = stl::addStrings("11111", "2222");
	//cout << ret.c_str() << endl;

	stl::string ret;
	ret = stl::addStrings("11111", "2222");
	cout << ret.c_str() << endl;


	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)​
	Function(10); // 右值​

	int a;
	// a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)​
	Function(a); // 左值​

	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)​
	Function(std::move(a)); // 右值​

	const int b = 8;
	// b是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int&t)
	// 所以Function内部会编译报错，x不能++​
	Function(b); // const 左值


	//std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&&t)
	// 所以Function内部会编译报错，x不能++​
	Function(std::move(b)); // const 右值​
}


template<class ...Args> void func(Args... args) {};
template<class ...Args> void func(Args&... args) {};
template<class ...Args> void func(Args&&... args) {};

void ShowList()
{
	cout << endl;
}

template<class T,class ...Args>
void ShowList(T&& x,Args... args)
{
	cout << x << endl;
	ShowList(args);
}

template<class ...Args>
void Print(Args&&... args)
{
	cout << sizeof...(args) << endl;
}

void test3()
{
	Print();
	//Print():

	Print(1, 1.1);
	//Print(int&&,double&&);

	Print(string("111"), 2, 3.3);
	//Print(std::string&&,int&&,double&&);
}

void test4()
{
	//扩展包 -- 递归推导

	Print(1, string("111"), 2.2);
	//1.生成匹配的函数
	//Print(int&& x, string&& y, double&& z);

	//2.调用ShowList(x,args),输出x 
	//ShowList(x,y,z)

	//3.ShowList(y,args),输出y
	//ShowList(y,z)

	//3.ShowList(z),输出z
	//ShowList() 

	//4.输出endl
}

template<class T>
const T& GetArg(const T& x)
{
	cout << x << " ";
	return x;
}

template<class ...Args>
void Arguments(Args... args)
{};

template<class ...Args>
void PRint(Args... args)
{
	Arguments(GetArg(args)...);
	//Arguments(GetArg(x),GetArg(y),GetArg(z));
}

void test5()
{
	//扩展包 -- 函数调用推导
	PRint(1, string("111"), 2.2);
}

void test6()
{
		std::list<stl::string> lt;
		// 传左值，跟push_back一样，走拷贝构造
		stl::string s1("111111111111");
		stl::string s2("111111111111");
	
		lt.emplace_back(s1);
		cout << "*********************************" << endl;
	
		lt.push_back(s1);
		cout << "*********************************" << endl;

		// 右值，跟push_back一样，走移动构造
		lt.emplace_back(move(s1));
		cout << "*********************************" << endl;
		
		lt.push_back(move(s2));
		cout << "*********************************" << endl;
			
		lt.emplace_back("111111111111");
		cout << "*********************************" << endl;
		
		// 直接传参，隐式类型转换
		lt.push_back("111111111111");
		cout << "*********************************" << endl;
}

int main()
{
	//test1();
	//test2();
	//test3()
	//test4();
	//test5();

	test6();

	return 0;
}


