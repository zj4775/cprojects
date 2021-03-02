//
// Created by jie on 2021/3/1.
//

#include "iostream"
#include "math.h"
#include "algorithm"
#include <cstring>
using namespace std;



string get_opsitive_bin(long n){
    char res[64];
    memset(res,'0',64);
    int i=63;
    while (n!=0){
        if (n%2==0){
            res[i--]='0';
        }else{
            res[i--]='1';
        }
        n/=2;
    }
    return string(res);
}

string get_negative_bin(long n){
    char res[64];
    memset(res,'1',64);
    int i=63;
    n=-n-1;
    while (n!=0){
        if (n%2==0){
            res[i--]='1';
        }else{
            res[i--]='0';
        }
        n/=2;
    }
    return string(res);
}

string getbin(long n){
    if (n>=0){
        return get_opsitive_bin(n);
    }else{
        return get_negative_bin(n);
    }
}

int count_one(string s1){
    int res=0;
    for (int i = 0; i <s1.length() ; i++) {
        if (s1[i]=='1'){
            res++;
        }
    }
    return res;
}

bool cmp(long a,long b){
    long aa=a;
    long bb=b;
    string str_aa=getbin(aa);
    string str_bb=getbin(bb);
    int count_aa=count_one(str_aa);
    int count_bb=count_one(str_bb);
    if (count_aa==count_bb){
        return a>b?false:true;
    }
    return count_aa>count_bb?true:false;
}

void quick_sort(long _array[],int start,int end){
    int i=start;
    int j=end;
    long _value=_array[start];
    while(i<j){
        while(i<j&&cmp(_value,_array[j])){
            j--;
        }
        if(i<j){
            _array[i]=_array[j];
            i++;
        }
        while(i<j&&cmp(_array[i],_value)){
            i++;
        }
        if(i<j){
            _array[j]=_array[i];
            j--;
        }
    }

    _array[i]=_value;
    if(start<i){
        quick_sort(_array,start,i-1);
    }
    if(j<end){
        quick_sort(_array,j+1,end);
    }


}

void merge(long * array,int s,int m,int e){
    long* newarray=(long*)malloc(sizeof(long)*(e-s+1));
    int i=s;
    int j=m+1;
    int k=0;
    while (i<=m&&j<=e){
        if (!cmp(array[i],array[j])){
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

void merge_sort(long * array,int s,int e){
    if (s<e){
        int m=(s+e)/2;
        merge_sort(array,s,m);
        merge_sort(array,m+1,e);
        merge(array,s,m,e);
    }
}



int main(){
    int count;
    long array[500000];
    cin>>count;
    for (int i = 0; i <count ; i++) {
        cin>>array[i];
    }
    heap_sort(array,0,count);
    //sort(array,array+count,cmp);
    for (int i = 0; i <count ; i++) {
        cout<<array[i]<<" ";
    }

    /*string s1=getbin(15);
    cout<<s1;*/

    return 0;
}