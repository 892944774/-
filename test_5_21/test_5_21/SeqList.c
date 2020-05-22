#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//��ʼ�������ṹ���ڵ���������ռ�
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	initCapacity = initCapacity <= 10 ? 10 : initCapacity;

	s->array = (SDataType*)malloc(sizeof(SDataType) * initCapacity);
	if (s->array == NULL)
		return;

	//����ɹ� ��ʼ������ ��ʼ����Чֵ0
	s->capacity = initCapacity;
	s->size = 0;
}

//1 �����¿ռ�
//2 ����Ԫ��
//3 �ͷ��¿ռ�
//4 ʹ���¿ռ�
int CheckCapacity(SeqList* s)
{
	assert(s);
	if (s->size == s->capacity)
	{
		int newCapacity = s->capacity * 2;
		s->array = (SDataType*)realloc(s->array ,newCapacity*sizeof(SDataType));
		if (s->array == NULL)
			return;
		//���ݳɹ���ʹ��������
		s->capacity = newCapacity;

		//�������ķ�ʽ��������
		/*
		int newCapacity = s->capacity * 2;

		//�����¿ռ�
		SDataType* temp = (SDataType*)malloc(newCapacity*sizeof(SDataType));
		if (temp = NULL)
			return;

		//����Ԫ��
		memcpy(temp, s->array, s->capacity*sizeof(SDataType));

		//�ͷžɿռ�
		free(s->array);

		//ʹ���¿ռ�
		s->array = temp;
		s->capacity = newCapacity;
		*/
	}

	return 1;
}

//β��
//1.����Ҫ����,ֱ�ӽ�Ԫ�ز�����size��λ��-->O(1)
//2.��Ҫ����
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//����֮ǰҪ�жϿռ��Ƿ��㹻�������ٽ�������

	if (!CheckCapacity)
		return;//���ݵĻ�ʧ��

	s->array[s->size++] = data;
	//s->size++
}

//βɾ O(1)
void SeqListPopBack(SeqList* s)
{
	if (SeqListEmpty(s))
		return;

	s->size--;
}

//ͷ��
//1 �ȼ���Ƿ���Ҫ����-�����Ҫ������
//2 ��˳����е�����Ԫ���������һ��λ��
//3 ��data���뵽˳������ʼλ��
//������Ԫ�ذ��� O(N)
void  SeqListFushFront(SeqList* s, SDataType data)
{
	//��˳����е�����Ԫ��������һ��λ��
	assert(s);
	if (CheckCapacity == 0)
		return;//���ݵĻ�ʧ��

	for (int i = s->size - 1; i >= 0; i--)
	{
		s->array[i + 1] = s->array[i];
	}

	//��0��λ�ò���data
	s->array[0] = data;
	s->size++;
}

//ͷɾ-����һ��Ԫ���⣬ʣ�����е�Ԫ����ǰ���ơ���O(N)
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

//����λ�ò���
//1 ���뱣֤pos��[0.size]
//2 ����Ƿ���Ҫ����
//3 ��[pos, size)λ�õ�Ԫ�������������һ��λ��
//4 ��pos��λ�ò�����Ԫ��
void SeqListInsert(SeqList* s, SDataType pos, SDataType data)
{
	assert(s);
	if (pos<0 || pos > s->size)
		return;

	//��Ҫ�������
	if (!CheckCapacity)
		return;//���ݵĻ�ʧ��

	//��[pos, size)�����Ԫ������������һ��λ��
	//i ��ʾ��Ҫ�����±��Ԫ��
	for (int i = s->size; i >= pos; i--)
	{
		s->array[i + 1] = s->array[i];
	}

	s->array[pos] = data;
	s->size++;
}

//����λ��ɾ��
//pos������[0,size)
//��pos֮�������Ԫ����ǰ����һ��λ��
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

//��ȡ˳�������ЧԪ�صĸ���
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

//�ж��Ƿ�Ϊ��
int SeqListEmpty(SeqList* s)
{
	assert(s);
	return 0 == s->size;
}

//����ֵΪdata��Ԫ���Ƿ���˳����У��ڷ�������Ԫ�ص��±꣬���򷵻�-1
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

//���
void SeqListClear(SeqList* s)
{
	assert(s);
	s->size = 0;
}

//����  -- ��̬���ٱ������ٿռ� - �ѽṹ�����Ķѿռ��ͷŵ��������ڴ�й©
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

//��ӡ����
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

	//����λ�õĲ��� ��3��λ�ò���0
	SeqListInsert(&s, 3, 0);
	SeqListPrint(&s);

	//ɾ����һ��ֵΪ4��Ԫ��
	SeqListErase(&s, SeqListFind(&s, 4));
	SeqListPrint(&s);
}