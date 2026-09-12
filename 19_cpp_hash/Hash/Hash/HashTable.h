#include <iostream>
#include <vector>

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<std::string>
{
	size_t operator()(const std::string& s)
	{
		size_t ch = 0;
		for (auto& e : s)
		{
			ch += e;
			ch *= 131;
		}

		return ch;
	}
};

inline unsigned long __stl_next_prime(unsigned long n)
{
	// Note: assumes long is at least 32 bits.
	static const int __stl_num_primes = 28;
	static const unsigned long __stl_prime_list[__stl_num_primes] =
	{
	  53,         97,         193,       389,       769,
	  1543,       3079,       6151,      12289,     24593,
	  49157,      98317,      196613,    393241,    786433,
	  1572869,    3145739,    6291469,   12582917,  25165843,
	  50331653,   100663319,  201326611, 402653189, 805306457,
	  1610612741, 3221225473, 4294967291
	};

	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	const unsigned long* pos = std::lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}

namespace open_address
{
	enum State
	{
		EMPTY,
		DELETE,
		EXIST
	};

	template<class K,class V>
	struct HashData
	{
		std::pair<K,V> _kv;
		State _state;

		HashData() = default;
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:


		HashTable()
			:_table(__stl_next_prime(0)) // 默认先开10个空间
			, _n(0)
		{}

		bool Insert(const std::pair<K,V>& kv)
		{
			Hash hash;

			if (Find(kv.first)) return false;

			//扩容
			if (_n * 10 / _table.size() == 7)
			{
				HashTable<K, V> newht;
				newht._table.resize(__stl_next_prime(_table.size() + 1));

				for (auto& e : _table)
				{
					if (e._state == EXIST)
					{
						newht.Insert(e._kv);
					}
				}
				
				_table.swap(newht._table);
			}

			//线性探测
			size_t hash0 = hash(kv.first) % _table.size(); // 冲突位置
			size_t hashi = hash0;
			size_t i = 1;
			while (_table[hashi]._state == EXIST)
			{
				// 到表尾直接回到表头
				hashi = (hash0 + i) % _table.size();
				++i;
			}

			// hashi即为空位置
			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;

			return true;
		}

		HashData<K,V>* Find(const K& key)
		{
			Hash hash;
			if (_n == 0) return nullptr;
				
			size_t hash0 = hash(key) % _table.size();
			size_t hashi = hash0;
			size_t i = 1;

			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state == EXIST &&
					_table[hashi]._kv.first == key)
				{
					return &_table[hashi];
				}

				hashi = (hash0 + i) % _table.size();
				++i;
			}

			return nullptr;
		}
		
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret == nullptr) return false;

			ret->_state = DELETE;
			--_n;

			return true;
		}

	private:
		std::vector<HashData<K,V>> _table;
		size_t _n;  //元素个数
	};
}

namespace hash_bucket
{
	template<class K, class V, class Hash>
	class HashTable;

	template<class K,class V,class Hash> 
	struct HashNode
	{
		using Node = HashNode<K, V,Hash> ;
		using HT = HashTable<K, V,Hash>;

		std::pair<K, V> _kv;
		Node* _next;

		HashNode(const std::pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{}

	};

	template<class K, class V,class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		using Node = HashNode<K, V,Hash>;

		HashTable()
			:_table(10)
			, _n(0)
		{}

		bool Insert(const std::pair<K,V>& kv)
		{
			if (Find(kv.first)) return false;

			Hash hash;
			//扩容
			if (_n == _table.size())
			{
				std::vector<Node*> v(__stl_next_prime(_table.size() + 1));

				//遍历旧表
				for (int i = 0; i < _table.size(); i++)
				{
					if (_table[i] != nullptr)
					{
						Node* cur = _table[i];
						size_t hashi = hash(_table[i]->_kv.first) % v.size();
						while (cur) 
						{
							Node* next = cur->_next;

							//头插到新表
							cur->_next = v[hashi];
							v[hashi] = cur;

							cur = next;
						}
						_table[i] = nullptr;
					}
				}
				_table.swap(v);
			}

			size_t hashi = hash(kv.first) % _table.size();
			Node* newnode = new Node(kv);

			Node* cur = _table[hashi];
			if (cur == nullptr)
			{
				//没有节点，直接插入
				_table[hashi] = newnode;
			}
			else
			{
				//头插
				newnode->_next = cur;
				_table[hashi] = newnode;
			}
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
			auto ret = Find(key);
			if (ret == nullptr) return false;

			Hash hash;
			size_t hashi = hash(key) % _table.size();
			if (ret->_next == nullptr)
			{
				delete ret;
				_table[hashi] = nullptr;
			}
			else
			{
				Node* prev = _table[hashi];
				Node* next = ret->_next;

				while (prev->_next != ret)
				{
					prev = prev->_next;
				}

				delete ret;
				prev->_next = next;
			}

			--_n;

			return true;
		}

	private:
		std::vector<Node*> _table;
		size_t _n;
	};



}