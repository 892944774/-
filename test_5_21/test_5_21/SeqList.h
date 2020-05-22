#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int SDataType;

typedef struct SeqList
{
	SDataType* array;
	int capacity;
	int size;
}SeqList;

//初始化
void SeqListInit(SeqList* s, int initcapacity);

//尾插
void SeqListPushBack(SeqList* s, SDataType data);

//尾删
void SeqListPopBack(SeqList* s);

//头插
void  SeqListFushFront(SeqList* s, SDataType data);

//头删
void SeqListPopFront(SeqList* s);

//任意位置插入
void SeqListInsert(SeqList* s, SDataType data);

//任意位置删除
void SeqListErase(SeqList* s, int pos);

//获取顺序表中有效元素的个数
int SeqListSize(SeqList* s);

//获取顺序表中的容量
int SeqListCapacity(SeqList* s);

//判断是否为空
int SeqListEmpty(SeqList* s);

//查找值为data的元素是否在顺序表中，在返回所在元素的下标，否则返回-1
int SeqListFind(SeqList* s);

//清空
void SeqListClear(SeqList* s);

//销毁
void SeqListDestory(SeqList* s);

