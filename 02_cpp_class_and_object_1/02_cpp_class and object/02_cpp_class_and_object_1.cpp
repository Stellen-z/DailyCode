#include <iostream>

using namespace std;

class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	//区分成员变量，加上_
	int _year;
	int _month;
	int _day;
};

#include <iostream>

using namespace std;

//struct升级为类
//1.struct里面可以定义函数
//2.名称即类型

//兼容C语言
typedef struct ListNodeC 
{
	int val;
	struct ListNodeC* next;
}ListNodeC;


//C++名称即代表类型
struct ListNodeCPP
{
	void Init(int x)
	{
		next = nullptr;
		val = x;
	}

	ListNodeCPP* next;
	int val;
};

int main()
{

	return 0;
}


#include <iostream>

using namespace std;

class Stack
{
public:
	//成员函数
	void Init(int n = 4);

private:
	//成员变量
	int* arr;
	int _top;
	int _capacity;
};

//没有指定类域
void Init(int n)
{
	////error C2065: “arr”: 未声明的标识符
	arr = (int*)malloc(sizeof(int) * n);
	if (nullptr == arr)
	{
		perror("malloc failed!\n");
		exit(1);
	}

	// error C2065:“_top”: 未声明的标识符
	_top = 0;
	//error C2065:“_capacity”: 未声明的标识符
	_capacity = 0;

}

void Stack::Init(int n)
{
	////error C2065: “arr”: 未声明的标识符
	arr = (int*)malloc(sizeof(int) * n);
	if (nullptr == arr)
	{
		perror("malloc failed!\n");
		exit(1);
	}

	// error C2065:“top”: 未声明的标识符
	_top = 0;
	//error C2065:“capacity”: 未声明的标识符
	_capacity = 0;

}

int main()
{
	Stack st;
	st.Init();


	return 0;
}


#include <iostream>

using namespace std;

class Date
{
public:
	void Init(Date* const this, int year, int month, int day)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	void Init(int year, int month, int day)
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
	//成员变量在类中只是声明，没有开空间
	int _year;
	int _month;
	int _day;
};

int main()
{
	//实例化对象d1,d2
	Date d1;
	Date d2;

	d1.Init(2026, 6, 7);
	d1.Print();

	d2.Init(2026, 7, 7);
	d2.Print();

	return 0;
}

#include <iostream>

using namespace std;

class A
{
public:
	void Print()
	{
		cout << "A::Print()" << endl;
		cout << _a << endl;
	}

private:
	int _a;
};


int main()
{
	A* p = nullptr;
	p->Print();

	return 0;
}

#include <iostream>
#include <assert.h>

using namespace std;

typedef int STDataType;

class Stack
{
public:
	void Init(int n = 4)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (_a == NULL)
		{
			perror("malloc failed!\n");
			exit(1);
		}

		_top = 0;
		_capacity = 0;
	}

	void Push(STDataType x)
	{
		if (_top == _capacity)
		{
			int newcapacity = _capacity * 2;
			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}
			_a = tmp;
			_capacity = newcapacity;
		}

		_a[_top++] = x;

	}


	void Pop()
	{
		assert(_top > 0);
		--_top;
	}

	bool Empty()
	{
		return _top == 0;
	}

	int Top()
	{
		assert(_top > 0);
		return _a[_top - 1];
	}

	void Destroy()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}

private:
	STDataType* _a;
	int _top;
	int _capacity;
};

int main()
{
	Stack st;
	st.Init();

	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);

	while (!st.Empty())
	{
		cout << st.Top() << " ";
		st.Pop();
	}
	
	st.Destroy();

	return 0;
}

