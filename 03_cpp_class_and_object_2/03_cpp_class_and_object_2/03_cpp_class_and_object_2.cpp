#include <iostream>

using namespace std;

class stack
{
public:
	stack(int n = 4)
	{
		
		_a = (int*)malloc(sizeof(int) * n);
		if (nullptr == _a)
		{
			perror("malloc failed!\n");
			exit(1);
		}

		_capacity = n;
		_top = 0;
	}
	

private:
	int* _a;
	int _top;
	int _capacity;
};


int main()
{
	stack s1;

	stack s2;

	return 0;
}

#include <iostream>

using namespace std;

class Date
{
public:
	//构造函数支持重载,通过参数进行匹配

	//1.无参构造函数
	Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}

	////2.有参构造函数
	//Date(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	//3.全缺省构造函数
	Date(int year = 0, int month = 0, int day = 0)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//只保留全缺省构造函数
	Date d1;
	d1.Print();

	Date d2(2026);
	d2.Print();

	Date d3(2026,6);
	d3.Print();

	Date d4(2026, 6,8);
	d4.Print();


	//注释掉所有的构造函数
	Date d;
	d.Print();

	//保留无参构造函数和全缺省构造函数
	// error C2668: “Date::Date”: 对重载函数的调用不明确
	Date d;
	d.Print();

	return 0;
}



#include <iostream>

typedef int STDateType;

using namespace std;

class Stack
{
public:
	
	//如果不写Stack的默认构造函数就会导致在MyQueue中创建对象时报错
	//全缺省构造函数
	Stack(int n = 4)
	{
		_a = (STDateType*)malloc(sizeof(STDateType) * n);
		if (_a == nullptr)
		{
			perror("malloc failed!\n");
			exit(1);
		}

		_top = 0;
		_capacity = n;
	}

	//析构函数
	~Stack()
	{
		cout << "~Stack()" << endl;
		
		free(_a);
		_a = nullptr;

		_top = 0;
		_capacity = 0;
	}


private:
	STDateType* _a;
	int _top;
	int _capacity;
};




//class MyQueue
//{
//private:
//	Stack st1;
//	Stack st2;
//
//};

int main()
{
	Stack st1;


	return 0;
}



#include <iostream>

using namespace std;

class Date
{
public:


private:
	int _year;
	int _month;
	int _day;
};

int main()
{

	return 0;
}


#include <iostream>

using namespace std;

class Date
{
public:
	//全缺省构造函数
	Date(int year = 1, int month = 1,int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << " " << _month << " " << _day << endl;
 	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2026, 6, 9);
	d1.Print();


	return 0;
}

#include <iostream>

typedef int STDateType;

using namespace std;

class Stack
{
public:
	//全缺省构造函数
	Stack(int n = 4)
	{
		_a = (STDateType*)malloc(sizeof(STDateType) * n);
		if (_a == nullptr)
		{
			perror("malloc failed!\n");
			exit(1);
		}

		_top = 0;
		_capacity = n;
	}

	//析构函数
	~Stack()
	{
		cout << "~Stack()" << endl;

		free(_a);
		_a = nullptr;

		_top = 0;
		_capacity = 0;
	}


private:
	STDateType* _a;
	int _top;
	int _capacity;
};

class MyQueue
{
public:
	~MyQueue()
	{
		cout << "~MyQueue()" << endl;
	}

private:
	//构造函数会调用Stack的默认构造函数，无需手动实现
	//析构函数会调用Stack的析构函数，无需手动实现
	Stack st1;
	Stack st2;
};

int main()
{
	MyQueue mq;

	return 0;
}


#include <iostream>

using namespace std;

class Date
{
public:
	//全缺省构造函数
	Date(int year = 1, int month = 1,int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	////拷贝构造函数,第一个参数必须是类类型对象的引用
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	////传值调用拷贝构造函数
	////“Date”: 非法的复制构造函数: 第一个参数不应是“Date”
	//Date(Date d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = _day;
	//}


	void Print()
	{
		cout << _year << " " << _month << " " << _day << endl;
 	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2026, 6, 9);
	d1.Print();

	Date d2(d1);

	return 0;
}


#include <iostream>

typedef int STDateType;

using namespace std;

class Stack
{
public:
	//全缺省构造函数
	Stack(int n = 4)
	{
		_a = (STDateType*)malloc(sizeof(STDateType) * n);
		if (_a == nullptr)
		{
			perror("malloc failed!\n");
			exit(1);
		}

		_top = 0;
		_capacity = n;
	}
	//深拷贝
	Stack(const Stack& st)
	{
		_a = (STDateType*)malloc(sizeof(int) * st._top);
		if (_a == nullptr)
		{
			perror("malloc failed!\n");
			exit(1);
		}

		memcpy(_a, st._a, sizeof(STDateType) * st._top);

		_top = st._top;
		_capacity = st._capacity;
	}

	//析构函数
	~Stack()
	{
		cout << "~Stack()" << endl;

		free(_a);
		_a = nullptr;

		_top = 0;
		_capacity = 0;
	}


private:
	STDateType* _a;
	int _top;
	int _capacity;
};

// warning C4172: 返回局部变量的地址或临时 : st
Stack& func()
{
	Stack st;
	return st;
}

int main()
{
	Stack st1;

	Stack st2(st1);

	return 0;
}



#include <iostream>

using namespace std;

class Date
{
public:
	//全缺省构造函数
	Date(int year = 1, int month = 1,int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << " " << _month << " " << _day << endl;
 	}
	
	//重载为成员函数
	bool operator==(Date d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	//重载前置++
	Date& operator++()
	{
		cout << "前置++" << endl;
		_day++;
		return *this;
	}

	//重载后置++
	Date operator++(int)
	{
		//返回自增前的值再进行++
		cout << "后置++" << endl;
		Date tmp = (*this);

		//复用前置++
		++(*this);
		
		//函数结束后tmp就被销毁，因此不能返回引用
		return tmp;
	}


private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	//Date d1(2026,6,10);
	//d1.Print();

	//Date d2(d1);

	////可以显示调用
	//d1.operator==(d2);

	//d1 == d2;
	
	Date d1(2026, 6, 10);
	Date d2(2026, 6, 11);

	cout << d1.operator==(d2) << endl;
	
	d1 == d2;//转换成 d1.operator==(d2)


	d1++;
	d1.Print();

	++d2;
	d2.Print();

	return 0;
}

#include <iostream>

using namespace std;

class Date
{
public:
	//全缺省构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	Date(const Date& d)
	{
		cout << "Date(const Date& d)" << endl;

		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print() const
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

	//赋值运算符重载
	Date& operator=(const Date& d)
	{
		//d1 = d2
		//返回的是d1即this指针

		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;		
	}

	Date* operator&()
	{
		return this;
		 return nullptr;
	}

	const Date* operator&()const
	{
		return this;
		 return nullptr;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2026, 6, 10);
	Date d2(2026, 6, 6);

	//拷贝构造
	Date d3 = d2;//Date d3(d2)

	//赋值重载
	d1 = d2;

	return 0;
}

int main()
{
	//非const对象也能调用Print,会导致权限的缩小
	Date d1(2026, 6, 10);
	d1.Print();


	Date const d2(2026, 6, 16);
	d2.Print();

	return 0;
}


int main()
{
	Date d1(2026, 6, 10);
	d1.Print();


	Date const d2(2026, 6, 16);
	d2.Print();

	return 0;
}