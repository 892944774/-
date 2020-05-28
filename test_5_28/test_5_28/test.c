#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//删除链表中等于给定值 val 的所有节点
//示例:
//输入: 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5

//struct ListNode* removElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//
//	while (cur)
//	{
//		//该节点要被删除
//		if (cur->val == val)
//		{
//			//要删除的是头结点
//			if (cur->val == head)
//			{
//				head->next = cur->next;
//				free(cur);
//				cur = head;
//			}
//			//非头结点
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		//没找到要删除的节点，继续向下寻找，记着先将prev的地址保存起来再移动cur
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	} 
//}

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个
//中间结点
//struct ListNode* middleNode(struct ListNode* head)
//{
//	ListNode* fast = head;
//	ListNode* slow = head;
//	ListNode* prev = NULL;
//
//	//保证前两步走成功
//	while (fast && fast->next)
//	{
//		//节点个数为偶数个，并且返回中间数的前一个
//		if (fast == NULL)
//		{
//			prev = slow;
//			fast = fast->next->next;
//			slow = slow->next;
//		}
//	}
//	return prev;
//}

//反转一个单链表。
//示例:
//
//输入: 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL

//typedef struct ListNode ListNode;
//ListNode* reverseList(ListNode* head) 
//{
//	ListNode* prev = NULL;
//	ListNode* cur = head;
//	//万一head为空，cur->next的程序崩溃，不能使用 ListNode* next = cur->next;
//	ListNode* next = NULL;
//
//	while (cur)
//	{ 
//		next = cur->next;//先将next的位置固定
//		cur->next = prev;//反转->将cur的next指向prev
//		prev = cur;//首先移动prev到cur位置
//		cur = next;//再移动cur到next的位置
//	} 
//	return prev;
//}

//输入一个链表，输出该链表中倒数第k个结点。
//typedef struct ListNode ListNode;
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
//{
//	if (NULL == pListHead || k == 0)
//		return NULL;
//	ListNode* fast = pListHead;
//	ListNode* slow = pListHead;
//
//	//1.让fast先往后走k步
//	while (k--)
//	{
//		//检测k是否大于链表中节点k的个数
//		if (NULL == fast)
//			return;
//		fast = fast->next;
//	}
//
//	//2 让slow和fast一块走，直达走到fast为NULL,slow刚好指向的是倒数第k个节点
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow;
//} 

