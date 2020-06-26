#define _CRT_SECURE_NO_WARNINGS 1
//1 单值二叉树
/*
_isUnivalTree(struct TreeNode*root, int value)
{
	if (root == NULL)
		return true;

	if (root->val != value)
		return false;

	return _isUnivalTree(root->left, value) && _isUnivalTree(root->right, value);
}

bool isUnivalTree(struct TreeNode* root) {
	if (root == NULL)
		return true;

	int value = root->val;
	return _isUnivalTree(root, value);
}
*/

//2 二叉树的最大深度
/*
int maxDepth(struct TreeNode* root) {
if (NULL == root)
return 0;

int leftHeight = maxDepth(root->left);
int rightHeight = maxDepth(root->right);
return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
*/

//3 反转二叉树
/*
struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root)
    {
        struct TreeNode* temp = NULL;
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        mirrorTree(root->left);
        mirrorTree(root->right);
    }
    return root;
*/

//4 判断两个数是否相同
/*
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)
    return true;

    if(p == NULL || q == NULL)
    return false;

    return p->val == q->val && 
           isSameTree(p->left, q->left)&&
           isSameTree(p->right, q->right);   
}
*/

//5 检测是否是镜像对称
/*
bool _isSymmetric(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL)
    return true;

    if(p == NULL || q == NULL)
    return false;

    return p->val == q->val &&
    _isSymmetric(p->left, q->right) &&
    _isSymmetric(p->right, q->left); 

}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL)
    return true;

    return _isSymmetric(root->left, root->right);
}
```
6 给定一个二叉树，返回它的前序遍历。

```c
 //需要给定数组的空间，取决于节点的个数，得先获取节点个数
 int GetSize(struct TreeNode* root)
 {
    if(root == NULL)
    return 0;

    return GetSize(root->left) + GetSize(root->right) + 1;     
 }

//进行遍历
void _preorderTraversal(struct TreeNode* root, int* array, int* index){
    if(root == NULL)
    return;

    //将节点中的值域保存在数组中
    array[(*index)++] = root->val;
    _preorderTraversal(root->left, array, index);
    _preorderTraversal(root->right, array, index);
}

//returnSize： 输出型参数--类似于另一种返回值的方式--即通过参数将返回值带回去
//返回值：返回空间的首地址
//空间中元素的个数：通过returnSize参数带出去
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = GetSize(root);
    int* ret = (int*)malloc((*returnSize) * sizeof(int));
    if(NULL == ret)
        return NULL;

    int index = 0;
    _preorderTraversal(root, ret, &index);
    return ret;
}
*/

//7 判断是否是平衡二叉树
/*
int Height(struct TreeNode* root)
{
    if(root == NULL)
    return 0;

    int LeftHeight = Height(root->left);
    int RightHeight = Height(root->right);

    return LeftHeight > RightHeight ? LeftHeight+1 : RightHeight+1;
}

bool isBalanced(struct TreeNode* root){
    if(NULL == root)
        return true;

    //递归检测根节点是否满足平衡性
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    if(abs(rightHeight - leftHeight)>1)
    return false;

    //递归检测根节点的左右子树是否满足平衡树的性质
    return isBalanced(root->left) && isBalanced(root->right);
}
*/

/*
二叉树的遍历
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char ch;
}TreeNode;

TreeNode* BuyTreeNode(char ch)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (newNode == NULL)
		return NULL;

	newNode->left = NULL;
	newNode->right = NULL;
	newNode->ch = ch;
	return newNode;
}

TreeNode* CreatBinTree(char szTree[], int size, int* index, char invalid)
{
	TreeNode* root = NULL;
	if (*index < size && szTree[*index] != invalid)
	{
		//创建新节点
		root = BuyTreeNode(szTree[*index]);

		//创建根节点的左子树
		++(*index);
		root->left = CreatBinTree(szTree, size, index, invalid);

		//创建根节点的右子树
		++(*index);
		root->right = CreatBinTree(szTree, size, index, invalid);
	}
	return root;
}
void InOrder(TreeNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%c ", root->ch);
		InOrder(root->right);
	}
}

int main()
{
	char szTree[100] = { 0 };
	int size = 0;
	int index = 0;
	scanf("%s", szTree);
	size = strlen(szTree);

	TreeNode* root = CreatBinTree(szTree, size, &index, '#');
	InOrder(root);
	printf("\n");
	return 0;
}
*/
