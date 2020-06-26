#define _CRT_SECURE_NO_WARNINGS 1
//1 ��ֵ������
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

//2 ��������������
/*
int maxDepth(struct TreeNode* root) {
if (NULL == root)
return 0;

int leftHeight = maxDepth(root->left);
int rightHeight = maxDepth(root->right);
return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
*/

//3 ��ת������
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

//4 �ж��������Ƿ���ͬ
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

//5 ����Ƿ��Ǿ���Գ�
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
6 ����һ������������������ǰ�������

```c
 //��Ҫ��������Ŀռ䣬ȡ���ڽڵ�ĸ��������Ȼ�ȡ�ڵ����
 int GetSize(struct TreeNode* root)
 {
    if(root == NULL)
    return 0;

    return GetSize(root->left) + GetSize(root->right) + 1;     
 }

//���б���
void _preorderTraversal(struct TreeNode* root, int* array, int* index){
    if(root == NULL)
    return;

    //���ڵ��е�ֵ�򱣴���������
    array[(*index)++] = root->val;
    _preorderTraversal(root->left, array, index);
    _preorderTraversal(root->right, array, index);
}

//returnSize�� ����Ͳ���--��������һ�ַ���ֵ�ķ�ʽ--��ͨ������������ֵ����ȥ
//����ֵ�����ؿռ���׵�ַ
//�ռ���Ԫ�صĸ�����ͨ��returnSize��������ȥ
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

//7 �ж��Ƿ���ƽ�������
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

    //�ݹ�����ڵ��Ƿ�����ƽ����
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    if(abs(rightHeight - leftHeight)>1)
    return false;

    //�ݹ�����ڵ�����������Ƿ�����ƽ����������
    return isBalanced(root->left) && isBalanced(root->right);
}
*/

/*
�������ı���
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
		//�����½ڵ�
		root = BuyTreeNode(szTree[*index]);

		//�������ڵ��������
		++(*index);
		root->left = CreatBinTree(szTree, size, index, invalid);

		//�������ڵ��������
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
