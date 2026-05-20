#include "List.h"
#define _CRT_SECURE_NO_WARNINGS

LTNode* LTInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->val = -1;
	phead->prev = phead->next = phead;

	return phead;
}

void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
}

void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d ", pcur->val);
		pcur = pcur->next;
	}
	printf("\n");
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		exit(1);
	}
	newnode->next = newnode->prev = newnode;
	newnode->val = x;

	LTNode* tail = phead->prev;

	newnode->next = phead;
	newnode->prev = phead->prev;
	
	phead->prev = newnode;
	tail->next = newnode;
	
}
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));

	LTNode* del = phead->prev;
	LTNode* newtail = del->prev;

	free(del);
	del = NULL;

	phead->prev = newtail;
	newtail->next = phead;
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		exit(1);
	}
	newnode->next = newnode->prev = newnode;
	newnode->val = x;


	newnode->next = phead->next;
	newnode->prev = phead;

	phead->next->prev = newnode;
	phead->next = newnode;
}
void LTPopFront(LTNode* phead)
{
	assert(phead);
	LTNode* del = phead->next;
	LTNode* next = del->next;

	free(del);
	del = NULL;

	phead->next = next;
	next->prev = phead;
	
}


void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		exit(1);
	}
	newnode->next = newnode->prev = newnode;
	newnode->val = x;

	newnode->prev = pos;
	newnode->next = pos->next;

	pos->next->prev = newnode;
	pos->next = newnode;

}
void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;

	free(pos);
	pos = NULL;

	prev->next = next;
	next->prev = prev;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->val == x)return pcur;
		pcur = pcur->next;
	}
	return NULL;
}

