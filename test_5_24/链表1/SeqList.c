#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

//����ڵ�
SListNode* BuySListNode(SLDataType data)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SLDataType));
	if (NULL == newNode)
	{
		assert(0);//���Ժ꣬����Ϊ0ʱ��������0���ᴥ��
	}

	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

//β�� 
void SListPushBack(SListNode** head, SLDataType data)
{
	assert(head);
	//������
	//������ڵ�
	SListNode* newNode = BuySListNode(data);
	if (NULL == *head)
	{
		*head = newNode;
	}
	else
	{
		//1 �ҵ������е����һ���ڵ�
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
			//cur++;err
		}

		//2 ���뵽�½ڵ�
		cur->next = newNode;
	}
}

//βɾ
void SListPopback(SListNode* head);

//ͷ��
void SListPushFront(SListNode* head, SLDataType data);

//ͷɾ
void SListPopFront(SListNode* head);

//����λ�õĲ���
void SListInsert(SListNode* pos, SLDataType data);

//����λ�õ�ɾ��
void SListErase(SListNode* pos);

//�����нڵ�ĸ���
int SListSize(SListNode* List);

//��սڵ�
int SListEmpty(SListNode* head);

SListNode* SListFind(SListNode* head, SLDataType data);

//����
void SListDestroy(SListNode* head);

void PrintSList(SListNode* head)
{
	SListNode* cur = head;
	while (cur)
	{
		printf("%d---->", cur->data);
		cur = cur->next;
	}

	printf("NULL\n");
}
////////////////////////////////////////////////////
void TestSList()
{
	SListNode* head = NULL;
	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPushBack(&head, 5);

	PrintSList(head);
}