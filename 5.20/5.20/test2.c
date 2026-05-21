#include "BinaryTree.h"


BTNode* BuyNode(BTDataType x)
{
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->val = x;

    return newnode;
}

BTNode* CreatBinaryTree()
{
    BTNode* node1 = BuyNode(1);
    BTNode* node2 = BuyNode(2);
    BTNode* node3 = BuyNode(3);
    BTNode* node4 = BuyNode(4);
    BTNode* node5 = BuyNode(5);
    BTNode* node6 = BuyNode(6);

    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    node4->left = node5;
    node4->right = node6;

    return node1;
}

void test01()
{
	BTNode* root = CreatBinaryTree();

    printf("前序遍历：");
	PreOrder(root);
    printf("\n");

    printf("中序遍历：");
    InOrder(root);
    printf("\n");

    printf("后序遍历：");
    PostOrder(root);
    printf("\n");

    printf("二叉树节点个数：%d\n", BinaryTreeSize(root));

    printf("二叉树叶子节点个数：%d\n", BinaryTreeLeafsize(root));
}



int main()
{
	test01();
	return 0;
}