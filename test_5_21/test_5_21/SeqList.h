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

//��ʼ��
void SeqListInit(SeqList* s, int initcapacity);

//β��
void SeqListPushBack(SeqList* s, SDataType data);

//βɾ
void SeqListPopBack(SeqList* s);

//ͷ��
void  SeqListFushFront(SeqList* s, SDataType data);

//ͷɾ
void SeqListPopFront(SeqList* s);

//����λ�ò���
void SeqListInsert(SeqList* s, SDataType data);

//����λ��ɾ��
void SeqListErase(SeqList* s, int pos);

//��ȡ˳�������ЧԪ�صĸ���
int SeqListSize(SeqList* s);

//��ȡ˳����е�����
int SeqListCapacity(SeqList* s);

//�ж��Ƿ�Ϊ��
int SeqListEmpty(SeqList* s);

//����ֵΪdata��Ԫ���Ƿ���˳����У��ڷ�������Ԫ�ص��±꣬���򷵻�-1
int SeqListFind(SeqList* s);

//���
void SeqListClear(SeqList* s);

//����
void SeqListDestory(SeqList* s);

