#include<stdio.h>
#include<sys/malloc.h>
#include<stdlib.h>
typedef struct node
{
	int ch;
	node *lchild;
	node *rchild;
	int ltag;
	int rtag;
}node;
node *pre=NULL;

/************************************************************************/
/* 创建树                                                                     */
/************************************************************************/
void creattree(node **p)
{
	int c;
	printf("请输入一个数字");
	scanf("%d",&c);

	if(c!=0)
	{
		(*p)=(node *)malloc(sizeof(node));
		(*p)->ch=c;
		(*p)->ltag=0;
		(*p)->rtag=0;

		creattree(&((*p)->lchild));
	    creattree(&((*p)->rchild));
	}
	else{(*p)=NULL;}

}
/************************************************************************/
/* 简单的先序遍历                                                                     */
/************************************************************************/
void preprint(node *root)
{
	if(root)
	{
		printf("%d   ",root->ch);
		preprint(root->lchild);
		preprint(root->rchild);
	}
}
void prethread(node *root)//先驱线索
{
	if(root)
	{
		if(pre&&pre->rchild==NULL){pre->rtag=1;pre->rchild=root;}
		if(root->lchild==NULL){root->lchild=pre;root->ltag=1;}
		pre=root;
		prethread(root->lchild);
		prethread(root->rchild);
	}
}

void inthread(node *root)//中序线索
{
	if(root)
	{
		inthread(root->lchild);
		if(pre&&pre->rchild==NULL){pre->rtag=1;pre->rchild=root;}
		if(root->lchild==NULL){root->lchild=pre;root->ltag=1;}
		pre=root;
		inthread(root->rchild);
	}
}
void postthread(node *root)//后序线索
{
	if(root)
	{
		postthread(root->lchild);
		postthread(root->rchild);
		if(pre&&pre->rchild==NULL){pre->rtag=1;pre->rchild=root;}
		if(root->lchild==NULL){root->lchild=pre;root->ltag=1;}
		pre=root;
		
	}
	
}

/**
**中序遍历第一个节点
**
**/


node *infirst(node *root)
{
	node *p=root;
	if(!p){return NULL;}
	while(p->ltag==0){p=p->lchild;}
	return p;

}

/************************************************************************/
/* 中序遍历取出下一个节点(右孩子的左到底)                                                                     */
/************************************************************************/
node *innext(node *root)
{
	node *next,*q;
		if(root->rtag==1){next=root->rchild;}
		else
		{
			
			for(q=root->rchild;q->ltag==0;q=q->lchild);
			next=q;
		}
		return next;
}
/************************************************************************/
/* 线索树的中序遍历                                                                     */
/************************************************************************/
void tinorder(node *root)
{
	node *p;
	p=infirst(root);
	while(p)
	{
		printf("%d   ",p->ch);
		p=innext(p);
	}
}


int main()
{
	node *R;
	R=(node *)malloc(sizeof(node));
	creattree(&R);
	//preprint(R);
	inthread(R);
	tinorder(R);
	//postthread(R);
	//prethread(R);
	//printf("000000000000");
    return 0;
}