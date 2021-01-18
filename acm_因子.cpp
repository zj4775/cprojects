//
// Created by jie on 2021/1/18.
//
#include "iostream"
#include "algorithm"
#include "math.h"

using namespace std;

int xiaoxue(int n){
    int count=0;
    int i;
    int k=sqrt(n);
    for (i = 1; i <=k ; i++) {
        if (n%i==0){
            count++;
        }
    }
    count*=2;
    if (k*k==n){
        count--;
    }
    return count;
}

int zhongxue(int n){
    int count=0;
    int subcount=0;
    for (int i = 1; i <sqrt(n) ; i++) {
        for (int j = 1; j <=n/i ; j++) {
            subcount=xiaoxue(n-i*j);
            if (subcount>0){
                count+=subcount;
            }
        }
    }
    return count;
}


int main(){

    int q;
    int n;
    int count;
    cin>>q>>n;
    if (q==1){
        count=xiaoxue(n);
    }else if(q==2){
        count=zhongxue(n);
    }
    cout<<count;
    return 0;
}
