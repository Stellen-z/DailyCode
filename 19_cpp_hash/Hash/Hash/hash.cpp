#include <iostream>
#include "HashTable.h"

using namespace std;

void test1()
{
	//int a[] = { 19,30,52,32,26,76,10 };
	int a[] = { 19,30,5,36,13,20,21,12,56,28 };

	openaddress::HashTable<int, int> ht;
	for (auto& e : a)
	{
		ht.Insert({ e,e });
	}
	
	ht.Erase(20);
	if (ht.Find(20))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}

 }

void test_2()
{
	//int a[] = { 19,30,52,63,11,22 };
	const char* a1[] = { "abcd", "sort", "insert" };
	openaddress::HashTable<string, string> ht1;
	for (auto& e : a1)
	{
		ht1.Insert({ e, e });
	}

	int a2[] = { -19,-30,5,36,13,20,21,12 };
	openaddress::HashTable<int, int> ht2;
	for (auto e : a2)
	{
		ht2.Insert({ e, e });
	}

	cout << "1" << endl;

	//// 哈希冲突
	//HashTable<Date, int, DateHashFunc> ht;
	//ht.Insert({ { 2024, 10, 12 }, 1});
	//ht.Insert({ { 2024, 12, 10 }, 1 });
}

//void test_3()
//{
//	int a2[] = { 19,30,5,36,13,20,21,12,24,96 };
//	hash_bucket::HashTable<int, int> ht2;
//	for (auto e : a2)
//	{
//		ht2.Insert({ e, e });
//	}
//
//	//ht2.Insert({ 100, 100 });
//	//ht2.Insert({ 101, 101 });
//	
//	cout << ht2.Find(96) << endl;
//	cout << ht2.Find(30) << endl;
//	cout << ht2.Find(19) << endl << endl;
//
//	ht2.Erase(96);
//	ht2.Erase(30);
//	ht2.Erase(19);
//
//	cout << ht2.Find(96) << endl;
//	cout << ht2.Find(30) << endl;
//	cout << ht2.Find(19) << endl << endl;
//
//	const char* a1[] = { "abcd","sort","insert" };
//	hash_bucket::HashTable<string, string> ht1;
//	for (auto& e : a1)
//	{
//		ht1.Insert({ e,e });
//	}
//
//	cout << 1 << endl;
//
//}

#include "UnorderedSet.h"
#include "UnorderedMap.h"

int main()
{
	//test1();
	//test_2();

	//test_3();

	stl::test_set1();
	return 0;
}