#include<stdio.h>
#include<sys/malloc.h>
#include<string.h>
#include <cstdlib>

typedef struct node
{
	char ch;
	node *lchild;
	node *rchild;
}node,*tree;

void creat(char pre[],int pres,int pree,char in[],int ins,int ine,tree *root)
{
	int i;
	if(pres>pree){(*root)=NULL;}
	else
	{
		(*root)=(node *)malloc(sizeof(node));
		(*root)->ch=pre[pres];
		for(i=ins;i<=ine;i++)
		{
			if(in[i]==pre[pres]){break;}
		}
		creat(pre,pres+1,pres+i-ins,in,ins,i-1,&((*root)->lchild));
		creat(pre,pres+i-ins+1,pree,in,i+1,ine,&((*root)->rchild));
	}
}
void print(node *root)
{
	if(root)
	{
		print(root->lchild);
		print(root->rchild);
		printf("%c",root->ch);
	}
}
/************************************************************************/
/* �����n��¼����� (���ʹ�ӡ����-���С����˳��)                                                                    */
/************************************************************************/
void shuxing(node *root,int n)
{
	int i;
	if(root)//���ܰ�if����while,����root���Ǹ�����һֱû�䣬��while�������ӡ����if��һ��
	{
		shuxing(root->rchild,n+1);
		for(i=0;i<n;i++,printf("  "));
	
		printf("%c\n",root->ch);

		shuxing(root->lchild,n+1);
		
	}
}
int main()
{
	int n=0;

	node *rt;
	char xian[20];
	char zhong[20];
	printf("�������������:\n");
	gets(xian);
	
	printf("�������������:\n");
	gets(zhong);




	printf("�������Ϊ:\n");
	creat(xian,0,strlen(xian)-1,zhong,0,strlen(zhong)-1,&rt);
	print(rt);

	printf("�����δ�ӡΪ:\n");
	shuxing(rt,n);
    return 0;



}
