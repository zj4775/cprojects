#include<stdio.h>
#include<string.h>

void f(char str[],int k,int n,char sub[])
{
	int leng;
	if(k==n){puts(sub);}
	else
	{
	   leng=strlen(sub);
	   sub[leng]=str[k];f(str,k+1,n,sub);	
	   sub[leng]='\0';f(str,k+1,n,sub);		
	}
}
int main()
{
	char str[10],sub[10];
	int n;
	printf("������һ���ַ���:");
	gets(str);
	n=strlen(str);
	memset(sub,0,10);
	printf("�����Ӽ�Ϊ:\n");
	f(str,0,n,sub);
    return 0;
}