#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

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

void ShellSort(int* a, int n)
{
	//int gap = n;
	//while (gap > 1)
	//{
	//	gap = gap / 3 + 1;

	//	for (int j = 0; j < gap; j++)
	//	{
	//		for (int i = 0; i < n - gap; i += gap)
	//		{
	//			int end = i + j;
	//			int tmp = a[end + gap];
	//			//插入排序
	//			while (end >= 0)
	//			{
	//				if (tmp < a[end])
	//				{
	//					a[end + gap] = a[end];
	//					end -= gap;
	//				}
	//				else break;
	//			}
	//			a[end + gap] = tmp;
	//		}
	//	}
	//}

	int gap = n;
	while (gap > 1)
	{
		//gap > 1时  --预排序
		//gap == 1时 --插入排序
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			//插入排序
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

		printf("gap:%2d-> ", gap);
		PrintArray(a, n);
	}
	 
}



void TestShellSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
	//InsertSort(a, sizeof(a) / sizeof(int));

	PrintArray(a, sizeof(a) / sizeof(int));

	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i < end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[mini], &a[begin]);
		Swap(&a[maxi], &a[end]);
		++begin;
		--end;
	}
}

void TestSelectSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
	//InsertSort(a, sizeof(a) / sizeof(int));

	PrintArray(a, sizeof(a) / sizeof(int));

	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}



int main()
{

	//TestShellSort();
	TestSelectSort();

	return 0;
}