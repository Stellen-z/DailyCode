#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)  return NULL;

	if (root->data == x) return root;

	//缺陷：1、返回值只会返回到上一层，找到之后并没有接受
	//      2、就算找到了，还会进行右子树的查找

	TreeFind(root->left,x);
	TreeFind(root->right,x);

	
}

//二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)  return NULL;

	if (root->data == x) return root;

	BTNode* ansleft = TreeFind(root->left, x);
	if (ansleft) return ansleft;

	BTNode* rightleft = TreeFind(root->right, x);
	if (ansright) return ansright;

	return NULL;
}

//二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)  return NULL;

	if (root->data == x) return root;

	BTNode* ansleft = TreeFind(root->left, x);
	if (ansleft) return ansleft;

	//此时根和左子树均已经查完，无论右子树是空还是节点，直接返回即可
	return TreeFind(root->right, x);
}

int main()
{

	//二叉树查找值为x的节点
	BTNode* TreeFind(BTNode * root, BTDataType x);


	return 0;
}