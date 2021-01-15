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
    cout<<endl<<"开始打印数组:"<<endl;
    for (int i = 0; i <n ; ++i) {
        cout<<array[i];
        if (i!=n-1){
            cout<<",";
        }else{
            cout<<endl;
        }
    }
    cout<<"打印数组结束"<<endl;
}

void quick_sort(int * array,int s,int e){
    cout<<"快速排序"<<endl;
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

int quick_sort_k(int * array,int s,int e,int k){
    //cout<<"获取第几大的数字"<<endl;
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
    if (i==k){
        return value;
    }else if (i>k){
        return quick_sort_k(array,s,i-1,k);
    }else{
        return quick_sort_k(array,i+1,e,k);
    }
}

void select_sort(int * array,int s,int e){
    cout<<"选择排序"<<endl;
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
    cout<<"冒泡排序"<<endl;
    for (int i = e; i >s ; --i) {
        for (int j = s; j <i -1; ++j) {//这里的j不用取到最后一个，而是最后第二个
            if (array[j]>array[j+1]){
                convert(array,j,j+1);
            }
        }
    }
}

void bi_bubble_sort(int * array,int s,int e){
    cout<<"双向冒泡排序"<<endl;
    int start=s;
    int end=e;
    while (start<end){
        for (int i = start; i < end-1; ++i) {
            if (array[i]>array[i+1]){
                convert(array,i,i+1);
            }
        }
        end--;
        for (int j = end-1; j >start ; --j) {
            if (array[j]<array[j-1]){
                convert(array,j-1,j);
            }
        }
        start++;
    }
}



int main(){
    int orgin[100]={3,6,9,1,2,7,5,0,8,4};
    int* array=orgin;
    int k=3;
    print_array(array,10);
    //quick_sort(array,0,9);
    cout<<"第"<<k<<"大的数字是:"<<quick_sort_k(array,0,9,k-1);
    //select_sort(array,0,10);
    //bi_bubble_sort(array,0,10);
    print_array(array,10);
    return 0;
}

