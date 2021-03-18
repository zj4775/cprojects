//
// Created by jie on 2021/3/18.
//
#include "iostream"
using namespace std;

int fun(int n,int m,int k){
    int count=0;
    int add=0;
    int i=0;
    int a[100000];
    memset(a,0,100000);
    while (i<n){
        if (a[i]==0){
            add++;
        }
        if (add==m){
            a[i]=1;
            add=0;
            count++;
            if (count==k){
                return i+1;
            }
        }
        if (i==n-1){
            i=0;
        }else{
            i++;
        }
    }

}


int main(){
    int total;
    cin>>total;
    int N;
    int M;
    int K;
    for (int i = 0; i <total ; i++) {
        cin>>N>>M>>K;
        cout<<fun(N,M,K)<<endl;
    }

    return 0;
}
