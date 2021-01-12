#include<stdio.h>
#include<stdlib.h>
#include <string.h>
const int VERTEX_NUM=100;
#define INFINITE 65535

typedef struct edgenode{
	int adjvex;
	edgenode* next;
	int weight;
}edgenode;

typedef struct vertexnode{
	int idx;
	edgenode* firstedge;
}vertexnode;

typedef struct adjlistgraph{
	int vertex_num;
	int edge_num;
	vertexnode vertexinfo[VERTEX_NUM];
}adjlistgraph;

typedef struct edge{
	int from;
	int to;
	int weight;
}edge;

typedef struct node{
	int idx;
	int weight;
}node;

/************************************************************************/
/* ջ                                                                     */
/************************************************************************/
typedef struct stack{
	int top;
	vertexnode ele[VERTEX_NUM];
	
}stack;

void init_stack(stack** s){
	*s=(stack*)malloc(sizeof(stack));
	(*s)->top=-1;
	
}

void push(stack* s,vertexnode node){
	if (s->top==VERTEX_NUM-1)
	{
		return;
	}
	s->top++;
	s->ele[s->top]=node;
}

vertexnode pop(stack* s){
	if (s->top==-1)
	{
		exit(0);
	}
	vertexnode res=s->ele[s->top];
	s->top--;
	return res;
}

bool isempty(stack* s){
	return s->top==-1?true:false;
}

/************************************************************************/
/* ����(����)                                                                     */
/************************************************************************/
typedef struct queue{
	int head;
	int tail;
	vertexnode ele[VERTEX_NUM];
}queue;

void init_queue(queue** q){
	*q=(queue*)malloc(sizeof(queue));
	(*q)->head=-1;
	(*q)->tail=-1;
}

void enqueue(queue* q,vertexnode node){
	if ((q->tail+1)%VERTEX_NUM==q->head)
	{
		exit(1);
	}
	q->ele[++q->tail]=node;
}

vertexnode dequeue(queue* q){
	if (q->head==q->tail)
	{
		exit(0);
	}
	return q->ele[++q->head];
}
bool isempty_queue(queue* q){
	return q->head==q->tail?true:false;
}




void visit(vertexnode node){
	printf("%d\n",node.idx);
	
}

/************************************************************************/
/* ��ȱ���                                                                     */
/************************************************************************/

void bfs(adjlistgraph* graph){
	printf("��ʼ��ȱ���ͼ:\n");
	int firstvertex=0;
	int visited[VERTEX_NUM]={0};
	queue* q;
	init_queue(&q);
	enqueue(q,graph->vertexinfo[0]);
	while(!isempty_queue(q)){
		vertexnode node= dequeue(q);
		visit(node);
		visited[node.idx]=1;
		edgenode* p=graph->vertexinfo[node.idx].firstedge;
		while(p){
			if (visited[p->adjvex]==0)
			{
				enqueue(q,graph->vertexinfo[p->adjvex]);
			}
			p=p->next;
		}
	}

}

/************************************************************************/
/* ��ȱ���                                                                     */
/************************************************************************/
void dfs(adjlistgraph* graph,int idx,int visited[]){
	visit(graph->vertexinfo[idx]);
	edgenode* p=graph->vertexinfo[idx].firstedge;
	while (p)
	{
		if (visited[p->adjvex]==0)
		{
			dfs(graph,p->adjvex,visited);
		}
		p=p->next;
	}
}

void deep(adjlistgraph* graph){//�ݹ�
	printf("��ʼ��ȱ���ͼ:\n");
	int firstvertex=0;
	int visited[VERTEX_NUM]={0};
	dfs(graph,0,visited);
	
}

void deep_fdg(adjlistgraph* graph,int idx){
	stack* s;
	init_stack(&s);
	int visited[VERTEX_NUM]={0};
	push(s,graph->vertexinfo[idx]);
	while(!isempty(s)){
		vertexnode node= pop(s);
		visit(node);
		visited[node.idx]=1;
		edgenode* p=graph->vertexinfo[node.idx].firstedge;
		while(p){
			if (visited[p->adjvex]==0)
			{
				push(s,graph->vertexinfo[p->adjvex]);
			}
			p=p->next;
		}
	}
}


void deepsearch_fdg(adjlistgraph* graph){//�ǵݹ�
	printf("��ʼ�ǵݹ���ȱ���ͼ:\n");
	deep_fdg(graph,0);
}

/************************************************************************/
/* �ж������Ƿ���ͨ ���(��ӡ����·����)                                                                     */
/************************************************************************/

void print_path(int path[VERTEX_NUM],int d){
	printf("·���ҵ���:\n");
	for (int i=0;i<d;i++)
	{
		printf("%d-->",path[i]+1);
	}
	printf("\n");
}

void find_path(adjlistgraph* graph,int from,int to,int path[VERTEX_NUM],int d,int visited[VERTEX_NUM]){
	path[d++]=from;
	visited[from]=1;
	if (from==to)
	{
		print_path(path,d);
	}
	edgenode* p=graph->vertexinfo[from].firstedge;
	while (p!=NULL)
	{
		int w=p->adjvex;
		if (visited[w]==0)
		{
			find_path(graph,w,to,path,d,visited);
		}
		p=p->next;
	}
	visited[from]=0; //������Ҫ�����ʵĽڵ㻹����
}


/************************************************************************/
/* �ж������Ƿ���ͨ����ȣ�                                                                     */
/************************************************************************/

bool is_connect(adjlistgraph* graph,int from,int to){
	if (from==to)
	{
		return true;
	}
	int visited[VERTEX_NUM];
	memset(visited,0,VERTEX_NUM);
	queue* q;
	init_queue(&q);
	enqueue(q,graph->vertexinfo[from-1]);
	while(!isempty_queue(q)){
		vertexnode nd= dequeue(q);
		edgenode* p=nd.firstedge;
		while (p!=NULL)
		{
			if (visited[p->adjvex]==0)
			{
				if (p->adjvex==to-1)
				{
					return true;
				}else{
					enqueue(q,graph->vertexinfo[p->adjvex]);
				}
			}
			p=p->next;
		}
	}
	return false;
}


/************************************************************************/
/* ��������                                                                     */
/************************************************************************/

void toposort(adjlistgraph* graph){
	int path[VERTEX_NUM];
	int count=0;
	int i;
	int indegree[VERTEX_NUM]={0};
	edgenode* p;
	stack* s;
	init_stack(&s);
	//��������ڵ�����
	for (i=0;i<graph->vertex_num;i++)
	{
		p=graph->vertexinfo[i].firstedge;
		while (p!=NULL)
		{
			indegree[p->adjvex]++;
			p=p->next;
		}
	}

	for (i=0;i<graph->vertex_num;i++)
	{
		if (indegree[i]==0)
		{
			push(s,graph->vertexinfo[i]);
		}
	}

	while (!isempty(s))
	{
		vertexnode v=pop(s);
		path[count++]=v.idx;
		p=graph->vertexinfo[v.idx].firstedge;
		while (p!=NULL)
		{
			indegree[p->adjvex]--;
			if (indegree[p->adjvex]==0)
			{
				push(s,graph->vertexinfo[p->adjvex]);
			}
			p=p->next;
		}
	}
	if (count<graph->vertex_num)
	{
		printf("�޷���������\n");
	}else{
		printf("������������\n");
		print_path(path,count);
	}

}

/************************************************************************/
/* prim�㷨����С������ (�ӵ㷨)                                                                    */
/************************************************************************/
void prim(adjlistgraph* graph){
	int visited[VERTEX_NUM]={0};
	int cost[VERTEX_NUM]={0};
	int parent[VERTEX_NUM]={0};
	int path[VERTEX_NUM]={0};
	int count=0;
	visited[0]=1;
	int min=INFINITE;
	int i;
	int j;
	int k=0;
	for (i=0;i<graph->vertex_num;i++)
	{
		cost[i]=INFINITE;
	}
	//Ĭ�ϴ�0�ڵ㿪ʼ
	edgenode* edge= graph->vertexinfo[0].firstedge;
	while (edge!=NULL)
	{
		cost[edge->adjvex]=edge->weight;
		edge=edge->next;
	}
	for (i=0;i<graph->vertex_num-1;i++)
	{
		min=INFINITE;
		//�ѵ�ǰȨֵ��С�Ľڵ��ҵ�
		for (j=0;j<graph->vertex_num;j++)
		{
			if (cost[j]<min&&visited[j]==0)
			{
				min=cost[j];
				k=j;
			}
		}
		visited[k]=1;
		path[count++]=k;
		//���ڸ����ڵ����Сֵ(������һ����������������ڵ�ľ���Ҳ���ܻ���)
		edge= graph->vertexinfo[k].firstedge;
		while (edge!=NULL)
		{
			if (edge->weight<cost[edge->adjvex]&&visited[edge->adjvex]==0)
			{
				cost[edge->adjvex]=edge->weight;
				parent[edge->adjvex]=k;
			}
			edge=edge->next;
		}
	}
	printf("��ʼ��ӡ��С������\n");
	//��ӡ
	for (i=0;i<count;i++)
	{
		int idx=path[i];
		printf("%d-->%d\n",parent[idx]+1,idx+1);
	}
}

void convert(adjlistgraph* graph,edge* edges){
	int count=0;
	for (int i=0;i<graph->vertex_num;i++)
	{
		edgenode* p=graph->vertexinfo[i].firstedge;
		while (p!=NULL)
		{
			edges[count].from=i;
			edges[count].to=p->adjvex;
			edges[count].weight=p->weight;
			count++;
			p=p->next;
		}
	}
}
//ð����
void sort(edge* edges,int length){
	for (int i=length-2;i>=0;i--)
	{
		for (int j=0;j<=i;j++)
		{
			if (edges[j+1].weight<edges[j].weight)
			{
				edge tmp=edges[j+1];
				edges[j+1]=edges[j];
				edges[j]=tmp;
			}
		}
	}
}

int getroot(int* vend,int from){ //-1 �������ϵ������ڣ����ĵ�һ�����Ӿ���������
	while (vend[from]!=-1)
	{
		from=vend[from];
	}
	return from;
}

/************************************************************************/
/* �ӱ߷� ��³˹�����㷨                                              */
/************************************************************************/
void kruskal(adjlistgraph* graph){
	edge edges[VERTEX_NUM];
	convert(graph,edges);
	int vend[VERTEX_NUM]={0};
	int i;
	for (i=0;i<graph->vertex_num;i++)
	{
		vend[i]=-1;
	}
	int count=0;
	edge path[VERTEX_NUM];
	sort(edges,graph->edge_num);
	for (i=0;i<graph->edge_num;i++) //��һ��һ����
	{
		int from=edges[i].from;
		int to=edges[i].to;
		int root1=getroot(vend,from);//��������
		int root2=getroot(vend,to);//��������
		if (root1!=root2)//���������һ��˵�� ׼���¼ӵ������� �ò��ţ������Ϳɴ����͹��ɻ�·��
		{
			//parent[to]=from;
			vend[to]=from;
			//path[count++]=to;
			path[count++]=edges[i];
			
		}
	}

	printf("��ʼ��ӡ��С������\n");
	//��ӡ
	for (i=0;i<count;i++)
	{
		edge e=path[i];
		printf("%d-->%d\n",e.from+1,e.to+1);
	}

}



/************************************************************************/
/* ����ͼ                                                                     */
/************************************************************************/

void create_graph(adjlistgraph** graph){
	//char* verinfo;
	*graph=(adjlistgraph*)malloc(sizeof(adjlistgraph));
	printf("������ڵ�����:\n");
	scanf("%d",&((*graph)->vertex_num));
	for (int i=0;i<(*graph)->vertex_num;i++)
	{
		(*graph)->vertexinfo[i].idx=i;
		(*graph)->vertexinfo[i].firstedge=NULL;
	}

	printf("�����������:\n");
	scanf("%d",&((*graph)->edge_num));
	printf("������ߵ���Ϣ:\n");
	for (i=1;i<=(*graph)->edge_num;i++)
	{
		printf("�������%d���ߵ���Ϣ:\n",i);
		int from;
		int to;
		int weight;
		scanf("%d-%d-%d",&from,&to,&weight);//3��ֵ�ֱ��� ������ Ŀ�ĵ� Ȩ��
		edgenode* _edge=(edgenode*)malloc(sizeof(edgenode));
		_edge->adjvex=to-1;
		_edge->weight=weight;
		_edge->next=(*graph)->vertexinfo[from-1].firstedge;
		(*graph)->vertexinfo[from-1].firstedge=_edge;//ͷ��
	}
}

void print_path(int parent[VERTEX_NUM],int s,int c){
	if (s==c)
	{
		printf("%d->",s+1);
		return;
	}else{
		print_path(parent,s,parent[c]);
		printf("%d->",c+1);
	}
}

/************************************************************************/
/* �Ͻ�˹����   ����һ������������ڵ����·��                                                                  */
/************************************************************************/
void dijkstra(adjlistgraph* graph,int s){
	int visited[VERTEX_NUM]={0};
	int parent[VERTEX_NUM]={0};
	int top=-1;
	node d[VERTEX_NUM];
	int i;
	int j;
	for (i=0;i<graph->vertex_num;i++)
	{
		d[i].idx=i;
		d[i].weight=INFINITE;
	}
	edgenode* p= graph->vertexinfo[s].firstedge;
	while (p!=NULL)
	{
		d[p->adjvex].weight=p->weight;
		p=p->next;
	}

	visited[s]=1;
	for(i=0;i<graph->vertex_num;i++)
	{
		int min=INFINITE;
		int k=s;
		for (j=0;j<graph->vertex_num;j++)//�����С��Ȩֵ��
		{
			if (visited[j]==0&&d[j].weight<min)
			{
				min=d[j].weight;
				k=j;
			}
		}
		visited[k]=1;
		//���µ��ڵ������ڵ��Ȩֵ
		for (j=0;j<graph->vertex_num;j++)
		{
			if (visited[j]==0)
			{
				p=graph->vertexinfo[k].firstedge;
				while (p!=NULL)
				{
					if (d[p->adjvex].weight>d[k].weight+p->weight)
					{
						d[p->adjvex].weight=d[k].weight+p->weight;//�������prim�㷨��ͬ���ǣ�������Ҫ����ԭ�����������·������
						parent[p->adjvex]=k;//����ͬһ�������� ��˵ĳ���ڵ�ĸ��ڵ�����·���϶���Ψһ��(����·������һ����������Сֵ�϶���Ψһ��)
					}
					p=p->next;
				}
				
			}
		}
	}
	//��ӡ
	for (i=0;i<graph->vertex_num;i++)
	{
		printf("��ʼ��ӡ�ڵ�:%d\n",i+1);
		if (i!=s)
		{
			print_path(parent,s,i);
			printf("     Ȩ����:%d\n",d[i].weight);
		}
	}
	
}



int main(){
	adjlistgraph* g;
	create_graph(&g);
	//deepsearch_fdg(g);
	int path[VERTEX_NUM]={0};
	int visited[VERTEX_NUM]={0};
	//find_path(g,0,3,path,0,visited);
	//toposort(g);
	//prim(g);
	//kruskal(g);
	//dijkstra(g,0);


	
	int from;
	int to;
	printf("�����������:\n");
	scanf("%d",&from);
	printf("�������ս��:\n");
	scanf("%d",&to);

	while (from!=0)
	{
		bool flag=is_connect(g,from,to);
		if (flag==true)
		{
			printf("�����ڵ���ͨ");
		}else{
			printf("�����ڵ㲻��ͨ");
		}
		printf("�����������:\n");
		scanf("%d",&from);
		printf("�������ս��:\n");
		scanf("%d",&to);
	}
    return 0;

		


}

