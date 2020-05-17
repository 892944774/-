#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//菲波那契数列
int Fib(int N)
{
	if (N < 3)
		return 1;
	else
		return Fib(N - 1) + Fib(N-2);
}

// 请计算一下Func1基本操作执行了多少次？
//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//// 计算Func3的时间复杂度？
//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//二分查找
//int binarysearch(int arr[], int data, int size)
//{
//	int left = 0;
//	int right = size - 1;
//
//	while (left <= right)
//	{
//		int mid = left + ((right - left) >> 1);
//		if (data == arr[mid])
//			return mid;
//		else if (data < arr[mid])
//			right = mid - 1;
//		else
//			left = mid + 1;
//	}
//	return -1;
//}

int binarysearch(int arr[], int data, int size)
{
	int left = 0;
	int right = size;

	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (data == arr[mid])
			return mid;
		else if (data < arr[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return -1;
}


