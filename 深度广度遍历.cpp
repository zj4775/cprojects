#include<stdio.h>
#include<string.h>
#include<sys/malloc.h>
#define MAX 100
typedef struct
{
	int l[MAX];
	int front;
	int rear;
}link;
typedef struct node
{
	int date;
	node *next;
}node;
typedef struct
{
	char sign;
	int date;
	node *first;
}tou;
typedef struct
{
	tou A[MAX];
	int vexnum;
	int edgenum;
}matrix;
void inlink(link *lk,int n)
{
	lk->rear++;
	lk->l[lk->rear]=n;
}
void outlink(link *lk,int *n)
{
	*n=lk->l[lk->front+1];
	lk->front++;
}
void creat(matrix *M)
{
	char s[MAX];
	int i,m,n;
	node *p;
	printf("请输入顶点的个数");
	scanf("%d",&M->vexnum);
	printf("请输入边的条数");
	scanf("%d",&M->edgenum);
	printf("请输入顶点信息");
	getchar();
	gets(s);
	for(i=0;i<M->vexnum;i++)
	{
		M->A[i].first=NULL;
		M->A[i].sign=s[i];
		M->A[i].date=i;
	}
	for(i=0;i<M->edgenum;i++)
	{
		printf("请输入一条边的起点和终点");
		scanf("%d,%d",&m,&n);
		p=(node *)malloc(sizeof(node));
		p->date=n;
		p->next=M->A[m].first;
		M->A[m].first=p;
	}

}
void shendu(matrix *M,int k,int visited[])
{
	node *p;
	int i;
	printf("%c",M->A[k].sign);
	visited[k]=1;
	p=M->A[k].first;
	while(p)
	{
		i=p->date;
		if(visited[i]==0)
		{
			shendu(M,i,visited);
		}
		p=p->next;
	}
}

void guangdu(matrix *M,int k,int visited[],link *lk)
{
	int n=MAX;
	node *p;
	printf("%c",M->A[k].sign);
	inlink(lk,k);
	visited[k]=1;
	while(lk->front!=lk->rear)
	{
		outlink(lk,&n);
		p=M->A[n].first;
		while(p)
		{
			if(visited[p->date]==0)
			{
				printf("%c",M->A[p->date].sign);
				visited[p->date]=1;
				inlink(lk,p->date);
			}
			p=p->next;
		}
	}

}
int main()
{
	matrix M;
	link L;
	int i,visited1[MAX],visited2[MAX];
	creat(&M);
	L.front=L.rear=-1;
	for(i=0;i<M.vexnum;i++)
	{
		visited1[i]=0;
		visited2[i]=0;
	}
	for(i=0;i<M.vexnum;i++)
	{
		if(visited1[i]==0)
		{
			printf("深度遍历为");
			shendu(&M,i,visited1);
			printf("\n");
			printf("广度遍历为");
	        guangdu(&M,i,visited2,&L);

		}
	}
    return 0;

}
