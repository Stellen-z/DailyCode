#include <iostream>

using namespace std;

////实现一个交换函数
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void Swap(double& x, double& y)
//{
//	double tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void Swap(char& x, char& y)
//{
//	char tmp = x;
//	x = y;
//	y = tmp;
//}

////使用格式
//template<class T1, class T2>
//template<typename T1,typename n2>
////建议配套使用
//template<class T1,typename T2>

//template<class T>
//void Swap(T& x,T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}

//void Test01()
//{
//	int a = 1, b = 2;
//	swap(a, b);
//
//	double d1 = 1.1, d2 = 2.2;
//	swap(d1, d2);
//
//	char x = 'a', y = 'b';
//	swap(x, y);
//
//}

//void Test02()
//{
//	int a = 1, b = 2;
//	cout << "交换前：" << "a = " << a << " " << "b = " << b << endl;
//	Swap(a, b);
//	cout << "交换后：" << "a = " << a << " " << "b = " << b << endl;
//
//	double d1 = 1.1, d2 = 2.2;
//	cout << "交换前：" << "d1 = " << d1 << " " << "d2 = " << d2 << endl;
//	Swap(d1, d2);
//	cout << "交换后：" << "d1 = " << d1 << " " << "d2 = " << d2 << endl;
//}

//template<class T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}


//void Test03()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	Add(a1, a2);
//	Add(d1, d2);
//
//}

//void Test04()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	//传入参数类型不一致
//	//Add(a1, d1);//error C2672: “Add”: 未找到匹配的重载函数
//
//	//手动强制类型转换
//	Add(a1, (int)d1);
//
//}

//void Test05()
//{
//	int a = 1;
//	double d = 1.1;
//
//	Add<int>(a, d);
//	Add<double>(a, d);
//}


//int Add(int x,int y)
//{
//	return x + y;
//}

template<class T>
T Add(const T& x, const T& y)
{
	return x + y;
}
void Test06()
{
	Add(1, 2);      
	Add<int>(1, 2);
}

int Add(int x, int y)
{
	return x + y;
}

template<class T1,class T2>
T1 Add(const T1& x, const T2& y)
{
	return x + y;
}
void Test07()
{
	Add(1, 2);  //与非函数模板完全匹配，无需实例化
	Add(1.0,2); 
}



//template<class T1,class T2...>
//class 类模板名
//{
//	//...
//};

template<class T>
class Stack
{
public:
	Stack(size_t capacity = 4)
	{
		arr = new T[capacity];
		top = 0;
		_capacity = capacity;
	}


private:
	T* arr;
	size_t top;
	size_t capacity;
};



int main()
{
	//Test01();
	//Test02();
	//Test03();
	//Test04();
	//Test05();

	//Test06();
	//Test07();

	//stack是类名
	Stack<int> st1;    //int类型
	Stack<double> st2; //double类型


	return 0;
}

