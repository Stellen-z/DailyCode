#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

namespace stl
{
    class string
    {
        //friend ostream& operator<<(ostream& _cout, const bit::string& s);

        //friend istream& operator>>(istream& _cin, bit::string& s);

    public:
        typedef char* iterator;


        string(const char* str = "")
        {
            _size = strlen(str);
            _capacity = _size + 1;
            _str = new char[_size + 1];

            strcpy(_str, str);
        }

        //s2(s1)
        string(const string& s)
        {
            _size = s._size;
            _capacity = s._capacity;

            _str = new char[_size + 1];
            strcpy(_str, s._str);
        }

        //s2 = s1
        string& operator=(const string& s)
        {
            if (*this != s)
            {
                delete[] _str;

                _size = s._size;
                _capacity = s._capacity;

                _str = new char[_size + 1];
                strcpy(_str, s._str);
            }

            return *this;
            
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _capacity = 0;
            _size = 0;
        }



        //////////////////////////////////////////////////////////////

        // iterator

        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }



        /////////////////////////////////////////////////////////////

        // modify

        void push_back(char c);

        string& operator+=(char c);

        void append(const char* str);

        string& operator+=(const char* str);

        void clear()
        {
            _size = 0;
            _str[_size] = '\0';
        }

        void swap(string& s)
        {
            std::swap(_str,s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        const char* c_str()const
        {
            return _str;
        }



        /////////////////////////////////////////////////////////////

        // capacity

        size_t size()const
        {
            return _size;
        }

        size_t capacity()const
        {
            return _capacity;
        }

        bool empty()const
        {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0');

        void reserve(size_t n);



        /////////////////////////////////////////////////////////////

        // access

        char& operator[](size_t index)
        {
            return _str[index];
        }

        const char& operator[](size_t index)const
        {
            return _str[index];
        }



        /////////////////////////////////////////////////////////////

        //relational operators

        bool operator<(const string& s)
        {
            return strcmp(_str, s._str) < 0;
        }

        bool operator<=(const string& s)
        {
            return *this < s || *this == s;
        }

        bool operator>(const string& s)
        {
            return !(*this <= s);
        }

        bool operator>=(const string& s)
        {
            return !(*this < s);
        }

        bool operator==(const string& s)
        {
            return strcmp(_str, s._str) == 0;
        }

        bool operator!=(const string& s)
        {
            return !(*this == s);
        }



        // 返回c在string中第一次出现的位置

        size_t find(char c, size_t pos = 0) const;

        // 返回子串s在string中第一次出现的位置

        size_t find(const char* s, size_t pos = 0) const;

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置

        string& insert(size_t pos, char c);

        string& insert(size_t pos, const char* str);


        // 删除pos位置上的元素，并返回该元素的下一个位置

        string& erase(size_t pos, size_t len);

    private:
        char* _str = nullptr;
        size_t _size = 0;
        size_t _capacity = 0;
    };
}
