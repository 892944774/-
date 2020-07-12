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
			while (end >= 0 && key < array[end])
			{
				//比插入的元素大，向后移动，然后向前继续寻找
				array[end + 1] = array[end];
				end--;
			}

			//插入元素
			array[end + 1] = key;
		}
}

//时间复杂度：O(N^1.25)~O(1.6N^1.25)
//空间复杂度：O(1)
void ShellSort(int array[], int size)
{
	int gap = 3;
	//i从1开始,下标为0的元素只有一个，已经有序，直接从1开始
	//外层循环控制多少个数据需要插入
	while (gap>0)
	{
		for (int i = gap; i < size; i++)
		{
			//单个元素的插入过程
			int key = array[i];
			int end = i - gap;

			//找待插入元素在区间中的位置,end到下标为0之前的位置就结束
			//最差情况下需要将i之前所有已插入的元素向后进行搬移---O(N)
			while (end >= 0 && key < array[end])
			{
				//比插入的元素大，向后移动，然后向前继续寻找
				array[end + gap] = array[end];
				end -= gap;
			}
			//插入元素：插入到当前分组的下一个位置
			array[end + gap] = key;
		}
		gap--;
	} 
}

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

//选择排序
//时间复杂度 O(N^2)
//空间复杂度 O(1)
//稳定性 不稳定
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		//找当前区间中最大元素的位置
		int maxPos = 0;
		for (int j = 0; j < size - i; ++j)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}

		//依次循环将最大元素放在最后一个位置
		if (maxPos != size - i - 1)
		{
			Swap(&array[maxPos], &array[size-i-1]);
		}
	}
}

void SelectSortOP(int array[], int size)
{
	int begin = 0, end = size - 1;//[begin, end]
	while (begin < end)
	{
		//在[begin, end]区间中找到最大和最小的元素
		int maxPos = begin, minPos = begin;
		int j = begin + 1;

		while (j <= end)
		{
			if (array[j] > array[maxPos])
				maxPos = j;

			if (array[j] < array[minPos])
				minPos = j;

			++j; 
		}

		//如果最大的元素不在区间最后的位置
		if (maxPos != end)
			Swap(&array[maxPos], &array[end]);

		//如果end位置存储的刚好是最小的元素，上面的交换就将最小的元素位置更改了---maxPos
		//最小元素的位置发生了改变，则必须要更新minPos
		if (minPos == end)
			minPos = maxPos;

		//如果最小的元素不在区间的起始位置
		if (minPos != begin)
			Swap(&array[minPos], &array[begin]);
		
		++begin;
		--end;
	}
}



//堆排序
//时间复杂度 O(NlogN)
//空间复杂度 O(1)
//稳定性：不稳定
void HeapSortOP(int array[], int size)
{
	int end = size - 1;
	//1 建堆
	//注意从倒数第一个非叶子节点的位置开始使用堆调整，一直调整到根节点的位置
	for (int root = (size - 2) / 2; root >= 0; root--)
		HeapAdjust(array, size, root);//向下调整
	//2 排序->利用堆删除的思想进行排序
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

//向下调整
void HeapAdjust(int array[], int size, int parent)
{
	//用child标记parent中较大的孩子，默认先标记parent的左孩子
	//先标记左孩子的原因是：如果parent有孩子，parent一定先是有左孩子

	int child = parent * 2 + 1;

	while (child < size)
	{
		//找parent中较大的孩子:用parent左右孩子比较，必须先保证parent的右孩子存在
		if (child+1 < size && array[child + 1] > array[child])
			child += 1;

		//检测parent是否满足堆的性质
		if (array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

//冒泡排序
void BubbleSort(int array[], int size)
{
	//减一是为了少冒一趟，因为最后一次区间只剩下一个元素
	//外层循环控制冒泡的趟数
	for (int i = 0; i < size - 1; i++)
	{

	}
}

void TestSort()
{
	int array[] = {4,1,7,6,3,9,5,8,0,2};
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	printf("\n");
	//InsertSort(array, sizeof(array) / sizeof(array[0]));
	ShellSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
}