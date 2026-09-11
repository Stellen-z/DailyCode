#pragma once
#include "HashTable.h"

namespace stl
{
	template<class K,class T,class Hash>
	class unordered_map
	{
	public:
		struct MapOfKey
		{
			K& operator()(const std::pair<K,V>& kv)
			{
				return kv.first;
			}
		};
	};
}