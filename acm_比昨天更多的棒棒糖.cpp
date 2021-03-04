//
// Created by jie on 2021/3/3.
//

#include "iostream"
using namespace std;


long sum(long x,long n,long k){

    if (x==n){
        return 1;
    }else if (x>n){
        return 0;
    }
    if (k==0){
        return 0;
    }
    long count=1;
    if (x<=n-x&&k>=1){
        count+=sum(x,n-x,k-1);
    }

    /*if (x<=n&&k==1){
        count+=1;
    }else{
        count++;
        count+=sum(x,n-x,k-1);
    }*/

    for (long j = x+1; j <=n ; j++) {
        long s=0;
        if (j<=n-x&&k>=1){
            s=sum(j,n-x,k);
        }
        if (s==0){
            break;
        }
        count+=s;
    }
    return count;

}


int main(){
    long total=0;
    long n=0;
    long x=0;
    long k=0;
    cin>>n>>x>>k;
    for (long i = x; i <=n ; i++) {
        total+=sum(i,n,k-1);
    }
    cout<<total;
    return 0;
}