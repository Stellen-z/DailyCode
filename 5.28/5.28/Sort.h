#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintArray(int* a, int n);
void Swap(int* p1, int* p2);

//归并排序
void MergeSort(int* a, int n);

//归并排序非递归
void MergeSortNonR(int* a, int n);

//计数排序
void CountSort(int* a, int n);