#pragma once
#include <deque>

namespace stl
{
	template<class T,class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top() const
		{
			return _con.back();
		}

		const size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}


	private:
		Container _con;
	};
}