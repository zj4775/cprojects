 
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
//����ڵ�  
struct node {  
    int data;  
    struct node *next;  
};  
//�����������  
void QListSort(struct node **head, struct node *end) {  
    struct node *right;  
    struct node **left_walk, **right_walk;  
   struct node *pivot, *old;  
    int count, left_count, right_count;  
    if (*head == end)  
       return;  
    do {  
        pivot = *head;  
        left_walk = head;  
        right_walk = &right;  
        left_count = right_count = 0;  
        //ȡ��һ���ڵ���Ϊ�ȽϵĻ�׼��С�ڻ�׼����������������У�  
        //���ڻ�׼�����ұߵ���������  
        for (old = (*head)->next; old != end; old = old->next) {  
            if (old->data < pivot->data) {   //С�ڻ�׼,���뵽�����������,�����Ƚ�  
               ++left_count;  
                *left_walk = old;            //�Ѹýڵ���뵽��ߵ������У�  
                left_walk = &(old->next);  
           } else {                         //���ڻ�׼,���뵽�ұߵ������������Ƚ�  
               ++right_count;  
                *right_walk = old;             
                right_walk = &(old->next);  
           }  
        }  
        //�ϲ�����  
        *right_walk = end;       //����������  
        *left_walk = pivot;      //�ѻ�׼������ȷ��λ����  
        pivot->next = right;     //������ϲ�  
        //�Խ�С����������п����򣬽ϴ����������е�������  
        if(left_walk > right_walk) {  
            QListSort(&(pivot->next), end);  
            end = pivot;  
            count = left_count;  
       } else {  
            QListSort(head, pivot);  
            head = &(pivot->next);  
           count = right_count;  
        }  
   } while (count > 1);   
} 

//��ӡ����  
void print_list(struct node *head) {  
    struct node *p;  
    for (p = head; p != NULL; p = p->next) {  
       printf("%d ", p->data);  
   }  
    printf("/n");  
}  

void swap(node* p,node* q){
	int a=p->data;
	p->data=q->data;
	q->data=a;
}

/************************************************************************/
/* ��ʵҲ�ܼ򵥣�����ѡ������ֻ�����Ƚϵ�ֵ�ǹ̶��ĵ�һ��value�������Щ��valueС��ֵ
/************************************************************************/
node* get_quick_sort(node* head,node* end){
	int _value=head->data;
	node* p=head;
	node* q=p->next;
	while (q!=end)
	{
		if (q->data<_value)
		{
			p=p->next;
			swap(p,q);
		}
		q=q->next;
	}
	swap(p,head);
	return p;
}

void quick_sort(node* head,node* end){
	if (head!=end)
	{
		node* sp=get_quick_sort(head,end);
		quick_sort(head,sp);
		quick_sort(sp->next,end);
	}
}


int main(void) {  
    struct node *head;  
    struct node *p;  
    int i = 0;  
	int array[10]={5,7, 1,2,6};
    
 
    head = (struct node*)malloc(sizeof(struct node));  
    head->next = NULL;  
    head->data = array[0];  
    srand((unsigned)time(NULL));  
    /*for (i = 1; i < 10; ++i) {  
        p = (struct node*)malloc(sizeof(struct node));  
       p->data = rand() % 10 + 1;  
        p->next = head->next;  
       head->next = p;  
    } */ 
	node* aa=head;
	for (int j=2;j<=5;j++)
	{
		p = (struct node*)malloc(sizeof(struct node));  
		p->data = array[j-1];   
        p->next = NULL;  
		aa->next = p;
		aa=p;
	}



      
    print_list(head);  
    printf("\n");  
    //QListSort(&head, NULL);  
	quick_sort(head,NULL);
    print_list(head);  
    return 0;  
}  
  
