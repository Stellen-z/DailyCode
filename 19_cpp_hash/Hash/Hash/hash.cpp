#include "HashTable.h"

namespace open_address
{
	void test_insert()
	{
		int a[] = { 19,30,5,36,13,20,23};
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert({ e, e });
		}
		
		ht.Insert({ 15, 15 });


		ht.Erase(30);
		if (ht.Find(20))
		{
			std::cout << "找到了" << std::endl;
		}
		else
		{
			std::cout << "没有找到" << std::endl;
		}
		
		if (ht.Find(30))
		{
			std::cout << "找到了" << std::endl;
		}
		else
		{
			std::cout << "没有找到" << std::endl;
		}
	}

	void test_template()
	{
	    int a[] = { 19,30,52,63,11,22 };
		
		const char* a1[] = { "abcd", "sort", "insert" };
		HashTable<std::string, std::string> ht1;
		for (auto& e : a1)
		{
			ht1.Insert({ e, e });
		}
	
		std::cout << HashFunc<std::string>()("abcd") << std::endl;
		std::cout << HashFunc<std::string>()("bcad") << std::endl;
		std::cout << HashFunc<std::string>()("aadd") << std::endl;
	
		int a2[] = { -19,-30,5,36,13,20,21,12 };
		HashTable<int, int> ht2;
		for (auto e : a2)
		{
			ht2.Insert({ e, e });
		}
	
	}
}

namespace hash_bucket
{
	void test_insert()
	{
		int a[] = { 19,30,5,36,13,20,23,38,27,69};
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert({ e, e });
		}

		ht.Insert({ 15, 15 });

	}

	void test_template()
	{
		int a[] = { 19,30,52,63,11,22 };

		const char* a1[] = { "abcd", "sort", "insert" };
		HashTable<std::string, std::string> ht1;
		for (auto& e : a1)
		{
			ht1.Insert({ e, e });
		}

		std::cout << HashFunc<std::string>()("abcd") << std::endl;
		std::cout << HashFunc<std::string>()("bcad") << std::endl;
		std::cout << HashFunc<std::string>()("aadd") << std::endl;

		int a2[] = { -19,-30,5,36,13,20,21,12 };
		HashTable<int, int> ht2;
		for (auto e : a2)
		{
			ht2.Insert({ e, e });
		}

	}
}

int main()
{
	//open_address::test_insert();
	//open_address::test_template();

	//hash_bucket::test_insert();
	hash_bucket::test_template();
	return 0;
}