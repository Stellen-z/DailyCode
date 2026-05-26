#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int GetMidi(int* a, int left, int right)
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


void QuickSort(int* a, int left, int right)
{
	if (left >= right) return;

	int midi = GetMidi(a, left,right);
	Swap(&a[midi], &a[left]);

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
	Swap(&a[begin],&a[keyi]);

	QuickSort(a, left, begin - 1);
	QuickSort(a, begin + 1, right);
}

//快速排序非递归
void QuickSortNonR(int* a, int left, int right)
{

}
