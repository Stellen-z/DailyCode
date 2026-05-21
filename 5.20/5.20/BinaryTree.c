#include "BinaryTree.h"


//前序遍历
void PreOrder(BTNode* root)
{
    if (root == NULL) return;

    printf("%d ", root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}


//中序遍历
void InOrder(BTNode* root)
{
    if (root == NULL) return;

    InOrder(root->left);
    printf("%d ", root->val);
    InOrder(root->right);
}


//后序遍历
void PostOrder(BTNode* root)
{
    if (root == NULL) return;

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->val);
}

////层序遍历
//void LevelOrder(BTNode* root)
//{
//    if (root == NULL) return;
//
//    Queue q;
//    QueueInit(&q);
//
//    QueuePush(&q, root);          
//
//    while (!QueueEmpty(&q))
//    {
//        BTNode* front = QueueFront(&q);
//        QueuePop(&q);                    
//
//        printf("%d ", front->val);        
//
//        // 左右孩子入队
//        if (front->left)
//            QueuePush(&q, front->left);
//        if (front->right)
//            QueuePush(&q, front->right);
//    }
//
//    QueueDestroy(&q);
//}


//二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
    //if (root == NULL) return 0;

    //int leftnums = BinaryTreeSize(root->left);
    //int rightnums = BinaryTreeSize(root->right);

    //return leftnums + rightnums + 1;

    return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//二叉树叶子节点个数
int BinaryTreeLeafsize(BTNode* root)
{
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 1;

    return BinaryTreeLeafsize(root->left) + BinaryTreeLeafsize(root->right);
}

//二叉树第k层节点个数
int TreeLevelKSize(BTNode* root, int k)
{
    if (root == NULL)
        return 0;

    if (k == 1)
        return 1;

    //子问题
    return TreeLevelKSize(root->left, k - 1)
        + TreeLevelKSize(root->right, k - 1);
}


