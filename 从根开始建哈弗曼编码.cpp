#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 5
#define M 2*N-1
typedef struct
{
	int elem;
	int lchild;
	int rchild;
	int parent;
	char code[10];
}node;
void creathfm(node h[])
{
	int i,n,small1,small2,s1,s2,j;
	for(i=1;i<=M;i++)
	{
		h[i].parent=h[i].lchild=h[i].rchild=0;
		memset(h[i].code,10,0);
	}
	for(i=1;i<=N;i++)
	{
		printf("请输入一个数");
		scanf("%d",&n);
		h[i].elem=n;
	}
	for(i=N+1;i<=M;i++)
	{
		small1=small2=9999;
		s1=s2=0;
		for(j=1;j<i;j++)
		{
			if(h[j].parent==0)
			{
				if(h[j].elem<small1){small2=small1;s2=s1;small1=h[j].elem;s1=j;}
				else if(h[j].elem<small2){small2=h[j].elem;s2=j;}
			}
		}
		h[i].elem=h[s1].elem+h[s2].elem;
		h[i].lchild=s1;
		h[i].rchild=s2;
		h[s1].parent=h[s2].parent=i;
	}
}
/**
*左子树编码为0 右子树是1
*/
void creathfmcode(int p,char ch[],int n,node h[])
{
	if(h[p].lchild==0&&h[p].rchild==0)
	{
		ch[n]='\0';
		strcpy(h[p].code,ch);

	}
	if(h[p].lchild!=0)
	{
		ch[n]='0';
		creathfmcode(h[p].lchild,ch,n+1,h);
	}
	if(h[p].rchild!=0)
	{
		ch[n]='1';
		creathfmcode(h[p].rchild,ch,n+1,h);
	}
}
void print(int n,node h[])
{
	if(n!=0)
	{
		printf("%d   ",h[n].elem);
		print(h[n].lchild,h);
		print(h[n].rchild,h);


	}


}
int main()
{
	node hfm[M+1];
	int i;
	char ch[10];
	memset(ch,10,0);
	creathfm(hfm);
	creathfmcode(M,ch,0,hfm);
	print(M,hfm);
	printf("\n");
	for(i=1;i<=N;i++)
	{
		printf("数字%d的哈弗曼编码为:%s\n",hfm[i].elem,hfm[i].code);
	}
    return 0;


}
