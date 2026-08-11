#pragma once

namespace stl
{
	//Container适配转换出stack
	template<class T,class Container = vector<T>>
	class stack
	{
	private:
		Container _con;
	public:
		//栈顶在尾
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top() const
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

	};
}