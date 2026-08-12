#pragma once

#include <vector>

//仿函数
template <class T>
class Less
{
public:
	//没有成员变量，大小为1字节
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template <class T>
class Greater
{
public:
	//没有成员变量，大小为1字节
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};


namespace stl
{
	//类模板参数传类型，函数参数传对象
	//默认建大堆，升序
	template<class T, class Container = std::vector<T>,class Compare = Less<T>>
	class priority_queue
	{
	private:
		Container _con;
	public:

		void AdjustUp(size_t child)
		{
			Compare _cmp;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] < _con[child])
				if (_cmp(_con[parent],_con[child]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else break;
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}

		void AdjustDown(int parent)
		{
			Compare _cmp;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && _cmp(_con[child],_con[child + 1])) ++child;
				//if (_con[parent] < _con[child])
				if (_cmp(_con[parent],_con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else break;
			}
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		const T& top()
		{
			return _con[0];
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