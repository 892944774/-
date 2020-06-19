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
void TestBinTree();