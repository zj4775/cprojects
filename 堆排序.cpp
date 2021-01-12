#include<stdio.h>
void tiaozheng(int a[],int k,int n)
{
	int i=k,j=2*i,temp;
	while(j<=n)
	{
		if(j<n&&a[j]<a[j+1]){j++;}//求出左右子树的大的那个
		if(a[i]<a[j]){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i=j;
			j=2*i;//每次如果把大的节点往上调了，那么那个小的节点可能对于更小的子树来说可能就是大值了，所以还要继续调整
		}//父节点调整为大的，如果有子树的话，子树也要做调整
		else{break;}
	}	
}
void tuipx(int a[],int leng)
{
	int i,temp;
	for(i=leng/2;i>=1;i--){tiaozheng(a,i,leng);}// 把每个节点的父节点调整为最大，由于这个循环i最小值为1，所以第一个就会是最大值
	for(i=leng;i>=2;i--)//依次把最大值放到最后
	{ 
		temp=a[1];//把第一个最大的放到最后
		a[1]=a[i];
		a[i]=temp;
		tiaozheng(a,1,i-1);//每次调整后第一个就是最大的
	}
}
void print(int a[],int leng)
{
	int i;
	for(i=1;i<=leng;i++)
	{
		printf("%d  ",a[i]);
	}

}

int main()
{
	int i,a[100],leng=0;
	printf("请输入需要排序的个数");
	scanf("%d",&leng);
	for(i=1;i<=leng;i++)
	{
		printf("请输入第%d个数字",i);
		scanf("%d",&a[i]);
	}
	printf("原序列为:");
	print(a,leng);
	tuipx(a,leng);
	printf("\n调整好的序列为:");
	print(a,leng);
    return 0;

}