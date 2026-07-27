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
		}
		//更新_size
		_size = n;
		_str[_size] = '\0';
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

		return *this;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos >= 0);
		assert(pos <= _size);
		
		//扩容
		if (_size + 1 >= _capacity)
		{
			reserve(_size + 1 >= 2 * _capacity ? _size + 1 : 2 * _capacity);
		}

		//size_t end = _size;
		//while (end >= pos)
		//{
		//	_str[end + 1] = _str[end];
		//	--end;
		//}

		size_t end = _size + 1;
		while (end >= pos + 1)
		{
			_str[end] = _str[end - 1];
			--end;
		}

		_str[pos] = ch;
		_size++;

	}


	void string::insert(size_t pos, const char* str)
	{
		assert(pos >= 0);
		assert(pos <= _size);

		size_t len = strlen(str);
		if (_size + 1 + len >= _capacity)
		{
			reserve(_size + 1 + len >= 2 * _capacity ? _size + 1 + len: 2 * _capacity);
		}

		size_t end = _size + len;
		while (end >= pos + len)
		{
			_str[end] = _str[end - len];
			--end;
		}

		//填充数据
		for (size_t i = 0; i < len; i++)
		{
			_str[i + pos] = str[i];
		}
		
		_size += len;

	}

	void string::erase(size_t pos, size_t len)
	{
		assert(pos >= 0);
		assert(pos < _size);

		if (len >= _size - pos)
		{
			_size = pos;
			_str[pos] = '\0';
		}
		else
		{
			size_t begin = pos + len;
			while (begin <= _size)
			{
				_str[begin - len] = _str[begin];
				++begin;
			}

			_size -= len;
		}
	}


	string& string::operator+=(const char* s)
	{
		//复用append
		append(s);

		return *this;
	}

	string& string::operator+=(char c)
	{
		//复用push_back
		push_back(c);

		return *this;
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
		char* ret = strstr(_str + pos, s);
		if (ret == nullptr) return npos;

		return ret - _str;
	}

	string string::substr(size_t pos, size_t len) const
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

	std::ostream& operator<<(std::ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}
	std::istream& operator>>(std::istream& in, string& s)
	{
		s.clear();

		const int N = 128;
		char buff[N];
		int index = 0;

		char ch;
		//in >> ch;
		//使用get函数
		ch = in.get();
		
		while (ch != ' ' && ch != '\n')
		{
			buff[index++] = ch;

			//还有一个位置
			if (index == N - 1)
			{
				buff[index] = '\0';
				s += buff;

				index = 0;
			}

			//in >> ch;
			ch = in.get();
		}
		
		if (index > 0)
		{
			buff[index] = '\0';
			s += buff;
		}

		return in;
	}

	bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}
	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

}