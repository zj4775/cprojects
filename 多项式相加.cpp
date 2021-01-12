#include<stdio.h>
#include<stdlib.h>
#include<sys/malloc.h>
typedef struct nod
{
	float x;
	int z;
	nod *next;
}node;
node *creat()
{
	node *p,*q,*head;
	float a;
	int b;
	head=(node *)malloc(sizeof(node));
	head->next=NULL;
	scanf("%f,%d",&a,&b);
	while(a!=0)
	{
		p=(node *)malloc(sizeof(node));
		p->x=a;
		p->z=b;
		p->next=NULL;
		q=head;
		while(q->next&&q->next->z<b)
		{
			q=q->next;
		}
		p->next=q->next;
		q->next=p;
		scanf("%f,%d",&a,&b);

	}
	return head;

}
node *js(node *ha,node *hb)
{
	node *p1,*p2,*q1,*q2;
	float c;
	p2=ha;
	p1=ha->next;
	q2=hb;
	q1=hb->next;
	while(p1&&q1)
	{
		if(p1->z<q1->z){p2=p1;p1=p1->next;}
		else if(p1->z>q1->z)
		{
			q2=q1;q1=q1->next;
			q2->next=p1;
			p2->next=q2;
		}
		else
		{
			c=p1->x+q1->x;
			if(c==0)
			{
				p1=p1->next;
				free(p2->next);
				p2->next=p1;
				q2=q1;
				q1=q1->next;
			}
			else
			{
				p1->x=c;
				p2=p1;
				p1=p1->next;
				q2=q1;
				q1=q1->next;
				free(q2);
			}
		}
	}
	if(q1)
	{
		p2->next=q1;
	}
	return ha;
}
void print(node *hd)
{
	node *p;
	p=hd->next;
	while(p)
	{
		printf("%1.0f^%d  ",p->x,p->z);
		p=p->next;
	}
	printf("\n");
}
int main()
{
	node *A,*B;
	printf("请输入A\n");
	A=creat();
	printf("请输入B\n");
	B=creat();
	print(A);
	print(B);
	js(A,B);
	printf("答案为:\n");
	print(A);
    return 0;
}
