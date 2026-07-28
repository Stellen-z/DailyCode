#pragma once
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <list>

namespace stl
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//即使没写初始化列表，成员变量也会走初始化列表
		//对于内置类型使用缺省值，对于自定义类型会调用其默认构造
		vector() {};

		//C++11强制生成默认构造
		//vector() = default;

		vector(const vector<T>& v)
		{
			//提前开好空间，防止多次扩容
			reserve(v.size());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		//类模版的成员函数还可以继续是函数模版
		template<class InputIterator>
		//迭代器区间构造
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n,const T& val = T())
		{
			reserve(n);

			for (size_t i = 0;i < n;i++)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
		{
			reserve(n);

			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		void clear()
		{
			_finish = _start;
		}

		//传统写法
		//v1 = v3
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		clear();

		//		//如果v.size() < size()，reserve会检查，就不会扩容
		//		reserve(v.size());
		//		for (auto& e : v)
		//		{
		//			push_back(e);
		//		}
		//	}

		//	return *this;
		//}


		//现代写法
		//传值，不能改变v
		vector<T>& operator=(vector<T> v)
		{
			swap(v);

			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;

				_start = _finish = _end_of_storage = nullptr;
			}
		}

		iterator begin() 
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];

				size_t old_size = size();

				//memcpy是浅拷贝，vector内如果有自定义类型就会导致内存泄漏
				//memcpy(tmp, _start,old_size * sizeof(T));
				for (size_t i = 0; i < old_size; i++)
				{
					tmp[i] = _start[i];
				}

				delete[] _start;

				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n,const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		bool empty() const
		{
			return _start == _finish;
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(!empty());

			--_finish;
		}

		//pos是迭代器，指向有效位置
		iterator insert(iterator pos,const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			iterator it = pos + 1;
			while (it != end())
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;

			return pos;
		}


		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	template<class Container>
	void print_Container(const Container& v)
	{
		//2.迭代器
		//for (auto it = v.begin(); it != v.end(); it++)
		//{
		//	cout << *it << " ";
		//}
		//cout << endl;
		
		//类模板实例化之前不能取东西
		//编译器不能区分const_iterator是类型还是静态成员变量
		//加上typename表示取出的是类型，非静态成员变量
		typename Container::const_iterator it = v.begin();
		//或者直接使用auto即可
		//auto it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;


		//3.范围for
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void Test_vector1()
	{
		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		//for (size_t i = 0; i < v.size(); i++)
		//{
		//	cout << v[i] << " ";
		//}
		//cout << endl;

		////1.下标
		//for (size_t i = 0; i < v.size(); i++)
		//{
		//	cout << v[i] << " ";
		//}
		//cout << endl;

		////2.迭代器
		////for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
		//for (auto it = v.begin(); it != v.end(); it++)
		//{
		//	cout << *it << " ";
		//}
		//cout << endl;

		////3.范围for
		//for (auto e : v)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;
		
		print_Container(v);
	}

	void Test_vector2()
	{
		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		print_Container(v);

		v.insert(v.begin() + 2,10);
		print_Container(v);


		int x; cin >> x;
		auto pos = find(v.begin(), v.end(), x);
		if (pos != v.end())
		{
			//insert之后，pos就失效了，不能访问
			//v.insert(pos, 20);

			//接受返回值并更新才能访问
			pos = v.insert(pos, 20);
			*(pos) *= 10;
		}
		print_Container(v);

	}

	void Test_vector3()
	{
		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		v.push_back(5);

		print_Container(v);

		//删除所有偶数
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{																										
				it = v.erase(it);
			}
			else ++it;
		}

		print_Container(v);

	}

	void Test_vector4()
	{
		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		print_Container(v);

		vector<int> v1 = v;

		print_Container(v1);

		vector<int> v2;

		v2.push_back(10);
		v2.push_back(20);
		v2.push_back(30);
		print_Container(v2);

		v = v2;

		print_Container(v);

	}

	void Test_vector5()
	{
		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		print_Container(v);

		vector<int> v1(v.begin(), v.begin() + 3);
		print_Container(v1);

		list<int> lt;
		lt.push_back(10);
		lt.push_back(10);
		lt.push_back(10);
		print_Container(lt);

		vector<int> v3(lt.begin(), lt.end());
		print_Container(v3);

		vector<string> v4(10, "111111111");
		print_Container(v4);

		vector<int> v5(10);
		print_Container(v5);

		vector<int> v6(10, 1);
		print_Container(v6);
	}

	void Test_vector6()
	{
		vector<string> v;
		v.push_back("111111111");
		v.push_back("111111111");
		v.push_back("111111111");
		v.push_back("111111111");
		v.push_back("111111111");

		print_Container(v);
	}

}

