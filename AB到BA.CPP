#include<stdio.h>


void reverse(char* _array,int low,int high){
	int mid=(low+high+1)/2;
	char temp;
	for(int i=low;i<mid;i++){
		temp=_array[i];
		_array[i]=_array[high+low-i];
		_array[high+low-i]=temp;
	}
}

void reverse2(char* _array,int n,int m){
	for(int i=1;i<=m;i++){
		char last=_array[n-m+i-1];
		for (int j=n-m;j>=1;j--)
		{
			_array[j+i-1]=_array[j+i-2];
		}
		_array[i-1]=last;
	}
}

void print(char* _array,int length){
	printf("开始打印数组\n");
	for(int i=0;i<length;i++){
		printf("%c ",_array[i]);
	}
	printf("\n");
}


int main(){

	/*char _array[15]={'a','b','c','d','e','0','1','2','3','4','5','6','7','8','9'};
	print(_array,15);
	reverse(_array,0,14);
	print(_array,15);
	reverse(_array,0,9);
	reverse(_array,10,14);
	print(_array,15);*/

	char _array[15]={'a','b','c','d','e','0','1','2','3','4','5','6','7','8','9'};
	print(_array,15);
	reverse2(_array,15,10);
	print(_array,15);
	return 0;



}

