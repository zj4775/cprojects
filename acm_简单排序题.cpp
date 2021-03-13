//
// Created by jie on 2021/3/11.
//

#include "iostream"
#include <math.h>
#include <stdlib.h>
using namespace std;
typedef long long LL;

//no
LL absdiff(LL a,LL b){
    return a>b?(a-b):(b-a);
}

LL absLL(LL x){
    return x>0?x:-x;
}


int main(){
    int count;
    LL array1[100000];
    cin>>count;
    LL aes;
    LL des;
    LL aespre;
    LL despre;
    cin>>array1[0];
    LL min=LONG_LONG_MAX;
    for (int i = 1; i <count ; i++) {
        cin>>array1[i];
        LL subdiff=absdiff(array1[i-1],array1[i]);
        if (array1[i-1]>array1[i]){
            if (min>(subdiff+(i+1))){
                min=subdiff+(i+1);
            }
        }else{
            if (min>(subdiff-(i+1))){
                min=subdiff-(i+1);
            }
        }
    }
    cout<<min<<endl;
    return 0;
}