#include<stdio.h>
#include<stdlib.h>
#include <math.h>

typedef struct node{
	int data;
	node* lchild;
	node* rchild;
	int count;
}node;

/************************************************************************/
/* 非递归算法                                                                     */
/************************************************************************/

int search_x(node* root,int x,node** p){
	if (!root)
	{
		printf("ERROR");
		exit(1);
	}
	node* q=root;
	while (1)
	{
		if (q->data==x)
		{
			*p=q;
			return 0;
		}else if (q->data<x)
		{
			if (q->rchild)
			{
				q=q->rchild;
			}
			else{
				*p=q;
				return -1;
			}
		}else{
			if (q->lchild)
			{
				q=q->lchild;
			}
			else{
				*p=q;
				return 1;
			}
		}
	}
	
}
int search_x_zj(node* root,int x,node** res){
	if (root==NULL)
	{
		exit(1);
	}

	node* p=root;
	while (1)
	{
		if (p->data==x)
		{
			*res=p;
			return 0;
		}
		else if(p->data>x){
			if (p->lchild)
			{
				p=p->lchild;
			}else{
				*res=p;
				return 1;
			}
			
		}else{
			if (p->rchild)
			{
				p=p->rchild;
			}else{
				*res=p;
				return -1;
			}
		}
	}

	



}




void create_bst_fdg(node* root,int x){
	node* pre=root;
	node* p;
	int res=search_x(root,x,&pre);
	if (res!=0)
	{
		p=(node*)malloc(sizeof(node));
		p->data=x;
		p->lchild=NULL;
		p->rchild=NULL;
		if (res==-1)
		{
			pre->rchild=p;
		}else if (res==1)
		{
			pre->lchild=p;
		}
	}
}

/************************************************************************/
/* 递归算法                                                                     */
/************************************************************************/
void create_bst(node** root,int x){
	if (*root==NULL)
	{
		*root=(node*)malloc(sizeof(node));
		(*root)->data=x;
		(*root)->lchild=NULL;
		(*root)->rchild=NULL;
	}else if ((*root)->data==x){
		return;
	}else if((*root)->data>x){
		create_bst(&((*root)->lchild),x);
	}else{
		create_bst(&((*root)->rchild),x);
	}
}

void inorder(node* root){
	if (root)
	{
		inorder(root->lchild);
		printf("%d\n",root->data);
		inorder(root->rchild);
	}
}

/************************************************************************/
/* 判断是否是排序二叉树（中序遍历处理）                                                                     */
/************************************************************************/
bool is_bst(node* root,int pre){
	if (root==NULL)
	{
		return true;
	}
	bool lflag=is_bst(root->lchild,pre);
	if (lflag==false||pre>root->data)
	{
		return false;
	}
	return is_bst(root->rchild,root->data);


}


void create_tree(node** root){
	int c;
	printf("请输入数字:\n");
	scanf("%d",&c);
	if (c==-1)
	{
		*root=NULL;
	}else{
		*root=(node*)malloc(sizeof(node));
		(*root)->data=c;
		create_tree(&((*root)->lchild));
		create_tree(&((*root)->rchild));
	}
}

void pre_print(node* root){
	if (root!=NULL)
	{
		printf("%d\n",root->data);
		pre_print(root->lchild);
		pre_print(root->rchild);
	}
}

int search_level(node* root,int x){
	int res;
	if (root==NULL)
	{
		return -1;
	}
	if (root->data==x)
	{
		return 1;
	}else if (x<root->data)
	{
		res=search_level(root->lchild,x);
		if (res!=-1)
		{
			return res+1;
		}else{
			return -1;
		}
		 
	}else{
		res=search_level(root->rchild,x);
		if (res!=-1)
		{
			return res+1;
		}else{
			return -1;
		}
	}
}

/************************************************************************/
/* 判断是否是平衡二叉树                                                                     */
/************************************************************************/

bool is_avl(node* root,int* high){
	if (root==NULL)
	{
		*high=0;
		return true;
	}else if (root->lchild==NULL&&root->rchild==NULL)
	{
		*high=1;
		return true;
	}else{
		int lhigh;
		int rhigh;
		bool lflag=is_avl(root->lchild,&lhigh);
		bool rflag=is_avl(root->rchild,&rhigh);
		if (lflag&&rflag)
		{
			if (fabs(lhigh-rhigh)>=2)
			{
				return false;
			}
			if (lhigh>rhigh)
			{
				*high=lhigh+1;
			}else{
				*high=rhigh+1;
			}
			return true;
			
		}else{
			return false;
		}
		
	}
}

/************************************************************************/
/* 查询第k小的元素(借助count值)                                                      */
/************************************************************************/
node* search_small(node* root,int k){
	if (k<1||k>root->count)
	{
		return NULL;
	}
	if (root->lchild==NULL)
	{
		if (k==1)
		{
			return root;
		}else{
			return search_small(root->rchild,k-1);
		}
	}else{
		if (root->lchild->count==k-1)
		{
			return root;
		}else if (root->lchild->count>k-1)
		{
			return search_small(root->lchild,k);
		}else{
			return search_small(root->rchild,k-root->lchild->count-1);
		}
	}
}

int deal_count(node* root){
	if (root==NULL)
	{
		return 0;
	}else if (root->lchild==NULL&&root->rchild==NULL)
	{
		root->count=1;
		return 1;
	}else{
		int lcount=deal_count(root->lchild);
		int rcount=deal_count(root->rchild);
		root->count=lcount+rcount+1;
		return root->count;
	}
}

int main(){
	int x;
	printf("请输入一个数字:\n");
	scanf("%d",&x);
	node* root=NULL;
	while (x!=-1)
	{
		create_bst(&root,x);
		printf("请输入一个数字:\n");
		scanf("%d",&x);
	}
	inorder(root);
	deal_count(root);
	int k=7;
	node* res=search_small(root,k);
	printf("第%d小的元素是:%d",k,res->data);


	/*int high=0;
	bool res=is_avl(root,&high);
	if (res)
	{
		printf("是平衡二叉树");
	}else{
		printf("不是平衡二叉树");
	}*/


	/*int x;
	printf("请输入一个数字:\n");
	scanf("%d",&x);
	node* root=(node*)malloc(sizeof(node));
	root->data=x;
	root->lchild=NULL;
	root->rchild=NULL;
	while (x!=-1)
	{
		create_bst_fdg(root,x);
		printf("请输入一个数字:\n");
		scanf("%d",&x);
	}
	inorder(root);
    int search;
    printf("请输入需要查询的数字:\n");
	scanf("%d",&search);
	while (search!=-1)
	{
		int level=search_level(root,search);
		printf("搜索的节点在第%d层",level);

		printf("请输入需要查询的数字:\n");
		scanf("%d",&search);

	}*/

	
	


	/*node* root=NULL;
	create_tree(&root);
	pre_print(root);

	bool res=is_bst(root,-1000);
	if (res)
	{
		printf("是排序树");
	}else{
		printf("不是排序树");
	}*/
    return 0;
		
}