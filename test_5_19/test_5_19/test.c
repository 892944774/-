#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

//���ֲ��� �������
//int binarysearch(int arr[], int data, int size)
//{
//	int left = 0;
//	int right = size - 1;
//	while (left < right)
//	{
//		int mid =left + ((right - left) >> 1);
//		if (data == arr[mid])
//			return arr[mid];
//		else if (data > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//			right = mid - 1;
//	}
//	return -1;
//}

//int binarysearch(int arr[], int size, int data)
//{
//	int left = 0;
//	int right = size;
//	while (left <= right)
//	{
//		int mid = left + ((right - left)>>1);
//		if (data == arr[mid])
//			return arr[mid];
//		else if (data > arr[mid])
//			left = mid + 1;
//		else
//			right = mid;
//	}
//	return -1;
//}

//ʱ�临�Ӷ� O(N),ֻ��һ��ѭ��
//�ռ临�Ӷ� O(5)->O(1),��Ϊ������5��������������O(5)��ת����ΪO(1)
//unsigned long long Fib(int N)
//{
//	unsigned long long first = 1, second = 1;
//	unsigned long long ret = 1;
//	for (int i = 2; i < N ; i++)
//	{
//		ret = first + second;
//		first = second;
//		second = ret;
//	}
//	return ret;
//}

//��2�����������ϲ�����������
//ʱ�临�Ӷ�(���д���):��������ֵ�Ĵ���, O(M+N)
//�ռ临�Ӷ�(��������):���������ĸ���������malloc�ڶ��Ͽ��ٵı���,O(M+N+8) = O(M+N)
//int* MergeData(int array1[], int size1, int array2[], int size2)
//{
//	int index1 = 0, index2 = 0, index = 0;
//	int* array = (int*)malloc((size1 + size2) * sizeof(array1[0]));
//	if (array == NULL)
//		return NULL;
//
//	while (index1 < size1 && index2 < size2)
//	{
//		if (array1[index1] <= array2[index2])
//			array[index++] = array1[index1++];
//		else
//			array[index++] = array2[index2++];
//	}
//
//	while (index1 < size1)
//		array[index++] = array1[index1++];
//	while (index2 < size2)
//		array[index++] = array2[index2++];
//	return array;
//}
//
//int main()
//{
//	int array1[] = { 2,5,6,8 };
//	int array2[] = {1,3,5,6,8,9};
//
//	int* array = MergeData(array1, sizeof(array1)/sizeof(array1[0]), array2, sizeof(array2)/sizeof(array2[0]));
//
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
////	printf("%lld ", Fib(10));
//
//	free(array);
//	array = NULL;
//	return 0;
//} 

//�ݹ��㷨��ʱ�临�Ӷ� = �ݹ����� * ÿ�εݹ�����Ҫ�Ŀռ�ĸ���
//int Fac(int N)
//{
//	if (0 == N)
//		return 1;
//
//	return Fac(N - 1) * N;
//}

//˳���ľ�̬�洢
//#define N 100
//typedef int SLDataType;
//
//typedef struct Seqlist
//{
//	SLDataType array[N];//��������
//	size_t size;//��¼��Ч���ݵĸ���
//}SeqList;
//
