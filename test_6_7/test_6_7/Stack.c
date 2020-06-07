#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (SData*)malloc(sizeof(SData) * 10);
	if (ps->array == NULL)
	{
		assert(0);  
		return;
	}
	 
	ps->capacity = 10;
	ps->size = 0;
}

void CheakCapacity(Stack* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		//1 开辟新空间
		SData* temp = (SData*)malloc(sizeof(SData) * ps->size * 2);
		if (temp == NULL)
		{
			assert(0);
			return;
		}
		//2 拷贝元素
		memcpy(temp, ps->array, sizeof(SData) * ps->size * 2);
		//3 释放旧空间
		free(ps->array);
		//4 使用新空间
		ps->array = temp;
		ps->capacity *= 2;
	}
}

//入栈: 尾插
void StackPush(Stack* ps, SData data)
{
	//assert(ps);
	CheakCapacity(ps);//插入之前一定要检测是否扩容
	ps->array[ps->size++] = data;
}

//出栈; 尾插
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;

	ps->size--;
}

//获取栈顶元素
SData StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));//不为空才能获取栈顶元素
	return ps->array[ps->size - 1];
}

//获取栈中有效元素的个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

//检测栈是否为空
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

//销毁栈
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void TestStack()
{
	Stack(s);
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));

	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));

	StackDestory(&s);
}