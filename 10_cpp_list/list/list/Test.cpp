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

void test_operations()
{
	std::list<int> lt1(5,1);
	std::list<int> lt1(5,5);



}




int main()
{
	//test_constructor();
	//test_iterator();
	//test_capacity();
	//test_access();
	//test_modify();
	test_operations();

	return 0;
}