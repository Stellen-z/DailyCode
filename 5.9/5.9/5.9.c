#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int LeafSize(BTNode* root)
{
	/*return (root->left) && (root->right) == NULL ? LeafSize(root) + 1 : LeafSize(root + 1);*/
	if (root == NULL) return 0;
	if ((root->left == NULL) && (root->right == NULL)) return 1;
	return LeafSize(root->left) + LeafSize(root->right);
}


int TreeHeight(BTNpde* root)
{
	return root == NULL ? 0 : fmax(TreeHeight(root->left),TreeHeight(root->right)) + 1;
	//if (root == NULL) return 0;

}


bool _isUnivalTree(struct TreeNode* root, int val)
{
	//遍历，与val进行比较

	if (root == NULL) return true;

	if (root && root->val != val) return false;

	return _isUnivalTree(root->left, val) && _isUnivalTree(root->right, val);


}
bool isUnivalTree(struct TreeNode* root)
{
	if (root == NULL) return true;
	return _isUnivalTree(root, root->val);
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode* root)
{
	if (root == NULL) return true;
	if (root->left && root->left->val != root->val) return false;
	if (root->right && root->right->val != root->val) return false;

	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

int main()
{
	//统计叶子节点
	LeafSize(root);
	return 0;
}