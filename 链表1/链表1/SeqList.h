#pragma once

typedef int SLDataType; 

typedef struct SListNode
{
	struct SListNode* next;//ָ����һ���ڵ�ĵ�ַ
	SLDataType data;//
}SListNode;

//β��
void SListPushBack(SListNode** head, SLDataType data);

//βɾ
void SListPopback(SListNode** head);

//ͷ��
void SListPushFront(SListNode** head, SLDataType data);

//ͷɾ
void SListPopFront(SListNode** head);

//����λ�õĲ���
void SListInsertAfter(SListNode* pos, SLDataType data);

//����λ�õ�ɾ��
void SListEraseAfter(SListNode* pos);
 
//�����нڵ�ĸ���
int SListSize(SListNode* head);

//��սڵ�
int SListEmpty(SListNode* head);

SListNode* SListFind(SListNode* head, SLDataType data);

//����
void SListDestroy(SListNode** head);

////////////////////////////////////////////////////
void TestSList();