#include "Sort.h"
#define _CRT_SECURE_NO_WARNINGS


void TestInsertSort()
{
	int a[] = { 2,4,1,7,8,3,9,2,8,5 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 2,4,1,7,8,3,9,2,8,5 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


int main()
{
	TestInsertSort();
	TestShellSort();
	return 0;
}