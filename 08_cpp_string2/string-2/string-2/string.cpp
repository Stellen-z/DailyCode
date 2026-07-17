#include "string.h"

namespace stl
{
	const size_t string::npos = -1;

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			_capacity = n;

			strcpy(tmp, _str);
			delete[] _str;

			_str = tmp;
		}
	}

	void string::resize(size_t n, char c)
	{
		if (n > _size)
		{
			//扩容
			if (_size + 1 >= _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			//填充字符c
			for (size_t i = _size; i < n; i++)
			{
				_str[i] = c;
			}

			//更新_size
			_size = n;
		}
	}

	void string::push_back(char c)
	{
		//扩容
		if (_size + 1 >= _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}

		_str[_size++] = c;
		_str[_size] = '\0';
	}

	string& string::append(const char* s)
	{
		//扩容
		size_t len = strlen(s);
		if (len + _size + 1 >= _capacity)
		{
			reserve(len + _size + 1 > 2 * _capacity ? len + _size + 1 : 2 * _capacity);
		}

		//strcpy即可
		strcpy(_str + _size, s);

		//更新_size
		_size += len;
	}

	string& string::operator+=(const char* s)
	{
		//复用append
		append(s);
	}


	string& string::operator+=(char c)
	{
		//复用push_back
		push_back(c);
	}

	const char* string::c_str() const
	{
		return _str;
	}

	size_t string::find(char c, size_t pos) const
	{
		assert(pos < _size);

		//从pos位置向后查找
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == c) return i;
		}
		return npos;
	}


	size_t string::find(const char* s, size_t pos) const
	{
		assert(pos < _size);

		//strstr()返回第一次出现位置的地址，减去起始地址即为下标
		return strstr(_str + pos, s) - _str;
	}

	string string::substr(size_t pos = 0, size_t len = npos) const
	{
		assert(pos < _size);

		//更新len
		if (_size - pos < len)
		{
			len = _size - pos;
		}

		string tmp;
		tmp.reserve(len);

		for (size_t i = pos; i < pos + len; i++)
		{
			tmp += _str[i];
		}

		return tmp;
	}

}