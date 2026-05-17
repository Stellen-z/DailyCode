#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

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

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else break;
		}
		a[end + 1] = tmp;
	}
	
}


//优化一：三数取中
int Getmid(int* a,int left, int right)
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
		else if (a[mid] > a[left]) return left;
		else return mid;
	}
}

//1.hoare版本
int PartSort1(int* a,int left,int right)
{
	int mid = Getmid(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = left;
	int begin = left, end = right;
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

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[begin], &a[key]);
	return begin;
}

//2.前后指针
int PartSort2(int* a,int left,int right)
{
	int mid = Getmid(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		//cur找小
		//[prev + 1,cur - 1]是比a[key]大的元素
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[key]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right) return;

	//优化二：小区间优化
	if (right - left + 1 > 10)
	{
		InsertSort(a, right - left + 1);
	}
	else
	{
		//int key = PartSort1(a, left, right);
		int key = PartSort2(a, left, right);

		//[left,key - 1] key [key + 1,right]
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}

}


void QuickSortNonR(int* a,int left,int right)
{
	//利用栈来改非递归
	Stack st;
	STInit(&st);

	STPush(&st, right);
	STPush(&st, left);

	while (!STEmpty(&st))
	{
		//循环每走一次，取栈顶区间进行单趟排序
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st); 

		int key = PartSort2(a, begin, end);
		//[left,key - 1] key [key + 1,right]
		//右左子区间入栈
		if (end - key > 1)
		{
			STPush(&st, end);
			STPush(&st, key + 1);
		}
		if (key - begin > 1)
		{
			STPush(&st, key - 1);
			STPush(&st, begin);
		}

	}
	STDestroy(&st);
}


void TestQuickSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
	//InsertSort(a, sizeof(a) / sizeof(int));

	PrintArray(a, sizeof(a) / sizeof(int));

	//QuickSort(a, 0,sizeof(a) / sizeof(int) - 1);
	QuickSortNonR(a,0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void _MergeSort(int* a, int* tmp,int left,int right) 
{
	if (left == right) return;

	int mid = (left + right) / 2;
	//[left,mid][mid + 1,right]
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int cur = left;
	int begin1 = left, end1 = mid;
	int	begin2 = mid + 1, end2 = right;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2]) tmp[cur++] = a[begin1++];
		else tmp[cur++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[cur++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[cur++] = a[begin2++];
	}

	memcpy(a + left, tmp + left,sizeof(int) * (right - left + 1));
}


void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc failed!\n");
		return;
	}

	_MergeSort(a, tmp,0,n - 1);

}

void TestMergeSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
	//InsertSort(a, sizeof(a) / sizeof(int));

	PrintArray(a, sizeof(a) / sizeof(int));

	MergeSort(a, sizeof(a) / sizeof(int));
	//MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


int main()
{

	//TestQuickSort();
	TestMergeSort();
	return 0;
}