#include<stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct node 
{
	char data;
	node* first;
	node* next;
}node;

void create_tree(node** root,char* data,int* degree,int n){
	node** temp=(node**)malloc(sizeof(node)*n);
	int i;
	int j;
	for (i=0;i<n;i++)
	{
		temp[i]=(node*)malloc(sizeof(node));
		temp[i]->data=data[i];
		temp[i]->first=NULL;
		temp[i]->next=NULL;
	}

	int index=0;
	int d;
	for (i=0;i<n;i++)
	{
		d=degree[i];
		if (d>0)
		{
			index++;
			temp[i]->first=temp[index];
			for (j=1;j<d;j++)
			{
				index++;
				temp[index-1]->next=temp[index];
			}
			
		}
	}
	*root=temp[0];
	for (j=0;j<n;j++)
	{
		printf("%c  ",temp[j]->data);
	}
}

int main(){
	node* root;
	char* data="abcdefghi";
	int degree[MAX_SIZE]={3,3,2,0,0,0,0,0,0};
	create_tree(&root,data,degree,9);
    return 0;
}