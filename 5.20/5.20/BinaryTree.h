#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
    BTDataType val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;


//前序遍历
void PreOrder(BTNode* root);

//中序遍历
void InOrder(BTNode* root);

//后序遍历
void PostOrder(BTNode* root);

//层序遍历
void LevelOrder(BTNode* root);

//二叉树节点个数
int BinaryTreeSize(BTNode* root);

//二叉树叶子节点个数
int BinaryTreeLeafsize(BTNode* root);

//二叉树第k层节点个数
int TreeLevelsize(BTNode* root, int k);




