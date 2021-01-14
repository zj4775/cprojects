//
// Created by jie on 2021/1/13.
//
#include "iostream"
#include "stdio.h"
#include "string"
#include "stdlib.h"
#include "set"

#define MAX 1e10
#define MIN -1e10

using namespace std;


void convert(int* array,int s,int e){
    int tmp=array[s];
    array[s]=array[e];
    array[e]=tmp;
}

void print_array(int* array,int n){
    cout<<endl<<"��ʼ��ӡ����:"<<endl;
    for (int i = 0; i <n ; ++i) {
        cout<<array[i];
        if (i!=n-1){
            cout<<",";
        }else{
            cout<<endl;
        }
    }
    cout<<"��ӡ�������"<<endl;
}

void quick_sort(int * array,int s,int e){
    cout<<"��������"<<endl;
    int value=array[s];
    int i=s;
    int j=e;
    while (i<j){
        while (i<j&&array[j]>value){
            j--;
        }
        if (i<j){
            array[i]=array[j];
            i++;
        }
        while (i<j&&array[i]<value){
            i++;
        }
        if (i<j){
            array[j]=array[i];
            j--;
        }
    }
    array[i]=value;
    if (s<i){
        quick_sort(array,s,i-1);
    }
    if (i<e){
        quick_sort(array,i+1,e);
    }
}

void select_sort(int * array,int s,int e){
    cout<<"ѡ������"<<endl;
    int min=0;
    int k=0;
    for (int i = 0; i < e; ++i) {
        k=i;
        min=array[i];
        for (int j = i; j < e; ++j) {
            if (array[j]<min){
                min=array[j];
                k=j;
            }
        }
        if(k!=i){
            convert(array,i,k);
        }
    }
}

void bubble_sort(int * array,int s,int e){
    cout<<"ð������"<<endl;

}



int main(){
    int orgin[100]={3,6,9,1,2,7,5,0,8,4};
    int* array=orgin;
    print_array(array,10);
    //quick_sort(array,0,9);
    select_sort(array,0,10);
    print_array(array,10);
    return 0;
}

