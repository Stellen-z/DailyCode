#include "Sort.h"
#define _CRT_SECURE_NO_WARNINGS

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
void Swao(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else break;
		}
		a[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//for (int j = 0; j < gap; j++)
		//{
		//	for (int i = j; i < n - gap; i += gap)
		//	{
		//		int end = i;
		//		int tmp = a[end + gap];
		//		while (end >= 0)
		//		{
		//			if (tmp < a[end])
		//			{
		//				a[end + gap] = a[end];
		//				end -= gap;
		//			}
		//			else break;
		//		}
		//		a[end + gap] = tmp;
		//	}
		//}	

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else break;
			}
			a[end + gap] = tmp;

		}

		printf("%d-> ", gap);
		PrintArray(a, n);
	}
}