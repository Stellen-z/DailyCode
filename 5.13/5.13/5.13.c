#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//单趟排序
		int end = i;
		int tmp = a[end + 1];
		//[0,end]有序 
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				//向后挪
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}



int main()
{
	int a[] = { 1,5,9,3,8,2,3,5,7 };

	int sz = sizeof(a) / sizeof(int);

	//插入排序
	InsertSort(a,sz);

	return 0;
}
