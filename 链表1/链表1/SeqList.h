#pragma once

typedef int SLDataType; 

typedef struct SListNode
{
	struct SListNode* next;//指向下一个节点的地址
	SLDataType data;//
}SListNode;

//尾插
void SListPushBack(SListNode** head, SLDataType data);

//尾删
void SListPopback(SListNode** head);

//头插
void SListPushFront(SListNode** head, SLDataType data);

//头删
void SListPopFront(SListNode** head);

//任意位置的插入
void SListInsertAfter(SListNode* pos, SLDataType data);

//任意位置的删除
void SListEraseAfter(SListNode* pos);
 
//链表中节点的个数
int SListSize(SListNode* head);

//清空节点
int SListEmpty(SListNode* head);

SListNode* SListFind(SListNode* head, SLDataType data);

//销毁
void SListDestroy(SListNode** head);

////////////////////////////////////////////////////
void TestSList();