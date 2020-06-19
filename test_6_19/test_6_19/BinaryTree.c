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

BTNode* CreateBinTree()
{
	BTNode* root = NULL;
	BTNode* n1 = BuyBinTreeNode(1);
	BTNode* n2 = BuyBinTreeNode(2);
	BTNode* n3 = BuyBinTreeNode(3);
	BTNode* n4 = BuyBinTreeNode(4);
	BTNode* n5 = BuyBinTreeNode(5);
	BTNode* n6 = BuyBinTreeNode(6);

	root = n1;
	root->left = n2;
	n2->left = n3;

	root->right = n4;
	n4->left = n5;
	n4->right = n6;
	return root;
}

//根-左-右
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//左-根- 右
void InOrder(BTNode* root)
{
	if (root)
	{
		PreOrder(root->left);
		printf("%d ", root->data);
		PreOrder(root->right);
	}
}

//左-右-根
void PostOrder(BTNode* root)
{
	PreOrder(root->left);
	PreOrder(root->right);
	printf("%d ", root->data);
}

void TestBinTree()
{
	BTNode* root = CreateBinTree();
	printf("前序遍历:");
	PreOrder(root);
	printf("\n");

	printf("中序遍历:");
	InOrder(root);
	printf("\n");

	printf("后序遍历:");  
	PostOrder(root);
	printf("\n");
}