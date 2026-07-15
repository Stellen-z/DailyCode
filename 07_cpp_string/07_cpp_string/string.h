#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <iostream>
#include <assert.h>
#include <cstring>

using namespace std;

namespace stn
{
	class string
	{
	public:
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


		//string()
		//	:_str(new char[1]('\0'))
		//	, _size(0)
		//	, _capacity(0)
		//{ }

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			//strcpy会将\0一并拷贝
			strcpy(_str, str);
		}

		//s2(s1)
		//string(const string& s)
		//{
		//	_str = new char[s._capacity + 1];
		//	strcpy(_str, s._str);
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}

		//现代写法
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		//s1(s2)
		string(const string& s)
		{
			string tmp(s);

			swap(tmp);
		}

		//s2 = s1
		//string& operator=(const string& s)
		//{
		//	//防止自己直接释放自己
		//	if (this != &s)
		//	{
		//		delete[] _str;
		//		_str = new char[s._capacity + 1];
		//		strcpy(_str, s._str);

		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	return *this;
		//}
		
		//s2 = s1
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		string tmp(s._str);

		//		swap(tmp);

		//		return *this;
		//	}
		//}

		//s2 = s1
		string& operator=(string tmp)
		{
			swap(tmp);

			return *this;
		}


		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			return _str[pos];
		}


		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t len = npos);

		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);
		string substr(size_t pos = 0, size_t len = npos);

	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;


		static const size_t npos;
	};

	bool operator<(const string& s1, const string& s2);
	bool operator<=(const string& s1, const string& s2);
	bool operator>(const string& s1, const string& s2);
	bool operator>=(const string& s1, const string& s2);
	bool operator==(const string& s1, const string& s2);
	bool operator!=(const string& s1, const string& s2);

	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in , string& s);


}

