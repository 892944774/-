#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

typedef int SData;

/*
静态栈
#define MAXSIZE 100
typedef srtuct Stack
{
	SDataType array[MAXSIZE];
	int top;   //标记栈顶
}Stack; 
如果在笔试时需要用到栈，可以自定义快速创建一个静态栈，不用考虑扩容
*/

//栈中没有任意位置的插入和删除，若要使用，使用顺序表，栈不需要遍历
//动态栈 
typedef struct Stack
{ 
	SData* array;
	int capacity;
	int size;    //栈中元素的个数  栈顶
}Stack;

void StackInit(Stack* ps);

//入栈: 尾插
void StackPush(Stack* ps, int data);

//出栈; 尾插
void StackPop(Stack* ps);

//获取栈顶元素
SData StackTop(Stack* ps);

//获取栈中有效元素的个数
int StackSize(Stack* ps);

//检测栈是否为空
int StackEmpty(Stack* ps);

//销毁栈
void StackDestory(Stack* ps);

void TestStack();