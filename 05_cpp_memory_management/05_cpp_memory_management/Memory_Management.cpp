#include <iostream>

using namespace std;

class A
{
public:
	A(int a1,int a2 = 0)
		:_a1(a1)
		,_a2(a2)
	{
		cout << "A(int a = 0)" << endl;
	}

	A(const A& aa)
	{
		cout << "A(const A& aa)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

	void Print() const
	{
		cout << _a1 << _a2  << endl;
	}

private:
	int _a1;
	int _a2;

};

struct ListNode
{
	int val;
	ListNode* next;

public:
	ListNode(int x)
		:val(x)
		, next(nullptr)
	{ }


};


void func()
{
	int n = 1;
	while (1)
	{
		void* p1 = new char[1024 * 1024];
		cout << p1 << "->" << n << endl;

		++n;
	}
}

int main()
{
	int* p1 = new int;
	int* p2 = new int[10];

	delete p1;
	delete[] p2;

	int* p3 = new int(1);
	int* p4 = new int[10] {1, 2, 3, 4, 5};

	delete[] p3;
	delete[] p4;

	A* p1 = new A;
	A* p2 = new A(1);
	(*p2).Print();

	delete p1;
	delete p2;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(1);
	ListNode* n4 = new ListNode(1);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	delete n1;
	delete n2;
	delete n3;
	delete n4;

	A* p1 = new A(1);
	A* p2 = new A(1,1);

	A aa1(2, 2);
	A aa2(3, 3);
	A aa3(4, 4);
	A* p3 = new A[3]{aa1,aa2,aa3};

	//匿名对象
	A* p4 = new A[3]{ A(2,2),A(3,3),A(4,4) };

	//隐式类型转换
	A* p5 = new A[3]{ {2,2},{3,3},{4,4} };
	
	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;

	try
	{
		func();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	

	return 0;
}

#include <iostream>

using namespace std;


void Test()
{
	int* p1 = (int*)calloc(4, sizeof(int));
	int* p2 = (int*)realloc(p1, sizeof(int) * 10);

	//需要free(p1)吗？
	free(p2);
}


class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A()" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void Test02()
{
	//对于自定义类型
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);//自动调用构造函数和析构函数
	free(p1);
	delete p2;

	A* p3 = new A[10];
	delete[] p3;
}

int main()
{
	//申请一个int类型空间
	int* p1 = new int;
	delete p1;

	//申请一个int类型空间并初始化为1
	int* p2 = new int(1);
	delete p2;

	//申请5个int类型的空间
	int* p3 = new int[5];
	delete[] p3;

	//申请5个int类型的空间并初始化
	int* p4 = new int[5] {1, 2, 3, 4, 5};
	delete[] p4;

	//申请10个int类型的空间并初始化
	//后续没有被初始化的值均为0
	int* p5 = new int[10] {1, 2, 3, 4, 5};
	delete[] p5;

	test02();


	return 0;
}
 
 
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A()" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
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
	//此时p1指向的是一块分配好的空间，但并没有被初始化，因为没有执行构造函数
	A* p1 = (A*)malloc(sizeof(A));

	new(p1)A;//如果A类的构造函数有参数时，需要传参
	p1->~A();//析构函数

	//显示调用析构函数之后，可以直接使用free，不过建议配套使用
	free(p1);


	return 0;
}


int main()
{
	A* p2 = (A*)operator new(sizeof(A));

	new(p2)A(10);//显示调用构造函数
	p2->Print();
	p2->~A();//析构函数

	operator delete (p2);//底层调用free
	return 0;
}

int main()
{
	try
	{
		// throw try/catch 
		//相当于申请1G	
		void* p1 = new char[1024 * 1024 * 1024];
		cout << p1 << endl;

		void* p2 = new char[1024 * 1024 * 1024];
		cout << p2 << endl;

	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}