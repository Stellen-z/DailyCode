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



//选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while(begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi) 	maxi = mini;
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

//向下调整算法
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child]) child++;

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}


//堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i], &a[i + 1]);
			}
		}
	}
}


