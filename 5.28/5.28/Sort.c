#include"Sort.h"

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

void _MergeSort(int* a,int* tmp, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	//[left,mid][mid + 1,right]
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	//合并两个有序区间
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

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}



//归并排序
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int left = 0, right = n - 1;

	_MergeSort(a,tmp,left, right);
	free(tmp);
	tmp = NULL;
}

//归并排序非递归
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc failed!\n");
		exit(1);
	}

	int left = 0, right = n - 1;
	int mid = (left + right) / 2;
	int gap = 1;
	while (gap < n)
	{
		int cur = 0;
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			if (end1 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}

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
}

//计数排序
void CountSort(int* a, int n)
{
	int maxi = a[0], mini = a[0];
	for(int i = 0;i < n;i++)
	{
		if (a[i] > maxi)
		{
			maxi = a[i];
		}
		if (a[i] < mini)
		{
			mini = a[i];
		}
	}

	int size = maxi - mini + 1;
	int* cnt = (int*)calloc(size,sizeof(int));
	if (cnt == NULL)
	{
		perror("calloc failed!\n");
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		cnt[a[i] - mini]++;
	}

	int j = 0;
	for (int i = 0; i < size; i++)
	{
		while (cnt[i]--)
		{
			a[j++] = i + mini;
		}
	}
	free(cnt);
	cnt = NULL;
}


////计数排序
//void CountSort(int* a, int n)
//{
//	int maxi = a[0], mini = a[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] > maxi)
//		{
//			maxi = a[i];
//		}
//		if (a[i] < mini)
//		{
//			mini = a[i];
//		}
//	}
//
//	int size = maxi - mini + 1;
//	int* cnt = (int*)calloc(size, sizeof(int));
//	if (cnt == NULL)
//	{
//		perror("calloc failed!\n");
//		exit(1);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		cnt[a[i] - a[mini]]++;
//	}
//
//	int j = 0;
//	for (int i = 0; i < n; i++)
//	{
//		while (cnt[i]--)
//		{
//			a[j++] = cnt[i] + a[mini];
//		}
//	}
//	free(cnt);
//	cnt = NULL;
//}
