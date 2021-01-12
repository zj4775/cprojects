#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/malloc.h>
typedef struct node
{
	char data[10];
	int count;
	node *lchild;
	node *rchild;
}node,*linktree;

struct mynode{
	int a;
	int b;
	char c;
};

struct mynode2 
{
	int a;
	char b;
	char c;
	char e;
	int d[3];
	char f[10];
	int g;
};

void inorder(linktree bt)
{
	if(bt!=NULL)
	{
		inorder(bt->lchild);
		printf("字符串%s出现的次数为%d   \n",bt->data,bt->count);
		inorder(bt->rchild);
	}
}
void clear(linktree *bt)
{
	linktree p=*bt;
	if(*bt!=NULL)
	{
		clear(&(p->lchild));
		clear(&(p->rchild));
		free(p);
		*bt=NULL;
	}
}
void insert(node **bst,char x[])
{
	node *p,*q;
	q=*bst;
		
	if(!q)
	{

		p=(node *)malloc(sizeof(node));
		strcpy(p->data,x);
		p->count=1;
		
		p->lchild=p->rchild=NULL;
		*bst=p;
	
	}
	
	else if(strcmp(q->data,x)>0){insert(&q->lchild,x);}
	else if(strcmp(q->data,x)<0){insert(&q->rchild,x);}
	else{(q->count)++;}
}
int main()
{

	char arr[10];
	int count;
	float f;
	printf("%d\n",sizeof(arr));
	printf("%d\n",sizeof(count));
	printf("%d\n",sizeof(f));
	printf("%d\n",sizeof(mynode2));
	printf("%d\n",sizeof(node));

	linktree pnode=(node *)malloc(sizeof(node));

	printf("%d\n",sizeof(pnode->rchild));
	printf("%d\n",sizeof(node));

	linktree p;
	p=(node *)malloc(sizeof(node));
	p->count=1;
	strcpy(p->data,"ff");
	p->lchild=p->rchild=NULL;
	
	int i;
	char a[][8]={"ss","bb","aa","aa","ff","dd","ff","tt","tt","hh","ll","ff","ee","jj","qq","kk","bb","ff","ss","jj"};
	
	for(i=0;i<20;i++)
	{
		insert(&p,a[i]);
	}
	
	inorder(p);
	clear(&p);
    return 0;
}

