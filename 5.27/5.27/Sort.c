#include "Stack.h"
#include "Sort.h"


//打印
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//交换
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


int GetMidi(int* a, int left,int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[right])
	{
		if (a[mid] < a[left]) return left;
		else if (a[mid] < a[right]) return mid;
		else return right;
	}
	else
	{
		if (a[mid] < a[right]) return right;
		else if (a[mid] < a[left]) return mid;
		else return left;
	}

}

int PartSort(int* a, int left, int right)
{
	int mid = GetMidi(a, left, right);
	Swap(&a[mid], &a[left]);

	int keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);

	return begin;
}

//快排
void QuickSort(int* a, int left, int right)
{
	if (left >= right) return;
 
	int keyi = PartSort(a, left, right);

	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);

}

//快排非递归
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);	

	StackPush(&st, right);
	StackPush(&st, left);


	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		if (StackEmpty(&st)) return;
		int end = StackTop(&st);

		int keyi = PartSort(a, begin, end);

		//[begin,keyi - 1] keyi [keyi + 1,end]
		if (keyi - 1 > begin)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}
		if (keyi + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}
	}
	StackDestroy(&st);
}