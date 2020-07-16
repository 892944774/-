#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>


void InsertSort(int array[], int size);

void PrintArray(int array[], int size);

//ϣ������
void ShellSort(int array[], int size);

//ѡ������
void SelectSort(int array[], int size);

//ѡ������
void SelectSortOP(int array[], int size);

//������
void HeapSortOP(int array[], int size);

//ð������
void BubbleSort(int array[], int size);

//��������
void QuickSort(int array[], int left, int right);

//�鲢����
void MergeSort(int array[], int size);

//ѭ����ʽ������
void MergeSortNor(int array[], int size);

//void QuickSortNor(int array[], int size);

void TestSort();