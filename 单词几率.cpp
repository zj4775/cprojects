/*#include<stdio.h>
#include<string.h>
#include<sys/malloc.h>
typedef struct node
{
	char ch[10];
	int count;
	node *lchild;
	node *rchild;
}node,*tree;
void insert(tree *root,char str[])
{
	node *p,*q=*root;
	//int flag;
	if(q==NULL)
	{
		p=(node *)malloc(sizeof(node));
		p->count=1;
		p->lchild=p->rchild=NULL;
		strcpy(p->ch,str);
		*root=p;
	}
	else if(strcmp(q->ch,str)>0){insert(&q->lchild,str);}
	else if(strcmp(q->ch,str)<0){insert(&q->rchild,str);}
	else{(q->count)++;}









	//else
	//{
		//flag=strcmp(q->ch,str);
		//if(flag==0){(q->count)++;}
		//if(flag>0){insert(&(q->lchild),str);}
		//else{insert(&(q->rchild),str);}
	//}
}
int count(node *root)
{

	if(!root){return 0;}
	else if(root->lchild==NULL&&root->rchild==NULL){return(root->count);}
	else{return(count(root->lchild)+count(root->rchild)+root->count);}

}
double js(node *root,char str[],int n)
{
	double k;
	//int flag;
	if(!root){printf("找不到");k=0;}
	else if(strcmp(root->ch,str)==0){printf("%d    ",root->count);printf("%d    ",n);k=(root->count)/n;printf("%d",(root->count)*100/n);}//与计算机位数有关不用太纠结
	else if(strcmp(root->ch,str)>0){k=js(root->lchild,str,n);}
	else{k=js(root->rchild,str,n);}
	return k;






	//else
	//{
		//flag=strcmp(root->ch,str);
		//if(flag==0){return((root->count)/n);}
		//else if(flag>0){return js(root->lchild,str,n);}
		//else{return js(root->rchild,str,n);}
	//}
}
void print(node *root)
{

	if(root!=NULL)
	{
		print(root->lchild);
		printf("%s-%d   ",root->ch,root->count);
		print(root->rchild);


	}


}
int main()
{
	tree root;
	root=(node *)malloc(sizeof(node));
	int n;
	double p;
	char str[10];
	gets(str);
	strcpy(root->ch,str);
	root->count=1;
	root->lchild=root->rchild=NULL;
	gets(str);
	while(strcmp(str,"#")!=0)
	{
		insert(&root,str);
		gets(str);

	}

	print(root);
	n=count(root);
	printf("\n%d",n);
	printf("请输入一个单词");
	gets(str);
	p=js(root,str,n);
	printf("该单词出现的几率为%f",p);
}*/












//用输入一个长的字符串来求单词个数
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N=0;
typedef struct  node
{
    char dc[10];
    int gs;
    node *lchild;
    node *rchild;
}node,*tree;
int zmm(char ch)
{
    if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z'){return 1;}
    else{return 0;}
}
void zh(char ls[],char s[100][10])
{
    int i=0,j=0,k=0,flag=0,leng=0,p=0;
    while(ls[k]!='#')
    {
        if(zmm(ls[k])){k++;flag=1;leng++;}
        else
        {
            if(flag)
            {
                flag=0;
                j=0;
                for(p=k-leng;zmm(ls[p]);p++)
                {
                    s[i][j++]=ls[p];
                }
                s[i][j]='\0';
                i++;
                leng=0;

            }
            k++;
        }

    }
    N=i-1;
    if(flag)
    {
        j=0;;
        for(p=k-leng;zmm(ls[p]);p++)
        {
            s[i][j++]=ls[p];
        }
        s[i][j]='\0';
        N=i;

    }


}
void insert(tree *root,char cc[])
{
    node *p;
    if((*root)==NULL)
    {
        p=(node *)malloc(sizeof(node));
        strcpy(p->dc,cc);
        p->gs=1;
        p->lchild=p->rchild=NULL;
        *root=p;
    }
    else
    {
        if(strcmp((*root)->dc,cc)==0){(*root)->gs++;}
        else if(strcmp((*root)->dc,cc)>0){insert(&((*root)->lchild),cc);}
        else{insert(&((*root)->rchild),cc);}
    }
}
node *creat(char s[100][10])
{
    int i;
    node *R;
    R=(node *)malloc(sizeof(node));
    R->gs=1;
    strcpy(R->dc,s[0]);
    R->lchild=R->rchild=NULL;
    for(i=1;i<=N;i++)
    {
        insert(&R,s[i]);
    }
    return R;

}
void print(node *root)
{
    if(root)
    {
        printf("字符串%s有%d个\n",root->dc,root->gs);
        print(root->lchild);
        print(root->rchild);
    }
}
int main()
{
    node *R;
    char ls[300],s[100][10];
    printf("请输入一个字符串以'#'结束");
    gets(ls);
    zh(ls,s);
    R=creat(s);
    print(R);
    return 0;

}





















