typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate()
{
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&obj->q1);
	QueueInit(&obj->q2);

	if (obj == NULL)
	{
		return NULL;
	}
	return obj;
}


bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

int myStackTop(MyStack* obj)
{
	return QueueEmpty(&obj->q1) ? QueueBack(&obj->q2) : QueueBack(&obj->q1);
}

void myStackPush(MyStack* obj, int x)
{
	Queue* empty = &obj->q1;
	Queue* nonempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		nonempty = &obj->q1;
	}

	QueuePush(nonempty, x);
}

int myStackPop(MyStack* obj)
{
	Queue* empty = &obj->q1;
	Queue* nonempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		nonempty = &obj->q1;
	}

	while (QueueSize(nonempty) > 1)
	{
		int top = QueueFront(nonempty);
		QueuePush(empty, top);
		QueuePop(nonempty);
	}

	int ret = QueueFront(nonempty);
	QueuePop(nonempty);

	return ret;
}


void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);

	free(obj);
	obj = NULL;
}

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

	if (pq == NULL)
	{
		return NULL;
	}

	return pq;
}

void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->st1, x);
}

int myQueuePop(MyQueue* obj)
{
	if (StackEmpty(&obj->st2))
	{
		while (StackSize(&obj->st1))
		{
			StackPush(&obj->st2, StackTop(&obj->st1));
			StackPop(&obj->st1);
		}
	}

	int ret = StackTop(&obj->st2);
	StackPop(&obj->st2);

	return ret;

}

int myQueuePeek(MyQueue* obj)
{
	int ret = myQueuePop(obj);

	StackPush(&obj->st2, ret);

	return ret;
}

bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->st1) && StackEmpty(&obj->st2);
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->st1);
	StackDestroy(&obj->st2);

	free(obj);
	obj = NULL;
}


typedef struct
{
	int* a;
	int phead;
	int ptail;
	int size;
	int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	int* tmp = (int*)malloc(sizeof(int) * (k + 1));
	pq->a = tmp;
	pq->phead = pq->ptail = 0;
	pq->size = 0;
	pq->k = k;
	return pq;
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return obj->size == obj->k;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj)) return false;

	obj->a[obj->ptail] = value;
	obj->ptail = (obj->ptail + 1) % (obj->k + 1);
	obj->size++;

	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj)) return false;

	obj->phead++;
	obj->phead %= (obj->k + 1);

	obj->size--;

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj)) return -1;

	return obj->a[obj->phead];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj)) return -1;

	return obj->a[(obj->ptail - 1 + (obj->k + 1)) % (obj->k + 1)];
}


void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->a);
	obj->a = NULL;
	obj->phead = obj->ptail = 0;
	obj->size = 0;
	obj->k = 0;

	free(obj);
	obj = NULL;
}

