#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "vector.h"

void test_constructor1()
{
	//vector()
	vector<int> v1;

	//vector (size_type n, const value_type& val = value_type())
	vector<int> v2(10,1);

	//vector (const vector& x)
	vector<int> v3(v2);

	//vector (InputIterator first, InputIterator last)
	vector<int> v4(v2.begin(), v2.begin() + 5);
}
void test_constructor2()
{
	//vector()
	vector<string> v1;

	//vector (size_type n, const value_type& val = value_type())
	vector<string> v2(10, "cpp");

	//vector (const vector& x)
	vector<string> v3(v2);

	//vector (InputIterator first, InputIterator last)
	vector<string> v4(v2.begin(), v2.begin() + 5);
}

void test_constructor3()
{
	vector<int> v1(5, 1);
	vector<int> v2;

	//拷贝构造
	vector<int> v3 = v1;

	//赋值重载
	v2 = v1;
}

void test_iterator()
{
	vector<int> v(10, 1);

	//1.迭代器
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//2.范围for
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//3.反向迭代器
	for (auto it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void print_vector(vector<int>& v)
{
	//2.范围for
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_capacity()
{
	//vector<int> v(10, 1);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;
	//print_vector(v);

	//v.resize(20);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;
	//print_vector(v);


	//v.resize(15);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;
	//print_vector(v);


	//v.resize(5);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;
	//print_vector(v);


	vector<int> v(10, 1);
	v.reserve(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	print_vector(v);

	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	print_vector(v);

}

void test_access()
{
	vector<int> v(10, 1);

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void test_modify()
{
	vector<int> v(10, 1);

	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	print_vector(v);

	v.pop_back();
	print_vector(v);

	//查找
	vector<int>::iterator pos = find(v.begin(),v.end(),3);
	v.insert(pos, 10);

	v.insert(v.begin(), 20);
	print_vector(v);


	v.erase(v.end() - 1);
	print_vector(v);

	vector<int> vv(5, 2);
	swap(v, vv);

	cout << "v:" << endl;
	cout << vv.size() << endl;
	cout << vv.capacity() << endl;
	print_vector(v);

	cout << "vv:" << endl;
	print_vector(vv);
	cout << vv.size() << endl;
	cout << vv.capacity() << endl;
}

void test_cmpare()
{
	vector<int> v1(3, 20);
	vector<int> v2(5, 10);

	if (v1 == v2) cout << "v1 and v2 are equal" << endl;
	if (v1 != v2) cout << "v1 and v2 are not equal" << endl;
	if (v1 < v2) cout << "v1 is less than v2" << endl;
	if (v1 > v2) cout << "v1 is greater than v2" << endl;
	if (v1 <= v2) cout << "v1 is less than or equal to v2" << endl;
	if (v1 >= v2) cout << "v1 is greater than or equal to v2" << endl;
}

// 测试vector的默认扩容机制
void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();

	v.reserve(100);

	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void TEST1()
{
	//test_constructor1();
	//test_constructor2();
	//test_constructor3();

	//test_iterator();

	//test_capacity();

	//test_access();

	//test_modify();

	//test_cmpare();

	TestVectorExpand();
}

/////////////////////////////////////////////////////



int main()
{
	//TEST1();
	

	return 0;
}
