#define _CRT_SECURE_NO_WARNINGS
typedef struct
{
    int* a;
    int head;
    int tail;
    int k;
} MyCircularQueue;


bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->tail == obj->head;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->tail + 1) % (obj->k + 1) == obj->head;
}


MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

    pq->a = (int*)malloc(sizeof(int) * (k + 1));
    pq->head = pq->tail = 0;
    pq->k = k;

    return pq;
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    if (myCircularQueueIsFull(obj)) return false;

    //入数据
    obj->a[obj->tail] = value;
    obj->tail++;

    //避免回绕
    obj->tail %= (obj->k + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj)) return false;

    obj->head = (obj->head + 1) % (obj->k + 1);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj)) return -1;
    return obj->a[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj)) return -1;

    //return obj->tail == 0 ? obj->a[obj->k] : obj->a[obj->tail - 1];

    return obj->a[(obj->tail - 1 + obj->k + 1) % (obj->k + 1)];
}



void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->a);
    free(obj);
    //obj = NULL;    
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/