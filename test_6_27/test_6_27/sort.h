#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>


void InsertSort(int array[], int size);

void PrintArray(int array[], int size);

//œ£∂˚≈≈–Ú
void ShellSort(int array[], int size);

//—°‘Ò≈≈–Ú
void SelectSort(int array[], int size);

//—°‘Ò≈≈–Ú
void SelectSortOP(int array[], int size);

//∂—≈≈–Ú
void HeapSortOP(int array[], int size);

//√∞≈›≈≈–Ú
void BubbleSort(int array[], int size);

//øÏÀŸ≈≈–Ú
void QuickSort(int array[], int left, int right);

//πÈ≤¢≈≈–Ú
void MergeSort(int array[], int size);

//—≠ª∑∑Ω Ωµƒ≈≈–Ú
void MergeSortNor(int array[], int size);

//void QuickSortNor(int array[], int size);

void TestSort();