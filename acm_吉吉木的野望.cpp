//
// Created by jie on 2021/2/28.
//
#include <iomanip>
#include "iostream"

using namespace std;

double getAn(int n,int d){
    if(n==0){
        return 0;
    }else if (n==1){
        return 1;
    }else{
        return 1+(n-1)*d;
    }
}

/*double xn(int a,int b){
    return (double)a/b;
}*/

double fn(int k,int n,int d){
    if (k==n){
        return (double)1/getAn(n,d);
    }else{
        return (double)1/(getAn(k,d)+(double)fn(k+1,n,d));
    }
}

int main(){
    int d=0;
    int k=0;
    cin>>d>>k;
    if(k>100){
        k=100;//我擦，不加这个k很大内存会溢出
    }
    double res=fn(1,k,d);
    cout<<setprecision(12)<<fixed<<res;
    //cout<<setprecision(12)<<fixed<<xn(1,3);
    return 0;
}
