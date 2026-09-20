#include "BSTree.h"

namespace stl
{
	void test_insert()
	{
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		BST<int> bt;
		for (auto& e : a)
		{
			bt.Insert(e);
		}
	
		bt.InOrder();

		std::cout << bt.Find(1) << std::endl;
		std::cout << bt.Find(3) << std::endl;
		std::cout << bt.Find(100) << std::endl;
		std::cout << bt.Find(6) << std::endl;
		std::cout << bt.Find(7) << std::endl;

	}


	void test_erase()
	{
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		BST<int> bt;
		for (auto& e : a)
		{
			bt.Insert(e);
		}

		bt.InOrder();		

		bt.Erase(3);
		bt.InOrder();

		bt.Erase(4);
		bt.InOrder();

		bt.Erase(8);
		bt.InOrder();
	}



}

int main()
{
	//stl::test_insert();
	stl::test_erase();
	return 0;
}



















