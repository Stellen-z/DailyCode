#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "Stack.h"
#include "Queue.h"

using namespace std;

namespace stl
{
	void test_stack()
	{
		stack<int, vector<int>> st;
		//stack<int, list<int>> st;

		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		while (!st.empty())
		{
			std::cout << st.top() << " ";
			st.pop();
		}
		std::cout << std::endl;
	}

	void test_queue()
	{
		queue<int, list<int>> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			std::cout << q.front() << " ";
			q.pop();
		}
		std::cout << std::endl;

	}

	void test_deque()
	{

	}


}

int main()
{
	stl::test_stack();
	stl::test_queue();
	stl::test_deque();

}

