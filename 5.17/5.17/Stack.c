#include "Stack.h"

//初始化
void STInit(Stack* st)
{
	assert(st);
	st->a = NULL;
	st->top = st->capacity = 0;
}

//入栈
void STPush(Stack* st, STDatatype x)
{
	assert(st);

	//检查空间
	if (st->top == st->capacity)
	{
		//扩容
		int newcapacity = st->capacity == 0 ? 4 : 2 * st->capacity;
		STDatatype* tmp = (STDatatype*)realloc(st->a,sizeof(STDatatype) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc failed!\n");
			return;
		}

		st->capacity = newcapacity;
		st->a = tmp;
	}

	st->a[st->top] = x;
	st->top++;
}

//出栈
void STPop(Stack* st)
{
	assert(st);
	assert(st->top > 0);
	st->top--;
}

//获取栈顶元素
STDatatype STTop(Stack* st)
{
	assert(st);
	assert(st->top > 0);
	return st->a[st->top - 1];
}

//获取栈中有效元素个数
int STSize(Stack* st)
{
	assert(st);
	return st->top;
}

//检测栈是否为空
bool STEmpty(Stack* st)
{
	assert(st);
	return st->top == 0;
}

//销毁栈
void STDestroy(Stack* st)
{
	assert(st);
	free(st->a);
	st->a = NULL;
	st->capacity = st->top = 0;
}
