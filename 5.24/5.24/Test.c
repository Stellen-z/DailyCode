#include "Sort.h"
#define _CRT_SECURE_NO_WARNINGS


void TestSelectSort()
{
	int a[] = { 2,4,1,7,8,3,9,2 };
	//int a[] = { 2,9,4,8,0,3 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = { 2,4,1,7,8,3,9,2 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
	int a[] = { 2,4,1,7,8,3,9,2 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}



int main()
{

	TestSelectSort();
	TestHeapSort();
	TestBubbleSort();
	return 0;

}