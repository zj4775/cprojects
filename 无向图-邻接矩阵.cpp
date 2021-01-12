#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX 65535

typedef struct graph 
{
	int vertex;
	int edge;
	int ele[MAX_SIZE][MAX_SIZE];
}graph;

typedef struct {
	int ele[MAX_SIZE];
	int top;
}stack;

typedef struct{
	int ele[MAX_SIZE];
	int front;
	int rear;
}queue;

bool is_queue_empty(queue* q){
	if (q->front==q->rear)
	{
		return true;
	}
	return false;
}

bool is_queue_full(queue* q){
	if ((q->rear+1)%MAX_SIZE==q->front)
	{
		return true;
	}
	return false;
}

void init_queue(queue** q){
	*q=(queue*)malloc(sizeof(queue));
	(*q)->front=-1;
	(*q)->rear=-1;
}

void enqueue(queue* q,int x){
	if (is_queue_full(q))
	{
		exit(1);
	}
	q->rear=(q->rear+1)%MAX_SIZE;
	q->ele[q->rear]=x;
}

int dequeue(queue* q){
	if (is_queue_empty(q))
	{
		exit(1);
	}
	q->front=(q->front+1)%MAX_SIZE;
	return q->ele[q->front];
}

void init_stack(stack** s){
	*s=(stack*)malloc(sizeof(stack));
	(*s)->top=-1;
}

bool is_stack_empty(stack* s){
	if (s->top==-1)
	{
		return true;
	}
	return false;
}

bool is_stack_full(stack* s){
	if (s->top==MAX_SIZE)
	{
		return true;
	}
	return false;
}

void push(stack* s,int x){
	if (is_stack_full(s))
	{
		exit(1);
	}
	s->ele[++s->top]=x;
}

int pop(stack* s){
	if (is_stack_empty(s))
	{
		exit(1);
	}
	return s->ele[s->top--];
}

void print_edge(graph* g,int from,int to){
	printf("访问边%d->%d:%d\n",from,to,g->ele[from][to]);
}

int get_first_neighbor(graph* g,int v){
	for (int i=0;i<g->vertex;i++)
	{
		if (i!=v&&g->ele[v][i]!=MAX)
		{
			return i;
		}
	}
	return -1;
}

int get_next_neighbor(graph* g,int v,int b){
	for (int i=b+1;i<g->vertex;i++)
	{
		if (i!=v&&g->ele[v][i]!=MAX)
		{
			return i;
		}
	}
	return -1;
}



void init_graph(graph** g){
	*g=(graph*)malloc(sizeof(graph));
	(*g)->edge=0;
	(*g)->vertex=0;
	for (int i=0;i<MAX_SIZE;i++)
	{
		for (int j=0;j<MAX_SIZE;j++)
		{
			(*g)->ele[i][j]=MAX;
		}
	}
}

void print_graph(graph* g){
	for(int i=0;i<g->vertex;i++)
	{
		for (int j=0;j<g->vertex;j++)
		{
			if (g->ele[i][j]!=MAX)
			{
				printf("%d   ",g->ele[i][j]);
			}else{
				printf("%s","∞  ");
			}
		}
		printf("\n\n");
	}
}

void create_graph(graph* g){
	printf("请输入节点个数:\n");
	scanf("%d",&(g->vertex));
	getchar();
	printf("请输入边个数:\n");
	scanf("%d",&(g->edge));
	int from=0;
	int to=0;
	int weight=0;
	for (int i=0;i<g->edge;i++)
	{
		printf("请输入边:\n");
		scanf("%d-%d-%d",&from,&to,&weight);
		g->ele[from-1][to-1]=weight;
		g->ele[to-1][from-1]=weight;
	}

}

/************************************************************************/
/* 递归深度                                                                     */
/************************************************************************/
void dfs(graph* g,int x,int pre,int visited[MAX_SIZE]){
	for (int i=0;i<g->vertex;i++)
	{
		if (x!=i&&i!=pre&&visited[i]==0&&g->ele[x][i]!=MAX)
		{
			print_edge(g,x,i);
			visited[i]=1;
			dfs(g,i,x,visited);
		}
	}
}
/************************************************************************/
/* 非递归深度                                                                     */
/************************************************************************/


void dfs_fdg(graph* g,int v,int pre,int visited[MAX_SIZE]){
	stack* s;
	init_stack(&s);
	push(s,v);
	int x;
	visited[0]=1;
	while (!is_stack_empty(s))
	{
		x= pop(s);
		printf("%d\n",x);
		for (int i=0;i<g->vertex;i++)
		{
			if (x!=i&&i!=pre&&visited[i]==0&&g->ele[x][i]!=MAX)
			{
				visited[i]=1;
				push(s,i);
			}
		}
		pre=x;
	}
}



void is_tree(graph* g,int x,int* vcount,int* ecount,int visited[MAX_SIZE]){

	visited[x]=1;
	(*vcount)++;
	int p=get_first_neighbor(g,x);
	while (p!=-1)
	{
		(*ecount)++;
		if (visited[p]==0)
		{
			is_tree(g,p,vcount,ecount,visited);
		}
		p=get_next_neighbor(g,x,p);
	}

}

/************************************************************************/
/* 非递归广度                                                                     */
/************************************************************************/

void bfs(graph* g,int x){
	queue* q;
	init_queue(&q);
	enqueue(q,x);
	int p;
	int visited[MAX_SIZE]={0};
	visited[x]=1;
	while (!is_queue_empty(q))
	{
		p=dequeue(q);
		printf("%d\n",p);
		int w=get_first_neighbor(g,p);
		while (w!=-1)
		{
			if (visited[w]==0)
			{
				visited[w]=1;
				enqueue(q,w);
			}
			w=get_next_neighbor(g,p,w);
		}
	}
}

int main(){
	graph* g=NULL;
	init_graph(&g);
	create_graph(g);
	print_graph(g);
	int visited[MAX_SIZE]={0};
	memset(visited,0,MAX_SIZE*sizeof(int));
	//dfs(g,0,-1,visited);
	//dfs_fdg(g,0,-1,visited);
	int vcount=0;
	int ecount=0;
	is_tree(g,0,&vcount,&ecount,visited);
	if (ecount==2*(vcount-1))
	{
		printf("可以构成树");
	}else{
		printf("不可以构成树");
	}
	//bfs(g,0);
    return 0;

}