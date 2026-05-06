typedef int STDataType;

//定义栈结构体
typedef struct stack
{
	STDataType* a; //动态数组
	int top;       //栈顶
	int capacity;  //容量
}Stack;

//初始化
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

//入栈
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	//判断空间够不够
	if (ps->top == ps->capacity)
	{
		//申请空间
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* newa = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (newa == NULL)
		{
			printf("realloc failed!\n");
			return;
		}
		ps->a = newa;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

//获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

//获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

//检测栈是否为空
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

//销毁栈
void StackDestroy(Stack* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}


//初始化
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps, STDataType x);

//出栈
void StackPop(Stack* ps);

//获取栈顶元素
STDataType StackTop(Stack* ps);

//获取栈中有效元素个数
int StackSize(Stack* ps);

//检测栈是否为空
bool StackEmpty(Stack* ps);

//销毁栈
void StackDestroy(Stack* ps);



typedef struct
{
	Stack st1;
	Stack st2;
} MyQueue;


MyQueue* myQueueCreate()
{
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));

	StackInit(&pq->st1);
	StackInit(&pq->st2);

	return pq;
}

void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->st1, x);
}

int myQueuePop(MyQueue* obj)
{

	//先判断 st2 是否为空
	if (StackEmpty(&obj->st2))
	{
		//为空就导数据
		while (!StackEmpty(&obj->st1))
		{
			StackPush(&obj->st2, StackTop(&obj->st1));
			StackPop(&obj->st1);
		}
	}
	//此时 st2 中已经存在数据
	int top = StackTop(&obj->st2);

	StackPop(&obj->st2);

	return top;
}

int myQueuePeek(MyQueue* obj)
{
	int top = myQueuePop(obj);
	StackPush(&obj->st2, top);

	return top;
}

bool myQueueEmpty(MyQueue* obj)
{
	Stack* st1 = &obj->st1;
	Stack* st2 = &obj->st2;

	return (StackEmpty(st1) && StackEmpty(st2));
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->st1);
	StackDestroy(&obj->st2);

	free(obj);

	//obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/