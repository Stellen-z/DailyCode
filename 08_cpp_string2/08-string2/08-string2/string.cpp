#include "string.h"

namespace stl
{
	void string::resize(size_t n, char c)
	{
		if (n > _size)
		{
			reserve(n + 1 > _capacity ? n + 1 : _capacity);

			while (_size < n)
			{
				push_back(c);
				_size++;
			}

			_str[_size] = '\0';
		}
		else if(n < _size)
		{
			_size = n;
			_str[_size] = '\0';
		}
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n];
			strcpy(tmp, _str);

			delete[] _str;
			_str = tmp;
			tmp = nullptr;
			_capacity = n;
		}
	}


	void string::push_back(char c)
	{
		_str[_size++] = c;
		_str[_size] = '\0';
	}

	string& string::operator+=(char c)
	{
		push_back(c);

		return *this;
	}

	void string::append(const char* str)
	{
		size_t sz = strlen(str);
		//扩容
		if (sz + _size + 1 > _capacity)
		{
			reserve(sz + _size + 1 > 2 * _capacity ? sz + _size + 1 : 2 * _capacity);
		}

		for (int i = 0; i < sz; i++)
		{
			_str[_size + i] = str[i];
		}

		_size += sz; 
		
		_str[_size] = '\0';
	}

	string& string::operator+=(const char* str)
	{
		append(str);

		return *this;
	}


	// 返回c在string中第一次出现的位置
	size_t string::find(char c, size_t pos) const
	{
		assert(pos < _size);
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == c) return i;
		}
		return -1;
	}

	// 返回子串s在string中第一次出现的位置
	size_t string::find(const char* s, size_t pos) const
	{
		assert(pos < _size);
		return strstr(_str, s) - _str;
	}

	// 在pos位置上插入字符c/字符串str，并返回该字符的位置
	string& string::insert(size_t pos, char c)
	{
		assert(pos <= _size);

		//扩容
		if (_size + 1 >= _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}

		for (size_t i = _size + 1; i > pos; i--)
		{
			_str[i] = _str[i - 1];
		}
		_str[pos] = c;
		_size++;


		return *this;
	}

	string& string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		size_t len = strlen(str);
		//扩容
		if (len + _size + 1 > _capacity)
		{
			reserve(len + _size + 1 > 2 * _capacity ? len + _size + 1 : 2 * _capacity);
		}

		for (size_t i = _size + len; i > pos + len - 1; i--)
		{
			_str[i] = _str[i - len];
		}

		//添加
		for (int i = 0; i < len; i++)
		{
			_str[pos + i] = str[i];
		}

		_size += len;

		return *this;
	}

	// 删除pos位置上的元素，并返回该元素的下一个位置
	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		assert(pos + len <= _size);

		for (size_t i = pos + len; i <= _size; i++)
		{
			_str[i - len] = _str[i];
		}

		_size -= len;

		return *this;
	}


}