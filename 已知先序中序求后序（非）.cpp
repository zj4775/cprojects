#include <stdio.h>
#include<string.h>

int find(char c,char A[],int s,int e) /* 找出中序中根的位置。 */
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
	if(in_s>in_e) return ; /* 非法子树，完成。 */
	if(in_s==in_e)
	{
		printf("%c",in[in_s]); /* 子树子仅为一个节点时直接输出并完成。 */
		return ;
	} 
	c=pre[pre_s]; 
	k=find(c,in,in_s,in_e); 
	pronum(pre,pre_s+1,pre_s+k-in_s,in,in_s,k-1); //注意要减去in_s的
	pronum(pre,pre_s+k-in_s+1,pre_e,in,k+1,in_e); 
	printf("%c",c); /* 根节点输出。 */
}

int main()
{
	char pre[20];
	char in[20];
	printf("请输入先序遍历:\n");
	gets(pre);
	printf("请输入中序遍历:\n");
	gets(in);
	printf("后序遍历为:\n");
	pronum(pre,0,strlen(in)-1,in,0,strlen(pre)-1);
    return 0;
}