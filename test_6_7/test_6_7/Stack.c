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
		//1 �����¿ռ�
		SData* temp = (SData*)malloc(sizeof(SData) * ps->size * 2);
		if (temp == NULL)
		{
			assert(0);
			return;
		}
		//2 ����Ԫ��
		memcpy(temp, ps->array, sizeof(SData) * ps->size * 2);
		//3 �ͷžɿռ�
		free(ps->array);
		//4 ʹ���¿ռ�
		ps->array = temp;
		ps->capacity *= 2;
	}
}

//��ջ: β��
void StackPush(Stack* ps, SData data)
{
	//assert(ps);
	CheakCapacity(ps);//����֮ǰһ��Ҫ����Ƿ�����
	ps->array[ps->size++] = data;
}

//��ջ; β��
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;

	ps->size--;
}

//��ȡջ��Ԫ��
SData StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));//��Ϊ�ղ��ܻ�ȡջ��Ԫ��
	return ps->array[ps->size - 1];
}

//��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

//����ջ
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