#pragma once
#include <iostream>
#include <assert.h>

namespace stl
{
	template<class K,class V>
	struct AVLNode
	{
		std::pair<K,V> _kv;
		AVLNode<K, V>* _left;
		AVLNode<K, V>* _right;
		AVLNode<K, V>* _parent;
		int _bf;

		AVLNode(const std::pair<K, V>& kv)
			:_kv(kv)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _bf(0)
		{}

	};
	
	template<class K,class V>
	class AVLTree
	{
	public:
		using Node = AVLNode<K, V>;


		bool Insert(const std::pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);

				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;

			while (cur)
			{
				if (kv.first > cur->_kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kv.first < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(kv);
			if (kv.first > parent->_kv.first) parent->_right = cur;
			else parent->_left = cur;

			cur->_parent = parent;

			//更新平衡因子
			while (parent)
			{
				if (parent->_left == cur) --parent->_bf;
				else ++parent->_bf;

				if (parent->_bf == 0)
				{
					//合理情况,不会影响上一层
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					//继续往上更新
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//旋转
					if (parent->_bf == 2 && cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1)
					{
						RotateLR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1)
					{
						RotateRL(parent);
					}

					break;
				}
				else
				{
					//防御性编程
					assert(false);
				}

			}

			return true;
		}

		void RotateR(Node* RNode)
		{
			Node* RNodeL = RNode->_left;
			Node* RNodeLR = RNodeL->_right;

			//修改节点要同时修改孩子和父亲指针
			RNode->_left = RNodeLR;
			if (RNodeLR) RNodeLR->_parent = RNode;

			//避免RNode的父节点被覆盖，需提前记录
			Node* RNodeP = RNode->_parent;

			RNodeL->_right = RNode;
			RNode->_parent = RNodeL;

			if (RNodeP == nullptr)
			{
				_root = RNodeL;
				_root->_parent = nullptr;
			}
			else
			{
				if (RNodeP->_left == RNode) RNodeP->_left = RNodeL;
				else RNodeP->_right = RNodeL;

				RNodeL->_parent = RNodeP;
			}

			RNode->_bf = RNodeL->_bf = 0;
		}

		void RotateL(Node* RNode)
		{
			Node* RNodeR = RNode->_right;
			Node* RNodeRL = RNodeR->_left;

			RNode->_right = RNodeRL;
			if (RNodeRL) RNodeRL->_parent = RNode;

			Node* RNodeP = RNode->_parent;

			RNodeR->_left = RNode;
			RNode->_parent = RNodeR;

			if (RNodeP == nullptr)
			{
				_root = RNodeR;
				_root->_parent = nullptr;
			}
			else
			{
				if (RNodeP->_left == RNode) RNodeP->_left = RNodeR;
				else RNodeP->_right = RNodeR;

				RNodeR->_parent = RNodeP;
			}

			RNode->_bf = RNodeR->_bf = 0;
		}

		void RotateLR(Node* RNode)
		{
			Node* RNodeL = RNode->_left;
			Node* RNodeLR = RNodeL->_right;
			int bf = RNodeLR->_bf;

			RotateL(RNodeL);
			RotateR(RNode);

			if (bf == 0)
			{
				RNode->_bf = 0;
				RNodeL->_bf = 0;
				RNodeLR->_bf = 0;
			}
			else if (bf == 1)
			{
				RNode->_bf = 0;
				RNodeL->_bf = -1;
				RNodeLR->_bf = 0;
			}
			else if (bf == -1)
			{
				RNode->_bf = 1;
				RNodeL->_bf = 0;
				RNodeLR->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}

		void RotateRL(Node* RNode)
		{
			Node* RNodeR = RNode->_right;
			Node* RNodeRL = RNodeR->_left;
			int bf = RNodeRL->_bf;

			RotateR(RNodeR);
			RotateL(RNode);

			if (bf == 0)
			{
				RNode->_bf = 0;
				RNodeR->_bf = 0;
				RNodeRL->_bf = 0;
			}
			else if (bf == 1)
			{
				RNode->_bf = -1;
				RNodeR->_bf = 0;
				RNodeRL->_bf = 0;
			}
			else if (bf == -1)
			{
				RNode->_bf = 0;
				RNodeR->_bf = 1;
				RNodeRL->_bf = 0;
			}
			else
			{
				assert(false);
			}

		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_kv.first)
				{
					cur = cur->_right;
				}
				else if (key < cur->_kv.first)
				{
					cur = cur->_left;
				}
				else return cur;
			}

			return nullptr;
		}


		void InOrder()
		{
			_InOrder(_root);
			std::cout << std::endl;
		}

		int Height()
		{
			return _Height(_root);
		}

		int Size()
		{
			return _Size(_root);
		}

		bool IsBalanceTree()
		{
			return _IsBalanceTree(_root);
		}

	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr) return;

			_InOrder(root->_left);
			std::cout << root->_kv.first << ":" << root->_kv.second << std::endl;
			_InOrder(root->_right);
		}

		int _Height(Node* _root)
		{
			if (_root == nullptr) return 0;

			return std::max(_Height(_root->_left), _Height(_root->_right)) + 1;
		}


		int _Size(Node* _root)
		{
			if (_root == nullptr) return 0;

			return _Size(_root->_left) + _Size(_root->_right) + 1;
		}

		bool _IsBalanceTree(Node* root)
		{
			// 空树也是AVL树​
			if (nullptr == root)
				return true;
			// 计算pRoot结点的平衡因子：即pRoot左右子树的高度差​
			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			int diff = rightHeight - leftHeight;
			// 如果计算出的平衡因子与pRoot的平衡因子不相等，或者​
			// pRoot平衡因子的绝对值超过1，则一定不是AVL树​
			if (abs(diff) >= 2)
			{
				std::cout << root->_kv.first << "高度差异常" << std::endl;
				return false;
			}
			if (root->_bf != diff)
			{
				std::cout << root->_kv.first << "平衡因子异常" << std::endl;
				return false;
			}
			// pRoot的左和右如果都是AVL树，则该树一定是AVL树​
			return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
		}

		Node* _root = nullptr;
	};
}
