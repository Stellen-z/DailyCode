#include <stdio.h>

int main()
{
	printf("Hello World!\n");
	return 0;
}


#include <iostream>

using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

int rand = 10;


int main()
{
	//error C2365: “rand”: 重定义；以前的定义是“函数”
	printf("%d\n", rand);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>


//1.命名空间定义
namespace stn
{
	//定义变量
	int rand = 20;
	//定义函数
	int Add(int x, int y)
	{
		return x + y;
	}
}

//2.命名空间的嵌套
namespace mn
{
	//pq命名空间
	namespace pq
	{
		int rand = 1;
		int Add(int x, int y)
		{
			return x + y;
		}
	}
	//xy命名空间
	namespace xy
	{
		int rand = 1;
		int Add(int x, int y)
		{
			return x + y;
		}
	}
}

int main()
{
	printf("%p\n", rand);//默认访问rand函数指针
	printf("%d\n", stn::rand);//访问stn命名空间中的rand


	return 0;
}

#include <stdio.h>
#include <stdlib.h>

//2.命名空间的嵌套
namespace mn
{
	//pq命名空间
	namespace pq
	{
		int rand = 1;
		int Add(int x, int y)
		{
			return x + y;
		}
	}
	//xy命名空间
	namespace xy
	{
		int rand = 1;
		int Add(int x, int y)
		{
			return x + y;
		}
	}
}

int main()
{
	printf("%d\n", mn::pq::rand);
	printf("%d\n", mn::xy::rand);

	printf("%d\n", mn::pq::Add(1, 2));
	printf("%d\n", mn::xy::Add(1, 2));


	return 0;
}


#include <stdio.h>

namespace stn
{
	int a = 0;
	int b = 1;
}

int main()
{
	//error C2065: “a”: 未声明的标识符
	printf("%d\n", a);

	return 0;
}

using stn::a;

int main()
{
	printf("%d\n", a);
	printf("%d\n", stn::b);

	return 0;
}

using namespace stn;

int main()
{
	printf("%d\n", a);
	printf("%d\n", b);

	return 0;
}

#include <iostream>

int main()
{
	int a = 0;
	double b = 0.1;
	char c = 'm';

	std::cout << a << " " << b << " " << c << std::endl;

	//自动识别变量类型
	std::cin >> a >> b >> c;

	std::cout << a << " " << b << " " << c << std::endl;
}

#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	return 0;
}

#include <iostream>

using namespace std;
	
void fun(int a = 1)
{
	cout << a << endl;
}

int main()
{
	fun();   //没有传参时，使用参数的默认值
	fun(10); //传参时，使用指定的实参
}

#include <iostream>

using namespace std;

//全缺省
void Func1(int a = 1,int b = 2,int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

//半缺省
void Func2(int a, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	Func1();            //1 2 3
	Func1(10);          //10 2 3
	Func1(10,20);       //10 20 3
	Func1(10,20,30);    //10 20 30

	Func2(100);         //100 2 3
	Func2(100,200);     //100 200 3
	Func2(100,200,300); //100 200 300

}

#include <iostream>

using namespace std;

namespace stn
{
	//1.参数类型不同
	int Add(int x, int y)
	{
		cout << "Add(int x, int y)" << endl;
		return x + y;
	}

	double Add(double x, double y)
	{	
		cout << "Add(double x, double y)" << endl;
		return x + y;
	}


	//2.参数个数不同
	void func(int a)
	{
		cout << "func(int a)" << endl;
	}
	void func(int a, int b)
	{
		cout << "func(int a,int b)" << endl;
	}

	//3.参数类型顺序不同
	void f(int a, char b)
	{
		cout << "f(int a, char b)" << endl;
	}

	void f(char b, int a)
	{
		cout << "f(char b, int a)" << endl;
	}

}

int main()
{
	stn::Add(1, 2);
	stn::Add(1.1, 2.2);

	stn::func(1);
	stn::func(1,2);

	stn::f(1, 'x');
	stn::f('x', 1);


	return 0;
}

#include <iostream>

using namespace std;

int f()
{
	cout << "f()" << endl;
	return 1;
}

//error C2556: “void f(void)”: 重载函数与“int f(void)”只是在返回类型上不同
void f()
{
	cout << "f()" << endl;
}


int main()
{

	f();
	f();

	return 0;
}

#include <iostream>

using namespace std;

void f()
{
	cout << "f()" << endl;
}

void f(int a = 10)
{
	cout << "f(int a = 10)" << endl;
}

int main()
{
	f();//error C2668: “f”: 对重载函数的调用不明确
	f(10);
	return 0;
}

#include <iostream>

using namespace std;

inline int Add(int x, int y)
{
	int ret = x + y;

	ret += 1;

	return ret;
}

int main()
{
	int ret = Add(1, 2);
	cout << ret << endl;

	return 0;
}

#include <iostream>

using namespace std;

//请问哪个宏函数是正确的？
#define Add(int a,int b) return a + b;
#define Add(a,b) a + b;
#define Add(a,b) (a + b)

int main()
{

	//#define Add(int a,int b) return a + b; 
	int ret = Add(1, 2);  
	//展开之后变成 int ret = return 1 + 2;;
	//1.return不能出现在赋值表达式
	//2.末尾有两个分号	


	//#define Add(a,b) a + b;
	int ret = Add(1, 2);	
	//展开之后变成 int ret = 1 + 2;;
	//此时影响不大，结果正常
	cout << Add(1, 2) * 3 << endl;
	//这样展开之后呢？
	cout << 1 + 2 * 3 ; << endl;
	//显然1.没有括号 2.分号多余

	//#define Add(a,b) (a + b)
	cout << Add(1, 2) << endl; // -> cout << (1 + 2) << endl;
	//此时没有问题
	cout << Add(1 & 2, 1 | 2) << endl; // -> cout << (1 & 2 + 1 | 2) << endl;
	//显然错误，+ 的运算符优先级高于 & ,导致计算顺序错误
	 
	#define Add(a,b) ((a) + (b));


	return 0;
}

#include <iostream>

using namespace std;

int main()
{	
	const int a = 1;
	//权限放大：error C2440: “初始化”: 无法从“const int”转换为“int &”
	//int& ra = a;
	
	//正确引用
	const int& ra = a;
	
	//error C3892: “ra”: 不能给常量赋值
	//ra++;

	//权限缩小
	int b = 10;
	const int& rb = b;
	
	//error C3892: “rb”: 不能给常量赋值
	//rb++;

	return 0;
}

#include <iostream>

using namespace std;

int main()
{
	int a = 10;

	//常量值用常引用
	const int& x = 20;
	
	//error C2440: “初始化”: 无法从“int”转换为“int &”
	//int& ret = a * 2;

	//临时对象用常引用	
	const int& ret = a * 2;

	double d = 11.22;
	
	//error C2440: “初始化”: 无法从“double”转换为“int &”
	//int& rd = d;

	//类型转换会产生临时对象，要用常引用
	const int& rd = d;


	return 0;
}


#include <iostream>

using namespace std;

void f(int x)
{
	cout << "f(int x)" << endl;
}

void f(int* ptr)
{
	cout << "f(int* ptr)" << endl;
}

int main()
{

	f(0);
	f(NULL);//调用f(int x)

	f((int*)0);
	f((int*)NULL);//调用f(int* ptr)

	error C2665: “f”: 没有重载函数可以转换所有参数类型
	f((void*)NULL);
	
	return 0;
}