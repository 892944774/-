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
int GetNodeCount(BTNode* root); //�������ڵ�ĸ���
int GetLeafNodeCount(BTNode* root);//������Ҷ�ӽڵ�ĸ���
int GetKLevelNodeCount(BTNode* root,unsigned int k);//��������K��ڵ�ĸ���
BTNode* Find(BTNode* root, BTNDataType data);//����ֵΪdata�Ľڵ�
int GetHeight(BTNode* root);
int BinaryTreeComplete(BTNode* root);
void DestroyTree(BTNode** root);

void TestBinTree();