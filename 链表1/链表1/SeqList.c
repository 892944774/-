#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

//链表不存在:没有定义相应函数
//链表为空:head存在，只不过其指向的是NULL

//申请节点
SListNode* BuySListNode(SLDataType data)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
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
void SListPopback(SListNode** head)
{
	assert(head);

	//1 空链表  直接返回
	if (NULL == *head)
		return;
	//2 只有一个节点
	else if (NULL == (*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	//3 链表非空 - 至少一个节点
	else
	{
		SListNode* cur = *head;
		SListNode* prev = NULL;//标记cur的前一个节点
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}

		//最后一个节点已经找到，并删除该节点,同时让cur的前一个的节点指向NULL
		prev->next = NULL;
		//或者prev->next = cur->next;
		free(cur);
	}
}

//1 参数检测
//2 程序逻辑
//头插
void SListPushFront(SListNode** head, SLDataType data)
{
	assert(head);
	SListNode* newNode = BuySListNode(data);
	newNode->next = *head;//新节点的next指向原来头节点的地址
	*head = newNode;//头指针指向新节点

	//1 空链表
	//if (NULL == *head)
	//{
	//	*head = newNode;
	//}
	// 
	////2 链表中有多个节点
	//else
	//{
	//	newNode->next = *head;//新节点的next指向原来头节点的地址
	//	*head = newNode;//头指针指向新节点
	//}
}

//头删    head保存的是头指针的地址，需要改变的是头指针的指向
void SListPopFront(SListNode** head)
{
	SListNode* delNode = NULL;
	assert(head);

	if (NULL == *head)
		return;

	delNode = *head;
	*head = delNode->next;
	free(delNode);

	//有一个节点，也就是*head->next为空，然后直接free，置位NULL
	//else if (NULL == (*head)->next)
	//{
	//	free(*head);
	//	*head = NULL;
	//}
	////不止一个节点，先标记，再移动，后删除
	//else
	//{
	//	SListNode* delNode = *head;
	//	*head = delNode->next;
	//	free(delNode);
	//}
}

//任意位置的插入,只能向当前位置的后面进行插入，链表只能向后走
void SListInsertAfter(SListNode* pos, SLDataType data)
{
	if (NULL == pos)
		return;

	SListNode* newNode = BuySListNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
}

//任意位置的删除,只能向当前位置的后面进行删除，链表只能向后走
void SListEraseAfter(SListNode* pos)
{
	SListNode* delNode = NULL;
	if (NULL == pos && pos->next == NULL)
		return;
	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}

//链表中节点的个数  head指向的就是链表中第一个节点，只需要遍历节点个数，不需要改变头指针的指向
int SListSize(SListNode* head)
{
	assert(head);//此处不用assert，因为传过来的是一个链表，空链表是合法的

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

//清空节点
int SListEmpty(SListNode* head)
{
	return NULL == head;//返回一个非零的数据
}

//查找
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

//销毁  采用头删法将链表销毁
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
//	//SListPushBack(NULL, 5);//非法调用，应该使用assert使程序停止下来，调试
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

	SListEraseAfter(SListFind(Listhead, 0));//删除了0后面的4
	PrintSList(Listhead);


	SListDestroy(&Listhead);
}

void TestSList() 
{
    //TestList1();
	//TestList2();
	TestList3();
}