#include "5.19-work.h"
#define _CRT_SECURE_NO_WARNINGS

void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SLDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//void SLPrint(SL* ps)
//{
//	for (int i = 0; i < ps->size; i++)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	printf("\n");
//}

void SLCheckCapacity(SL* ps)
{
	int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
	SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
	if (tmp == NULL)
	{
		perror("realloc failed!\n");
		return;
	}

	ps->a = tmp;
	ps->capacity = newcapacity;
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->capacity == ps->size) SLCheckCapacity(ps);

	ps->a[ps->size++] = x;
}


void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);

	ps->size--;
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->capacity == ps->size) SLCheckCapacity(ps);
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}

void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);

	for (int i = 1; i < ps->size; i++)
	{
		ps->a[i - 1] = ps->a[i];
	}
	ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(0 <= pos <= ps->size);
	if (ps->capacity == ps->size) SLCheckCapacity(ps);

	for (int i = ps->size - 1; i >= pos ; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(ps->size > 0);
	assert(0 <= pos < ps->size);

	for (int i = pos; i < ps->size; i++)
	{
		ps->a[i - 1] = ps->a[i];
	}
	ps->size--;
}

//int SLFind(SL* ps, SLDataType x)
//{
//	assert(ps);
//
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->a[i] == x) return i;
//	}
//	return -1;
//}





