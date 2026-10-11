#include "AVL.h"
#include <vector>

namespace stl
{
	void test_insert()
	{
		AVLTree<std::string, int> dict;

		dict.Insert(std::make_pair("sort", 1));
		dict.Insert(std::make_pair("string", 1));
		dict.Insert(std::make_pair("test", 1));
		dict.Insert(std::make_pair("hello", 1));
		dict.Insert(std::make_pair("world", 1));


		dict.InOrder();

	}

	void test_balance()
	{
		AVLTree<int, int> t;
		// 常规的测试用例
		int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		// 特殊的带有双旋场景的测试用例
		//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

		for (auto e : a)
		{
			t.Insert({ e, e });
		}

		t.InOrder();
		std::cout << t.IsBalanceTree() << std::endl;
	}

}

int main()
{
	//stl::test_insert();
	stl::test_balance();
	return 0;
}



























