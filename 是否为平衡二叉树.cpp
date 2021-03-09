#include<stdio.h>
#include<sys/malloc.h>
#include<math.h>
#include <cstdlib>

typedef struct node
{
	char ch;
	node *lchild;
	node *rchild;
}node;
node *creat()
{
	node *p;
	char cc;
	printf("请输入一个字符");
	cc=getchar();
	getchar();
	if(cc==' '){p=NULL;}
	else
	{
		p=(node *)malloc(sizeof(node));
		p->ch=cc;
		p->lchild=creat();
		p->rchild=creat();

	}
	return p;
}
int count(node *root)
{
	int n,m,max;
	if(root!=NULL)
	{
		n=count(root->lchild);
		m=count(root->rchild);
		max=n>m?n:m;
		return max+1;
	}
	else{return 0;}

}
int isb(node *root)
{
	int n,m;
	if(root==NULL){return 1;}
	else
	{
		m=count(root->lchild);
		n=count(root->rchild);
	
		if(fabs(n-m)>=2){return 0;}
		else
		{
			if(isb(root->lchild)&&isb(root->rchild)){return 1;}
			else{return 0;}
		}
	}
}
void print(node *root)
{
	if(root)
	{
		printf("%c",root->ch);
		print(root->lchild);
		print(root->rchild);

	}
}
int main()
{
	int k;
	node *R;
	R=creat();
	print(R);
	k=isb(R);


	if(k){printf("该二叉树为平衡二叉树");}
	else{printf("该二叉树不为平衡二叉树");}
    return 0;
}