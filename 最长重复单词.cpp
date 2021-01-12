#include<stdio.h>
#include<string.h>
void max(char s[],int *pos,int *len)
{
	int i=0,j=i+1,k=1;
	while(s[j]!='\0')
	{
		while(s[j])
		{
			if(s[i]==s[j]){k++;j++;}
			else  break;
		}
		if(k>*len){*len=k;*pos=i;k=1;}
		i=j;j=i+1;
	}
	
}
int main()
{
	char str[100];
	memset(str,0,100);
	int i,len=0,pos=0;
	printf("ÇëÊäÈëÒ»¸ö×Ö·û´®:");
	gets(str);
	max(str,&pos,&len);
	for(i=0;i<len;i++)
	{
		printf("%c",str[i+pos]);
	}

    return 0;
}