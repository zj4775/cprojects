#include<stdio.h>
#include <string.h>
#include<stdlib.h>

typedef char DATA_TYPE;
int const MAX_SIZE=100;

typedef struct node 
{
	DATA_TYPE data;
	node* lchild;
	node* rchild;
	int level;
}node ;

typedef struct queue{
	node* ele[MAX_SIZE];
	int front;
	int rear;
}queue;

typedef struct {
	node* ele[MAX_SIZE];
	int top;
}stack;

void init_stack(stack** s){
	*s=(stack*)malloc(sizeof(stack));
	(*s)->top=-1;
}

void push(stack* s,node* x){
	if (s->top==MAX_SIZE-1)
	{
		printf("FULL\n");
		exit(1);
	}
	else{
		s->ele[++s->top]=x;
	}
}

node* gettop(stack* s){
	return s->ele[s->top];
}

node* pop(stack* s){
	if(s->top==-1){
		printf("EMPTY\n");
		exit(1);
	}else{
		return s->ele[s->top--];
	}
}

void init_queue(queue** q){
	*q=(queue*)malloc(sizeof(queue));
	(*q)->front=-1;
	(*q)->rear=-1;
}

bool is_empty_stack(stack* s){
	if (s->top==-1)
	{
		return true;
	}
	return false;
}

bool is_full_stack(stack* s){
	if(s->top==MAX_SIZE-1){
		return true;
	}
	return false;
}

bool isempty(queue* q){
	if (q->front==q->rear)
	{
		return true;
	}
	return false;
}

bool isfull(queue* q){
	if (q->rear==MAX_SIZE-1)
	{
		return true;
	}
	return false;
}

void enqueue(queue* q,node* x){
	if (isfull(q))
	{
		printf("FULL\n");
		exit(1);
	}else{
		q->ele[++q->rear]=x;
	}
}

node* dequeue(queue* q){
	if(isempty(q)){
		printf("EMPTY\n");
		exit(1);
	}else{
		q->front++;
		return q->ele[q->front];
	}
}

void create_tree(node** root){
	char c=getchar();
	if (c=='#')
	{
		*root=NULL;
	}else{
		*root=(node*)malloc(sizeof(node));
		(*root)->data=c;
		create_tree(&((*root)->lchild));
		create_tree(&((*root)->rchild));
	}

}

void pre_print(node* root){
	if (root!=NULL)
	{
		printf("%c\n",root->data);
		pre_print(root->lchild);
		pre_print(root->rchild);
	}
}

bool is_full_tree(node* root,queue* q){
	if (root==NULL)
	{
		return true;
	}
	else{
		enqueue(q,root);
	}
	while (!isempty(q))
	{
		node* e=dequeue(q);
		if (e!=NULL)
		{
			enqueue(q,e->lchild);//这里入队列的节点可能是NULL节点
			enqueue(q,e->rchild);
		}else{
			while (!isempty(q))
			{
				node* e2=dequeue(q);//完全二叉树的节点最后一层的节点从左至右不会出现NULL节点
				if (e2!=NULL)
				{
					return false;
				}
			}
		}
	}
	return true;
}

void exchange_child(node* root){
	if (root!=NULL)
	{
		exchange_child(root->lchild);
		exchange_child(root->lchild);
		node* temp=root->lchild;
		root->lchild=root->rchild;
		root->rchild=temp;
	}
}

void hxfdg(node* root){
	node* p=root;
	stack* s;
	init_stack(&s);
	while (p||!is_empty_stack(s))
	{
		while (p)
		{
			push(s,p);
			p=p->lchild;
		}
		node* q=gettop(s);
		node* pre;
		if(q->rchild==NULL||pre==q->rchild){
			q=pop(s);
			printf("%c\n",q->data);
			pre=q;
			p=NULL;// 重要重要重要
		}else{
			p=q->rchild;
		}
	}
}

void level(node* root){
	queue* q;
	init_queue(&q);
	if (root)
	{
		enqueue(q,root);
		while (!isempty(q))
		{
			node* p=dequeue(q);
			printf("%c\n",p->data);
			if (p->lchild)
			{
				enqueue(q,p->lchild);
			}
			if (p->rchild)
			{
				enqueue(q,p->rchild);
			}
		}
	}
}

int tree_width(node* root){
	queue* q;
	init_queue(&q);
	if (root)
	{
		root->level=1;
		enqueue(q,root);
		while (!isempty(q))
		{
			node* p=dequeue(q);
			if (p->lchild)
			{
				p->lchild->level=p->level+1;
				enqueue(q,p->lchild);
			}
			if (p->rchild)
			{
				p->rchild->level=p->level+1;
				enqueue(q,p->rchild);
			}
		}

		int i=0;
		int max=0;
		int n;
		int level;
		while (i<=q->rear)
		{
			n=0;
			level=q->ele[i]->level;
			while (i<=q->rear&&q->ele[i]->level==level)
			{
				n++;
				i++;
			}
			if (n>max)
			{
				max=n;
			}
		}
		return max;
	}
	return 0;
}

/************************************************************************/
/* 二叉树宽度2                                                                     */
/************************************************************************/

int tree_width2(node* root){
	queue* q;
	init_queue(&q);
	enqueue(q,root);
	node* p;
	node* last_node=root;
	node* new_last_node;
	int width=0;
	int maxwidth=1;
	while (!isempty(q))
	{
		p=dequeue(q);
		if (p->lchild)
		{
			enqueue(q,p->lchild);
			width++;
			new_last_node=p->lchild;
		}
		if (p->rchild)
		{
			enqueue(q,p->rchild);
			width++;
			new_last_node=p->rchild;
		}
		/**
		 * 上一层的最后一个节点作为当前节点的父节点时则 当前节点也是此层的最后一个节点
		 */
		if (last_node==p)
		{
			printf("%c\n",p->data);
			last_node=new_last_node;
			if (maxwidth<width)
			{
				maxwidth=width;
			}
			width=0;
		}
	}
	return maxwidth;
}

/************************************************************************/
/* 打印每一层最后一个节点                                                                     */
/************************************************************************/
void level_last(node* root){
	queue* q;
	init_queue(&q);
	enqueue(q,root);
	node* p;
	node* last_node=root;
	node* new_last_node;
	while (!isempty(q))
	{
		p=dequeue(q);
		if (p->lchild)
		{
			enqueue(q,p->lchild);
			new_last_node=p->lchild;
		}
		if (p->rchild)
		{
			enqueue(q,p->rchild);
			new_last_node=p->rchild;
		}
		if (last_node==p)
		{
			printf("%c\n",p->data);
			last_node=new_last_node;
		}
	}
}

void copy(stack* s,char* list){
	 for (int i=0;i<=s->top;i++)
	 {
		 list[i]=s->ele[i]->data;
	 }
}


/************************************************************************/
/* 求公共的最近祖先                                                                     */
/************************************************************************/
char common_parent(node* root,char a,char b){
	node* p=root;
	stack* s;
	init_stack(&s);
	char a_list[MAX_SIZE];
	char b_list[MAX_SIZE];
	while (p||!is_empty_stack(s))
	{
		while (p)
		{
			push(s,p);
			p=p->lchild;
		}
		node* q=gettop(s);
		node* pre;
		if(q->rchild==NULL||pre==q->rchild){
			q=pop(s);
			if(q->data==a){
				copy(s,a_list);
			}
			if(q->data==b){
				copy(s,b_list);
			}
			pre=q;
			p=NULL;
		}else{
			p=q->rchild;
		}
	}
	int idx=0;
	while (a_list[idx]==b_list[idx])
	{
		idx++;
	}
	return a_list[idx-1];
}


/************************************************************************/
/* 删除x值的子树                                                                     */
/************************************************************************/

void del_tree(node* root){
	if (root->lchild)
	{
		del_tree(root->lchild);
		root->lchild=NULL;
	}
	if (root->rchild)
	{
		del_tree(root->rchild);
		root->rchild=NULL;
	}
	free(root);
}

void del_x(node* root,char x){
	node* p=root;
	stack* s;
	init_stack(&s);
	node* pre=NULL;
	node* q=NULL;
	node* parent;
	while (p||!is_empty_stack(s))
	{
		while (p)
		{
			push(s,p);
			p=p->lchild;
		}
		q=gettop(s);
		if (q->rchild==NULL||q->rchild==pre)
		{
			q=pop(s);
			if (q->data==x)
			{
				parent=gettop(s);
				if (parent->lchild==q)
				{
					parent->lchild=NULL;
				}
				if (parent->rchild==q)
				{
					parent->rchild=NULL;
				}
				free(q);
			}
			pre=q;
			p=NULL;

			
		}else{
			p=q->rchild;
		}

	}



}

/************************************************************************/
/* 打印表达式                                                                     */
/************************************************************************/

void express(node* root,int level){
	if (root==NULL)
	{
		return;
	}
	else if (!root->lchild&&!root->rchild)
	{
		printf("%c",root->data);
	}else{
		if (level>1)
		{
			printf("%c",'(');
		}
		express(root->lchild,level+1);
		printf("%c",root->data);
		express(root->rchild,level+1);
		if (level>1)
		{
			printf("%c",')');
		}
	}
	
	
}

node* copy_tree(node* root){
	if(!root){
		return NULL;
	}
	node* newroot=(node*)malloc(sizeof(node));
	queue* q1;
	queue* q2;
	init_queue(&q1);
	init_queue(&q2);
	enqueue(q1,root);
	enqueue(q2,newroot);
	node* p;
	node* q;
	while (!isempty(q1))
	{
		p=dequeue(q1);
		q=dequeue(q2);
		q->data=p->data;
		if (p->lchild)
		{
			enqueue(q1,p->lchild);
			q->lchild=(node*)malloc(sizeof(node));
			enqueue(q2,q->lchild);
		}else{
			q->lchild=NULL;
		}

		if (p->rchild)
		{
			enqueue(q1,p->rchild);
			q->rchild=(node*)malloc(sizeof(node));
			enqueue(q2,q->rchild);
		}else{
			q->rchild=NULL;
		}

	}
	return newroot;
	

}





int main(){

	//CaculateWeekDay(2019,9,18);



	/*node* root;
	create_tree(&root);
	printf("开始打印树:\n");
	pre_print(root);
	getchar();//过滤掉回车符
	printf("请输入需要删除的节点:\n");
	char x;
	scanf("%c",&x);
	del_x(root,x);
	printf("开始打印树:\n");
	pre_print(root);*/

	//express(root,1);
	

	/*char a;
	char b;
	getchar();
	printf("请输入第一个节点值:\n");
	scanf("%c",&a);
	getchar();
	printf("请输入第二个节点值:\n");
	scanf("%c",&b);
	char c=common_parent(root,a,b);
	printf("两个节点最近公共节点值:%c\n",c);*/


	//level_last(root);

	/*int width=tree_width(root);
	printf("该树的宽度是:%d",width);*/
	
	/*printf("按层打印树:\n");
	level(root);*/



	/*printf("后续非递归:\n");
	hxfdg(root);*/



	/*exchange_child(root);
	printf("开始打印树:\n"); 
	pre_print(root);*/

	/*queue* q;
	init_queue(&q);
	if(is_full_tree(root,q)){
		printf("是完全二叉树");
	}else{
		printf("不是完全二叉树");
	}*/
	

	node* root;
	create_tree(&root);
	printf("开始打印树:\n");
	pre_print(root);
	/*node* newroot=copy_tree(root);
	printf("开始打印拷贝树:\n");
	pre_print(newroot);*/
	int max=tree_width2(root);
	printf("树的宽度是:%d",max);

    return 0;

	


}
