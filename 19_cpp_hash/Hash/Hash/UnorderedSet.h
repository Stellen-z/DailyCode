#pragma once
#include "HashTable.h"

namespace stl
{
	template<class K,class Hash = HashFunc<K>>
	class unordered_set
	{
	public:
		struct SetOfKey
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		using iterator       = hash_bucket::HashTable<K, const K, SetOfKey, Hash>::iterator;
		using const_iterator = hash_bucket::HashTable<K,const K, SetOfKey, Hash>::const_iterator;


		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		const_iterator begin() const
		{
			return _ht.Begin();
		}

		const_iterator end() const
		{
			return _ht.End();
		}
		
		std::pair<iterator, bool> Insert(const K& key)
		{
			return _ht.Insert(key);
		}

		iterator Find(const K& key)
		{
			return _ht.Find(key);
		}

		bool Erase(const K& key)
		{
			return _ht.Erase(key);
		}


	private:
		hash_bucket::HashTable<K, const K, SetOfKey, Hash> _ht;
	};

	void test_set1()
	{
		int a[] = { 3,11,86,7,88,82,1,881,5,6,7,6 };
		unordered_set<int> s;
		for (auto e : a)
		{
			s.Insert(e);
		}

		unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			//*it = 1;
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		for (auto e : s)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;

	}
}