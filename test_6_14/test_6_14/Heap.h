#pragma once
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef int HDataType;

int Less(HDataType left, HDataType right);
int Greater(HDataType left, HDataType right);

//函数指针变量:可以指向任何类型的有两个HDataType参数以及一个int类型返回值的函数
//Cmp是函数指针变量：CMP既可以指向Less,也可以指向Greater
//CMP的类型：int(*)(HDataType, HDataType)

int(*Cmp)(HDataType left, HDataType right);

//CMP就是int(*)(HDataType, HDataType)类型的别名
typedef int(*CMP)(HDataType, HDataType);

typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
	CMP Cmp; //函数指针变量
}Heap;

void HeapInit(Heap* hp, int initCap, CMP cmp);
void HeapCreate(Heap* hp, int* array, int size, CMP cmp);
void HeapPush(Heap* hp);
void HeadPop(Heap* hp);
HDataType HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
int HeapSize(Heap* hp);
void HeapDestroy(Heap* hp);

//////////////////
void TestHeap();