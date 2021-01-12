#include<stdio.h>
#include<sys/malloc.h>
#include<string.h>
typedef struct node
{
	char ch;
	node *lchild;
	node *rchild;
	node *next;
}node,*tree;
typedef struct
{
	node *front;
	node *rear;
}list;
void in(list *l,node *p)
{
	l->rear->next=p;
	l->rear=p;
}
node *out(list *l)
{
	node *p;
	p=l->front->next;
	l->front->next=p->next;
	if(p==l->rear){l->rear=l->front;}
	
	return p;

}
//void out(list *l,tree *p)//或者用这种方法出去，想要改变地址就必须用二级指针
//{
	
	//*p=l->front->next;
	//l->front->next=(*p)->next;
	//if((*p)==l->rear){l->rear=l->front;}
	
//}
void creat(tree *root)
{

	char ch;
	
	ch=getchar();
	if(ch==' '){root=NULL;}
	else
	{
		(*root)=(node *)malloc(sizeof(node));
		(*root)->ch=ch;
		(*root)->lchild=(*root)->rchild=NULL;
		creat(&((*root)->lchild));	
		creat(&((*root)->rchild));
	}
	
}
void preprint(node *root)
{
	if(root)
	{
	printf("%c",root->ch);
	preprint(root->lchild);
	preprint(root->rchild);
	}
	
}
void rowprint(node *root,list *l)
{
	node *r;
	in(l,root);
	
	while(l->front!=l->rear)
	{

		r=out(l);
		printf("%c",r->ch);


		if(r->lchild){in(l,r->lchild);}
		if(r->rchild){in(l,r->rchild);}
	}

}
int main()
{
	list L;
	node *s;
	s=(node*)malloc(sizeof(node));
	tree R;
	creat(&R);
	printf("先序遍历为");
	preprint(R);
	printf("\n");
	L.front=L.rear=s;
	printf("按层遍历为");
	rowprint(R,&L);
    return 0;
}
