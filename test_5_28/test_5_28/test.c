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

//合并两个有序链表
//typedef struct ListNode ListNode;
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//{
//	//l.l1为空，合并后为l2数组
//	if (NULL == l1)
//		return l2;
//	
//	if (NULL == l2)
//		return l1;
//
//	ListNode* cur1 = l1;
//	ListNode* cur2 = l2;
//	ListNode* newhead = NULL;
//	ListNode* tailNode = NULL;
//
//	//l1和l2两个链表均不为空
//	if (cur1->val <= cur2->val)
//	{
//		newhead = cur1;
//		tailNode = cur1;
//		cur1 = cur1->next;
//	}
//	else
//	{
//		newhead = cur2;
//		tailNode = cur2;
//		cur2 = cur2->next;
//	}
//
//	//开始比较两个链表中数字大小，并进行尾插
//	while (cur1 && cur2)
//	{
//		if (cur1->val <= cur2->val)
//		{
//			tailNode->next = cur1;
//			cur1 = cur1->next;
//			//tailNode = tailNode->next;
//		}
//		else
//		{
//			tailNode->next = cur1;
//			cur1 = cur1->next;
//			//tailNode = tailNode->next;
//		}
//		tailNode = tailNode->next;
//	}
//
//	//如果有一个提前尾插结束，另一个数组还有多余
//	if (cur1)
//		tailNode->next = cur1;
//	else
//		tailNode->next = cur2;
//
//	return newhead;
//}

////改进
//typedef struct ListNode ListNode;
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//{
//	//l.l1为空，合并后为l2数组
//	if (NULL == l1)
//		return l2;
//	
//	if (NULL == l2)
//		return l1;
//
//	//链表均不为空
//	ListNode newhead;
//	ListNode* cur1 = l1;
//	ListNode* cur2 = l2; 
//	ListNode* tailNode = &newhead;
//
//	//开始比较两个链表中数字大小，并进行尾插
//	while (cur1 && cur2)
//	{
//		if (cur1->val <= cur2->val)
//		{
//			tailNode->next = cur1;
//			cur1 = cur1->next;
//			//tailNode = tailNode->next;
//		}
//		else
//		{
//			tailNode->next = cur1;
//			cur1 = cur1->next;
//			//tailNode = tailNode->next;
//		}
//		tailNode = tailNode->next;
//	}
//
//	//如果有一个提前尾插结束，另一个数组还有多余
//	if (cur1)
//		tailNode->next = cur1;
//	else
//		tailNode->next = cur2;
//
//	return newhead;
//}

//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持 原来的数据顺序不变。
//typedef struct ListNode ListNode
//ListNode* partition(ListNode* pHead, int x)
//{
//	if (NULL == pHead)
//		return NULL;
//
//	ListNode lessxhead(0);
//	ListNode* lessTail = &lessTail;
//	ListNode greatxHead(0);
//	ListNode* greatTail = &greatxHead;
//	ListNode* cur = pHead;
//	while (cur)
//	{
//		pHead = cur->next;
//
//		//将cur尾插到lessHead或greatHead
//		if (cur->val < x)
//		{
//			lessTail->next = cur;
//			lessTail = cur;
//		}
//		else
//		{
//			greatTail->next = cur;
//			greatTail = cur;
//		}
//		cur = pHead;
//	}
//
//	//最后的时候记着把greatTail->next的置位NULL
//	greatTail->next = NULL;
//	lessTail->next = greatxHead.next;
//	return lessHead.next;
//}

//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//测试样例：
//1->2->2->1
//返回：true
//法1
//bool chkPalindrome(ListNode* A) 
//{
//	//空链表也是一种回文结构
//	if (NULL == A)
//		return true;
//
//	int array[900] = {0}; 
//	//将链表中的节点放置到array的数组中
//	ListNode* cur = A;
//	int size = 0;
//	while(cur)
//	{
//		array[size++] = cur->val;
//		cur = cur->next;
//	}
//
//	int left = 0, right = size - 1;
//		while (left < right)
//		{
//			if (array[left] != array[right])
//				return false; 
//
//			left++;
//			right--;
//		}
//		return true;
//}

//法2 找中间节点
//ListNode* ReverseListNode(ListNode* head)
//{
//	ListNode* cur = head;
//	ListNode* prev = NULL;
//	ListNode* next = NULL;
//	while (cur)
//	{
//		next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//	return prev;
//}
//
//bool chkPalindrome(ListNode* A)
//{
//	if (NULL == A)
//		return true;
//
//	//找链表中的中间节点
//	ListNode* fast = A;
//	ListNode* slow = A;
//	ListNode* prevSlow = NULL;
//	while (fast && fast->next)
//	{
//		fast = fast->next->next;
//		prevSlow = slow;
//		slow = slow->next;
//	}
//
//	prevSlow->next = NULL;
//
//	//中间节点为slow
//	//将中间的节点及其后面的所有节点进行逆置
//	ListNode* rightHead = ReverseList(slow);
//
//	//检测两个链表中的节点是否相同 
//	ListNode* curRight = rightHead;
//	ListNode* curLeft = A;
//
//	while (curLeft && curRight)
//	{
//		if (curLeft->val != curRight->val)
//			return false;
//
//		curLeft = curLeft->next;
//		curRight = curRight->next;
//	}
//
//	//需要将链表还原
//	prevSlow->next = ReverseList(rightHead);
//	return true;
//	}
//}

//输入两个链表，找出它们的第一个公共结点
//typedef struct ListNode ListNode
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//	//两个链表中有一个为空，不可能相交
//	if (headB == NULL || headA == NULL)
//		return NULL;
//
//	 //两个链表都不为空
//	//1 两个链表是否相交：找到两个链表中的最后一个节点，监测该节点的地址是否相同
//	//计算两个链表中节点的个数
//	ListNode* curA = headA;
//	int countA = 1;
//	while (curA->next)
//	{
//		countA++;
//		curA = curA->next;
//	}
//
//	ListNode* curB = headB;
//	int countB = 1;
//	while (curB->next)
//	{
//		countB++;
//		curB = curB->next;
//	}
//
//	//检测循环中最后一个元素的地址是否相同，不同则不想交
//	if (curA != curB)
//		return NULL;
//
//	//相交求交点 
//	//让长的链表从起始位置走gap步
//	curA = headA;
//	curB = headB;
//	int gap = countA - countB;
//	if (gap > 0)
//	{
//		while (gap--)
//			curA = curA->next;
//	}
//	else
//	{
//		//此时gap为负数，只有gap=0时程序才跳出循环
//		while (gap++)
//			curB = curB->next;
//	}
//
//	while (curA != curB)
//	{
//		curA = curA->next;
//		curB = curB->next;
//	}
//	return curA;
//}

//给定一个链表，判断链表中是否有环。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环
//bool hasCycle(struct ListNode *head) 
//{
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//
//	while (fast && fast->next)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//
//		//在环中相遇
//		if (slow == fast)
//			return true;
//	}
//	return false;
//}

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
//typedef struct ListNode ListNode;
//struct ListNode* hasCycle(ListNode* head)
//{
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//	while (fast && fast->next)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//
//		if (fast == slow)
//			return fast;
//	}
//	return NULL;
//}
//
//struct ListNode *detectCycle(struct ListNode *head)
//{
//	ListNode* PM = hasCycle(head);
//	//两个指针不相等时则不带环
//	if (PM == NULL)
//		return NULL;
//
//	struct ListNode* PH = head;
//
//	while (PH != PM)
//	{
//		PH = PH->next;
//		PM = PM->next;
//	}
//	return PM;
//}

//对链表进行插入排序
//插入排序算法：
//1插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//2每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//3重复直到所有输入数据插入完为止
//typedef struct ListNode ListNode;
//struct ListNode* insertionSortList(struct ListNode* head) 
//{
//	//链表为空或者链表中只有一个节点
//	if (NULL == head || NULL == head->next)
//		return head;
//
//	//链表中至少有两个节点
//	//从原链表中获取一个节点将其插入到新链表中
//	ListNode* newHead = NULL;
//	ListNode* cur = head;
//	while (cur)
//	{
//		//cur指向的链表，插入到newHead指向的新链表，构成新的排序
//		head = cur->next;
//
//			//新链表中有节点，找新插入节点的位置
//			ListNode* insertPos = newHead;
//			ListNode* insertPosPrev = NULL;
//			while (insertPos)
//			{
//				if (cur->val > insertPos->val)
//				{
//					insertPosPrev = insertPos; 
//					insertPos = insertPos->next;
//				}
//				else
//				{
//					break;
//				}
//			}
//			if (NULL == insertPosPrev)
//			{
//				cur->next = newHead;
//				newHead = cur;
//			}
//			else
//			{
//				//cur节点中的数据比insertPos节点中的数据小
//				cur->next = insertPos;
//				insertPosPrev->next = cur;
//			}
//		cur = head;
//	}
//	return newHead;
//}

