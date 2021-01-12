#include<stdio.h>
#include<sys/malloc.h>
#include<stdlib.h>

const int CAPACITY =20;



typedef struct node{
	char data;
    node* lchild;
	node* rchild;
}node;

typedef struct stack{
	int top;
	node* ele[CAPACITY];
}stack;

void push(stack* s,node* p){
	if(s->top==CAPACITY-1){
		return;
	}
	s->top+=1;
	s->ele[s->top]=p;
}

node* pop(stack* s){
	if(s->top==-1){
		return NULL;
	}
	node* res=s->ele[s->top];
	s->top-=1;
	return res;
}

node* gettop(stack* s){
	if(s->top==-1){
		return NULL;
	}
	node* res=s->ele[s->top];
	return res;
}

void init(stack** s){
	*s=(stack*)malloc(sizeof(stack));
	(*s)->top=-1;
}
bool isempty(stack* s){
	if(s->top==-1){
		return true;
	}
	return false;
}

int equal(node* a,node* b){
	if(a->data==b->data){
		return 1;
	}
	return 0;
}




void create_tree(node** R){

	char c=getchar();
	if(c!='#'){
       *R=(node*)malloc(sizeof(node)); 
	   (*R)->data=c;
	   (*R)->lchild=NULL;
	   (*R)->rchild=NULL;
	   create_tree(&((*R)->lchild));
	   create_tree(&((*R)->rchild));

	}
}

void print_tree_xxdg(node* R){
	
	if(R!=NULL){
		printf("%c\n",R->data);
		print_tree_xxdg(R->lchild);	
		print_tree_xxdg(R->rchild);
	}
}

void print_tree_xxfdg(node* R){

	node* p=R;
	stack* s;
	init(&s);
	while(p||!isempty(s)){
		while(p){
			printf("%c\n",p->data);
			push(s,p);
			p=p->lchild;
		}
		node* q= pop(s);
		p=q->rchild;
		
	}
	
}

void print_tree_zxdg(node* R){
	
	if(R!=NULL){
		print_tree_zxdg(R->lchild);
		printf("%c\n",R->data);
		print_tree_zxdg(R->rchild);
	}
}

void print_tree_zxfdg(node* R){
	node* p=R;
	stack* s;
	init(&s);
	while(p||!isempty(s)){
		while(p){
			push(s,p);
			p=p->lchild;
		}
		node* q= pop(s);
		printf("%c\n",q->data);
		p=q->rchild;
		
	}
	
}

void print_tree_hxdg(node* R){
	
	if(R!=NULL){
		print_tree_hxdg(R->lchild);
		print_tree_hxdg(R->rchild);
		printf("%c\n",R->data);
	}
}

void print_tree_hxfdg(node* R){
	node* p=R;
	stack* s;
	node* pre=NULL;
	init(&s);
	while(p||!isempty(s)){
		while(p){
			push(s,p);
			p=p->lchild;
		}
		node* q= gettop(s);
		if(q->rchild==NULL||q->rchild==pre){
			q=pop(s);
			printf("%c\n",q->data);
			pre=q;
			p=NULL;//这里很重要,一旦右子树打印了，那么他的父节点下一次肯定会打印

		}else{
			p=q->rchild;

		}
	}
	
}

void print_stack(stack* s){
	while(!isempty(s)){
		node* a=pop(s);
		printf("%c\n",a->data);
	}
}

void search(node* R,node* r){
	node* p=R;
	stack* s;
	node* pre=NULL;
	init(&s);
	while(p||!isempty(s)){
		while(p){
			push(s,p);
			p=p->lchild;
		}
		node* q= gettop(s);
		if(q->rchild==NULL||q->rchild==pre){
			q=pop(s);
			if(equal(q,r)==1){
				print_stack(s);
			}else{
				pre=q;
				p=NULL;//这里很重要,一旦右子树打印了，那么他的父节点下一次肯定会打印
			}	
			
		}else{
			p=q->rchild;
			
		}



		


		/*if(equal(q,r)==1){
			print_stack(s);
		}else{
			p=q->rchild;
		}*/
		
		
	}
	
}



int main(){
	node* root;
	create_tree(&root);
	/*printf("先序递归处理\n");
	print_tree_xxdg(root);
	printf("先序非递归处理\n");
	print_tree_xxfdg(root);
	printf("中序递归处理\n");
	print_tree_zxdg(root);
	printf("中序非递归处理\n");
	print_tree_zxfdg(root);
	printf("后序递归处理\n");
	print_tree_hxdg(root);
	printf("后序非递归处理\n");
	print_tree_hxfdg(root);*/
	printf("请输入需要查找的节点值\n");
	char c=getchar();
	c=getchar();
	node* r=(node*)malloc(sizeof(node));
	r->data=c;
	printf("查找的节点的父节点\n");
	search(root,r);
    return 0;

}