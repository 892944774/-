#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//ɾ�������е��ڸ���ֵ val �����нڵ�
//ʾ��:
//����: 1->2->6->3->4->5->6, val = 6
//��� : 1->2->3->4->5

//struct ListNode* removElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//
//	while (cur)
//	{
//		//�ýڵ�Ҫ��ɾ��
//		if (cur->val == val)
//		{
//			//Ҫɾ������ͷ���
//			if (cur->val == head)
//			{
//				head->next = cur->next;
//				free(cur);
//				cur = head;
//			}
//			//��ͷ���
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		//û�ҵ�Ҫɾ���Ľڵ㣬��������Ѱ�ң������Ƚ�prev�ĵ�ַ�����������ƶ�cur
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	} 
//}

//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ���
//�м���
//struct ListNode* middleNode(struct ListNode* head)
//{
//	ListNode* fast = head;
//	ListNode* slow = head;
//	ListNode* prev = NULL;
//
//	//��֤ǰ�����߳ɹ�
//	while (fast && fast->next)
//	{
//		//�ڵ����Ϊż���������ҷ����м�����ǰһ��
//		if (fast == NULL)
//		{
//			prev = slow;
//			fast = fast->next->next;
//			slow = slow->next;
//		}
//	}
//	return prev;
//}

//��תһ��������
//ʾ��:
//
//����: 1->2->3->4->5->NULL
//��� : 5->4->3->2->1->NULL

//typedef struct ListNode ListNode;
//ListNode* reverseList(ListNode* head) 
//{
//	ListNode* prev = NULL;
//	ListNode* cur = head;
//	//��һheadΪ�գ�cur->next�ĳ������������ʹ�� ListNode* next = cur->next;
//	ListNode* next = NULL;
//
//	while (cur)
//	{ 
//		next = cur->next;//�Ƚ�next��λ�ù̶�
//		cur->next = prev;//��ת->��cur��nextָ��prev
//		prev = cur;//�����ƶ�prev��curλ��
//		cur = next;//���ƶ�cur��next��λ��
//	} 
//	return prev;
//}

//����һ����������������е�����k����㡣
//typedef struct ListNode ListNode;
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
//{
//	if (NULL == pListHead || k == 0)
//		return NULL;
//	ListNode* fast = pListHead;
//	ListNode* slow = pListHead;
//
//	//1.��fast��������k��
//	while (k--)
//	{
//		//���k�Ƿ���������нڵ�k�ĸ���
//		if (NULL == fast)
//			return;
//		fast = fast->next;
//	}
//
//	//2 ��slow��fastһ���ߣ�ֱ���ߵ�fastΪNULL,slow�պ�ָ����ǵ�����k���ڵ�
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow;
//} 

//�ϲ�������������
//typedef struct ListNode ListNode;
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//{
//	//l.l1Ϊ�գ��ϲ���Ϊl2����
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
//	//l1��l2�����������Ϊ��
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
//	//��ʼ�Ƚ��������������ִ�С��������β��
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
//	//�����һ����ǰβ���������һ�����黹�ж���
//	if (cur1)
//		tailNode->next = cur1;
//	else
//		tailNode->next = cur2;
//
//	return newhead;
//}

////�Ľ�
//typedef struct ListNode ListNode;
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//{
//	//l.l1Ϊ�գ��ϲ���Ϊl2����
//	if (NULL == l1)
//		return l2;
//	
//	if (NULL == l2)
//		return l1;
//
//	//�������Ϊ��
//	ListNode newhead;
//	ListNode* cur1 = l1;
//	ListNode* cur2 = l2; 
//	ListNode* tailNode = &newhead;
//
//	//��ʼ�Ƚ��������������ִ�С��������β��
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
//	//�����һ����ǰβ���������һ�����黹�ж���
//	if (cur1)
//		tailNode->next = cur1;
//	else
//		tailNode->next = cur2;
//
//	return newhead;
//}

//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
//����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳� ԭ��������˳�򲻱䡣
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
//		//��curβ�嵽lessHead��greatHead
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
//	//����ʱ����Ű�greatTail->next����λNULL
//	greatTail->next = NULL;
//	lessTail->next = greatxHead.next;
//	return lessHead.next;
//}

//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//����������
//1->2->2->1
//���أ�true
//��1
//bool chkPalindrome(ListNode* A) 
//{
//	//������Ҳ��һ�ֻ��Ľṹ
//	if (NULL == A)
//		return true;
//
//	int array[900] = {0}; 
//	//�������еĽڵ���õ�array��������
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

//��2 ���м�ڵ�
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
//	//�������е��м�ڵ�
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
//	//�м�ڵ�Ϊslow
//	//���м�Ľڵ㼰���������нڵ��������
//	ListNode* rightHead = ReverseList(slow);
//
//	//������������еĽڵ��Ƿ���ͬ 
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
//	//��Ҫ������ԭ
//	prevSlow->next = ReverseList(rightHead);
//	return true;
//	}
//}

//�������������ҳ����ǵĵ�һ���������
//typedef struct ListNode ListNode
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//	//������������һ��Ϊ�գ��������ཻ
//	if (headB == NULL || headA == NULL)
//		return NULL;
//
//	 //����������Ϊ��
//	//1 ���������Ƿ��ཻ���ҵ����������е����һ���ڵ㣬���ýڵ�ĵ�ַ�Ƿ���ͬ
//	//�������������нڵ�ĸ���
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
//	//���ѭ�������һ��Ԫ�صĵ�ַ�Ƿ���ͬ����ͬ���뽻
//	if (curA != curB)
//		return NULL;
//
//	//�ཻ�󽻵� 
//	//�ó����������ʼλ����gap��
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
//		//��ʱgapΪ������ֻ��gap=0ʱ���������ѭ��
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

//����һ�������ж��������Ƿ��л���
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л�
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
//		//�ڻ�������
//		if (slow == fast)
//			return true;
//	}
//	return false;
//}

//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� NULL
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
//	//����ָ�벻���ʱ�򲻴���
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

//��������в�������
//���������㷨��
//1���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
//2ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
//3�ظ�ֱ�������������ݲ�����Ϊֹ
//typedef struct ListNode ListNode;
//struct ListNode* insertionSortList(struct ListNode* head) 
//{
//	//����Ϊ�ջ���������ֻ��һ���ڵ�
//	if (NULL == head || NULL == head->next)
//		return head;
//
//	//�����������������ڵ�
//	//��ԭ�����л�ȡһ���ڵ㽫����뵽��������
//	ListNode* newHead = NULL;
//	ListNode* cur = head;
//	while (cur)
//	{
//		//curָ����������뵽newHeadָ��������������µ�����
//		head = cur->next;
//
//			//���������нڵ㣬���²���ڵ��λ��
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
//				//cur�ڵ��е����ݱ�insertPos�ڵ��е�����С
//				cur->next = insertPos;
//				insertPosPrev->next = cur;
//			}
//		cur = head;
//	}
//	return newHead;
//}

