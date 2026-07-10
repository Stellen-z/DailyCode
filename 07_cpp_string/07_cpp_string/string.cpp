#include "string.h"

namespace stn
{
	static const size_t npos = -1;

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;

			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			//扩容
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}

		_str[_size++] = ch;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}
		strcpy(_str + _size, str);
		_size += len;
	}

	string& string::operator+=(char ch)
	{
		push_back(ch);

		return *this;
	}
	string& string::operator+=(const char* str)
	{
		append(str);

		return *this;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);

		//挪动数据
		if (_size == _capacity)
		{
			reserve(_capacity = _capacity == 0 ? 4 : 2 * _capacity);
		}

		for (size_t i = _size; i >= pos + 1; i--)
		{
			_str[i] = _str[i - 1];
		}
		
		_str[pos] = ch;
		_size++;
		_str[_size] = '\0';

	}
	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		//挪动数据
		if (_size == _capacity)
		{
			reserve(_capacity = _capacity == 0 ? 4 : 2 * _capacity);
		}

		for (size_t i = _size; i >= pos + 1; i--)
		{
			_str[i] = _str[i - 1];
		}

		size_t len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			_str[pos++] = str[i];
		}

		_size += len;
		_str[_size] = '\0';
	}


}