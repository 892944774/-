#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <assert.h>

typedef struct SeqList
{
	SDataType* array;    //存放元素的空间，不够时申请更大的
	int capacity;  //空间总的大小
	int size;      //空间中有效元素的个数
}SqeList;

void SeqListInit(SeqList* s, int initCapacity)

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
int SeqListSize(SeqList* s)
{
	assert(s);
	return s->size;
}

//获取顺序表中的容量
int SeqListCapacity(SeqList* s)
{
	assert(s);
	return s->capacity;
}

//判断是否为空
int SeqListEmpty(SeqList* s)
{
	assert(s);
	return 0 == s->size;
}

int SeqListData(SeqList* s, SDataType data);

//清空
void SeqListClear(SeqList* s)
{
	assert(s);
	s->size = 0;
}

void SeqListDestory(SeqList* s);