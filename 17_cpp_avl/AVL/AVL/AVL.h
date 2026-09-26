#pragma once
#include <iostream>
#include <assert.h>

namespace stl
{
	template<class K,class V>
	struct AVLNode
	{
		std::pair<K, V> _kv;
		std::pair<K, V>* _left;
		std::pair<K, V>* _right;
		std::pair<K, V>* _parent;
		int _bf;

		AVLNode(const std : pair<K, V>& kv)
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


		bool Insert(const std::pair<K,V>& kv)
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
				else if(kv.first < cur->_kv.first)
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
					break;
				}
				else
				{
					//防御性编程
					assert(false;)
				}

			}

		}

		void RotateR(Node* RNode)
		{
			Node* RNodeL = RNode->_right;
			Node* RNodeLR = RNodeR->_left;

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

			if (RNodoP == nullptr)
			{
				_root = RNodeR;
				_root->_parent = nullptr;
			}
			else
			{
				if (RNodeP->_left == RNode) RNodeP->_left = RNodeR:
				else RNodeP->_right = RNodeR;

				RNodeR->_parent = RNodeP;
			}

			RNode->_bf = RNodeR->_bf = 0;
		}

	private:
		Node* _root = nullptr;
	};
}
