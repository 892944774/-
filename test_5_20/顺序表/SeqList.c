#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//��ʼ��
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	initCapacity = initCapacity <= 10 ? 10 : initCapacity;

	//10��SDataType ���ֽ�����sizeof(SDataType)*10
	s->array = (SDataType*)malloc(sizeof(SDataType) * initCapacity);
	if (s->array == NULL) 
		return;

	//����ɹ� ������ʼ�� ��ЧֵΪ0
	s->capacity = initCapacity;
	s->size = 0; 
}

//β��
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//����֮ǰҪ�жϿռ��Ƿ��㹻������������

	s->array[s->size++] = data;
	//s->size++;
}

//βɾ
void SeqListPopBack(SeqList* s)
{
	if (SeqListEmpty(s))
		return;
	s->size--;
}

//ͷ��
void SeqListPushFront(SeqList* s, SDataType data)
{
	//��˳����е�����Ԫ��������һ��λ��
	assert(s);
	for (int i = s->size - 1; i >= 0; i--)
	{
		s->array[i + 1] = s->array[i];
	}

	//��0��λ�ò���data
	s->array[0] = data;
	s->size++;
}

//ͷɾ  --  ɾ��֮ǰ��Ӧ���жϽṹ���Ƿ�Ϊ��
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

//����λ�ò���
void SeqListInsert(SeqList* s, int pos, SDataType data);

//����λ�õ�ɾ��
void SeqListErase(SeqList* s, int pos);

//��ȡ˳�������ЧԪ�ظ���
int SeqListSize(SeqList* s)
{
	assert(s);
	return s->size;
}

//��ȡ˳����е�����
int SeqListCapacity(SeqList* s)
{
	assert(s);
	return s->capacity;
}

//�ж�˳����Ƿ�Ϊ��
int SeqListEmpty(SeqList* s)
{
	assert(s);
	return 0 == s->size;
}

//����ֵΪdata��Ԫ���Ƿ���˳����У�����ڷ����±꣬���򷵻�-1
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

//���
void SeqListClear(SeqList* s)
{
	assert(s);
	s->size = 0;
}

//���� -- ��̬���ٱ������ٿռ� - �ѽṹ�����Ķѿռ��ͷŵ��������ڴ�й©
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
//���Է���
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