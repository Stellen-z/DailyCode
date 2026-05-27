#pragma once
#include <stdio.h>
#include <stdlib.h>


//打印
void PrintArray(int* a, int n);

//交换
void Swap(int* x, int* y);


//快排
void QuickSort(int* a, int left, int right);

//快排非递归
void QuickSortNonR(int* a, int left, int right);