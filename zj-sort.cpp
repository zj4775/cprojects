//
// Created by jie on 2021/1/13.
//
#include "iostream"
#include "stdio.h"
#include "string"
#include "stdlib.h"
#include "set"
#include "math.h"

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
        while (i<j&&array[j]<value){
            j--;
        }
        if (i<j){
            array[i]=array[j];
            i++;
        }
        while (i<j&&array[i]>value){
            i++;
        }
        if (i<j){
            array[j]=array[i];
            j--;
        }
    }
    array[i]=value;
    if ((i-s)==k){
        return value;
    }else if ((i-s)>k){
        return quick_sort_k(array,s,i-1,k);
    }else{
        return quick_sort_k(array,i+1,e,k-(i-s+1));//这里需要去掉i本身自己的位置
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

void insert_sort(int * array,int s,int e){
    cout<<"插入排序"<<endl;
    int j=0;
    int value=0;
    for (int i = s+1; i <e ; ++i) {
        value=array[i];
        for (j = i-1; j >=s ; --j) {
            if (array[j]>value){
                array[j+1]=array[j];
            }else{
                break;
            }
        }
        array[j+1]=value;
    }
}

void shell_sort(int * array,int s,int e){
    cout<<"希尔排序"<<endl;
    int d=(s+e)/2;
    int j=0;
    int value=0;
    while (d >=1){
        for (int i = d+s; i <e ; ++i) {
            value=array[i];
            for (j = i-d; j >=s ; j-=d) {
                if (array[j]>value){
                    array[j+d]=array[j];
                }else{
                    break;
                }
            }
            array[j+d]=value;
        }
        d/=2;
    }
}

void merge(int * array,int s,int m,int e){//感觉有时结尾还是用等号好算一点
    int* newarray=(int*)malloc(sizeof(int)*(e-s+1));
    int i=s;
    int j=m+1;
    int k=0;
    while (i<=m&&j<=e){
        if (array[i]>array[j]){
            newarray[k++]=array[j++];
        }else{
            newarray[k++]=array[i++];
        }
    }
    while (i<=m){
        newarray[k++]=array[i++];
    }
    while (j<=e){
        newarray[k++]=array[j++];
    }
    k=0;
    while (s<=e){
        array[s++]=newarray[k++];
    }
}

void merge_sort(int * array,int s,int e){
    if (s<e){
        int m=(s+e)/2;
        merge_sort(array,s,m);
        merge_sort(array,m+1,e);
        merge(array,s,m,e);
    }
}

int get_num_len(int n){
    int count=0;
    while (n!=0){
        count++;
        n/=10;
    }
    return count;
}

int get_num_by_pos(int n,int pos){
    int len=get_num_len(n);
    if (len<pos){
        return 0;
    }
    return (int)(n/pow(10,pos-1))%10;
}

void radix_sort(int * array,int s,int e){
    cout<<"基数排序"<<endl;
    int tmp[10][30];
    int count[10]={0};
    int maxlen=0;
    int c=0;
    for (int i = s; i <e ; ++i) {
        int l=get_num_len(array[i]);
        if (l>maxlen){
            maxlen=l;
        }
    }
    for (int k = 1; k <=maxlen ; ++k) {
        memset(count,0,10*sizeof(int));
        for (int i = s; i <e ; ++i) {
            int t=get_num_by_pos(array[i],k);
            tmp[t][count[t]]=array[i];
            count[t]++;
        }
        c=0;
        for (int i = 0; i <10 ; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                array[c++]=tmp[i][j];
            }
        }
    }
}


void adjust_heap(int * array,int s,int e){
    int i=s;
    int j=2*i;
    while (j<=e){

    }
}


void heap_sort(int * array,int s,int e){
    int m=(s+e)/2;
    for (int i = m; i >=1 ; --i) {
        adjust_heap(array,s,i,e);
    }
    for (int j = e; j >=0 ; --j) {
        convert(array,0,array[j]);
        adjust_heap(array,s,j);
    }

}



int main(){
    int orgin[100]={3,6,9,1,2,7,5,0,8,4};
    int* array=orgin;
    int k=7;
    print_array(array,10);
    //quick_sort(array,0,9);
    //cout<<"第"<<k<<"大的数字是:"<<quick_sort_k(array,0,9,k-1);
    //select_sort(array,0,10);
    //bi_bubble_sort(array,0,10);
    //insert_sort(array,0,10);
    //shell_sort(array,0,10);
    //merge_sort(array,0,9);
    //print_array(array,10);
    /*int array2[100]={34,64,9,95,123,27,7297,5,82,433};
    radix_sort(array2,0,10);
    print_array(array2,10);*/


    return 0;
}

