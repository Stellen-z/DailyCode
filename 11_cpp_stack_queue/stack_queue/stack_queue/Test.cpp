#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>

#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
//#include "PriorityQueue.h"

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




	template<class Com>
	void BubbleSort(int* a, int n,Com cmp)
	{
		for (int j = 0; j < n - 1; j++)
		{
			int flag = 1;
			for (int i = 0; i < n - 1 - j; i++)
			{
				//if (a[i] < a[i - 1])
				if (cmp(a[i + 1],a[i]))
				{
					swap(a[i], a[i + 1]);
					flag = 0;
				}
			}
			if (flag == 1) break;
		}
		
	}

	void test_priority_queue()
	{
		//测试仿函数
		//int a[] = { 1,5,7,2,8,4,0,3,6 };
		//BubbleSort(a, sizeof(a) / sizeof(int), Less<int>());
		//BubbleSort(a, sizeof(a) / sizeof(int), Greater<int>());

		//priority_queue<int> pq;
		priority_queue<int,vector<int>,greater<int>> pq;

		pq.push(1);
		pq.push(3);
		pq.push(4);
		pq.push(6);
		pq.push(8);

		while (!pq.empty())
		{
			std::cout << pq.top() << " ";
			pq.pop();
		}
		std::cout << std::endl;

	}


}

int main()
{
	//stl::test_stack();
	//stl::test_queue();
	stl::test_priority_queue();

}

