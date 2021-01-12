#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
	char data;
	node* lchild;
	node* rchild;
}node;

/************************************************************************/
/* 根据先续及中序遍历创建树                                                                     */
/************************************************************************/

int find(char* order,int start,int end,char x){
	int i;
	for (i=start;i<end;i++)
	{
		if (order[i]==x)
		{
			return i;
		}
	}
	return -1;
}

void create_tree(node** root,char* preorder,char* inorder,int pre_s,int pre_e,int in_s,int in_e){
	if (pre_s==pre_e)
	{
		(*root)=(node*)malloc(sizeof(node));
		(*root)->data=preorder[pre_s];
		(*root)->lchild=NULL;
		(*root)->rchild=NULL;
	}
	else{
		(*root)=(node*)malloc(sizeof(node));
		(*root)->data=preorder[pre_s];
		int k=find(inorder,in_s,in_e,preorder[pre_s]);
		create_tree(&((*root)->lchild),preorder,inorder,pre_s+1,pre_s+k-in_s,in_s,k-1);
		create_tree(&((*root)->rchild),preorder,inorder,pre_s+k-in_s+1,pre_e,k+1,in_e);
	}
}

void pre_print(node* root){
	printf("%c ",root->data);
	if(NULL!=root->lchild){
		pre_print(root->lchild);
	}
	if(NULL!=root->rchild){
		pre_print(root->rchild);
	}
	
}

int main(){
	char preorder[20];
	char inorder[20];
	printf("请输入先序遍历\n");
	gets(preorder);
	printf("请输入中序遍历\n");
	gets(inorder);
	int length=strlen(preorder-1);
	node* root;
	create_tree(&root,preorder,inorder,0,length,0,length);
	pre_print(root);
    return 0;
}