#include <iostream>

using namespace std;

class Date
{
public:
	////在函数体内赋值
	//Date(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	//使用初始化列表
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		//,_year(year)//error C2437: “_year”: 已初始化
	{}
	
private:
	int _year;
	int _month;
	int _day;
};

class B
{
public:
	//没有默认构造
	B(int x,int y)
	{
		_x = x;
		_y = y;
	}

private:
	int _x;
	int _y;
};

class A
{
public:
	A(int& a, int n, B b)
		:_ra(a)
		, _n(n)
		, _b(b)
	{
		//error C2530: “A::_ra”: 必须初始化引用
		//error C2789: “A::_n”: 必须初始化常量限定类型的对象
		//error C2512: “B”: 没有合适的默认构造函数可用
	}

private:
	int& _ra;    //引用
	const int _n;//const
	B _b;        //没有默认构造
};


class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
	{ }

	//Date()
	//	: _year(2000)
	//{}

	void Print() const
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

private:
	int _year = 2026;
	int _month = 6;
	int _day = 13;
};

int main()
{
	Date d1;
	d1.Print();

	return 0;
}


class A
{
public:
	//先初始化_a,在初始化_b
	A(int a = 1, int b = 1)
		:_b(b)
		, _a(a)
	{ }

private:
	
	int _a = 0;
	int _b = 0;
};

class A
{
public:
	explicit A(int a)
		:_a(a)
	{}
	//A(int a)
	//	:_a(a)
	//{}

	int Get() const
	{
		return _a;
	}

	void Print() const
	{
		cout << _a << endl;
	}

private:
	int _a;
};

int main()
{
	// error C2440: “初始化”: 无法从“int”转换为“A”
	A aa = 1;
	return 0;
}

class B
{
public:
	B(int b = 0)
		:_b(b)
	{ }

	//转换构造函数
	B(const A& a)
		:_b(a.Get())
	{ }

	void Print() const
	{
		cout << _b << endl;
	}

	void Push(const A& a) const
	{ }
private:
	int _b = 0;
};

int main()
{
	//1构造一个A的临时对象，再用这个临时对象拷贝构造给aa1
	//本质是整形隐式转换成类类型
	//A aa1 = 1;
	//aa1.Print();

	A aa2(1);
	aa2.Print();

	B b1;
	b1 = aa2;
	b1.Print();

	B b2;
	A aa3 = 3;
	b2.Push(aa3);

	//上述Push等价于下面
	//3构造一个A的临时对象，然后Push到b2
	b2.Push(3);

	return 0;
}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{ }

	
	static int Get()
	{
		//静态成员函数不能访问非静态成员变量
		//error C2597: 对非静态成员“A::_a”的非法引用
		// return _a;

		return _sta;
		
	}

private:
	int _a;
	//静态成员变量不能给缺省值
	//类里面声明
	static int _sta;
};

//静态成员变量在类外初始化
int A::_sta = 0;

int main()
{
	cout << A::Get() << endl;

	A aa;

	//error C2248: “A::_sta”: 无法访问 private 成员(在“A”类中声明)
	//cout << aa._sta << endl;
	return 0;
}

class A
{
public:
	////友元函数可以在类的任意地方声明
	//friend void func();
	
	A(int m = 0,int n = 0)
		:_m(m)
		,_n(n)
	{ }

private:
	//友元函数可以在类的任意地方声明
	friend void func();
	int _m;
	int _n;
};

class B
{
public:
	//一个函数可以是多个类的友元函数
	friend void func();

	B(int b = 0)
		:_b(b)
	{ }
	
	
private:
	int _b;
};

void func()
{
	A a;
	//正常情况下类的私有成员不能被类外函数访问
	//error C2248: “A::_m”: 无法访问 private 成员(在“A”类中声明)
	//error C2248: “A::_n”: 无法访问 private 成员(在“A”类中声明)
	//cout << a._m << " " << a._n << endl;

	//加上友元声明之后即可访问
	cout << a._m << " " << a._n << endl;


	B b;
	cout << b._b << endl;
}

int main()
{
	func();
	return 0;
}

class Engine
{
	//car就是Engine的友元类
	friend class Car;

public:
	Engine(int eg = 0)
		:_eg(eg)
	{ }

private:
	int _eg;
};

class Car
{
public:
	void ShowCar(const Engine& eg)
	{
		cout << eg._eg << endl;
	}
};

class A
{
public:
	A(int a = 0)
		:_a(a)
	{}

	//B默认就是A的友元类
	class B
	{
	public:
		void Print(const A& a)
		{
			cout << a._a << endl;
		}
	};

private:
	int _a = 1;

};

int main()
{
	//外部类定义的对象中不包含内部类
	cout << sizeof(A) << endl;
	//A类中只有一个整型变量，大小为4

	A aa;
	A::B bb;
	bb.Print(aa);

	return 0;
}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a = 0)" << endl;
	}


	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
	
};

int main()
{
	//有名对象
	A aa1;

	//匿名对象
	A();
	A(1);
	return 0;
}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a = 0)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

	A& operator==(const A& a)
	{
		cout << "A& operator=(const A& a)" << endl;
		if (this != &a)
		{
			_a = a._a;
		}

		return *this;
	}
	
private:
	int _a;
};

void f1(A aa)
{}

A f2()
{
	A aa;
	return aa;
}

int main()
{
	//传值传参
	//构造+拷贝构造 -> 直接构造
	A aa1;
	f1(1);

	//构造+拷贝构造返回
	f2();
	return 0;
}
















