#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


void PrintArray(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);

	}
	printf("\n");
}


void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


//调试选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
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
		Swap(&a[begin], &a[mini]);
		if (begin == maxi) maxi = mini;
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}

}


void TestSelectSort()
{
	int a[] = { 3,7,2,9,4,0,4 ,1,8,4,3,8,0,};
	PrintArray(a, sizeof(a)/sizeof(int));

	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//优化一：三数取中
int GetMid(int* a,int left,int right)
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


void TestInsertSort()
{
	int a[] = { 3,7,2,9,4,0,4 ,1,8,4,3,8,0, };
	PrintArray(a, sizeof(a) / sizeof(int));

	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


void ShellSort(int* a,int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];

			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else break;
			}
			a[end + gap] = tmp;
		}
	}
	
}



void TestShellSort()
{
	int a[] = { 3,7,2,9,4,0,4 ,1,8,4,3,8,0, };
	PrintArray(a, sizeof(a) / sizeof(int));

	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


void QuickSort(int* a, int left, int right)
{
	if (left >= right) return;

	//以a[begin]为基准

	//优化二：小区间优化
	if (right - left + 1 < 10)
	{
		InsertSort(a+left,right - left + 1);
	}
	else
	{
		int mid = GetMid(a, left, right);
		Swap(&a[mid], &a[left]);

		int begin = left, end = right;
		int key = left;
		while (begin < end)
		{
			//右边找小
			while (begin < end && a[end] >= a[key])
			{
				--end;
			}
			//左边找大
			while (begin < end && a[begin] <= a[key])
			{
				++begin;
			}

			//找到begin 和 end
			Swap(&a[begin], &a[end]);
		}
		//此时相遇
		Swap(&a[begin], &a[key]);
		key = begin;//划分区间
		//[left,key-1] key [key+1,right]

		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}
	
}


void TestQuickSort()
{
	int a[] = { 3,7,2,9,4,0,4 ,1,8,4,3,8,0, };
	PrintArray(a, sizeof(a) / sizeof(int));

	QuickSort(a, 0,sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}


void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child]) child++;
		if (a[parent] < a[child])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a,n,i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}


void TestHeapSort()
{
	int a[] = { 3,7,2,9,4,0,4 ,1,8,4,3,8,0, };
	PrintArray(a, sizeof(a) / sizeof(int));

	HeapSort(a,sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}



int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestQuickSort();
	TestHeapSort();
	
	return 0;
}