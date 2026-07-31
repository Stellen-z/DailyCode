#pragma once
#include <iostream>

namespace stl
{
	//模板参数
	template<class T>
	class vector
	{
		typedef T* iterator;
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	public:
		//1、无参的默认构造函数
		//即使什么都不写，成员变量也会走初始化列表，使用缺省值
		vector()
		{}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		bool empty()
		{
			return _start == _finish;
		}

		void reserve(size_t n);
	};
	
	template<class T>
	void vector<T>::reserve(size_t n)
	{
		if (n > capacity())
		{
			//扩容
			iterator tmp = new[n] T;
			memcpy()

		}
	}

}
