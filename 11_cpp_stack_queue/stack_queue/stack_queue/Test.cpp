#include <iostream>
#include <stack>
#include <queue>

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

#include "Stack.h"
#include "Queue.h"

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

}




int main()
{
	//test_stack();
	stl::test_stack();
	//test_queue();
	stl::test_queue();

	return 0;
}