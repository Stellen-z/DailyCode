#include "Sort.h"

void TestMergeSort()
{
	int a[] = { 2,4,1,7,8,3,9,2,5};
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestCountSort()
{
	int a[] = { 2,4,1,7,8,3,9,2,5 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


int main()
{
	//TestMergeSort();
	TestCountSort();

	return 0;
}