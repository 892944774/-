#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

void PrintArray(int array[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

//在整个排序的过程中没有使用额外的辅助空间,空间复杂度O(1)
//一个元素时间复杂度为O(N)，size个元素,时间复杂度为O(N^2) 
//稳定性：稳定
void InsertSort(int array[], int size)
{
	//i从1开始,下标为0的元素只有一个，已经有序，直接从1开始
	//外层循环控制多少个数据需要插入
	for (int i = 1; i < size; i++)
	{
		//单个元素的插入过程
		int key = array[i];
		int end = i - 1;

		//找待插入元素在区间中的位置,end到下标为0之前的位置就结束
		//最差情况下需要将i之前所有已插入的元素向后进行搬移---O(N)
		while (end>=0 && key < array[end])
		{
			//比插入的元素大，向后移动，然后向前继续寻找
			array[end + 1] = array[end];
			end--;
		}

		//插入元素
		array[end + 1] = key;
	}

}

void TestSort()
{
	int array[] = {4,1,7,6,3,9,5,8,0,2};
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	printf("\n");
	InsertSort(array, sizeof(array) / sizeof(array[0]));\
	PrintArray(array, sizeof(array) / sizeof(array[0]));
}