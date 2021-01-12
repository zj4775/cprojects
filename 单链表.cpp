#include<stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>

struct node{
    int data;
    node* next;
};

/************************************************************************/
/*   循环双向链表                                                       */
/************************************************************************/
struct binnode{
    int data;
    binnode* pre;
    binnode* next;
};


void create_bin_link(binnode* head){
    int v;
    printf("请输入一个数字\n");
    scanf("%d",&v);
    while (v!=-1)
    {
        binnode* p=(binnode*)malloc(sizeof(binnode));
        p->data=v;
        binnode* q=head->next;
        p->next=q;
        q->pre=p;
        head->next=p;
        p->pre=head;
        printf("请输入一个数字\n");
        scanf("%d",&v);

    }
}

void print_bin_link(binnode* head){
    binnode* p=head->next;
    while (p!=head)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
}

/************************************************************************/
/* 是否是对称的循环链表                                                                     */
/************************************************************************/
bool is_symmetry(binnode* head){
    binnode* next=head->next;
    binnode* pre=head->pre;
    while (pre!=next&&pre->pre!=next)
    {
        if (pre->data==next->data)
        {
            pre=pre->pre;
            next=next->next;
        }else{
            return false;
        }
    }
    return true;
}

/************************************************************************/
/* 将两个循环链表合并                                                                     */
/************************************************************************/


void merge_bin_list(binnode* h1,binnode* h2){
    binnode* t1=h1->pre;
    binnode* f2=h2->next;
    binnode* e2=h2->pre;
    t1->next=f2;
    f2->pre=t1;
    e2->next=h1;
    h1->pre=e2;
}

/************************************************************************/
/* 创建没有头结点的链表                                                                     */
/************************************************************************/
void create_with_no_head(node** head){
    int v;
    printf("请输入一个数字\n");
    scanf("%d",&v);
    node* p=NULL;
    node* last=NULL;
    while (v!=-1)
    {
        if (last==NULL)
        {
            *head=(node*)malloc(sizeof(node));
            last=*head;
            last->data=v;
            last->next=NULL;
        }else{
            p=(node*)malloc(sizeof(node));
            p->data=v;
            p->next=NULL;
            last->next=p;
            last=p;
        }
        printf("请输入一个数字\n");
        scanf("%d",&v);
    }
}

void print_link_with_no_head(node * head){
    node* tail=head;
    printf("打印单链表\n");
    while (tail!=NULL)
    {
        printf("%d  ",tail->data);
        tail=tail->next;
    }
    printf("\n");
}

void del_x_with_no_head(node** head,int x){
    if (*head!=NULL)
    {
        node* h=*head;
        if (h->data==x)
        {
            *head=(*head)->next;
            free(h);
        }
        del_x_with_no_head(&(*head)->next,x);
    }

}

/************************************************************************/
/* 创建单循环链表                                                                     */
/************************************************************************/
void create_cycle_link(node * head){
    int v;
    printf("请输入一个数字\n");
    scanf("%d",&v);
    node* tail=head;
    while (v!=-1)
    {
        node * p=(node*)malloc(sizeof(node));
        p->data=v;
        p->next=NULL;
        tail->next=p;
        tail=p;
        printf("请输入一个数字\n");
        scanf("%d",&v);
    }
    tail->next=head;
};


void print_cycle_link(node * head){
    node* tail=head->next;
    printf("打印单链表\n");
    while (tail!=head)
    {
        printf("%d  ",tail->data);
        tail=tail->next;
    }
    printf("\n");
}

/************************************************************************/
/* 每次删除 单循环链表 中值最小的节点                                                                    */
/************************************************************************/
void del_min_cycle_link(node * head){
    int min=head->next->data;
    node* p=head;
    node* q;
    node* min_pre=head;
    while(head->next!=head){
        p=head;
        min_pre=head;
        while(p->next->next!=head){
            q=p->next;
            if (q->data<min)
            {
                min=q->data;
                min_pre=p;
            }
            p=p->next;
        }
        q=min_pre->next;
        min_pre->next=q->next;
        printf("删除节点:%d后的链表",q->data);
        free(q);
        print_cycle_link(head);
    }
    printf("全部删除完毕了");
    free(head);

}



void create_link(node * head){
    int v;
    printf("请输入一个数字\n");
    scanf("%d",&v);
    node* tail=head;
    while (v!=-1)
    {
        node * p=(node*)malloc(sizeof(node));
        p->data=v;
        p->next=NULL;
        tail->next=p;
        tail=p;
        printf("请输入一个数字\n");
        scanf("%d",&v);
    }
};

void print_link(node * head){
    node* tail=head->next;
    printf("打印单链表\n");
    while (tail!=NULL)
    {
        printf("%d  ",tail->data);
        tail=tail->next;
    }
    printf("\n");
}

void revert_print(node * head){
    if (head!=NULL)
    {
        revert_print(head->next);
        printf("%d   ",head->data);
    }
}

void del_min(node * head){
    node* min_pre=head;
    int min=min_pre->next->data;
    node* p=min_pre;
    while (p->next!=NULL)
    {
        if (p->next->data<min)
        {
            min=p->next->data;
            min_pre=p;
        }
        p=p->next;
    }
    node* q=min_pre->next;
    min_pre->next=q->next;
    free(q);
}

/************************************************************************/
/* 删除单链表倒数第k个元素  (一次遍历哦)     */
/************************************************************************/

void print_reverse_k(node* head,int k){
    int count=0;
    node* p=head;
    node* q=head;
    while (p!=NULL&&count<k)
    {
        p=p->next;
        count++;
    }
    if (p==NULL)
    {
        printf("输入的k非法");
        exit(0);
    }
    else{
        while(p!=NULL){
            p=p->next;
            q=q->next;
        }
        printf("倒数第:%d个元素的值是:%d",k,q->data);
    }
}

/************************************************************************/
/* 就地逆转                                                                     */
/************************************************************************/

void reverse(node* head){
    node* p=head->next;
    node* first;
    if (head->next!=NULL)
    {
        node* q=head->next->next;
        head->next->next=NULL;

        while (q!=NULL)
        {
            first=q->next;
            q->next=head->next;
            head->next=q;
            q=first;
        }

    }
}

/************************************************************************/
/* 逆序打印单链表                                                                     */
/************************************************************************/

void reverse_print(node* p){
    if (p->next!=NULL)
    {
        reverse_print(p->next);
        printf("%d  ",p->data);
    }else{
        printf("%d  ",p->data);
    }
}
/************************************************************************/
/* 删除值为x的节点                                                                     */
/************************************************************************/

void del_x(node* head,int x){
    node* p=head;
    node* q;
    while(p->next!=NULL){
        if(p->next->data==x){
            q=p->next;
            p->next=q->next;
            free(q);
        }else{
            p=p->next;
        }
    }
}

/************************************************************************/
/* 单链表排序                                                                     */
/************************************************************************/

void insert(node* head,node* i){
    i->next=NULL;
    node* p=head;
    while (p->next!=NULL)
    {
        if (p->next->data<i->data)
        {
            p=p->next;
        }
        else{
            i->next=p->next;
            p->next=i;
            break;
        }
    }
    if (p->next==NULL)
    {
        p->next=i;
    }
}

void sort(node* head){
    node* p=head->next;
    node* first;
    if (p!=NULL)
    {
        node* q=p->next;
        p->next=NULL;
        while (q!=NULL)
        {
            first=q->next;
            insert(head,q);
            q=first;
        }
    }
}

/************************************************************************/
/* 求两个链表的公共节点,相当于是一个Y型(因为一个节点的next不会有两个所以以后不会再分叉了)                                                                   */
/************************************************************************/

int get_length(node* head){
    int count=0;
    node* p=head->next;
    while (p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}


node* common_node(node* head1,node* head2){
    int l1=get_length(head1);
    int l2=get_length(head2);
    node* long_list;
    node* short_list;
    int diff=0;
    if (l1>l2)
    {
        long_list=head1;
        short_list=head2;
        diff=l1-l2;
    }else{
        long_list=head2;
        short_list=head1;
        diff=l2-l1;
    }
    int count=0;
    node* p=long_list;
    node* q=short_list;
    while (count<diff)
    {
        p=p->next;
        count++;
    }
    p=p->next;
    q=short_list->next;
    while (p!=NULL)
    {
        if (p==q)
        {
            return p;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    return NULL;

}


/************************************************************************/
/* 拆为奇偶两个                                                                     */
/************************************************************************/
void chaifeng(node* head,node** js,node** os){
    *js=(node*)malloc(sizeof(node));
    *os=(node*)malloc(sizeof(node));
    node* p=head->next;
    node* jp=*js;
    node* op=*os;
    while (p!=NULL)
    {
        if (p->data%2==0)
        {
            op->next=p;
            op=p;

        }else{
            jp->next=p;
            jp=p;

        }
        p=p->next;
    }
    op->next=NULL;
    jp->next=NULL;

}

/************************************************************************/
/* 奇偶序号拆分                                                                   */
/************************************************************************/
void chaifeng_idx(node* head,node** js,node** os){
    *js=(node*)malloc(sizeof(node));
    *os=(node*)malloc(sizeof(node));
    node* p=head->next;
    node* jp=*js;
    node* op=*os;
    int count=1;
    while (p!=NULL)
    {
        if (count%2==0)
        {
            op->next=p;
            op=p;
        }else{
            jp->next=p;
            jp=p;
        }
        p=p->next;
        count++;
    }
    op->next=NULL;
    jp->next=NULL;

}





/************************************************************************/
/* 递增的输出元素(并释放每次打印的节点)                                                                     */
/************************************************************************/
void incr_print(node* head){
    while (head->next!=NULL)
    {
        int min=head->next->data;
        node* min_pre=head;
        node* p=head->next;
        node* pre=head;
        while (p!=NULL)
        {
            if (p->data<min)
            {
                min=p->data;
                min_pre=pre;
            }
            pre=p;
            p=p->next;
        }
        printf("%d  ",min_pre->next->data);
        node* q=min_pre->next;
        min_pre->next=q->next;
        free(q);
    }
}

/************************************************************************/
/* 去掉重复                                                                     */
/************************************************************************/

void del_duplicate(node* head){
    node* p=head->next;
    node* q;
    while (p!=NULL)
    {
        while (p->next!=NULL&&p->next->data==p->data)
        {
            q=p->next;
            p->next=q->next;
            free(q);
        }
        p=p->next;
    }
}

/************************************************************************/
/* 归并两个单链表并倒序                                                                     */
/************************************************************************/


void merge(node* head1,node* head2){
    node* head=head1;
    node* p1=head1->next;
    node* p2=head2->next;
    node* q1;
    node* q2;
    head1->next=NULL;

    while(p1!=NULL&&p2!=NULL){
        if (p1->data<=p2->data)
        {
            q1=p1->next;
            p1->next=head->next;
            head->next=p1;
            p1=q1;

        }else{
            q2=p2->next;
            p2->next=head->next;
            head->next=p2;
            p2=q2;
        }
    }
    while (p1!=NULL)
    {
        q1=p1->next;
        p1->next=head->next;
        head->next=p1;
        p1=q1;
    }
    while (p2!=NULL)
    {
        q2=p2->next;
        p2->next=head->next;
        head->next=p2;
        p2=q2;
    }
}

/************************************************************************/
/* 获取两个链表公共的元素(原数据递增有序,不破坏原来的链表)                                                                     */
/************************************************************************/

node* get_common_ele(node* head1,node* head2){

    node * head=(node*)malloc(sizeof(node));
    head->next=NULL;
    node* p1=head1->next;
    node* p2=head2->next;
    while(p1!=NULL&&p2!=NULL){
        if (p1->data==p2->data)
        {
            node * s=(node*)malloc(sizeof(node));
            s->data=p1->data;
            s->next=head->next;
            head->next=s;
            p1=p1->next;
            p2=p2->next;
        }else{
            while (p1->data<p2->data)
            {
                p1=p1->next;
            }
            while (p1->data>p2->data)
            {
                p2=p2->next;
            }
        }
    }
    return head;

}

/************************************************************************/
/* 交集存入A中                                                                     */
/************************************************************************/

void interact(node* head1,node* head2){
    node* p1=head1->next;
    node* p2=head2->next;
    node* q1;
    node* head=head1;
    head->next=NULL;
    while (p1!=NULL&&p2!=NULL)
    {
        if (p1->data==p2->data)
        {

            q1=p1->next;
            p1->next=head->next;
            head->next=p1;
            p1=q1;
            p2=p2->next;
        }else{
            while (p1->data<p2->data)
            {
                p1=p1->next;
            }
            while (p1->data>p2->data)
            {
                p2=p2->next;
            }
        }
    }

}

/************************************************************************/
/* 求B是否是A的连续子序列                                                                     */
/************************************************************************/

bool is_sub_seq(node* head1,node* head2){
    node* p1=head1->next;
    node* p2=head2->next;
    node* pre=head1->next;
    while(pre!=NULL){
        while(pre!=NULL&&pre->data!=p2->data){
            pre=pre->next;
        }
        if (pre!=NULL)
        {
            node* q1=pre;
            node* q2=p2;
            while (q1!=NULL&&q2!=NULL)
            {
                if (q1->data==q2->data)
                {
                    q1=q1->next;
                    q2=q2->next;
                }else{
                    break;
                }
            }
            if (q2==NULL)
            {
                return true;
            }
            pre=pre->next;
        }
    }
    return false;
}

int main(){
    node * head=(node*)malloc(sizeof(node));
    head->next=NULL;
    create_link(head);
    print_link(head);

    //reverse(head);
    //print_link(head);
    //reverse_print(head->next);


    /*printf("请输入需要删除的节点值\n");
    int x=-1;
    scanf("%d",&x);
    del_x(head,x);
    print_link(head);*/


    /*sort(head);
    print_link(head);*/

    /*node * head2=(node*)malloc(sizeof(node));
    head2->next=NULL;
    create_link(head2);
    node* t=head2;
    while (t->next!=NULL)
    {
        t=t->next;
    }
    t->next=head->next;
    print_link(head2);
    node* c=common_node(head,head2);
    while (c!=NULL)
    {
        printf("%d  ",c->data);
        c=c->next;
    }*/

    /*node* jishu;
    node* oushu;
    chaifeng(head,&jishu,&oushu);
    print_link(jishu);
    print_link(oushu);*/

    /*del_duplicate(head);
    print_link(head);*/

    /*node * head2=(node*)malloc(sizeof(node));
    head2->next=NULL;
    create_link(head2);
    print_link(head2);
    merge(head,head2);
    print_link(head);*/

    /*node * head2=(node*)malloc(sizeof(node));
    head2->next=NULL;
    create_link(head2);
    print_link(head2);
    node * res=get_common_ele(head,head2);
    print_link(res);*/

    /*node * head2=(node*)malloc(sizeof(node));
    head2->next=NULL;
    create_link(head2);
    print_link(head2);
    interact(head,head2);
    print_link(head);*/



    /*node* head;
    create_with_no_head(&head);
    print_link_with_no_head(head);
    printf("请输入需要删除的节点值\n");
    int x=-1;
    scanf("%d",&x);
    del_x_with_no_head(&head,x);
    print_link_with_no_head(head);*/



    //revert_print(head->next);

    /*del_min(head);
    print_link(head);*/

    //incr_print(head);

    /*node* jishu;
    node* oushu;
    chaifeng_idx(head,&jishu,&oushu);
    print_link(jishu);
    print_link(oushu);*/

    /*node * head2=(node*)malloc(sizeof(node));
    head2->next=NULL;
    create_link(head2);
    print_link(head2);
    bool res=is_sub_seq(head,head2);
    if (res)
    {
        printf("是子序列");
    }else{
        printf("不是子序列");
    }*/


    /*binnode* head=(binnode*)malloc(sizeof(binnode));
    head->next=head;
    head->pre=head;
    create_bin_link(head);
    print_bin_link(head);*/

    /*bool res=is_symmetry(head);
    if (res)
    {
        printf("是对称序列");
    }else{
        printf("不是对称序列");
    }*/

    /*binnode* head2=(binnode*)malloc(sizeof(binnode));
    head2->next=head2;
    head2->pre=head2;
    create_bin_link(head2);
    print_bin_link(head2);

    merge_bin_list(head,head2);
    printf("合并完毕:\n");
    print_bin_link(head);*/

    /*node * head=(node*)malloc(sizeof(node));
    head->next=NULL;
    create_cycle_link(head);
    print_cycle_link(head);
    del_min_cycle_link(head);*/

    int k;
    printf("请输入倒数第几个数");
    scanf("%d",&k);
    print_reverse_k(head,k);
    return 0;


}