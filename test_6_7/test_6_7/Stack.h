#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

typedef int SData;

/*
��̬ջ
#define MAXSIZE 100
typedef srtuct Stack
{
	SDataType array[MAXSIZE];
	int top;   //���ջ��
}Stack; 
����ڱ���ʱ��Ҫ�õ�ջ�������Զ�����ٴ���һ����̬ջ�����ÿ�������
*/

//ջ��û������λ�õĲ����ɾ������Ҫʹ�ã�ʹ��˳���ջ����Ҫ����
//��̬ջ 
typedef struct Stack
{ 
	SData* array;
	int capacity;
	int size;    //ջ��Ԫ�صĸ���  ջ��
}Stack;

void StackInit(Stack* ps);

//��ջ: β��
void StackPush(Stack* ps, int data);

//��ջ; β��
void StackPop(Stack* ps);

//��ȡջ��Ԫ��
SData StackTop(Stack* ps);

//��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps);

//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);

//����ջ
void StackDestory(Stack* ps);

void TestStack();