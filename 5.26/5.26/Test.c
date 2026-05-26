#include "Sort.h"

void TestQuickSort()
{
	int a[] = { 2,4,1,7,8,3,9,2 };
	QuickSort(a, 0,sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestQuickSort();

	return 0;
}