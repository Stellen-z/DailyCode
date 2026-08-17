#pragma once

namespace stl
{
	//N即为非类型模板参数
	template<size_t N = 2>
	class Stack
	{
	private:
		int _a[N];
		int _top;
		int _size;
	};

	template<class T, size_t N = 10>
	class array
	{
	public:
		T& operator[](size_t pos)
		{
			return _array[pos];
		}

		const T& operator[](size_t pos) const
		{
			return _array[pos];
		}

		size_t size()
		{
			return _size;
		}

		bool ematy()
		{
			return _size == 0;
		}

	private:
		size_t _size = 0;
		T _array[N];//N的大小来控制静态数组的大小
	};

	template<class T>
	bool less(const T& x,const T& y)
	{
		return x < y;
	}
	
	//特化
	template<>
	bool less<std::string*>(std::string* const & x, std::string* const & y)
	{
		return *x < *y;
	}

	bool less(std::string* const& x, std::string* const& y)
	{
		return *x < *y;
	}

	template<class T1,class T2>
	class example
	{
	public:
		example()
		{
			std::cout << "example<T1, T2>" << std::endl;
		}
	private:
		T1 _a;
		T2 _b;
	};

	template<>
	class example<int,char>
	{
	public:
		example()
		{
			std::cout << "example<int, char>" << std::endl;
		}
	private:
		int _a;
		char _b;
	};

	//偏特化
	template<class T>
	class example<T,int>
	{
	public:
		example()
		{
			std::cout << "example<T,int>" << std::endl;
		}
	private:
		T _a;
		int _b;
	};

	//参数偏特化为指针
	template<class T1,class T2>
	class example<T1*,T2*>
	{
	public:
		example()
		{
			std::cout << "example<T1*,T2*>" << std::endl;
		}
	private:
		T1* _a;
		T2* _b;
	};

	//参数偏特化为引用
	template<class T1, class T2>
	class example<T1&, T2&>
	{
	public:
		example(const T1& _a, const T2& _b)
			:_a(_a)
			,_b(_b)//引用必须要初始化
		{
			std::cout << "example<T1&, T2&>" << std::endl;
		}
	private:
		
		const T1& _a;
		const T2& _b;
	};
	
	//声明
	template<class T>
	T Add(const T& x, const T& y);
	
	//显示实例化
	template int Add(const int&, const int&);
	template double Add(const double&, const double&);


	//声明+定义
	//template<class T>
	//T Add(const T& x, const T& y)
	//{
	//	return x + y;
	//}



}