#include <iostream>
#include <list>

template<class T>
void print_container(const T& val)
{
	for (auto& e : val)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_constructor()
{
	//1.默认构造
	std::list<int> lt1;
	print_container(lt1);

	//2.n个val构造
	std::list<int> lt2(5, 1);
	print_container(lt2); //1 1 1 1 1


	//3.迭代器构造	
	std::list<int> lt3(lt2.begin(), lt2.end());
	print_container(lt3); //1 1 1 1 1


	//4.拷贝构造
	std::list<int> lt4(lt3);
	print_container(lt4); //1 1 1 1 1
	
	std::cout << std::endl;


	std::list<int> lt5;
	
	//赋值重载
	lt5 = lt4;
	print_container(lt5);

	//拷贝构造
	std::list<int> lt6 = lt4;
	print_container(lt6);
	
}


void test_iterator()
{
	std::list<int> lt(10,1);
	
	//正向迭代器
	std::list<int>::iterator it = lt.begin();
	while(it != lt.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	//反向迭代器
	std::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;


	for (const auto& e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

}

void test_capacity()
{
	std::list<int> lt1;
	std::list<int> lt2(5, 1);

	std::cout << lt1.size() << std::endl;
	std::cout << lt2.size() << std::endl;

	std::cout << lt1.empty() << std::endl;
	std::cout << lt2.empty() << std::endl;

}

void test_access()
{
	std::list<int> lt(5,1);

	lt.front() = 10;
	lt.back() = 10;

	print_container(lt);//10 1 1 1 10
}

void test_modify()
{
	std::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	print_container(lt);

	lt.pop_back();
	print_container(lt);


	lt.push_front(10);
	lt.push_front(10);
	print_container(lt);


	lt.pop_front();
	print_container(lt);

	lt.erase(lt.begin());
	lt.erase(--lt.end());
	print_container(lt);

	std::list<int> ltt;
	ltt.swap(lt);

	print_container(lt);
	print_container(ltt);

	ltt.clear();
	print_container(ltt);
}

void test_splice()
{
	std::list<int> lt1(5,1);
	std::list<int> lt2(5,2);
	std::list<int> lt3(5,3);
	std::list<int> lt4(5,4);


	//void splice (iterator position, list& x);
	lt1.splice(lt1.begin(),lt2);
	print_container(lt1);

	//void splice (iterator position, list& x, iterator i);
	lt1.splice(lt1.begin(), lt3, lt3.begin());
	print_container(lt1);

	//void splice (iterator position, list& x, iterator first, iterator last);
	lt1.splice(lt1.begin(), lt4, lt4.begin(), lt4.end());
	print_container(lt1);

}

bool is_odd(const int& val)
{
	return val % 2 == 1;
}

void test_remove()
{
	std::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(4);
	lt.push_back(3);
	lt.push_back(2);
	lt.push_back(1);

	//void remove (const value_type& val);
	lt.remove(2);
	print_container(lt);
	
	//template <class Predicate>
	//void remove_if(Predicate pred);
	lt.remove_if(is_odd);
	print_container(lt);


}

void test_operations()
{
	std::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(2);
	lt1.push_back(1);
	print_container(lt1);

	//先排序再去重
	lt1.sort();
	lt1.unique();
	print_container(lt1);// 1 2 3

	std::list<int> lt2;
	lt2.push_back(5);
	lt2.push_back(6);
	lt2.push_back(7);
	lt2.push_back(8);
	print_container(lt2);

	lt1.sort();
	lt2.sort();

	//merge要求两个已排序的list
	//void merge (list& x)
	lt1.merge(lt2);
	print_container(lt1);


	lt1.reverse();
	print_container(lt1);

}


void TEST1()
{
	test_constructor();
	test_iterator();
	test_capacity();
	test_access();
	test_modify();
	test_splice();
	test_remove();
	test_operations();
}

#include "list.h"

namespace stl
{
	void Test_iterator()
	{
		list<int> lt;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;


	}


	void Test_customtypes()
	{
		list<A> lt;
		lt.push_back(A());
		lt.push_back(A());
		lt.push_back(A());
		lt.push_back(A());
		lt.push_back(A());


		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//std::cout << *it << " ";
			//std::cout << (*it)._a << " " << (*it)._b << std::endl;
			std::cout << it->_a << " " << it->_b << std::endl;
			//std::cout << it.operator->()->_a << " " << it.operator->()->_b << std::endl;
			++it;
		}
		std::cout << std::endl;
	}
	void Test_insert()
	{
		list<int> lt;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		print_container(lt);

		lt.insert(lt.begin(),10);
		lt.insert(lt.end(), 20);
		lt.insert(++lt.begin(), 10);
		print_container(lt);

		lt.erase(lt.begin());
		print_container(lt);

		lt.erase(--lt.end());
		print_container(lt);

		lt.erase(++lt.begin());
		print_container(lt);


	}

	void Test_push_pop()
	{
		list<int> lt;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		print_container(lt);


		lt.push_front(10);
		print_container(lt);

		lt.pop_back();
		print_container(lt);

		lt.pop_front();
		print_container(lt);

	}

	void Test_constructor()
	{
		//1.默认构造
		list<int> lt1;
		print_container(lt1);

		//2.n个val构造
		list<int> lt2(10, 1);
		print_container(lt2);

		//3.迭代器区间构造
		list<int> lt3(++lt2.begin(), --lt2.end());
		print_container(lt3);

		//4.拷贝构造
		list<int> lt4(lt3);
		print_container(lt4);

		//两个已经存在的对象才会调用=
		list<int> lt5;
		lt5 = lt4;
		print_container(lt5);

	}


}


int main()
{
	//TEST1();

	//stl::Test_iterator();
	//stl::Test_customtypes();
	//stl::Test_insert();
	//stl::Test_push_pop();
	stl::Test_constructor();
	return 0;
}