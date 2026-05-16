#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//前后指针
//递归改非递归


void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void QuickSort(int* a, int left, int right)
{
	int key = left;
	int begin = left, end = right;
	while (begin < end)
	{
		//右边找小
		while (begin < end && a[end] > a[key])
		{
			end--;
		}
		//左边找大
		while (begin < end && a[begin] < a[key])
		{
			begin++;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);
	key = begin;

	QuickSort(a,left, key);
	QuickSort(a,key + 1, right);

}

void TestQuickSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
	//InsertSort(a, sizeof(a) / sizeof(int));

	PrintArray(a, sizeof(a) / sizeof(int));

	QuickSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


int main()
{

	TestQuickSort();

	return 0;
}