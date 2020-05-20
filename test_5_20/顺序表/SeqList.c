#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//初始化
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	initCapacity = initCapacity <= 10 ? 10 : initCapacity;

	//10个SDataType 总字节数：sizeof(SDataType)*10
	s->array = (SDataType*)malloc(sizeof(SDataType) * initCapacity);
	if (s->array == NULL) 
		return;

	//申请成功 容量初始化 有效值为0
	s->capacity = initCapacity;
	s->size = 0; 
}

//尾插
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//插入之前要判断空间是否足够，不够再扩容

	s->array[s->size++] = data;
	//s->size++;
}

//尾删
void SeqListPopBack(SeqList* s)
{
	if (SeqListEmpty(s))
		return;
	s->size--;
}

//头插
void SeqListPushFront(SeqList* s, SDataType data)
{
	//将顺序表中的所有元素向后搬移一个位置
	assert(s);
	for (int i = s->size - 1; i >= 0; i--)
	{
		s->array[i + 1] = s->array[i];
	}

	//在0号位置插入data
	s->array[0] = data;
	s->size++;
}

//头删  --  删除之前都应该判断结构体是否为空
void SeqListPopFront(SeqList* s)
{
	if (SeqListEmpty(s))
		return;
	for(int i=0;i< s->size;i++)
	{
		s->array[i] = s->array[i+1];
	}

	s->size--;
}

//任意位置插入
void SeqListInsert(SeqList* s, int pos, SDataType data);

//任意位置的删除
void SeqListErase(SeqList* s, int pos);

//获取顺序表中有效元素个数
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

//判断顺序表是否为空
int SeqListEmpty(SeqList* s)
{
	assert(s);
	return 0 == s->size;
}

//查找值为data的元素是否在顺序表中，如果在返回下标，否则返回-1
int SeqListFind(SeqList* s, SDataType data)
{
	assert(s);
	for (int i = 0; i < s->size; i++)
	{
		if (s->array[i] == data)
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

//销毁 -- 动态开辟必须销毁空间 - 把结构体管理的堆空间释放掉，否则内存泄漏
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


///////////////////////////////////////////////////////
//测试方法
void SeqListPrint(SeqList* s)
{
	assert(s);
	for (int i = 0; i < s->size; i++)
	{
		printf("%d ", s->array[i]);
	}
	printf("\n");
}

void TestSeqList()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);

	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s); 

	SeqListPopBack(&s);
	SeqListPopBack(&s);

	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);
	 
	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListDestory(&s);
} 