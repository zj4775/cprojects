#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define N 5

#define MAX_SIZE 50

#define yes 1
#define no 0

typedef struct{
	int x;
	int y;
	int value;
}node;


typedef struct seqstack{
	char elem[MAX_SIZE];
	int top;
}seqstack;

void init(seqstack** s){
	*s=(seqstack*)malloc(sizeof(seqstack));
	(*s)->top=-1;
}

int isempty(seqstack *s)
{
	if(s->top==-1){return yes;}
	else{return no;}
}
int isfull(seqstack *s)
{
	if(s->top==MAX_SIZE-1){return yes;}
	else{return no;}
}
void push(seqstack *s,char e)
{
	if(isfull(s)){exit(0);}
	else{s->top++;s->elem[s->top]=e;}/*先让top指向0*/
}
char pop(seqstack *s)
{
	if(isempty(s)){exit(0);}
	else{return s->elem[s->top--];}
}
char gettop(seqstack *s)
{
	if(isempty(s)){exit(0);}
	else{return s->elem[s->top];}
}
bool match(char a,char b)
{
	if((a=='(')&&(b==')')||(a=='[')&&(b==']')||(a=='{')&&(b=='}')){return true;}
	else{return false;}
}







void create_matrix(int array[N][N]){
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			array[i][j]=rand()%100+1;
		}
	}
}

void print_matrix(int array[N][N]){
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			printf("%d   ",array[i][j]);
			
		}
		printf("\n\n");
	}
}




void rotate_matrix(int array[N][N]){
	int tmp;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<i;j++)
		{
			tmp=array[i][j];
			array[i][j]=array[j][i];
			array[j][i]=tmp;
		}
	}
}

void init_node(node* n,int x){
	n->x=0;
	n->y=0;
	n->value=x;
}

void exchange(node n,int array[N][N],int x,int y){
	int tmp=array[x][y];
	array[x][y]=n.value;
	array[n.x][n.y]=tmp;
}

/************************************************************************/
/* 用二分法来求方程的解                                                                     */
/************************************************************************/

float compute(float x){
	return 2*pow(x,3)-4*pow(x,2)+3*x-10;
}

float bin_fun(float low,float high){
	float mid=(low+high)/2;
	float y1=compute(low);
	float y2=compute(high);
	if (y1==0)
	{
		return low;
	}
	if (y2==0)
	{
		return high;
	}
	if(fabs(y1-y2)>=1e-5)
	{
		if (compute(mid)>0)
		{
			return bin_fun(low,mid);
		}else{
			return bin_fun(mid,high);
		}
	}else{
		printf("解出来了:%f",compute(mid));
		return mid;
	}
	 
}

/************************************************************************/
/* 用牛顿迭代法求方程的解 xn+1=xn-f/f` (切线方程y=0推得) 其中f是求解的方程 比如这里的求3次方跟 */
/************************************************************************/

float compute3(float x,float a){
	return x-(pow(x,3)-a)/(3*pow(x,2));
}

float newton_fun(float a){
	float x1=a/2;
	float x2=compute3(x1,a);
	while (fabs(x1-x2)>=1e-5)
	{
		x1=x2;
		x2=compute3(x1,a);
	}
	return x2;
}


/************************************************************************/
/* 最大放中间，4个角放小值                                                                     */
/************************************************************************/

/*void opt_max_min(int* p){
	int length=N*N;
	for (int i=length-1;i>=0;i--)
	{
		for (int j=0;j<=i;j++)
		{
			if (*(p+j)>*(p+j+1))
			{
				exchange(p,j,j+1);
			}
		}
	}
	exchange(p,12,24);
	exchange(p,4,1);
	exchange(p,20,2);
	exchange(p,24,3);
}*/

void opt_max_min(int array[N][N]){
	node max;
	node min;
	
	init_node(&max,array[0][0]);
	init_node(&min,array[0][0]);
	int i;
	int j;
	
	
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (array[i][j]>max.value)
			{
				max.value=array[i][j];
				max.x=i;
				max.y=j;
			}
			if (array[i][j]<min.value)
			{
				min.value=array[i][j];
				min.x=i;
				min.y=j;
			}
		}
	}
	exchange(max,array,2,2);
	exchange(min,array,0,0);


	init_node(&min,array[0][4]);
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (!(i==0&&j==0))
			{
				if (array[i][j]<min.value)
				{
					min.value=array[i][j];
					min.x=i;
					min.y=j;
				}
			}
		}
	}
	exchange(min,array,0,4);

	init_node(&min,array[4][0]);
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (!((i==0&&j==0)||(i==0&&j==4)))
			{
				if (array[i][j]<min.value)
				{
					min.value=array[i][j];
					min.x=i;
					min.y=j;
				}
			}
		}
	}
	exchange(min,array,4,0);

	init_node(&min,array[4][4]);
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (!((i==0&&j==0)||(i==0&&j==4)||(i==4&&j==0)))
			{
				if (array[i][j]<min.value)
				{
					min.value=array[i][j];
					min.x=i;
					min.y=j;
				}
			}
		}
	}
	exchange(min,array,4,4);
}



float fun1(float n){
	if (n==1)
	{
		return 2;
	}else if (n==2)
	{
		return 3;
	}else{
		return fun1(n-1)+fun1(n-2);
	}
}

float fun2(float n){
	if (n==1)
	{
		return 1;
	}else if (n==2)
	{
		return 2;
	}else{
		return fun1(n-1)+fun1(n-2);
	}
}

void sort(char data[MAX_SIZE][MAX_SIZE],int length){
	char tmp[MAX_SIZE];
	for (int i=length-1;i>=0;i--)
	{
		for (int j=0;j<=i;j++)
		{
			if (strcmp(data[j],data[j+1])>0)
			{
				strcpy(tmp,data[j]);
				strcpy(data[j],data[j+1]);
				strcpy(data[j+1],tmp);
			}
		}
	}
}


void trans_data(char* from_file,char* to_file){
	char data[MAX_SIZE][MAX_SIZE];
	FILE* from= fopen(from_file,"r");
	int idx=0;
	int i=0;
	if (!from)
	{
		printf("输入文件不存在");
		exit(1);
	}
	while (!feof(from))
	{
		fscanf(from,"%s",data[idx++]);
	}
	for (i=0;i<idx;i++)
	{
		printf("%s\n",data[i]);
	}
	sort(data,idx);
	FILE* to= fopen(to_file,"w+");
	if (!to)
	{
		printf("输出文件不存在");
		exit(1);
	}
	for (i=0;i<idx;i++)
	{
		fprintf(to,"%s\n",data[i]);
	}
	fclose(from);
	fclose(to);

}

/************************************************************************/
/* 买鸡                                                                     */
/************************************************************************/

void buy_chickine(){
	for (int i=1;i<=33;i++)
	{
		for (int j=1;j<20;j++)
		{
			int k=100-i-j;
			if (k%3==0)
			{
				if (k/3+3*i+5*j==100)
				{
					printf("小鸡买:%d只,母机买:%d只,公鸡买:%d只\n",k,i,j);
				}
			}
		}
	}
}

/************************************************************************/
/* 元音字母                                                                     */
/************************************************************************/
void yuanyin(char* arr){
	char yuanyin[5];
	char fuyin[5];
	int length=5;
	int yuanyin_idx=0;
	int fuyin_idx=0;
	int i=0;
	int j=0;
	for (i=0;i<length;i++)
	{
		if (arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u')
		{
			yuanyin[yuanyin_idx++]=arr[i];
		}else{
			fuyin[fuyin_idx++]=arr[i];
		}
	}
	if (yuanyin_idx==0||yuanyin_idx>=4)
	{
		printf("无法构成拼装");
		exit(1);
	}
	if (yuanyin_idx==1)
	{
		for (i=0;i<fuyin_idx;i++)
		{
			for (j=0;j<fuyin_idx;j++)
			{
				if (i!=j)
				{
					printf("%c-%c-%c\n",fuyin[i],yuanyin[0],fuyin[j]);
				}
			}
		}
	}
	if (yuanyin_idx==2)
	{
		for (i=0;i<fuyin_idx;i++)
		{
			for (j=0;j<fuyin_idx;j++)
			{
				if (i!=j)
				{
					printf("%c-%c-%c\n",fuyin[i],yuanyin[0],fuyin[j]);
					printf("%c-%c-%c\n",fuyin[i],yuanyin[1],fuyin[j]);
				}
			}
		}
	}
}

/************************************************************************/
/*  机器人 add min max                                                                    */
/************************************************************************/

char* ncopy(char* array,int start,int end){
	char new_array[MAX_SIZE];
	memset(new_array,0,MAX_SIZE);
	int idx=0;
	for (int i=start;i<=end;i++)
	{
		new_array[idx++]=array[i];
	}
	return new_array;
}

int split(char* array,int start,int end){
	seqstack* s;
	init(&s);
	int idx=start+3;
	bool isnum=false;
	//push(s,array[idx]);
	
	push(s,array[idx++]);
	bool first=true;
	while (!isempty(s))
	{
		char c=gettop(s);
		if (match(c,array[idx]))
		{
			pop(s);
		}else if(array[idx]=='('){
			push(s,array[idx]);
			
		}else if (array[idx]==','&&s->top==0)//当栈里面只有一个括号并且访问到了逗号说明这个逗号是分隔符
		{
			return idx;
		}
		idx++;
	}
	return idx;
	

}

int max(int a,int b){
	if (a>b)
	{
		return a;
	}else{
		return b;
	}
}

int min(int a,int b){
	if (a<b)
	{
		return a;
	}else{
		return b;
	}
}

int robot_compute(char* array,int start,int end){
	if (end-start<=3)
	{
		return atoi(ncopy(array,start,end));
	}else{
		int split_idx=split(array,start,end);
		int left=robot_compute(array,start+4,split_idx-1);
		int right=robot_compute(array,split_idx+1,end-1);
		char* opt=ncopy(array,start,start+2);
		if (strcmp(opt,"add")==0)
		{
			return left+right;
		}else if (strcmp(opt,"min")==0)
		{
			return min(left,right);
		}else if (strcmp(opt,"max")==0)
		{
			return max(left,right);
		}else{
			printf("ERROR");
			exit(1);
		}


	}
}

void luoxuan(int n){
	int deep;
	int idx=1;
	int j=0;
	int array[MAX_SIZE][MAX_SIZE];
	if (n%2==0)
	{
		deep=n/2;
	}else{
		deep=n/2+1;
	}
	for (int i=1;i<=deep;i++)
	{
		for (j=i;j<=n+1-i;j++)//上
		{
			array[i-1][j-1]=idx++;
		}
		for (j=i+1;j<=n+1-i;j++)//右
		{
			array[j-1][n-i]=idx++;
		}
		for (j=n+1-i;j>=i+1;j--)//下
		{
			array[n-i][j-2]=idx++;
		}
		for (j=n-i;j>i;j--)//左
		{
			array[j-1][i-1]=idx++;
		}	
	}

	printf("开始打印螺旋:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%d   ",array[i][j]);
		}
		printf("\n\n");
	}
}

void print_matrix(int array[MAX_SIZE][MAX_SIZE],int n){
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			printf("%d   ",array[i][j]);
		}
		printf("\n\n");
	}
}

void mofangshu(int n){
	int array[MAX_SIZE][MAX_SIZE];
	int i=0;
	int j=n/2;
	array[i][j]=1;
	for (int k=2;k<=n*n;k++)
	{
		if (k%n==1)//序号余数为1的下移
		{
			i++;
		}else{
			i--;
			j++;
		}
		if (i==-1)
		{
			i=n-1;
		}
		if (j==n)
		{
			j=0;
		}
		array[i][j]=k;
		

	}
	print_matrix(array,n);


}

/************************************************************************/
/* 0-1 之间的随机数                                                                     */
/************************************************************************/

void randnum(){
	srand((unsigned)time(NULL));
	for (int i=0;i<100;i++)
	{
		printf("%.3f\n",rand()%1001*0.001f);
	}
}

/************************************************************************/
/* 计算星期几                                                                     */
/************************************************************************/
void CaculateWeekDay(int y,int m, int d)
{
    if(m==1||m==2) {
        m+=12;
        y--;
    }
    int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    switch(iWeek)
    {
    case 0: printf("星期一\n"); break;
    case 1: printf("星期二\n"); break;
    case 2: printf("星期三\n"); break;
    case 3: printf("星期四\n"); break;
    case 4: printf("星期五\n"); break;
    case 5: printf("星期六\n"); break;
    case 6: printf("星期日\n"); break;
    }
} 

int main(){
	/*float sum=0;
	float div;
	for (int i=1;i<=20;i++)
	{
		float a=fun1(i);
		float b=fun2(i);
		div=a/b;
		sum+=div;
	}
	printf("%.2f",sum);*/

	/*srand((unsigned)time(NULL));

	int array[N][N];
	create_matrix(array);
	print_matrix(array);*/
	/*printf("旋转后的矩阵:\n\n\n");
	rotate_matrix(array);
	print_matrix(array);*/

	/*printf("转换后的矩阵:\n\n\n");
	opt_max_min(array);
	print_matrix(array);*/

	/*char from[MAX_SIZE]="F:\\c\\data\\aaa.txt";
	char to[MAX_SIZE]="F:\\c\\data\\bbb.txt";
	trans_data(from,to);*/

	/*float low=0;
	float high=0;
	float y1=compute(low);
	float y2=compute(high);

	while (y1>0)
	{
		printf("请输入第一个数:\n");
		scanf("%f",&low);
		getchar();
		y1=compute(low);
	}
	while (y2<0)
	{
		printf("请输入第二个数:\n");
		scanf("%f",&high);
		getchar();
		y2=compute(high);
	}
	float res= bin_fun(low,high);
	printf("%f",res);*/


	/*float res=newton_fun(2);
	printf("%f",res);*/

	//buy_chickine();

	/*char str[MAX_SIZE];
	printf("请输入一个字符串:\n");
	gets(str);
	int len=strlen(str);
	int res=robot_compute(str,0,strlen(str));
	printf("结果:%d",res);*/

	//luoxuan(4);

	mofangshu(5);

	//randnum();

    return 0;
	
	

}