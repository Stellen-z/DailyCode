#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef int STDatatype;

//定义栈
typedef struct Stack
{
	STDatatype* a;
	int top;
	int capacity;
}Stack;

//初始化
void STInit(Stack* st);

//入栈
void STPush(Stack* st, STDatatype x);

//出栈
void STPop(Stack* st);

//获取栈顶元素
STDatatype STTop(Stack* st);

//获取栈中有效元素个数
int STSize(Stack* st);

//检测栈是否为空
bool STEmpty(Stack* st);

//销毁栈
void STDestroy(Stack* st);
