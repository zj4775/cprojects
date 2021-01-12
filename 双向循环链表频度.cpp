#include<stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct node{
	int data;
	node* pre;
	node* next;
	int freq;
}node;

int get_random(){
	return rand()%10+1;
}

void create_list(node** head,int n){
	*head=(node*)malloc(sizeof(node));
	(*head)->freq=0;
	(*head)->next=(*head);
	(*head)->pre=(*head);
	node* h=*head;
	node* p;
	node* q;
	node* rear;
	node* start;
	int x;
	for (int i=0;i<n;i++)
	{
		x=get_random();
		q=h->next;
		while(h!=q){
			if (q->data!=x)
			{
				q=q->next;
			}else{
				break;
			}
		}
		if (q->data==x)
		{
			q->freq++;
			if (q->pre->freq<q->freq)
			{
				start=q->pre;
				start->next=q->next;
				q->next->pre=start;
				while (start!=h)
				{
					if (start->freq<q->freq)
					{
						start=start->pre;
					}else{
						break;
					}
				}
				q->next=start->next;
				start->next->pre=q;
				start->next=q;
				q->pre=start;
			}

		}else{
			rear=h->pre;
			p=(node*)malloc(sizeof(node));
			p->data=x;
			p->freq=1;
			p->pre=rear;
			rear->next=p;
			h->pre=p;
			p->next=h;

		}
		
	
	}

}

void print_list(node* head){
	node* p=head->next;
	while(p!=head){
		printf("节点:%d,频度:%d\n",p->data,p->freq);
		p=p->next;
	}
}

void locate_x(node* head,int x){
	
	node* p;
	node* q=head->next;
	node* rear;
	node* start;
	while(q!=head){
		if (q->data!=x)
		{
			q=q->next;
		}else{
			break;
		}
	}
	if (q->data==x)
	{
		q->freq++;
		if (q->pre->freq<q->freq)
		{
			start=q->pre;
			start->next=q->next;
			q->next->pre=start;
			while (start!=head)
			{
				if (start->freq<q->freq)
				{
					start=start->pre;
				}else{
					break;
				}
			}
			q->next=start->next;
			start->next->pre=q;
			start->next=q;
			q->pre=start;
		}
		
	}else{
		rear=head->pre;
		p=(node*)malloc(sizeof(node));
		p->data=x;
		p->freq=1;
		p->pre=rear;
		rear->next=p;
		head->pre=p;
		p->next=head;
		
	}

}


int main(){
	srand((unsigned)time(NULL));
	int n;
	int x;
	printf("请输入链表的长度:\n");
	scanf("%d",&n);
	node* head;
	create_list(&head,n);
	print_list(head);

	printf("请输入一个数字:\n");
	scanf("%d",&x);
	while(x!=-1){
		locate_x(head,x);
		print_list(head);
		getchar();
		printf("请输入一个数字:\n");
		scanf("%d",&x);


	}
    return 0;


}