#pragma once
#include <iostream>
#include <assert.h>


namespace stl
{
	template<class T>
	struct list_node
	{
		list_node(const T& data = T())
			:_data(data)
			, _next(nullptr)
			,_prev(nullptr)
		{}

		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
	};
		

	//T  T&  T*
	//T const T& const T*
	template<class T,class Ref,class Ptr>
	//template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;

		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{}


		Ref operator*()
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

		//后置++
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

		Self& operator--(int)
		{
			Self tmp(*this);

			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};

	//const_iterator
	//const T* ptr;
	//const * T ptr
	//template<class T>
	//struct list_const_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef list_const_iterator<T> Self;

	//	Node* _node;

	//	list_const_iterator(Node* node)
	//		:_node(node)
	//	{}


	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	const Self& operator++() 
	//	{
	//		_node = _node->_next;

	//		return *this;
	//	}

	//	//后置++
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

	//	Self& operator--(int)
	//	{
	//		Self tmp(*this);

	//		_node = _node->_prev;

	//		return tmp;
	//	}


	//	bool operator!=(const Self& s) const
	//	{
	//		return _node != s._node;
	//	}

	//	bool operator==(const Self& s) const
	//	{
	//		return _node == s._node;
	//	}
	//};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator < T, T&, T* > iterator;
		typedef list_iterator < T, const T&, const T* > const_iterator;
	private:
		Node* _head;
		size_t _size;

	public:

		void empty_init()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		list()
		{
			empty_init();
		}


		list(list<T>& lt)
		{
			empty_init();

			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		void swap(list<T>& lt)
		{
			std::swap(lt->_head);
			std::swap(lt->_size);
		}

		list& operator=(list<T> lt)
		{
			swap(lt);

			return *this;
		}

		void clear()
		{
			list<T>::iterator it = begin();

			while (it != end())
			{
				//更新it
				it = erase(it);
			}
		}

		~list()
		{
			clear();
			
			delete _head;
			_head = nullptr;
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}
		

		size_t size() const
		{
			return _size;
		}
		
		bool empty() const
		{
			return _size == 0;
		}

		void push_back(const T& x = T())
		{
			Node* newnode = new Node(x);
			//找尾节点
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			++_size;
		}

		void push_front(const T& x = T())
		{
			insert(begin(), x);
		}

		iterator insert(iterator pos, const T& x = T())
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			//prev  newnode cur 
			newnode->_prev = prev;
			newnode->_next = cur;
			prev->_next = newnode;
			cur->_prev = newnode;

			++_size;

			return cur;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
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

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

	};

	struct AA
	{
		int _a1 = 1;
		int _a2 = 1;
	};

	template<class Container>
	void Print_Container(const Container& con)
	{
		//typename Container::const_iterator it = con.begin();
		//while (it != con.end())
		//{
		//	cout << *it << " ";
		//	++it;
		//}
		//cout << endl;

		for (const auto& e : con)
		{
			cout << e << " ";
		}
		cout << endl;
	}


}