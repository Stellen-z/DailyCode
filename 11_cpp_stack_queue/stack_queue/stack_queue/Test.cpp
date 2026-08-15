#include <iostream>
#include <stack>
#include <queue>
#include <vector>



#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

void test_stack()
{
	std::stack<int> st;

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);

	std::cout << st.size() << std::endl;

	while (!st.empty())
	{
		std::cout << st.top() << " ";
		st.pop();
	}
	std::cout << std::endl;


}

void test_queue()
{
	std::queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	std::cout << q.size() << std::endl;

	while (!q.empty())
	{
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << std::endl;
}

//template <class T>
//class Less
//{
//public:
//	bool operator()(const T& x, const T& y)
//	{
//		return x < y;
//	}
//};
//
//template <class T>
//class Greater
//{
//public:
//	bool operator()(const T& x, const T& y)
//	{
//		return x > y;
//	}
//};

void test_priority_queue()
{
	//默认大根堆
	std::priority_queue<int> pq;

	pq.push(1);
	pq.push(3);
	pq.push(3);
	pq.push(5);
	pq.push(7);
	pq.push(7);

	std::cout << pq.size() << std::endl;


	while (!pq.empty())
	{
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << std::endl;
}

void test_functor()
{
	std::vector<int> v{ 2,6,8,3,6,9,1,2,7 };

	//大根堆
	std::priority_queue<int, std::vector<int>, Less<int>> Lpq;
	//小根堆
	std::priority_queue<int, std::vector<int>, Greater<int>> Gpq;

	for (const auto& e : v)
	{
		Lpq.push(e);
		Gpq.push(e);
	}

	std::cout << "大根堆:";
	while (!Lpq.empty())
	{
		std::cout << Lpq.top() << " ";
		Lpq.pop();
	}
	std::cout << std::endl;

	std::cout << "小根堆:";
	while (!Gpq.empty())
	{
		std::cout << Gpq.top() << " ";
		Gpq.pop();
	}
	std::cout << std::endl;

}

namespace stl
{
	void test_stack()
	{
		stack<int> st;

		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		st.push(6);

		std::cout << st.size() << std::endl;

		while (!st.empty())
		{
			std::cout << st.top() << " ";
			st.pop();
		}
		std::cout << std::endl;

	}

	void test_queue()
	{
		queue<int> q;

		q.push(6);
		q.push(5);
		q.push(4);
		q.push(3);
		q.push(2);
		q.push(1);

		std::cout << q.size() << std::endl;

		while (!q.empty())
		{
			std::cout << q.front() << " ";
			q.pop();
		}
		std::cout << std::endl;
	}

	void test_priority_queue()
	{
		std::vector<int> v{ 2,6,8,3,6,9,1,2,7 };

		//大根堆
		priority_queue<int, std::vector<int>, Less<int>> Lpq;
		std::cout << typeid(Lpq).name() << std::endl;
		//小根堆
		priority_queue<int, std::vector<int>, Greater<int>> Gpq;
		std::cout << typeid(Gpq).name() << std::endl;

		for (const auto& e : v)
		{
			Lpq.push(e);
			Gpq.push(e);
		}

		std::cout << "大根堆:";
		while (!Lpq.empty())
		{
			std::cout << Lpq.top() << " ";
			Lpq.pop();
		}
		std::cout << std::endl;

		std::cout << "小根堆:";
		while (!Gpq.empty())
		{
			std::cout << Gpq.top() << " ";
			Gpq.pop();
		}
		std::cout << std::endl;

	}

}




int main()
{
	//test_stack();
	//stl::test_stack();
	//test_queue();
	//stl::test_queue();
	//test_priority_queue();
	//test_functor();
	stl::test_priority_queue();

	return 0;
}