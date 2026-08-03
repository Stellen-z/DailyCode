#pragma once
#include <iostream>
#include <assert.h>
#include <algorithm>

namespace stl
{
	//模板参数
	template<class T>
	class vector
	{
	public:
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
		void resize(size_t n,const T& val = T());


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

		void push_back(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}

			*_finish = val;
			++_finish;
		}

		void pop_back()
		{
			assert(!empty());

			--_finish;
		}


		iterator insert(iterator pos, const T& val);
		iterator erase(iterator pos);


	};
	
	template<class T>
	void vector<T>::reserve(size_t n)
	{
		if (n > capacity())
		{
			size_t old_size = size();
			//扩容
			iterator tmp = new T[n] ;
			//memcpy(tmp, _start, old_size * sizeof(T));
			for (size_t i = 0; i < old_size; i++)
			{
				tmp[i] = _start[i];
			}

			delete[] _start;
			 
			//方法一
			//_finish = _tmp + size();
			//_start = _tmp;
			//_end_of_storage = _tmp + n;

			//方法二
			_start = tmp;
			_finish = _start + old_size;
			_end_of_storage = _start + n;

		}
	}

	template<class T>
	void vector<T>::resize(size_t n, const T& val)
	{
		if (n < size())
		{
			_finish = _start + n;
		}
		else
		{
			reserve(n);

			//挪动数据
			for (size_t i = size(); i < n; i++)
			{
				_start[i] = val;
			}
			_finish = _start + n;
		}
	}

	template<class T>
	void print_vector(vector<T>& v)
	{
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	template<class T>
	vector<T>::iterator vector<T>::insert(iterator pos, const T& val)
	{
		assert(pos >= _start);
		assert(pos <= _finish);

		if (_finish == _end_of_storage)
		{
			//更新pos
			size_t old_pos = pos - _start;
			reserve(capacity() == 0 ? 4 : 2 * capacity());
			pos = old_pos + _start;
		}
		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end + 1) = *end;
			--end;
		}

		*pos = val;

		++_finish;

		return pos;
	}

	template <class T>
	vector<T>::iterator vector<T>::erase(iterator pos)
	{
		assert(pos >= _start);
		assert(pos < _finish);

		auto begin = pos + 1;
		while (begin != _finish)
		{
			*(begin - 1) = *begin;
			++begin;
		}

		--_finish;

		return pos;
	}


}
