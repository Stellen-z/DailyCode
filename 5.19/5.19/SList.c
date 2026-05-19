#include "SList.h"

void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d ", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		return;
	}
	newnode->next = NULL;
	newnode->data = x;

	if (*pphead == NULL)
	{
		*pphead = newnode;
		return;
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}


}


void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		return;
	}
	newnode->next = NULL;
	newnode->data = x;

	newnode->next = *pphead;
	*pphead = newnode;

}

void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && (*pphead));

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* delprev = *pphead;
		while (delprev->next->next)
		{
			delprev = delprev->next;
		}
		free(delprev->next);
		delprev->next = NULL;
	}
}

void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && (*pphead));
	SLTNode* newhead = (*pphead)->next;
	free(*pphead);
	*pphead = newhead;
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x) return pcur;
		pcur = pcur->next;
	}
	return NULL;
}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);

	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
		if (newnode == NULL)
		{
			perror("malloc failed!\n");
			return;
		}
		newnode->next = NULL;
		newnode->data = x;

		SLTNode* posprev = *pphead;
		while (posprev && posprev->next != pos)
		{
			posprev = posprev->next;
		}

		newnode->next = pos;
		posprev->next = newnode;
	}
}

void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);

	if (pos == (*pphead))
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev && prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* next = pos->next;

		free(pos);
		pos = NULL;

		prev->next = next;
	}
	
}

void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		return;
	}
	newnode->data = x;
	newnode->next = pos->next;
	pos->next = newnode;
}


void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	free(pos->next);
	pos->next = NULL;
}

void SListDesTroy(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
	pcur = NULL;
}

