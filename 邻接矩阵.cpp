#include<stdio.h>
#include<string.h>
#include<sys/malloc.h>
#define MAX_NUM 10
#define INFINITY 65535
typedef struct matrixgraph{
	int vertexnum;
	int edgenum;
	int ele[MAX_NUM][MAX_NUM];
}matrixgraph;

typedef struct queue{
	int head;
	int tail;
	int ele[MAX_NUM];
}queue;

typedef struct edge{
	int from;
	int to;
	int weight;
}edge;

typedef struct node{
	int idx;
	int weight;
}node;

void init_queue(queue** q){
	*q=(queue*)malloc(sizeof(queue));
	(*q)->head=0;
	(*q)->tail=0;
}

bool isempty(queue* q){
	return q->head==q->tail?true:false;
}

bool isfull(queue* q){
	return q->tail==MAX_NUM-1?true:false;
}

bool enqueue(queue* q,int v){
	if (isfull(q))
	{
		printf("FULL");
		return false;
	}
	q->ele[q->tail]=v;
	q->tail++;
	return true;

}
bool dequeue(queue* q,int* v){
	if (isempty(q))
	{
		printf("EMPTY");
		return false;
	}
	*v=q->ele[q->head];
	q->head++;
	return true;
	
}




void init(matrixgraph* graph){
	graph->vertexnum=0;
	graph->edgenum=0;
	for (int i=0;i<MAX_NUM;i++)
	{
		for (int j=0;j<MAX_NUM;j++)
		{
			graph->ele[i][j]=INFINITY;
		}
	}
	
}



void create(matrixgraph** graph){
	*graph=(matrixgraph*)malloc(sizeof(matrixgraph));
	init(*graph);
	matrixgraph* g=*graph;
	printf("������ڵ����:\n");
	scanf("%d",&(g->vertexnum));
	printf("������ߵ�����:\n");
	scanf("%d",&(g->edgenum));

	int from;
	int to;
	int weight;
	for (int i=0;i<g->edgenum;i++)
	{
		printf("�������%d���ߵ���Ϣ:\n",i+1);
		scanf("%d-%d-%d",&from,&to,&weight);
		(*graph)->ele[from-1][to-1]=weight;//�����from�ʹ�0��ʼ�����
	}
}

void print(matrixgraph* graph){
	for (int i=0;i<graph->vertexnum;i++)
	{
		for (int j=0;j<graph->vertexnum;j++)
		{
			if (graph->ele[i][j]!=INFINITY)
			{
				printf("%2d   ",graph->ele[i][j]);
			}else{
				printf("��   ");
			}
			
		}
		printf("\n");
	}
}
/************************************************************************/
/* ��ȱ���                                                                     */
/************************************************************************/

void dfs(matrixgraph* graph,int idx,int visited[]){
	printf("%d  ",idx);
	for (int i=0;i<MAX_NUM;i++)
	{
		if (i!=idx&&graph->ele[idx][i]!=INFINITY&&visited[i]==0)
		{
			visited[i]=1;
			dfs(graph,i,visited);
		}
	}
}

/************************************************************************/
/* �ж�һ��ͼ�Ƿ���Թ�����(һ�α����Ϳ��Է��ʵ����е�n���ڵ��n-1����)                                                                     */
/************************************************************************/

/*void dfs2(matrixgraph* graph,int idx,int visited[],int* vertexnum,int* edgenum){
	for (int i=0;i<MAX_NUM;i++)
	{
		if (i!=idx&&graph->ele[idx][i]!=INFINITY)
		{
			*edgenum++;
			if (visited[i]==0)
			{
				visited[i]=1;
				*vertexnum++;
				dfs(graph,i,visited,vertexnum,edgenum);
			}
		}
		
	}
}*/

/*bool is_tree(matrixgraph* graph){
	int first=0;
	int visited[MAX_NUM]={0};
	int vertexnum=0;
	int edgenum=0;

}*/

bool has_cycle(matrixgraph* graph,int idx,int visited[]){
	for (int i=0;i<MAX_NUM;i++)
	{
		if (i!=idx&&graph->ele[idx][i]!=INFINITY)
		{
			if (visited[i]==0)
			{
				visited[i]=1;
				dfs(graph,i,visited);
			}else{
				return false;
			}
			
		}
	}
	return true;
}

/************************************************************************/
/* ��ȱ���                                                                     */
/************************************************************************/

void bfs(matrixgraph* graph,queue* q,int visited[]){
	int res;
	while (!isempty(q))
	{
		dequeue(q,&res);
		printf("%d  ",res);
		for (int i=0;i<MAX_NUM;i++)
		{
			if (i!=res&&graph->ele[res][i]!=INFINITY&&visited[i]==0)
			{
				enqueue(q,i);
			}
		}

	}
	
}

/************************************************************************/
/* prim�㷨,�����ӵ� ��С������                                                               */
/************************************************************************/

void prim(matrixgraph* graph){
	printf("��ʼprim��С������\n");
	int i,j,k,min;
	int adjvex[MAX_NUM];
	int lowcost[MAX_NUM];
	for (i=1;i<graph->vertexnum;i++)
	{
		adjvex[i]=0;
		lowcost[i]=graph->ele[0][i];
	}
	for (i=1;i<graph->vertexnum;i++)
	{
		min=INFINITY;
		j=1;
		k=0;
		while (j<graph->vertexnum)
		{ 
			if (lowcost[j]!=0&&lowcost[j]<min)//���������С�Ľڵ�ֵ
			{
				min=lowcost[j];
				k=j;
			}
			j++;
		}
		printf("\n%d-%d-%d\n",adjvex[k],k,min);
		lowcost[k]=0;
		j=1;
		while (j<graph->vertexnum)
		{
			if (lowcost[j]!=0&&graph->ele[k][j]<lowcost[j])//��k�ڵ����ʱ��ʣ��������ڵ���̾�����ܻ�ı�
			{
				lowcost[j]=graph->ele[k][j];
				adjvex[j]=k;
			}
			j++;
		}
	}
}

/************************************************************************/
/*kruskal,�����ӱ�   ��С������                                                                  */
/************************************************************************/

void convert(matrixgraph* graph,edge* edges){
	
	int k=0;
	for (int i=0;i<graph->vertexnum;i++)
	{
		for (int j=0;j<graph->vertexnum;j++)
		{
			if (i!=j&&graph->ele[i][j]!=INFINITY)
			{
				edges[k].from=i;
				edges[k].to=j;
				edges[k].weight=graph->ele[i][j];
				k++;
			}
		}
	}
}

void sort(edge* edges,int length){
	for (int i=length-1;i>0;i--)
	{
		for (int j=0;j<i;j++)
		{
			if (edges[i].weight<edges[j].weight)
			{
				edge temp=edges[i];
				edges[i]=edges[j];
				edges[j]=temp;
			}
		}
	}
} 

int getroot(int* vend,int from){
	while (vend[from]!=-1)
	{
		from=vend[from];
	}
	return from;
}


void kruskal(matrixgraph* graph){
	printf("��ʼkruskal��С������\n");
	int* vend;
	int i,k,from,to,fromroot,toroot;
	vend=(int*)malloc(sizeof(int)*graph->vertexnum);
	for (i=0;i<graph->vertexnum;i++)
	{
		vend[i]=-1;
	}
	//memset(vend,-1,sizeof(vend));
	edge* edges;
	edge* path;
	edges=(edge*)malloc(sizeof(edge)*graph->edgenum);
	path=(edge*)malloc(sizeof(edge)*graph->edgenum);
	int count=0;
	convert(graph,edges);
	sort(edges,graph->edgenum);
	for (k=0;k<graph->edgenum;k++)
	{
		from=edges[k].from;
		to=edges[k].to;
		fromroot=getroot(vend,from);
		toroot=getroot(vend,to);
		if (fromroot!=toroot)
		{
			vend[to]=from;
			path[count++]=edges[k];
			//printf("\n%d-%d-%d\n",from,to,edges[k].weight);
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

void print_path(int parent[MAX_NUM],int s,int c){
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
/* ���·��                                                          */
/************************************************************************/
void dijkstra(matrixgraph* graph,int s){
	int visited[MAX_NUM]={0};
	int parent[MAX_NUM]={0};
	int top=-1;
	node d[MAX_NUM];
	int i;
	int j;
	for (i=0;i<graph->vertexnum;i++)
	{
		d[i].idx=i;
		if (i!=s&&graph->ele[s][i]!=INFINITY)
		{
			d[i].weight=graph->ele[s][i];
			parent[i]=s;
		}else{
			d[i].weight=INFINITY;
		}
	}
	visited[s]=1;
	for(i=0;i<graph->vertexnum;i++)
	{
		int min=INFINITY;
		int k=s;
		for (j=0;j<graph->vertexnum;j++)
		{
			if (visited[j]==0&&d[j].weight<min)
			{
				min=d[j].weight;
				k=j;
			}
		}
		visited[k]=1;
		//���µ��ڵ������ڵ��Ȩֵ
		for (j=0;j<graph->vertexnum;j++)
		{
			if (visited[j]==0)
			{
				if (d[j].weight>d[k].weight+graph->ele[k][j])//�����Ȩ��ֵ����Ҫ����֮ǰ��������ֵ
				{
					d[j].weight=d[k].weight+graph->ele[k][j];
					parent[j]=k;
				}
			}
		}
	}
	//��ӡ
	for (i=0;i<graph->vertexnum;i++)
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
	matrixgraph* graph;
	create(&graph);
	//print(graph);
	
	/*int visited[MAX_NUM]={0};
	printf("\n��ʼ��ȱ���\n");
	dfs(graph,0,visited);
	memset(visited,0,sizeof(int)*MAX_NUM);
	queue* q;
	init_queue(&q);
	printf("\n��ʼ��ȱ���\n");
	enqueue(q,0);
	bfs(graph,q,visited);*/
	
	//prim(graph);
	//kruskal(graph);
	/*int visited[MAX_NUM]={0};
	bool res= has_cycle(graph,1,visited);
	if (res)
	{
		printf("�޻�");
	}else{
		printf("�л�");
	}*/
	dijkstra(graph,0);
    return 0;
}