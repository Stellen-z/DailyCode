#pragma once
#include <list>

namespace stl
{
	template<class T,class Container = std::deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		T& front()
		{
			return _con.front();
		}

		const T& front() const
		{
			return _con.front();
		}

		T& back()
		{
			return _con.back();
		}

		const T& back() const
		{
			return _con.back();
		}

		const size_t size() const
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}