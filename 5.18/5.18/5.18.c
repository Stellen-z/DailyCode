#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right) return;


	int mid = (left + right) / 2;
	//[left,mid][mid + 1,right]
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int cur = left;
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2]) tmp[cur++] = a[begin1++];
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

	memcpy(a + left, tmp + left,sizeof(int) *  (right - left + 1));


}


void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc failed!\n");
		return;
	}

	int left = 0, right = n - 1;
	_MergeSort(a, tmp, left, right);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a,int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc failed!\n");
		return;
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//i控制每组归并的起始位置
			int cur = i;
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = end1 + 1, end2 = i + 2 * gap - 1;

			if (begin2 >= n) break;

			if (end2 >= n) end2 = n - 1;

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2]) tmp[cur++] = a[begin1++];
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
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));

		}
		gap *= 2;
	}
	 
	free(tmp);
	tmp = NULL;
}


void TestMergeSort()
{
	int a[] = { 9,1,2,5,7,4,6,3 };

	PrintArray(a, sizeof(a) / sizeof(int));
	//MergeSort(a, sizeof(a) / sizeof(int));
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* cnt = (int*)calloc(range, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		cnt[a[i] - min]++;
	}
	//覆盖原有数据
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (cnt[i]--)
		{
			a[j++] = i + min;
		}
	}

	free(cnt);
	cnt = NULL;
}

void TestCountSort()
{
	int a[] = { 9,1,2,5,7,4,6,3 };

	PrintArray(a, sizeof(a) / sizeof(int));
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}



int main()
{

	//TestMergeSort();
	TestCountSort();
	return 0;

 }


