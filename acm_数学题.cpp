//
// Created by jie on 2021/3/6.
//

#include "iostream"
#include <math.h>
#include <vector>
using namespace std;
typedef long long LL;

LL f(int n,int k){
    vector<int> v;
    for (int i = 2; i <sqrt(n) ; i++) {
       if (n%i==0){
           v.push_back(i);
           if (i*i!=n){
               v.push_back(n/i);
           }
       }
    }
    for (int j = 1; j <=n ; j++) {

    }



}

int main(){
    int n;
    int k;
    cin>>n>>k;


    return 0;
}