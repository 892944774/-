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

