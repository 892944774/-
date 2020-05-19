#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <assert.h>

typedef struct SeqList
{
	SDataType* array;    //���Ԫ�صĿռ䣬����ʱ��������
	int capacity;  //�ռ��ܵĴ�С
	int size;      //�ռ�����ЧԪ�صĸ���
}SqeList;

void SeqListInit(SeqList* s, int initCapacity)

//β��
void SeqListPushBack(SeqList* s, SDataType data);

//βɾ
void SeqListPopBack(SeqList* s);

//ͷ��
void SeqListPushFront(SeqList* s, SDataType data);

//ͷɾ
void SeqListPopFront(SeqList* s);

//����λ�ò���
void SeqListInsert(SeqList* s, int pos, SDataType data);

//����λ�õ�ɾ��
void SeqListErase(SeqList* s, int pos);

//��ȡ˳�������ЧԪ�ظ���
int SeqListSize(SeqList* s)
{
	assert(s);
	return s->size;
}

//��ȡ˳����е�����
int SeqListCapacity(SeqList* s)
{
	assert(s);
	return s->capacity;
}

//�ж��Ƿ�Ϊ��
int SeqListEmpty(SeqList* s)
{
	assert(s);
	return 0 == s->size;
}

int SeqListData(SeqList* s, SDataType data);

//���
void SeqListClear(SeqList* s)
{
	assert(s);
	s->size = 0;
}

void SeqListDestory(SeqList* s);