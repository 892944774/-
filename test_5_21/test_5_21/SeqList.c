#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//初始化——结构体内的数组申请空间
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	initCapacity = initCapacity <= 10 ? 10 : initCapacity;

	s->array = (SDataType*)malloc(sizeof(SDataType) * initCapacity);
	if (s->array == NULL)
		return;

	//申请成功 初始化容量 初始化有效值0
	s->capacity = initCapacity;
	s->size = 0;
}

//1 开辟新空间
//2 拷贝元素
//3 释放新空间
//4 使用新空间
int CheckCapacity(SeqList* s)
{
	assert(s);
	if (s->size == s->capacity)
	{
		int newCapacity = s->capacity * 2;
		s->array = (SDataType*)realloc(s->array ,newCapacity*sizeof(SDataType));
		if (s->array == NULL)
			return;
		//扩容成功后使用新容量
		s->capacity = newCapacity;

		//按两倍的方式进行扩容
		/*
		int newCapacity = s->capacity * 2;

		//申请新空间
		SDataType* temp = (SDataType*)malloc(newCapacity*sizeof(SDataType));
		if (temp = NULL)
			return;

		//拷贝元素
		memcpy(temp, s->array, s->capacity*sizeof(SDataType));

		//释放旧空间
		free(s->array);

		//使用新空间
		s->array = temp;
		s->capacity = newCapacity;
		*/
	}

	return 1;
}

//尾插
//1.不需要扩容,直接将元素插入在size的位置-->O(1)
//2.需要扩容
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//插入之前要判断空间是否足够，不够再进行扩容

	if (!CheckCapacity)
		return;//扩容的话失败

	s->array[s->size++] = data;
	//s->size++
}

//尾删 O(1)
void SeqListPopBack(SeqList* s)
{
	if (SeqListEmpty(s))
		return;

	s->size--;
}

//头插
//1 先检查是否需要扩容-如果需要则扩容
//2 讲顺序表中的所有元素往后搬移一个位置
//3 将data插入到顺序表的起始位置
//将所有元素搬移 O(N)
void  SeqListFushFront(SeqList* s, SDataType data)
{
	//将顺序表中的所有元素向后搬移一个位置
	assert(s);
	if (CheckCapacity == 0)
		return;//扩容的话失败

	for (int i = s->size - 1; i >= 0; i--)
	{
		s->array[i + 1] = s->array[i];
	}

	//在0号位置插入data
	s->array[0] = data;
	s->size++;
}

//头删-除第一个元素外，剩余所有的元素往前搬移——O(N)
void SeqListPopFront(SeqList* s)
{
	assert(s);
	if (SeqListEmpty(s))
		return;

	for (int i = 0; i < s->size; i++)
	{
		s->array[i] = s->array[i + 1];
	}

	s->size--;
}

//任意位置插入
//1 必须保证pos在[0.size]
//2 检测是否需要扩容
//3 将[pos, size)位置的元素整体往后搬移一个位置
//4 在pos的位置插入新元素
void SeqListInsert(SeqList* s, SDataType pos, SDataType data)
{
	assert(s);
	if (pos<0 || pos > s->size)
		return;

	//需要检测扩容
	if (!CheckCapacity)
		return;//扩容的话失败

	//将[pos, size)区间的元素整体向后搬移一个位置
	//i 表示需要搬移下标的元素
	for (int i = s->size; i >= pos; i--)
	{
		s->array[i + 1] = s->array[i];
	}

	s->array[pos] = data;
	s->size++;
}

//任意位置删除
//pos必须在[0,size)
//将pos之后的所有元素向前搬移一个位置
void SeqListErase(SeqList* s, int pos)
{
	assert(s);
	if (pos < 0 || pos >= s->size)
		return;

	for (int i = pos + 1; i < s->size; i++)
	{
		s->array[i-1] = s->array[i];
	}

	s->size--;
}

//获取顺序表中有效元素的个数
int SeqListSize(SeqList* s)
{
	assert(s);
	return s->size;
}

//获取顺序表中的容量
int SeqListCapacity(SeqList* s)
{
	assert(s);
	return s->capacity;
}

//判断是否为空
int SeqListEmpty(SeqList* s)
{
	assert(s);
	return 0 == s->size;
}

//查找值为data的元素是否在顺序表中，在返回所在元素的下标，否则返回-1
int SeqListFind(SeqList* s, SDataType data)
{
	assert(s);
	for (int i = 0; i < s->size; i++)
	{
		if (s->array[i] = data)
			return i;
	}
	return -1;
}

//清空
void SeqListClear(SeqList* s)
{
	assert(s);
	s->size = 0;
}

//销毁  -- 动态开辟必须销毁空间 - 把结构体管理的堆空间释放掉，否则内存泄漏
void SeqListDestory(SeqList* s)
{
	assert(s);
	if (s->array)
	{
		free(s->array);
		s->array = NULL;
		s->capacity = 0;
		s->size = 0;
	}
}

//打印函数
void SeqListPrint(SeqList* s)
{
	assert(s);

	for (int i = 0; i < s->size; i++)
	{
		printf("%d ", s->array[i]);
	}
}

void Test2()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPrint(&s);

	//任意位置的插入 在3号位置插入0
	SeqListInsert(&s, 3, 0);
	SeqListPrint(&s);

	//删除第一个值为4的元素
	SeqListErase(&s, SeqListFind(&s, 4));
	SeqListPrint(&s);
}