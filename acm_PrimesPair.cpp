//
// Created by jie on 2021/3/2.
//

#include "iostream"
#include <math.h>
using namespace std;

bool is_prime(int n){
    if (1==n){
        return false;
    }
    if (2==n){
        return true;
    }
    double x=sqrt(n);
    for (int i = 2; i <=x ; i++) {
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int count;
    cin>>count;
    int p_count=0;
    int n;
    for (int i = 0; i < count; i++) {
        cin>>n;
        for (int j = 1; j <=n ; j++) {
            if (is_prime(j)&&is_prime(1+n-j)){
                p_count++;
            }
        }
        cout<<p_count<<endl;
    }

    return 0;
}