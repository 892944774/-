#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

BTNode* BuyBinTreeNode(BTNDataType data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//array�����У�������Ƕ����������нڵ��ֵ��
BTNode* CreateBinTree(int array[], int size, int* index, int invalid)
{
	BTNode* root = NULL;
	if (*index < size && array[*index] != invalid)
	{
		//�������ڵ�
		root = BuyBinTreeNode(array[*index]);
		//�������ڵ��������
		++(*index);
		root->left = CreateBinTree(array, size, index, invalid);
		//�������ڵ��������
		++(*index);
		root->right = CreateBinTree(array, size, index, invalid);
	}
	return root;
}

//��-��-��
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//��-��- ��
void InOrder(BTNode* root)
{
	if (root)
	{
		PreOrder(root->left);
		printf("%d ", root->data);
		PreOrder(root->right);
	}
}

//��-��-��
void PostOrder(BTNode* root)
{
	PreOrder(root->left);
	PreOrder(root->right);
	printf("%d ", root->data);
}

void DestroyTree(BTNode** root)
{
	assert(root);//root�еĵ�ַ��Ҳ�����ⲿʵ�εĵ�ַ,*root�����ⲿ��ʵ��

	if (*root)
	{
		DestroyTree(&(*root)->left);
		DestroyTree(&(*root)->right);
		free(*root);
 		*root = NULL;
	}
}

//�������ڵ�ĸ���
int GetNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;

	return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;
}

//������Ҷ�ӽڵ�ĸ���,Ҳ���Ƕ�Ϊ0�Ľڵ�
int GetLeafNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;

	//�������Һ��ӵĶ�Ϊ�գ���ΪҶ�ӽڵ�
	if (NULL == root->left && NULL == root->right )
		return 1;

	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}

//��������K��ڵ�ĸ���
int GetKLevelNodeCount(BTNode* root, unsigned int k)
{
	if (NULL == root || k == 0)
		return 0;

	//��һ��ֻ�и��ڵ�
	if (1 == k)
		return 1;

	//������תΪ����������k-1��ڵ�ĸ���
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}

//����ֵΪdata�Ľڵ�
BTNode* Find(BTNode* root, BTNDataType data)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;

	if (root->data = data)
		return root;

	//�����������ң��ҵ��˷��أ��Ҳ�����������������
	(ret = Find(root->left, data)) || (ret = Find(root->right, data));
	return ret;
}

int GetHeight(BTNode* root)
{
	int leftHeight = 0, rightHeight = 0;
	if (root == NULL)
		return 0;

	leftHeight = GetHeight(root->left);
	rightHeight = GetHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

/*int BinaryTreeComplete(BTNode* root)
{
	int flag = 0;
	int ret = 0;
	//����Ҳ����ȫ������ 
	if (NULL == root)
		return 1;

	//�ǿ�
	//1 ����������Ĺ����Ҳ����ͽڵ�
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (flag)
		{
			//����ڵ㲻���к���
			if (cur->left || cur->right)
				break;
		}
		else
		{
			//�ҵ�һ�������͵Ľڵ�
			if (cur->left && cur->right)
			{ 
				QueuePush(&q, cur->left);
				QueuePush(&q, cur->right);
			}
			else if (cur->left)
			{
				//ֻ������
				QueuePush(&q, cur->left);
				flag = 1;
			}
			else if (cur->right)
			{
				//ֻ���Һ���
				break;
			}
			else
			{
				//û�����Һ���
				flag = 1;
			}
		}
		QueuePop(&q);
	}

	if (QueueEmpty(&q))
		ret = 1;

	DestroyQueue(&q);
	return ret;
	return 1;
}*/

BTNode* CopyBinTree(BTNode* root)
{
	BTNode* newroot = NULL;
	if (root)
	{
		//�������ڵ�
		newroot = BuyBinTreeNode(root->data);

		//�������ڵ��������
		newroot->left = CopyBinTree(root->left);

		//�������ڵ��������
		newroot->right = CopyBinTree(root->right);
	}
	return newroot;
}

void TestBinTree()
{
	//����������Ԫ�ط���������
	int array[] = { 1,2,3,-1,-1,-1,4,5,-1,-1, 6 };
	int index = 0;
	BTNode* root = CreateBinTree(array, sizeof(array)/sizeof(array[0]), &index, -1);


	BTNode* newroot = NULL;

	printf("ǰ�����:");
	PreOrder(root);
	printf("\n");

	printf("�������:");
	InOrder(root);
	printf("\n");

	printf("�������:");  
	PostOrder(root);
	printf("\n");

	//printf("%d\n", GetNodeCount(root));
	//printf("%d\n", GetLeafNodeCount(root));
	//printf("%d\n", GetKLevelNodeCount(root, 2));
	//printf("%d\n", GetKLevelNodeCount(root, 3));

	//BTNode* cur = Find(root, 5);
	//if (cur)
	//	printf("5 �Ƕ�����\n");
	//else
	//	printf("5���Ƕ�����\n");

	newroot = CopyBinTree(root);
	printf("ǰ�����:");
	PreOrder(root);
	printf("\n");

	printf("�������:");
	InOrder(root);
	printf("\n");

	printf("�������:");
	PostOrder(root);
	printf("\n");

	printf("%d\n", GetHeight(root));
	DestroyTree(&newroot);
	DestroyTree(&root);
}

