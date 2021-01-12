#include<stdio.h>
#include<string.h>
const int N=10;
int ctoi(char ch)
{
	int n;
	if(ch>='a'&&ch<='f')
	{
		n=ch-87;
	}
	else if(ch>='A'&&ch<='F')
	{
		n=ch-55;
	}
	else{n=ch-48;}
	return n;
}
int slzs(char s[])
{
	int n,sum=0,i,m;
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		m=ctoi(s[i]);
		sum=sum*16+m;

	}
	return sum;

}
void szsl(int n,char s[])
{
	int m,leng=-1;
	m=n;
	while(m)
	{
		leng++;
		m/=16;
	}
	m=n;
	while(m)
	{
		s[leng--]=m%16+55;
		m/=16;
	}
}

void ten2two(int n,char* arr){
	if(n==0){
		return;
	}
	int i=0;
	int m=n;
	while(m/2!=0){
		i++;	
		m=m/2;
	}
	arr[i]='1';
	int sum=1;
	while (i>0)
	{
		sum*=2;
		i--;
	}
	int sub=n-sum;
	if (sub!=0)
	{
		ten2two(sub,arr);
	}

}

void print_arr(char* arr){

	for (int i=N-1;i>0;i--)
	{
		printf("%c",arr[i]);
	}
}

void test1(char * a){
	a[0]='1';
	a[1]='9';
}

int main()
{
	/*char s[10];
	int n;
	printf("请输入一个十六进制数");
	gets(s);
	n=slzs(s);
	printf("该数的十进制为%d",n);
	printf("\n请输入一个十进制数");
	scanf("%d",&n);
	memset(s,10,0);
	szsl(n,s);
	printf("该数的十六进制为");
	puts(s);*/
	
	char arr[N];
	int a=10;
	for (int i=0;i<N;i++)
	{
		arr[i]='0';
	}
	ten2two(a,arr);
	print_arr(arr);

	/*char arr[2];
	test1(arr);
	print_arr(arr);*/
    return 0;
}