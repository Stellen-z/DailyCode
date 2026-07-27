#include <iostream>
#include <vector>

using namespace std;

void test_vector1()
{
	vector<int> v1;
	vector<int> v2(10,1);

	vector<int> v3(++v2.begin(), --v2.end());

	//1.下标
	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;

	//2.迭代器
	//for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	for (auto it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	//3.范围for
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}

// 测试vector的默认扩容机制
void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
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

void test_vector2()
{
	//TestVectorExpand();

	vector<int> v(10, 1);
	//v.reserve(20);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;

	//v.reserve(15);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;

	//v.reserve(5);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;

	v.resize(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void test_vector3()
{
	vector<int> v(10, 1);
	v.push_back(2);

	v.insert(v.begin(), 0);

	v.insert(v.begin() + 3, 20);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin() + 3);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v1(10, 0);
	for (size_t i = 0; i < 10; i++)
	{
		cin >> v1[i];
	}
	
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector4()
{
	vector<string> v;
	v.push_back("xxx");

	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector5()
{
	vector<int> v(5, 1);
	vector<vector<int>> vv(10, v);

	for (size_t i = 0; i < vv.size(); i++)
	{
		for (size_t j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	//vv[2]调用的是vector<vector<int>>的[]重载函数 返回的是vector<int>的引用
	//vv[2][2]调用的是vector<int>的
	cout << vv[2][2] << endl;
}

void test_vector6()
{
	vector<vector<int>> vv(10);

	for (size_t i = 0; i < vv.size(); i++)
	{
		for (size_t j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}


int main()
{
	//test_vector1();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	test_vector6();



	return 0;
}