#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

int main()
{
	Cmp = Less;
	Cmp(10, 20);

	Cmp = Greater;
	Cmp(10, 20);

	TestHeap();
	return 0;
}