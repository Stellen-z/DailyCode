#include <vector>

template <class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template <class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};

namespace stl
{
	template<class T, class Container = std::vector<T>, class Compare = Less<T>>
	class priority_queue
	{
	private:
		Container _con;
		Compare _cmp;
	public:
		void AdjustUp(size_t child)
		{
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//Less:父节点 < 孩子节点 -> 大根堆 
				//Greater:父节点 > 孩子节点 -> 小根堆 
				if (_cmp(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else break;
			}
		}

		void AdjustDown(size_t parent)
		{
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if(child + 1 < _con.size() && _cmp(_con[child],_con[child + 1])) ++child;
				//Less:父节点 < 孩子节点 -> 大根堆 
				//Greater:父节点 > 孩子节点 -> 小根堆 
				if (_cmp(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else break;
			}
		}
		
		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		T& top()
		{
			return _con.front();
		}

		const T& top() const
		{
			return _con.front();
		}

		const size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

	


	};

}