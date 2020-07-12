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

//����������Ĺ�����û��ʹ�ö���ĸ����ռ�,�ռ临�Ӷ�O(1)
//һ��Ԫ��ʱ�临�Ӷ�ΪO(N)��size��Ԫ��,ʱ�临�Ӷ�ΪO(N^2) 
//�ȶ��ԣ��ȶ�
void InsertSort(int array[], int size)
{
	//i��1��ʼ,�±�Ϊ0��Ԫ��ֻ��һ�����Ѿ�����ֱ�Ӵ�1��ʼ
	//���ѭ�����ƶ��ٸ�������Ҫ����
		for (int i = 1; i < size; i++)
		{
			//����Ԫ�صĲ������
			int key = array[i];
			int end = i - 1;

			//�Ҵ�����Ԫ���������е�λ��,end���±�Ϊ0֮ǰ��λ�þͽ���
			//����������Ҫ��i֮ǰ�����Ѳ����Ԫ�������а���---O(N)
			while (end >= 0 && key < array[end])
			{
				//�Ȳ����Ԫ�ش�����ƶ���Ȼ����ǰ����Ѱ��
				array[end + 1] = array[end];
				end--;
			}

			//����Ԫ��
			array[end + 1] = key;
		}
}

//ʱ�临�Ӷȣ�O(N^1.25)~O(1.6N^1.25)
//�ռ临�Ӷȣ�O(1)
void ShellSort(int array[], int size)
{
	int gap = 3;
	//i��1��ʼ,�±�Ϊ0��Ԫ��ֻ��һ�����Ѿ�����ֱ�Ӵ�1��ʼ
	//���ѭ�����ƶ��ٸ�������Ҫ����
	while (gap>0)
	{
		for (int i = gap; i < size; i++)
		{
			//����Ԫ�صĲ������
			int key = array[i];
			int end = i - gap;

			//�Ҵ�����Ԫ���������е�λ��,end���±�Ϊ0֮ǰ��λ�þͽ���
			//����������Ҫ��i֮ǰ�����Ѳ����Ԫ�������а���---O(N)
			while (end >= 0 && key < array[end])
			{
				//�Ȳ����Ԫ�ش�����ƶ���Ȼ����ǰ����Ѱ��
				array[end + gap] = array[end];
				end -= gap;
			}
			//����Ԫ�أ����뵽��ǰ�������һ��λ��
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

//ѡ������
//ʱ�临�Ӷ� O(N^2)
//�ռ临�Ӷ� O(1)
//�ȶ��� ���ȶ�
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		//�ҵ�ǰ���������Ԫ�ص�λ��
		int maxPos = 0;
		for (int j = 0; j < size - i; ++j)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}

		//����ѭ�������Ԫ�ط������һ��λ��
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
		//��[begin, end]�������ҵ�������С��Ԫ��
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

		//�������Ԫ�ز�����������λ��
		if (maxPos != end)
			Swap(&array[maxPos], &array[end]);

		//���endλ�ô洢�ĸպ�����С��Ԫ�أ�����Ľ����ͽ���С��Ԫ��λ�ø�����---maxPos
		//��СԪ�ص�λ�÷����˸ı䣬�����Ҫ����minPos
		if (minPos == end)
			minPos = maxPos;

		//�����С��Ԫ�ز����������ʼλ��
		if (minPos != begin)
			Swap(&array[minPos], &array[begin]);
		
		++begin;
		--end;
	}
}



//������
//ʱ�临�Ӷ� O(NlogN)
//�ռ临�Ӷ� O(1)
//�ȶ��ԣ����ȶ�
void HeapSortOP(int array[], int size)
{
	int end = size - 1;
	//1 ����
	//ע��ӵ�����һ����Ҷ�ӽڵ��λ�ÿ�ʼʹ�öѵ�����һֱ���������ڵ��λ��
	for (int root = (size - 2) / 2; root >= 0; root--)
		HeapAdjust(array, size, root);//���µ���
	//2 ����->���ö�ɾ����˼���������
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

//���µ���
void HeapAdjust(int array[], int size, int parent)
{
	//��child���parent�нϴ�ĺ��ӣ�Ĭ���ȱ��parent������
	//�ȱ�����ӵ�ԭ���ǣ����parent�к��ӣ�parentһ������������

	int child = parent * 2 + 1;

	while (child < size)
	{
		//��parent�нϴ�ĺ���:��parent���Һ��ӱȽϣ������ȱ�֤parent���Һ��Ӵ���
		if (child+1 < size && array[child + 1] > array[child])
			child += 1;

		//���parent�Ƿ�����ѵ�����
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

//ð������
void BubbleSort(int array[], int size)
{
	//��һ��Ϊ����ðһ�ˣ���Ϊ���һ������ֻʣ��һ��Ԫ��
	//���ѭ������ð�ݵ�����
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