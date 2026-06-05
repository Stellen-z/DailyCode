//Test.cpp
#include "Stack.h"

//定义全局的Stack
typedef struct Stack
{
    int a[10];
    int top;
}ST;

void STInit(ST* ps) {};
void STPush(ST* ps, int x) {};


int main()
{
    //调用全局的栈
    ST st1;
    STInit(&st1);
    STPush(&st1, 1);
    STPush(&st1, 2);
    STPush(&st1, 3);
    printf("%zd\n", sizeof(st1));//固定10个int类型，共44字节

    //调用stn的栈
    stn::Stack st2;
    printf("%zd\n", sizeof(st2));//一个x64环境下指针,两个int类型，共16字节
    stn::StackInit(&st2);
    stn::StackPush(&st2, 1);
    stn::StackPush(&st2, 2);
    stn::StackPush(&st2, 3);

}