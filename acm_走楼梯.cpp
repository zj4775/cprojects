//
// Created by jie on 2021/1/27.
//
#include "stdio.h"
#include "iostream"
#include "stdlib.h"

using namespace std;
#define N 100
#define K 100


int main(){
    int n;
    int k;
    int tmp;
    cin>>n>>k;
    int count[N]={0};
    bool damaged[K]={false};
    for (int j = 1; j <=k ; j++) {
        cin>>tmp;
        damaged[tmp]=true;
    }

    count[0]=1;
    for (int l = 1; l <=n ; l++) {
        if (!damaged[l]){
            if (l==1){
                count[l]=count[l-1];
            }else if(l==2){
                count[l]=count[l-1]+count[l-2];
            }else{
                count[l]=count[l-1]+count[l-2]+count[l-3];
            }
        }
    }
    cout<<count[n];
    return 0;
}

