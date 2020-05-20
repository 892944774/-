#pragma once
#include <assert.h>
#include <malloc.h>
#include <stdio.h>

typedef int SDataType;
//typedef double SDataType;

typedef struct SeqList
{
	SDataType* array;    //存放元素的空间，不够时申请更大的
	int capacity;  //空间总的大小
	int size;      //空间中有效元素的个数
}SeqList;

//初始化
void SeqListInit(SeqList* s, int initCapacity);

//尾插
void SeqListPushBack(SeqList* s, SDataType data);

//尾删
void SeqListPopBack(SeqList* s);

//头插
void SeqListPushFront(SeqList* s, SDataType data);

//头删
void SeqListPopFront(SeqList* s);

//任意位置插入
void SeqListInsert(SeqList* s, int pos, SDataType data);

//任意位置的删除
void SeqListErase(SeqList* s, int pos);

//获取顺序表中有效元素个数
int SeqListSize(SeqList* s);

//获取顺序表中的容量
int SeqListCapacity(SeqList* s);

//判断是否为空
int SeqListEmpty(SeqList* s);

//查找值为data的元素是否在顺序表中，如果在返回下标，否则返回-1
int SeqListFind(SeqList* s, SDataType data);

//清空
void SeqListClear(SeqList* s);

//销毁
void SeqListDestory(SeqList* s);

////////////////////
//测试方法
void TestSeqList();