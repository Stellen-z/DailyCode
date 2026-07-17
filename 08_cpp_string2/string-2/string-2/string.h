#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <iostream>
#include <assert.h>

namespace stl
{
	class string
	{
	public:
		//string(const char* str = "")
		//	: _size(strlen(str))
		//	, _capacity(_size)
		//	, _str(new char[_size + 1])
		//{
		//	strcpy(_str, str);
	    //}
		string(const char* str = "")
		{
			if (str == nullptr)
			{
				//让 _str 永远指向一块有效内存
				_str = new char[1]('\0'); 

				_size = 0;
				_capacity = 0;

				return;
			}
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];

			strcpy(_str, str);
		}

		//传统写法
		////s2(s1)
		//string(const string& s)
		//{
		//	_size = s._size;
		//	_capacity = s._capacity;

		//	_str = new char[_size + 1];
		//	strcpy(_str, s._str);
		//}
		//
		////s3 = s1
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		_size = s._size;
		//		_capacity = s._capacity;

		//		delete[] _str;
		//		_str = new char[_size + 1];
		//		strcpy(_str, s._str);
		//	}
		//
		//	return *this;
		//}

		//现代写法
		void swap(string& s)
		{
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
			std::swap(_str, s._str);

		}
		string(const string& s)
		{
			string tmp(s._str);

			swap(tmp);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);

				swap(tmp);
			}
			return *this;
		}

		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}

		//容量类操作
		size_t size() const
		{
			return _size;
		}

		size_t length() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		bool empty() const
		{
			return _size == 0;
		}

		void claer()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		void reserve(size_t n = 0);
		void resize(size_t n, char c);

		//访问及遍历
		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[] (size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}
		 
		//修改操作
		void push_back(char c);
		string& append(const char* s);
		string& operator+=(const char* s);
		string& operator+=(char c);
		const char* c_str() const;
		size_t find(char c, size_t pos = 0) const;
		size_t find(const char* s, size_t pos = 0) const;
		string substr(size_t pos = 0, size_t len = npos) const;


	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;


		static const size_t npos;
	};

}