#pragma once
#include "HashTable.h"

namespace stl
{
template<class K,class V,class Hash = HashFunc<K>>
class unordered_map
{
public:
	struct MapOfT
	{
		const K& operator()(const std::pair<K, V>& kv)
		{
			return kv.first;
		}
	};

	using iterator       = hash_bucket::HashTable<K, std::pair<const K, V>, MapOfT, Hash>::iterator;
	using const_iterator = hash_bucket::HashTable<K, std::pair<const K, V>, MapOfT, Hash>::const_iterator;

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

	std::pair<iterator, bool> Insert(const std::pair<K, V>& kv)
	{
		return _ht.Insert(kv);
	}

	iterator Find(const K& key)
	{
		return _ht.Find(key);
	}

	bool Erase(const K& key)
	{
		return _ht.Erase(key);
	}

	V& operator[](const K& key)
	{
		std::pair<iterator, bool> ret = Insert({ key, V() });
		return ret.first->second;
	}

private:
	hash_bucket::HashTable<K, std::pair<const K, V>, MapOfT, Hash> _ht;
};

	void test_map1()
	{
		unordered_map<std::string,std::string> dict;
		dict.Insert({ "sort", "排序" });
		dict.Insert({ "字符串", "string" });

		dict.Insert({ "sort", "排序" });
		dict.Insert({ "left", "左边" });
		dict.Insert({ "right", "右边" });

		dict["left"] = "左边，剩余";
		dict["insert"] = "插入";
		dict["string"];

		for (auto& kv : dict)
		{
			std::cout << kv.first << ":" << kv.second << std::endl;
		}
		std::cout << std::endl;

		unordered_map<std::string, std::string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			// 不能修改first，可以修改second
			//it->first += 'x';
			it->second += 'x';
			std::cout << it->first << ":" << it->second << std::endl;
			++it;
		}
		std::cout << std::endl;
	}
}