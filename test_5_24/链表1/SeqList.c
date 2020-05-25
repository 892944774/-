#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

//申请节点
SListNode* BuySListNode(SLDataType data)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SLDataType));
	if (NULL == newNode)
	{
		assert(0);//调试宏，参数为0时触发，非0不会触发
	}

	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

//尾插 
void SListPushBack(SListNode** head, SLDataType data)
{
	assert(head);
	//空链表
	//先申请节点
	SListNode* newNode = BuySListNode(data);
	if (NULL == *head)
	{
		*head = newNode;
	}
	else
	{
		//1 找到链表中的最后一个节点
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
			//cur++;err
		}

		//2 插入到新节点
		cur->next = newNode;
	}
}

//尾删
void SListPopback(SListNode* head);

//头插
void SListPushFront(SListNode* head, SLDataType data);

//头删
void SListPopFront(SListNode* head);

//任意位置的插入
void SListInsert(SListNode* pos, SLDataType data);

//任意位置的删除
void SListErase(SListNode* pos);

//链表中节点的个数
int SListSize(SListNode* List);

//清空节点
int SListEmpty(SListNode* head);

SListNode* SListFind(SListNode* head, SLDataType data);

//销毁
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