#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintArray(int* a, int n);
void Swap(int* x, int* y);

//选择排序
void SelectSort(int* a, int n);

//向下调整算法
void AdjustDown(int* a, int n, int parent);

//堆排序
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

