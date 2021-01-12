#include<stdio.h>
#include<string.h>
void max(char s1[],char s2[],int *len,int *ad1,int *ad2)
{
	int i=0,j=0,k=0;
	while(s1[i])
	{
		while(s2[j])
		{
			while(s1[i+k]&&s2[j+k])
			{
				if(s1[i+k]==s2[j+k]){k++;}
				else{break;}	
			}
			if(k>(*len)){(*len)=k;(*ad1)=i;(*ad2)=j;}
			j++;k=0;
		}
		i++;j=0;k=0;
	}
}
int main()
{
	int x,y,len,i;
	char str1[100];
	char str2[100];
	gets(str1);
	gets(str2);
	max(str1,str2,&len,&x,&y);
	printf("%d,%d,%d\n",len,x,y);
	for(i=0;i<len;i++)
	{
		printf("%c",str1[x+i]);	
	}
	printf("\n");
	for(i=0;i<len;i++)
	{
		printf("%c",str2[y+i]);

	}
    return 0;



}
