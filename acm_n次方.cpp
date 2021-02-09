//
// Created by jie on 2021/2/1.
//
#include "iostream"
#include "math.h"
using namespace std;

long m_pow(long x,long n){
    long res=1;
    for (int i = 0; i < n; i++) {
        res*=x;
    }
    return res;
}


int main(){
    long x;
    long n;
    int count;
    long res;
    cin>>count;
    for (int i = 0; i < count; i++) {
        cin>>x>>n;
        if (n==0){
            res=1;
        }else{
            res=m_pow(x,n);
        }
        //printf("%lf\n",res);
        cout<<"case #"<<i<<":"<<endl<<res<<endl;
    }
    return 1;
}


