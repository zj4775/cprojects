#include <stdio.h>
#include<string.h>

int find(char c,char A[],int s,int e) /* �ҳ������и���λ�á� */
{
	int i;
	for(i=s;i<=e;i++)
	  if(A[i]==c) return i;
	return -1;
}

void pronum(char pre[],int pre_s,int pre_e,char in[],int in_s,int in_e)
{
	char c;
	int k;
	if(in_s>in_e) return ; /* �Ƿ���������ɡ� */
	if(in_s==in_e)
	{
		printf("%c",in[in_s]); /* �����ӽ�Ϊһ���ڵ�ʱֱ���������ɡ� */
		return ;
	} 
	c=pre[pre_s]; 
	k=find(c,in,in_s,in_e); 
	pronum(pre,pre_s+1,pre_s+k-in_s,in,in_s,k-1); //ע��Ҫ��ȥin_s��
	pronum(pre,pre_s+k-in_s+1,pre_e,in,k+1,in_e); 
	printf("%c",c); /* ���ڵ������ */
}

int main()
{
	char pre[20];
	char in[20];
	printf("�������������:\n");
	gets(pre);
	printf("�������������:\n");
	gets(in);
	printf("�������Ϊ:\n");
	pronum(pre,0,strlen(in)-1,in,0,strlen(pre)-1);
    return 0;
}