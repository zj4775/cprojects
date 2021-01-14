#include<stdio.h>
#include <cstdlib>
#include "sys/malloc.h"
#include "iostream"
using namespace std;


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
	printf("¿ªÊ¼´òÓ¡Êý×é\n");
	for(int i=0;i<length;i++){
		printf("%c ",_array[i]);
	}
	printf("\n");
}

void reverse_zj(char * array,int s,int e){
    int mid=(s+e)/2;
    if ((s+e)%2==0&&s==0){
        mid=mid-1;
    }
    for (int i = s; i <=mid ; ++i) {
        int start=i;
        int end=e-(i-s);
        char tmp=array[end];
        array[end]=array[start];
        array[start]=tmp;
    }
}


int main(){

	/*char _array[15]={'a','b','c','d','e','0','1','2','3','4','5','6','7','8','9'};
	print(_array,15);
	reverse(_array,0,14);
	print(_array,15);
	reverse(_array,0,9);
	reverse(_array,10,14);
	print(_array,15);*/

	/*char _array[15]={'a','b','c','d','e','0','1','2','3','4','5','6','7','8','9'};
	print(_array,15);
	reverse2(_array,15,10);
	print(_array,15);*/
    char* array=(char*)malloc(100);
	char* array1=(char*)malloc(100);
    char* array2=(char*)malloc(100);
	cout<<"ÇëÊäÈë×Ö·û´®1\n";
	gets(array1);
    cout<<"ÇëÊäÈë×Ö·û´®2\n";
    gets(array2);
    array=strcat(array1,array2);
    cout<<"Æ´½Ó×Ö·û´®:"<<array<<endl;
    reverse_zj(array,0,strlen(array)-1);
    cout<<"×ª»»ºó×Ö·û´®:"<<array<<endl;
    reverse_zj(array,0,strlen(array2)-1);
    reverse_zj(array,strlen(array2),strlen(array)-1);
    cout<<"×îÖÕ×ª»»ºó×Ö·û´®:"<<array<<endl;
	return 0;



}

