#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

//��������:û�ж�����Ӧ����
//����Ϊ��:head���ڣ�ֻ������ָ�����NULL

//����ڵ�
SListNode* BuySListNode(SLDataType data)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
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
void SListPopback(SListNode** head)
{
	assert(head);

	//1 ������  ֱ�ӷ���
	if (NULL == *head)
		return;
	//2 ֻ��һ���ڵ�
	else if (NULL == (*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	//3 ����ǿ� - ����һ���ڵ�
	else
	{
		SListNode* cur = *head;
		SListNode* prev = NULL;//���cur��ǰһ���ڵ�
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}

		//���һ���ڵ��Ѿ��ҵ�����ɾ���ýڵ�,ͬʱ��cur��ǰһ���Ľڵ�ָ��NULL
		prev->next = NULL;
		//����prev->next = cur->next;
		free(cur);
	}
}

//1 �������
//2 �����߼�
//ͷ��
void SListPushFront(SListNode** head, SLDataType data)
{
	assert(head);
	SListNode* newNode = BuySListNode(data);
	newNode->next = *head;//�½ڵ��nextָ��ԭ��ͷ�ڵ�ĵ�ַ
	*head = newNode;//ͷָ��ָ���½ڵ�

	//1 ������
	//if (NULL == *head)
	//{
	//	*head = newNode;
	//}
	// 
	////2 �������ж���ڵ�
	//else
	//{
	//	newNode->next = *head;//�½ڵ��nextָ��ԭ��ͷ�ڵ�ĵ�ַ
	//	*head = newNode;//ͷָ��ָ���½ڵ�
	//}
}

//ͷɾ    head�������ͷָ��ĵ�ַ����Ҫ�ı����ͷָ���ָ��
void SListPopFront(SListNode** head)
{
	SListNode* delNode = NULL;
	assert(head);

	if (NULL == *head)
		return;

	delNode = *head;
	*head = delNode->next;
	free(delNode);

	//��һ���ڵ㣬Ҳ����*head->nextΪ�գ�Ȼ��ֱ��free����λNULL
	//else if (NULL == (*head)->next)
	//{
	//	free(*head);
	//	*head = NULL;
	//}
	////��ֹһ���ڵ㣬�ȱ�ǣ����ƶ�����ɾ��
	//else
	//{
	//	SListNode* delNode = *head;
	//	*head = delNode->next;
	//	free(delNode);
	//}
}

//����λ�õĲ���,ֻ����ǰλ�õĺ�����в��룬����ֻ�������
void SListInsertAfter(SListNode* pos, SLDataType data)
{
	if (NULL == pos)
		return;

	SListNode* newNode = BuySListNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
}

//����λ�õ�ɾ��,ֻ����ǰλ�õĺ������ɾ��������ֻ�������
void SListEraseAfter(SListNode* pos)
{
	SListNode* delNode = NULL;
	if (NULL == pos && pos->next == NULL)
		return;
	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}

//�����нڵ�ĸ���  headָ��ľ��������е�һ���ڵ㣬ֻ��Ҫ�����ڵ����������Ҫ�ı�ͷָ���ָ��
int SListSize(SListNode* head)
{
	assert(head);//�˴�����assert����Ϊ����������һ�������������ǺϷ���

	if (head == NULL)
		return 0;

	int count = 0; 
	while (head)
	{
		count++;
		head = head->next;
	}

	return count;
}

//��սڵ�
int SListEmpty(SListNode* head)
{
	return NULL == head;//����һ�����������
}

//����
SListNode* SListFind(SListNode* head, SLDataType data)
{
	SListNode* cur = head;

	while (cur)
	{
		if (cur->data == data)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

//����  ����ͷɾ������������
void SListDestroy(SListNode** head)
{
	SListNode* delNode = NULL;
	assert(head);
	while (*head)
	{
		delNode = *head;
		*head = delNode->next;
		free(delNode);
	}
}

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
//void TestList1()
//{
//	SListNode* Listhead = NULL;
//	SListPushBack(&Listhead, 1);
//	SListPushBack(&Listhead, 2);
//	SListPushBack(&Listhead, 3);
//	SListPushBack(&Listhead, 4);
//	SListPushBack(&Listhead, 5);
//
//	//SListPushBack(NULL, 5);//�Ƿ����ã�Ӧ��ʹ��assertʹ����ֹͣ����������
//
//	SlistPopback(&Listhead);
//	SlistPopback(&Listhead);
//	SlistPopback(&Listhead);
//	SlistPopback(&Listhead);
//	SlistPopback(&Listhead);
//	SlistPopback(&Listhead);
//
//	PrintSList(Listhead);
//  SListDestroy(&Listhead);
//}

//void TestList2()
//{
//	SListNode* Listhead = NULL;
//	SListPushFront(&Listhead, 1);
//	SListPushFront(&Listhead, 2);
//	SListPushFront(&Listhead, 3);
//	SListPushFront(&Listhead, 4);
//	SListPushFront(&Listhead, 5);
//
//	PrintSList(Listhead);
//	SListDestroy(&Listhead);
//
//}

void TestList3()
{
	SListNode* Listhead = NULL;
	SListPushBack(&Listhead, 1);
	SListPushBack(&Listhead, 2);
	SListPushBack(&Listhead, 3);
	SListPushBack(&Listhead, 4);
	SListPushBack(&Listhead, 5);

	SListInsertAfter(SListFind(Listhead, 3), 0);
	PrintSList(Listhead);

	SListInsertAfter(SListFind(Listhead, 100), 10);
	PrintSList(Listhead);

	SListEraseAfter(SListFind(Listhead, 0));//ɾ����0�����4
	PrintSList(Listhead);


	SListDestroy(&Listhead);
}

void TestSList() 
{
    //TestList1();
	//TestList2();
	TestList3();
}