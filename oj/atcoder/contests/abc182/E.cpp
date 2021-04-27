#include<stdio.h> 
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct TreeNode*root;
int CreateTree(struct TreeNode** root)
{
	int val;
	scanf("%d",&val);
	if(val<=0)
	{
		*root=NULL;
		return 0;
	}
	*root=(struct TreeNode*)malloc(sizeof(TreeNode));
	if(!root)
    {
        printf("创建失败\n");
    }
    if(val>0)
    {
        (*root)->val=val;
        CreateTree(&((*root)->left));
        CreateTree(&((*root)->right));
    }
    return 0;
}
void PreOrderTree(struct TreeNode*root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d",root->val);
	PreOrderTree(root->left);
	PreOrderTree(root->right);
}
 
int main()
{
TreeNode *root=(struct TreeNode*)malloc(sizeof(TreeNode));
CreateTree(&(root));
printf("先序排列为：");
PreOrderTree(root);
	return 0;
}