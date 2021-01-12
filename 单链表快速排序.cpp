 
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
//链表节点  
struct node {  
    int data;  
    struct node *next;  
};  
//链表快排序函数  
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
        //取第一个节点作为比较的基准，小于基准的在左面的子链表中，  
        //大于基准的在右边的子链表中  
        for (old = (*head)->next; old != end; old = old->next) {  
            if (old->data < pivot->data) {   //小于基准,加入到左面的子链表,继续比较  
               ++left_count;  
                *left_walk = old;            //把该节点加入到左边的链表中，  
                left_walk = &(old->next);  
           } else {                         //大于基准,加入到右边的子链表，继续比较  
               ++right_count;  
                *right_walk = old;             
                right_walk = &(old->next);  
           }  
        }  
        //合并链表  
        *right_walk = end;       //结束右链表  
        *left_walk = pivot;      //把基准置于正确的位置上  
        pivot->next = right;     //把链表合并  
        //对较小的子链表进行快排序，较大的子链表进行迭代排序。  
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

//打印链表  
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
/* 其实也很简单，就是选择排序只不过比较的值是固定的第一个value存后面那些比value小的值
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
  
