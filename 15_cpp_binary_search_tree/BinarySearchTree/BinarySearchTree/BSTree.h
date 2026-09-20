#pragma once
#include <iostream>

namespace stl
{
	template<class K>
	struct BSTNode
	{
		BSTNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}

		BSTNode<K>* _left;
		BSTNode<K>* _right;
		K _key;
	};

	template<class K>
	class BST
	{
	public:
		using Node = BSTNode<K>;

		BST() = default;

		void InOrder()
		{
			_InOrder(_root);
			std::cout << std::endl;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			//找到合适位置
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			//prev即为其父节点
			Node* newnode = new Node(key);
			if (key > parent->_key) parent->_right = newnode;
			else parent->_left = newnode;

			return true;

		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}

			return false;
		}

		bool Erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					if (cur->_left == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur) parent->_left = cur->_right;
							else parent->_right = cur->_right;
						}
					
						delete cur;
						return true;
					}
					else if (cur->_right == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur) parent->_left = cur->_left;
							else parent->_right = cur->_left;
						}

						delete cur;
						return true;
					}
					else
					{
						// 右子树的最小值
						Node* RightMinP = cur;
						Node* RightMin = cur->_right;
						while (RightMin->_left)
						{
							RightMinP = RightMin;
							RightMin = RightMin->_left;
						}
						
						cur->_key = RightMin->_key;

						if (RightMinP->_right == RightMin) RightMinP->_right = RightMin->_right;
						else RightMinP->_left = RightMin->_right;

						delete RightMin;
						return true;
					}
				}
			}

			return false;
		}


	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr) return;

			_InOrder(root->_left);
			std::cout << root->_key << " ";
			_InOrder(root->_right);
		}

		BSTNode<K>* _root = nullptr;
	};

}

