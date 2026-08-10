#include <iostream>
#include <algorithm>

namespace stl
{
	//节点
	template<class T>
	struct list_node
	{
		typedef list_node<T> Node;

		list_node(const T& data = T())
			:_data(data)
			, _prev(nullptr)
			, _next(nullptr)
		{}

		T _data;
		list_node<T>* _prev;
		list_node<T>* _next;
	};

	//迭代器
	//template<class T>
	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T,T&,T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;
		typedef list_iterator<T,Ref,Ptr> Self;

		list_iterator(Node* node)
			:_node(node)
		{}

		Node* _node;

		Ref& operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;

			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			
			_node = _node->_next;

			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;

			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);

			_node = _node->_prev;

			return tmp;
		}
		
		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

	};

	//const_iterator
	//template<class T>
	//struct list_const_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef list_const_iterator<T> Self;

	//	list_const_iterator(Node* node)
	//		:_node(node)
	//	{}

	//	Node* _node;

	//	const T& operator*() const 
	//	{
	//		return _node->_data;
	//	}
	// 
	// 
	//  const T* operator->() const 
	// {
	//	    return &_node->_data;
	// }
	// 
	//	Self& operator++()
	//	{
	//		_node = _node->_next;

	//		return *this;
	//	}

	//	Self operator++(int)
	//	{
	//		Self tmp(*this);

	//		_node = _node->_next;

	//		return tmp;
	//	}

	//	Self& operator--()
	//	{
	//		_node = _node->_prev;

	//		return *this;
	//	}

	//	Self operator--(int)
	//	{
	//		Self tmp(*this);

	//		_node = _node->_prev;

	//		return tmp;
	//	}

	//	bool operator==(const Self& s) const
	//	{
	//		return _node == s._node;
	//	}

	//	bool operator!=(const Self& s) const
	//	{
	//		return _node != s._node;
	//	}

	//};


	template<class T>
	class list
	{
	public:
		typedef list_node<T> Node;
		typedef list_iterator<T,T&,T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;

	private:
		Node* _head;
		size_t _size;
	public:
		//默认构造

		void empty_init()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		//n个val构造
		list(size_t n, const T& val = T())
		{
			//先创建头节点
			empty_init();

			for (size_t i = 1; i <= n; i++)
			{
				push_back(val);
			}
		}

		list(int n, const T& val = T())
		{
			//先创建头节点
			empty_init();

			for (size_t i = 1; i <= n; i++)
			{
				push_back(val);
			}
		}


		//迭代器区间构造
		template <class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			//先创建头节点
			empty_init();

			auto it = first;
			while (it != last)
			{
				push_back(*it);
				++it;
			}
		}


		//拷贝构造
		list(const list<T>& lt)
		{
			//先创建头节点
			empty_init();

			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		//现代写法
		list& operator=(list<T> lt)
		{
			swap(lt);

			return *this;
		}

		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}


		~list()
		{
			clear();

			delete _head;
			_head = nullptr;

			_size = 0;
		}

		size_t size()
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head->_prev->_next;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head->_prev->_next;
		}
		
		void push_back(const T& val = T());

		iterator insert(iterator pos, const T& val);
		iterator erase(iterator pos);
		
		void push_front(const T& val)
		{
			insert(begin(), val);
		}
		
		void pop_front()
		{
			erase(begin());
		}

		void pop_back()
		{
			erase(--end());
		}


	};

	template<class T>
	void list<T>::push_back(const T& val)
	{
		Node* newnode = new Node(val);

		_head->_prev->_next = newnode;
		newnode->_prev = _head->_prev;
		newnode->_next = _head;
		_head->_prev = newnode;

		_size++;
	}

	template<class Con>
	void print_container(const Con& con)
	{
		for (const auto& e : con)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

	struct A
	{
		int _a = 1;
		int _b = 1;
	};

	template<class T>
	list<T>::iterator list<T>::insert(iterator pos, const T& val)
	{
		Node* newnode = new Node(val);
		Node* cur = pos._node;
		Node* prev = cur->_prev;

		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
		prev->_next = newnode;

		++_size;

		return newnode;
	}

	template<class T>
	list<T>::iterator list<T>::erase(iterator pos)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;

		delete cur;
		cur = nullptr;

		--_size;

		return next;
	}

}