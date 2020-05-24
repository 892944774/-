#define _CRT_SECURE_NO_WARNINGS 1

//1.原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)
//给定 nums = [3, 2, 2, 3], val = 3,
//函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
//你不需要考虑数组中超出新长度后面的元素。

//int removeElement(vector<int>& nums, int val)
//{
//		int count = 0;
//
//		for (int i = 0; i<size; i++)
//		{
//			if (nums[i] == val)
//				count++;
//			else
//			nums[i - count] = nums[i];	
//		}
//      return size - count;
//}

//2. 删除排序数组中的重复项
//给定 nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
//你不需要考虑数组中超出新长度后面的元素

//int removeDuplicates(int* nums, int numsSize)
//{
//	int count = 0;
//	//这种情况只有一个元素，不需要搬移，直接返回元素个数
//	if (numsSize < 2)
//		return numsSize;
//
//	for (int i = 0; i < numsSize; ++i)
//	{
//		//判断两个数是否不相等，不相等则给count加一后进行替换
//		if (nums[count] != nums[i])
//			/*nums[count+1] = nums[i];
//			count++;*/
//			nums[++count] = nums[i];
//	}
//	return ++count;//count指向是最后一个有效元素，但返回去的数组应该包括'\0'，所以++count
//}

//3.合并两个有序数组
//说明:
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//输入:
//nums1 = [1, 2, 3, 0, 0, 0], m = 3
//nums2 = [2, 5, 6], n = 3
//
//输出 : [1, 2, 2, 3, 5, 6]

//法1:采用辅助空间
//1 申请辅助空间：M+N
//2 将nums1和nums2中的元素向新空间中搬移：每次搬移一个，并且搬移两个数组中较小的元素
//3 将新空间归并好并拷贝到nums1中
//4 释放新空间
//5 返回         时间复杂度O(M+N)  空间复杂度O(M+N)

//法2:不适用辅助空间
//将nums2中的元素逐个插入到nums1中合适的位置
//insert(pos, data)-->O(M)
//该种方式需要将nums2中的N个元素插入到nums1中
//时间复杂度：O(MN)    空间复杂度：O(1)

//法3:两个指针指向最后一个元素，从后向前搬移
//时间复杂度：O(M+N)  空间复杂度：O(1)

//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int index = n+m - 1;//最大元素在nums1中的存储位置
//
//	//n > 0; 表示nums2中还有元素未搬移到nums1中
//	while (n > 0)
//	{
//		if (m > 0 && nums1[m - 1] > nums2[m - 1])//先保证nums1中有值m > 0
//		{
//			nums1[index--] = nums1[m - 1];
//			m--;
//		}
//		else
//		{ 
//			nums2[index--] = nums2[n - 1];
//			n--;
//		}
//	}
//}

//循环逆置1，2，3，4，5，6，7     向右移位 k=3
//[1,2,3,4][5,6,7]
//[4,3,2,1][7,6,5]
//[5,6,7,1,2,3,4]
//k = 10的时候   k %= 数组长度

//5.数组形式的整数加法
//示例 4：
//输入：A = [9, 9, 9, 9, 9, 9, 9, 9, 9, 9], K = 1
//输出：[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
//解释：9999999999 + 1 = 10000000000

//A:[2 3]  k:10000 ->5位
//A[2 3]   k:9999 ->5位
//A:[9999999] k:10 -> 8位
//A:[2 3]   k:999 -> 4位
//保存结果的空间大小：应该比教长数据位数多1，因为可能还有进位

int* addToArrayForm(int* A, int ASize, int k, int* returnSize)
{
	int size = ASize > 5 ? ASize + 1 : 5 + 1;
	int* ret = calloc(size, sizeof(int));

	//表示加完后数据总的位数
	int total = 0;

	//用数组中的每一位加K
	int retIdx = size - 1;//新空间的末位
	while (ASize > 0)
	{
		k += A[ASize-1];
		ret[retIdx--] = k % 10;
		k /= 10;
		total++;
		ASize--; 
	}

	//如果k比A数组中数据长
	while (k>0)
	{
		ret[retIdx--] = k % 10;
		k /= 10;
		total++;
	}
	 
	//加完后元素数据长度小于size长度，向前进行搬移
	if (total < size)
	{
		memmove(ret, ret+(size - total), total*(sizeof(int)));
	}

	*returnSize = total;
	return ret;
}



