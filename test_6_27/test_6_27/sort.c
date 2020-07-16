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

//向下调整
void HeapAdjust(int array[], int size, int parent)
{
	//用child标记parent中较大的孩子，默认先标记parent的左孩子
	//先标记左孩子的原因是：如果parent有孩子，parent一定先是有左孩子

	int child = parent * 2 + 1;

	while (child < size)
	{
		//找parent中较大的孩子:用parent左右孩子比较，必须先保证parent的右孩子存在
		if (child + 1 < size && array[child + 1] > array[child])
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

//冒泡排序
//时间复杂度 O(N^2)
//空间复杂度 O(1)
//稳定
void BubbleSort(int array[], int size)
{
	//减一是为了少冒一趟，因为最后一次区间只剩下一个元素
	//外层循环控制冒泡的趟数
	for (int i = 0; i < size - 1; i++)
	{
		//具体冒泡的方式，用相邻位置的元素进行比较，不满足条件进行交换
		//减一的目的是区间只能取到倒数第二个元素，否则会产生越界
		//j表示前一个元素
		/*
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
				Swap(&array[j], &array[j+1]);
		}
		*/

		int flag = 0;//该趟冒泡还没有比较，因此将flag设置为0
		//j表示后一个元素
		for (int j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				Swap(&array[j], &array[j - 1]);
				flag = 1; //在该趟冒泡时区间还无序
			}
		}
		if (!flag)
			return;
	}
}

//三数取中法
int GetMiddleIndex(int array[], int left, int right)
{
	int mid = left + ((right - left) >> 1);
	//三个数据：left、mid、right-1

	//left为中间数
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right - 1;
		else
			return mid;
	}

	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

//快速排序 -- 分割法
int Partion1(int array[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key;
	int keyofindex = GetMiddleIndex(array, left, right);

	//将基准值和最右侧的值进行交换
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right-1]);

	key = array[right-1];//关键字为最右边的数字

	while (begin<end)
	{
		//让begin从前向后找，找到比关键字大的数字停止
		while (begin < end && array[begin] <= key)
			begin++;
		 
		//让end从后向前找比关键字小的停止
		while (begin < end && array[end] >= key)
			end--;
		
		//交换两数
		if(begin < end)
		Swap(&array[begin], &array[end]);
	}

	//结束后交换基准值到中间位置
	if(begin != right - 1)
	Swap(&array[begin], &array[right - 1]);

	return begin;
}

//快速排序 -- 挖坑法
int Partion2(int array[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key;
	int keyofindex = GetMiddleIndex(array, left, right);

	//将基准值和最右侧的值进行交换
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);

	key = array[right - 1];//关键字为最右边的数字

	while (begin<end)
	{
		//end位置形成了一个新的坑，让begin从前向后找 
		//让begin从前向后找，找到比关键字大的数字停止
		while (begin < end && array[begin] <= key)
			begin++;

		//让begin大的位置的元素填end位置的坑
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}

		//begin又形成了一个新的坑，让end从后向前找比基准值小的元素，填begin位置的坑
		//让end从后向前找比关键字小的停止
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
		{
			array[end] = array[begin];
			begin++;
		}

		//交换两数
		if (begin < end)
			Swap(&array[begin], &array[end]);
	}

	//结束后用基准值填中间位置的坑
	array[begin] = key;

	return begin;
}

//前后指针法
//int Partion3(int array[], int left, int right)
//{
//	int cur = left;
//	int prev = cur - 1;
//	int key;
//	int keyofindex = GetMiddleIndex(array, left, right);
//
//	//将基准值和最右侧的值进行交换
//	if (keyofindex != right - 1)
//		Swap(&array[keyofindex], &array[right - 1]);
//
//	key = array[right - 1];//关键字为最右边的数字
//
//	while (cur < right)
//	{
//		if (array[cur] < key && ++prev != cur)
//			Swap(&array[cur], &array[prev]);
//
//		cur++;
//	}
//
//	if (++prev != right - 1)
//		Swap(&array[right-1], &array[prev]);
//
//	return prev;
//}

//快速排序
//void QuickSort(int array[], int left, int right)
//{
//	if (right - left > 16)
//	{
//		//数据量较小时采用插入排序，这个阈值可以自己设定
//		InsertSort(array+left, right-left);
//	}
//	{
//		//Partion按照基准值（区间中的某个元素）对区间进行划分，左部分比基准值小，右部分比基准值大
//		//该函数返回基准值在区间中的位置
//		//[left, right)区间中的基准值位置已经存放好了，基准值左侧和基准值右侧不一定有序
//		//int div = Partion1(array, left, right);
//		int div = Partion3(array, left, right);
//
//		QuickSort(array, left, div);
//		QuickSort(array, div+1, right);
//	}
//}

//用栈将递归转化为循环，先将栈的源文件和头文件引用
//void QuickSortNor(int array[], int size)
//{
//	int left = 0;
//	int right = size;
//	Stack s;
//	StackInit(&s);
//
//	//先放右再放左，取得时候是先左再右
//	StackPush(&s, right);
//	StackPush(&s, left);
//	while(!StackEmpty(&s))
//	{
//		//先按照基准值来划分
//		left = StackTop(&s);
//		StackPop(&s);
//
//		right = StackTop(&s);
//		stackPop(&s);
//
//		if (right - left > 1)
//		{
//			int div = Partion2(array, left, right);
//
//			StackPush();
//			//排基准值的左半侧--将右半部分的区间入栈[div+1, right)
//			StackPush(&s, right);
//			StackPush(&s, div+1);
//
//			//排基准值的右半侧--将左半部分的区间入栈[left, div)
//			StackPush(&s, div);
//			StackPush(&s, left);
//		}
//	}
//	StackDestory(&s);
//}

//时间复杂度 O(N)
void MergeData(int array[], int left, int mid, int right, int temp[])
{
	int index1 = left, index2 = mid, index = left;
	while (index1 < mid && index2 < right)
	{
		//将较小的数据搬移到辅助空间
		if (array[index1] <= array[index2])
			temp[index++] = array[index1++];
		else
			temp[index++] = array[index2++];
	}

	//[left, mid)区间中的数据没有搬移完
	while (index1 < mid)
	{
		temp[index++] = array[index1++];
	}

	//[mid, right)区间中数据没搬移完
	while (index2 < right)
	{
		temp[index++] = array[index2++];
	}
}

void _MergeSort(int array[], int left, int right, int temp[])
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);

		//[left, mid) 排左半侧
		_MergeSort(array, left, mid, temp);

		//[mid, right) 排右半侧
		_MergeSort(array, mid, right, temp);

		//将[left, mid)和[mid, right]归并到一起
		MergeData(array, left, mid, right, temp);

		//归并好之后，有序的数据保存在辅助空间temp中，并拷贝到原空间中
		memcpy(array + left, temp + left, (right - left) * sizeof(array[0]));
	}
}

//将两个有序的数组合并成一个有序数组
//稳定性 稳定  
void MergeSort(int array[], int size)
{
	int* temp = (int*)malloc(size*sizeof(array[0]));
	if (NULL == temp)
		return;

	_MergeSort(array, 0, size, temp);
	free(temp);
}

void MergeSortNor(int array[], int size)
{
	int gap = 1;
	int* temp = (int*)malloc(size*array[0]);
	if (NULL == temp)
		return;

	while (gap < size)
	{
		for (int i = 0; i < size; i += 2*gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			//如果mid越界
			if (mid > mid)
				mid = size;

			//如果right越界
			if (right > size)
				right = size;

			//[left, mid)和[mid, right)每个分组中有gap个数据
			MergeData(array, left, mid, right, temp);
		}

		mencpy(array, temp, size * sizeof(array[0]));
		gap *= 2;
	}
	free(temp);
}

void TestSort()
{
	int array[] = {4,1,7,6,3,9,5,8,0,2};
	//int array[] = { 4,1,7,6,3,9,2,8,0,5 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	printf("\n");
	//InsertSort(array, sizeof(array) / sizeof(array[0]));
	//ShellSort(array, sizeof(array) / sizeof(array[0]));

	//BubbleSort(array, sizeof(array) / sizeof(array[0]));
	//QuickSort(array, 0, sizeof(array) / sizeof(array[0]));
	MergeSort(array, sizeof(array)/sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
}