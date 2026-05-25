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

//快速排序
void QuickSort(int* a, int left, int right)
{
	if (left >= right) return;

	int keyi = left;
	int begin = left, end = right;
	while(begin < end)
	{
		//右边找小
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}
		//左边找大
		while (begin < end && a[begin] <= a[keyi])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);

	//划分区间
	//[left,begin - 1] begin [begin + 1,end]
	QuickSort(a, left, begin - 1);
	QuickSort(a, begin + 1, right);

}