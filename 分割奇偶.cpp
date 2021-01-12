#include <stdio.h>
#include <time.h>  
#include <stdlib.h>

void print(int _array[],int n){
	printf("数组如下:\n");
	for (int i=1;i<=n;i++)
	{
		printf("%d  ",_array[i]);
	}
	printf("\n");
}

void jiou(int _array[],int n){
	int i=1;
	int j=n;
	while(i<j){
		while (_array[i]%2==0&&i<j)
		{
			i++;
		}
		while (_array[j]%2==1&&i<j)
		{
			j--;
		}
		if (i<j)
		{
			int temp=_array[i];
			_array[i]=_array[j];
			_array[j]=temp;
			i++;
			j--;
		}
	}
}


int main(){
	srand((unsigned)time(NULL)); 

	printf("请输入元素个数\n");
	int n;
	scanf("%d",&n);
	int _array[100];
	for (int i=1;i<=n;i++)
	{
		_array[i]=rand()%100+1;
	}
	print(_array,n);
	jiou(_array,n);
	print(_array,n);
    return 0;

	
}