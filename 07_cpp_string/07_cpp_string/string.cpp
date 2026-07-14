#include "string.h"

namespace stn
{
	const size_t string::npos = -1;

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			cout << "reserve:" << n << endl;

			char* tmp = new char[n + 1];
			//strcpy会一并拷贝\0
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

		//for (size_t i = _size; i >= pos; i--)
		//{
		//	_str[i + 1] = _str[i];
		//}
		
		//1.
		//无符号整形当end = -1时即7,继续进入循环
		//size_t end = _size;
		//while (end >= (int)pos)	
		//{
		//	_str[end + 1] = _str[end];
		//	end--;
		//}


		//2.
		//从\0的下一个位置开始
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}

		_str[pos] = ch;
		_size++;

	}
	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		//挪动数据
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}

		//for (size_t i = _size; i >= pos; i--)
		//{
		//	_str[i + 1] = _str[i];
		//}

		//1.
		//无符号整形当end = -1时即7,继续进入循环
		//size_t end = _size;
		//while (end >= (int)pos)	
		//{
		//	_str[end + 1] = _str[end];
		//	end--;
		//}
	

		//2.
		//从\0的下一个位置开始
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
		}

		for (int i = 0; i < len; i++)
		{
			_str[pos++] = str[i];
		}

		_size += len;
	}

	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);

		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			for (size_t i = pos + len; i < _size; i++)
			{
				_str[i - len] = _str[i];
			}
			_size -= len;
		}
	}

	size_t string::find(char ch, size_t pos)
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (ch == _str[i]) return i;
		}
		return npos;
	}

	size_t string::find(const char* str, size_t pos)
	{
		assert(pos < _size);

		const char* ptr = strstr(_str + pos, _str);

		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
	}

	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);

		//跟新len有效长度为剩余子串长度
		if (len > _size - pos)
		{
			len = _size - pos;
		}

		//开空间
		string sub;
		sub.reserve(len);

		for (size_t i = pos; i < len; i++)
		{
			sub += _str[pos++];
		}

		return sub;
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

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << s;
		}

		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		const int N = 256;

		char ch;
		in >> ch;

		char buff[N];
		int i = 0;
		
		while (ch != ' ' && ch != '\n')
		{
			//s += ch;
			

			buff[i++] = ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;

				i = 0;
			}

			//in >> ch;
			ch = in.get();
		}

		if (i > 0)
		{
			buff[i] = '\0';

			s += buff;
		}

		return in;
	}

}



