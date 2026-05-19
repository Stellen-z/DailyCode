#include "5.19-work.h"
#include "SList.h"
#define _CRT_SECURE_NO_WARNINGS



//void Test01()
//{
//	SL sl;
//	SLInit(&sl);
//
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPrint(&sl);
//
//
//	SLPushFront(&sl, 0);
//	SLPrint(&sl);
//
//	SLInsert(&sl, 2, 99);
//	SLPrint(&sl);
//
//
//	SLErase(&sl, 2);
//	SLPrint(&sl);
//
//
//	SLDestroy(&sl);
//}


void Test02()
{
	contact con;

	InitContact(&con);

	AddContact(&con);
	AddContact(&con);

	ShowContact(&con);

	DelContact(&con);

	ShowContact(&con);

	ModifyContact(&con);

	ShowContact(&con);


	DestroyContact(&con);

}


void Test03()
{
		SLTNode* list = NULL;

		// 尾插 + 打印
		SLTPushBack(&list, 1);
		SLTPushBack(&list, 2);
		SLTPushBack(&list, 3);
		SLTPrint(list); // 预期：1 2 3

		// 头插
		SLTPushFront(&list, 0);
		SLTPrint(list); // 预期：0 1 2 3

		// 查找 + 插入
		SLTNode* pos = SLTFind(list, 2);
		SLTInsert(&list, pos, 10);
		SLTPrint(list); // 预期：0 1 10 2 3

		// 删除
		SLTErase(&list, pos);
		SLTPrint(list); // 预期：0 1 10 3

		// 销毁
		SListDesTroy(&list);
		SLTPrint(list); // 预期：(空行)

}


int main()
{
	//Test01();

	//Test02();

	Test03();

	return 0;
}
