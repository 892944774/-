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

void DestroyTree(BTNode** root)
{
	assert(root);//root中的地址，也就是外部实参的地址,*root才是外部的实参

	if (*root)
	{
		DestroyTree(&(*root)->left);
		DestroyTree(&(*root)->right);
		free(*root);
 		*root = NULL;
	}
}

//二叉树节点的个数
int GetNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;

	return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;
}

//二叉树叶子节点的个数,也就是度为0的节点
int GetLeafNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;

	//遇到左右孩子的都为空，即为叶子节点
	if (NULL == root->left && NULL == root->right )
		return 1;

	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}

//二叉树第K层节点的个数
int GetKLevelNodeCount(BTNode* root, unsigned int k)
{
	if (NULL == root || k == 0)
		return 0;

	//第一层只有根节点
	if (1 == k)
		return 1;

	//将问题转为到子树中求k-1层节点的个数
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}

//查找值为data的节点
BTNode* Find(BTNode* root, BTNDataType data)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;

	if (root->data = data)
		return root;

	//先在左子树找，找到了返回，找不到继续在右子树找
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

int BinaryTreeComplete(BTNode* root)
{
	int flag = 0;
	int ret = 0;
	//空树也是完全二叉树 
	if (NULL == root)
		return 1;

	//非空
	//1 按层序遍历的规则找不饱和节点
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (flag)
		{
			//后序节点不能有孩子
			if (cur->left || cur->right)
				break;
		}
		else
		{
			//找第一个不饱和的节点
			if (cur->left && cur->right)
			{ 
				QueuePush(&q, cur->left);
				QueuePush(&q, cur->right);
			}
			else if (cur->left)
			{
				//只有左孩子
				QueuePush(&q, cur->left);
				flag = 1;
			}
			else if (cur->right)
			{
				//只有右孩子
				break;
			}
			else
			{
				//没有左右孩子
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

	printf("%d\n", GetNodeCount(root));
	printf("%d\n", GetLeafNodeCount(root));
	printf("%d\n", GetKLevelNodeCount(root, 2));
	printf("%d\n", GetKLevelNodeCount(root, 3));

	BTNode* cur = Find(root, 5);
	if (cur)
		printf("5 是二叉树\n");
	else
		printf("5不是二叉树\n");

	printf("%d\n", GetHeight(root));
	DestroyTree(&root);
}

