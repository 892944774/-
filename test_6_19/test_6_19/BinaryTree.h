#pragma once
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

typedef int BTNDataType;

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTNDataType data;
}BTNode;

BTNode* CreateBinTree();
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
int GetNodeCount(BTNode* root); //二叉树节点的个数
int GetLeafNodeCount(BTNode* root);//二叉树叶子节点的个数
int GetKLevelNodeCount(BTNode* root,unsigned int k);//二叉树第K层节点的个数
BTNode* Find(BTNode* root, BTNDataType data);//查找值为data的节点
int GetHeight(BTNode* root);
int BinaryTreeComplete(BTNode* root);
void DestroyTree(BTNode** root);

void TestBinTree();