#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//s=1+(1+2)+(1+2+3)+...+(1+2+3+...+n)
//int main()
//{
//	int i ,j;
//	int n = 0;
//	int sum = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			sum += j;
//		}
//	}
//	printf("%d ", sum);
//	return 0;
//}

//1-1/2+1-3-1/4+...+1/99-1/100
//int main()
//{
//	int i = 0;
//	float sum = 0.0;
//	float a = 1.0;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum + a/i;
//		a = -a;
//	}
//	printf("%lf ", sum);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i-1; j++)
//		{ 
//			printf(" ");
//		}
//		for (j = 0; j <= n-i; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}

// }

//int main()
//{
//	int i = 0;
//	int j = 0;
//	int s = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			s = j * i;
//			printf("%d*%d=%-2d ", j,i,s);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//����A+B֮��
//int main()
//{
//	int a[3][4] = { {1,2,3,4},{3,4,5,6},{5,6,7,8} };
//	int b[3][4] = { {1,2,3},{4,5},{6} };
//	int i, j;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			a[i][j] += b[i][j];
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%2d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

void heapSort(int *array, int length)
{
	int i, tmp;

	if (length <= 1) 
	return;//���Ԫ��С��1�����˳�
     		//��һ�����Ȱ�Ԫ�ض��ѻ��ã�����Ļ� �ĸ��ڵ��޸Ĺ����ʹ��ĸ��ڵ㿪ʼ������Ϊ���ڵ���������жѻ�
	for (i = length / 2 - 1; i >= 0; i--)  
		_heapSort(array, i, length);//�ӵ�һ����Ҷ�ӽڵ㿪ʼ����һֱ�����ڵ�

    // �ȳ�ȡ�����ڵ㣬Ȼ���ٶ�Ԫ�ؽ��жѻ���Ȼ���ֳ�ȡ���ڵ㣬�ٶ�Ԫ�ؽ��жѻ�������������ѭ��
	for (i = 0; i < length; i++)
	{
		tmp = array[0];
		array[0] = array[length - i - 1];
		array[length - i - 1] = tmp;
		_heapSort(array, 0, length - 1 - i);//�ѻ�����
	}
}