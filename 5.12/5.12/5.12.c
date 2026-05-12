#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root) QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		//pop中 free 的是 QNode,而 front 已经将二叉树的地址保存了下来
		QueuePop(&q);

		printf("%d ", front->val);

		if (front->left) QueuePush(&q, front->left);
		if (front->right) QueuePush(&q, front->right);

	}
	QueueDestroy(&q);
}	

//判断二叉树是否是完全二叉树
bool TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root) QueuePush(&q, root->val);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);

		if (front == NULL) break;

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);

	}

	//判断队列中是否有非空
	while (!QueueEmpty(&q)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			//返回结果之前记得销毁
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;

}

int main()
{
	//层序遍历
	TreeLevelOrder(root);

	//判断二叉树是否是完全二叉树
	TreeComplete(root);
	return 0;
}