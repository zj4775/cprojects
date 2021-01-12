#include<stdio.h>
#include<string.h>



int sum(int array[],int s,int e){
	int sum=0;
	for (int i=s;i<e;i++)
	{
		sum+=array[i];
	}
	return sum;
}

void max_sum(int array[],int n){
	int max=0;
	int begin=0;
	int end=0;
	for (int k=1;k<=n;k++)
	{
		for (int j=0;j+k<=n;j++)
		{
			int inner_sum=sum(array,j,j+k);
			if(inner_sum>max){
				max=inner_sum;
				begin=j;
				end=j+k-1;
			}
		}
	}
	
	printf("数组的最大和是:%d,开始节点在:%d,终结节点在:%d",max,begin,end);
	
}







int main()
{
    int array[10]={-1,5,-2,8,-3,8,-1,3,-16,6};
	max_sum(array,10);
    return 0;
	
}