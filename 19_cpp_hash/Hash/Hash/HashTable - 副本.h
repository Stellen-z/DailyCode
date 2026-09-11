#pragma once
#include <vector>


enum State
{
	EXIST,
	EMPTY,
	DELETE
};

inline unsigned long __stl_next_prime(unsigned long n)
{
	// Note: assumes long is at least 32 bits.
	static const int __stl_num_primes = 28;
	static const unsigned long __stl_prime_list[__stl_num_primes] =
	{
			53,         97,         193,        389,        769,
			1543,       3079,       6151,       12289,      24593,
			49157,      98317,      196613,     393241,     786433,
			1572869,    3145739,    6291469,    12582917,   25165843,
			50331653,   100663319,  201326611,  402653189,  805306457,
			1610612741, 3221225473, 4294967291
	};
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list +
		__stl_num_primes;
	const unsigned long* pos = std::lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}

//转成 size_t
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

//模板特化
template<>
struct HashFunc<std::string>
{
	size_t operator()(const std::string& s)
	{
		size_t hash = 0;
		for (auto& e : s)
		{
			hash += e;
			hash *= 131;
		}
		return hash;
	}
};

namespace openaddress
{
	template<class K, class V>
	struct HashData
	{
		std::pair<K, V> _kv;
		State _state = EMPTY;

	};


	template<class K, class V,class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
			:_tables(__stl_next_prime(0))
			, _n(0)
		{}



		bool Insert(const std::pair<K, V>& kv)
		{
			if (Find(kv.first)) return false;
			Hash hash;
			//负载因子 >= 0.7
			if (_n * 10 / _tables.size() >= 7)
			{
				//扩容
				HashTable<K, V,Hash> newht;
				newht._tables.resize(__stl_next_prime(_tables.size() + 1));

				for (auto& e : _tables)
				{
					if (e._state == EXIST) newht.Insert(e._kv);
				}

				_tables.swap(newht._tables);
			}

			size_t hash0 = hash(kv.first) % _tables.size();
			size_t hashi = hash0;
			size_t i = 1;
			while (_tables[hashi]._state == EXIST)
			{
				hashi = (hash0 + i) % _tables.size();
				++i;
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hash;

			size_t hash0 = hash(key) % _tables.size();
			size_t hashi = hash0;
			size_t i = 0;

			while (_tables[hashi]._state != EMPTY)
			{
				//由于循环条件是非空，可能是删除或存在，因此判断是必须存在且相等
				if (_tables[hashi]._state == EXIST && _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				hashi = (hash0 + i) % _tables.size();
				++i;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);

			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				ret->_state = DELETE;
				return true;
			}

		}

	private:
		std::vector<HashData<K, V>> _tables;
		size_t _n;
	};
}


namespace hash_bucket
{
	template<class K,class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		std::pair<K, V> _kv;

		HashNode(const std::pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{}
	};

	template<class K,class V,class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		using Node = HashNode<K, V>;

		HashTable(size_t size = __stl_next_prime(0))
			:_table(size)
			, _n(0)
		{}

		void Destroy()
		{
			for (int i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;

					cur = next;
				}

				_table[i] = nullptr;
				
			}
			_n = 0;
		}

		~HashTable()
		{
			Destroy();
			//自动调用自定义类型析构
		}

		HashTable(const HashTable& ht)
			: _n(0)
		{
			_table.resize(ht._table.size(),nullptr);
			for (int i = 0; i < ht._table.size(); i++)
			{
				Node* cur = ht._table[i];
				while (cur)
				{
					Node* newnode = new Node(cur->_kv);

					//头插到新链表
					newnode->_next = _table[i];
					_table[i] = newnode;

					++_n;

					cur = cur->_next;
				}
			}
		}

		HashTable& operator=(const HashTable& ht)
		{
			if (this != &ht)
			{
				//1.清空自身节点
				Destroy();

				//2.深拷贝
				_table.resize(ht._table.size(), nullptr);
				for (int i = 0; i < ht._table.size(); i++)
				{
					Node* cur = ht._table[i];
					while (cur)
					{
						Node* newnode = new Node(cur->_kv);

						//头插到新链表
						newnode->_next = _table[i];
						_table[i] = newnode;

						++_n;

						cur = cur->_next;
					}
				}
			}
			return *this;
		}

		bool Insert(const std::pair<K,V>& kv)
		{
			if (Find(kv.first)) return false;

			Hash hash;
			//负载因子 >= 1 --> 扩容
			if (_n == _table.size())
			{
				//不能创建 HashTable newtable + Insert,交换后原哈希桶链表无法释放
				std::vector<Node*> _newtable(__stl_next_prime(_table.size() + 1));
				for (int i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;
						
						//newtable 元素个数已改变，映射关系重新计算
						size_t hashi = hash(cur->_kv.first) % _newtable.size();
						cur->_next = _newtable[hashi];
						_newtable[hashi] = cur;

						cur = next;
					}

					//原表存储的地址改为nullptr
					_table[i] = nullptr;
				}
				_table.swap(_newtable);
			}
			
			size_t hashi = hash(kv.first) % _table.size();
			//头插
			Node* newnode = new Node(kv);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;

			return true;
		}

		Node* Find(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _table.size();

			Node* cur = _table[hashi];
			while (cur)
			{
				if (cur->_kv.first == key) return cur;

				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _table.size();

			Node* cur = _table[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
					{
						//第一个节点
						_table[hashi] = cur->_next;
					}
					else
					{
						//中间节点
						prev->_next = cur->_next;
					}

					delete cur;
					--_n;

					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}

	private:
		std::vector<Node*> _table;
		size_t _n;
	};
}