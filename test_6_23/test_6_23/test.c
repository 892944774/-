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

//数组A+B之和
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
	return;//如果元素小于1，则退出
     		//这一步是先把元素都堆化好，后面的话 哪个节点修改过，就从哪个节点开始对以它为根节点的子树进行堆化
	for (i = length / 2 - 1; i >= 0; i--)  
		_heapSort(array, i, length);//从第一个非叶子节点开始排序，一直到根节点

    // 先抽取到根节点，然后再对元素进行堆化，然后又抽取根节点，再对元素进行堆化。。。。依次循环
	for (i = 0; i < length; i++)
	{
		tmp = array[0];
		array[0] = array[length - i - 1];
		array[length - i - 1] = tmp;
		_heapSort(array, 0, length - 1 - i);//堆化子树
	}
}