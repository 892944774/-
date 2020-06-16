#pragma once
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef int HDataType;

int Less(HDataType left, HDataType right);
int Greater(HDataType left, HDataType right);

//����ָ�����:����ָ���κ����͵�������HDataType�����Լ�һ��int���ͷ���ֵ�ĺ���
//Cmp�Ǻ���ָ�������CMP�ȿ���ָ��Less,Ҳ����ָ��Greater
//CMP�����ͣ�int(*)(HDataType, HDataType)

int(*Cmp)(HDataType left, HDataType right);

//CMP����int(*)(HDataType, HDataType)���͵ı���
typedef int(*CMP)(HDataType, HDataType);

typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
	CMP Cmp; //����ָ�����
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