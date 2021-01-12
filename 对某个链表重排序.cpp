#include<stdio.h>
#include<sys/malloc.h>
#define len sizeof(node)
typedef struct student
{
	int a;
	struct student *next;
}node;
node *creat()
{
	node *head;
	head=NULL;
	node *p,*q;
	p=(node *)malloc(len);
	scanf("%d",&p->a);
	while(p->a!=0)
	{
		if(head==NULL){head=p;}
		else{q->next=p;}
		q=p;
		p=(node *)malloc(len);
	    scanf("%d",&p->a);

	}
	q->next=NULL;
	return (head);

}

void print(node *head)
{
	node *p;
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%d ",p->a);
	}
	
}
node *change(node *head)
{
	node *p,*q;
	int temp;
	p=head;
	while(p->next!=NULL)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->a>q->a)
			{
				temp=q->a;
				q->a=p->a;
				p->a=temp;
			}
		}
		p=p->next;
	}
	return (head);

}         
int main()
{
	node *hd;
	hd=creat();
	print(hd);
	printf("\n");
	hd=change(hd);
	print(hd);
    return 0;

}