#pragma once
#include <stdio.h>
#include <stdlib.h>


void PrintArray(int* a, int n);
void Swap(int* p1, int* p2);

//快速排序
void QuickSort(int* a, int left, int right);

//快速排序非递归
void QuickSortNonR(int* a, int left, int right);
