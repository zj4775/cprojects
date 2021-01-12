#include<stdio.h>
#include<sys/malloc.h>
#include<stdlib.h>
typedef struct node
{
	int elem;
	node *lchild;
	node *rchild;
}node;
void insert(node **root,int n)
{
	node *p;
	if(!(*root))
	{
		p=(node *)malloc(sizeof(node));
		p->elem=n;
		p->lchild=p->rchild=NULL;
		*root=p;
	}
	else
	{
		if((*root)->elem>n){insert(&((*root)->lchild),n);}
		if((*root)->elem<n){insert(&((*root)->rchild),n);}
	}
}
void del(node **root,int n)
{
	node *p1,*p2;
	if((*root)==NULL){printf("错误");exit(0);}
	else if((*root)->elem>n){del(&((*root)->lchild),n);}
	else if((*root)->elem<n){del(&((*root)->rchild),n);}
	else
	{
	
		if((*root)->rchild==NULL){(*root)=(*root)->lchild;}//这种方法要学会
		else if((*root)->lchild==NULL){(*root)=(*root)->rchild;}
		else
		{
			if((*root)->lchild->rchild==NULL)
			{
				(*root)->elem=(*root)->lchild->elem;
				del(&(*root)->lchild,(*root)->lchild->elem);
			}
			else
			{
				p1=(*root);
				p2=(*root)->lchild;
				while(p2->rchild!=NULL){p1=p2;p2=p2->rchild;}
				(*root)->elem=p2->elem;
				del(&(p1->rchild),p2->elem);//p1->rchild不能换成p2

			}
		}


	}
}
void print(node *root)
{
	if(root)
	{
		printf("%d  ",root->elem);
		print(root->lchild);
		print(root->rchild);

	}

}
int main()
{
	int n;
	node *R=NULL;
	printf("请输入一个数以0为结尾");
	scanf("%d",&n);
	while(n!=0)
	{
		insert(&R,n);
		printf("请输入一个数以0为结尾");
		scanf("%d",&n);
	}
	print(R);
	printf("请输入需要删掉的数");
	scanf("%d",&n);
	del(&R,n);
	printf("剩下的数字为\n");
	print(R);
    return 0;


}