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
		while (end>=0 && key < array[end])
		{
			//�Ȳ����Ԫ�ش�����ƶ���Ȼ����ǰ����Ѱ��
			array[end + 1] = array[end];
			end--;
		}

		//����Ԫ��
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