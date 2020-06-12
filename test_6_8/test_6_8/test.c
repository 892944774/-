#define _CRT_SECURE_NO_WARNINGS 1
//1 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

//typedef char SData;
////栈中没有任意位置的插入和删除，若要使用，使用顺序表 栈不需要遍历
////动态栈 
//typedef struct Stack
//{
//	SData* array;
//	int capacity;
//	int size;    //栈中元素的个数  栈顶
//}Stack;
//
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->array = (SData*)malloc(sizeof(SData) * 10);
//	if (ps->array == NULL)
//	{
//		assert(0);
//		return;
//	}
//	ps->capacity = 10;
//	ps->size = 0;
//}
//
//void CheakCapacity(Stack* ps)
//{
//	assert(ps);
//	if (ps->capacity == ps->size)
//	{
//		//1 开辟新空间
//		SData* temp = (SData*)malloc(sizeof(SData) * ps->size * 2);
//		if (temp == NULL)
//		{
//			assert(0);
//			return;
//		}
//		//2 拷贝元素
//		memcpy(temp, ps->array, sizeof(SData) * ps->size * 2);
//		//3 释放旧空间
//		free(ps->array);
//		//4 使用新空间
//		ps->array = temp;
//		ps->capacity *= 2;
//	}
//}
//
////入栈: 尾插
//void StackPush(Stack* ps, SData data)
//{
//	//assert(ps);
//	CheakCapacity(ps);//插入之前一定要检测是否扩容
//	ps->array[ps->size++] = data;
//}
//
////出栈; 尾插
//void StackPop(Stack* ps)
//{
//	if (StackEmpty(ps))
//		return;
//	ps->size--;
//}
//
////获取栈顶元素
//SData StackTop(Stack* ps)
//{
//	assert(!StackEmpty(ps));//不为空才能获取栈顶元素
//	return ps->array[ps->size - 1];
//}
//
////获取栈中有效元素的个数
//int StackSize(Stack* ps)
//{
//	assert(ps);
//	return ps->size;
//}
//
////检测栈是否为空
//int StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return ps->size == 0;
//}
//
////销毁栈
//void StackDestory(Stack* ps)
//{
//	assert(ps);
//	free(ps->array);
//	ps->array = NULL;
//	ps->capacity = 0;
//	ps->size = 0;
//}
//
//bool isValid(char * s)
//{
//	Stack st;
//	StackInit(&st);
//	int len = strlen(s);
//	bool ret = true;
//
//	for (int i = 0; i < len; i++)
//	{
//		//左括号入栈
//		if ('(' == s[i] || '[' == s[i] || '{' == s[i])
//			StackPush(&st, s[i]);
//		else
//		{
//			//当前为右括号，且栈为空，没有与之对应的左括号
//			if (StackEmpty(&s))
//			{
//				ret = false;
//				break;
//			}
//
//			//当前括号是右括号
//			char ch = StackTop(&st);
//
//			//用当前右括号检测是否与栈顶的左括号匹配
//			if ((ch == '(' && s[i] == ')') || ch = '[' && s[i] == ']' || ch = '{' && s[i] == '}')
//			{
//				StackPop(&st);
//				continue;
//			}
//			else
//			{
//				ret false;
//			}
//		}
//	}
//
//	//左括号比右括号多
//	if (StackEmpty(&st))
//		ret = false;
//
//	StackDestory(&st);
//	return ret;
//}

