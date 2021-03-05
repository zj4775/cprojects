//
// Created by jie on 2021/3/4.
//
#include "iostream"
#include <vector>
#include <math.h>
using namespace std;

typedef  long long LL;
#define N 1000000000

int gcd(int a,int b){
    int max;
    int min;
    int k;
    if (a>=b){
        max=a;
        min=b;
    }else{
        max=b;
        min=a;
    }
    while (min){
        k=max%min;
        max=min;
        min=k;
    }
    return max;
}

int muti_gcd(vector<int> v){
    while (v.size()>1){
        vector<int>::iterator first=v.begin();
        vector<int>::iterator second=first++;
        int x=gcd(*first,*second);
        if (x==1){
            return 1;
        }else{
            v.erase(first);
            v.erase(second);
            v.push_back(x);
        }
    }
    return *v.begin();
}


int main(){
    /*LL llarray[3];
    llarray[0]=3;
    llarray[1]=4;
    llarray[2]=llarray[0]+llarray[1];*/
    int n;
    int k;
    int x;
    int gc;
    vector<int> v;

    cin>>n>>k;
    cin>>x;
    for (int j = 2; j <=sqrt(x) ; j++) {
        if (x%j==0){
            v.push_back(j);
            if (j*j != x){
                v.push_back(x/j); //约数的另外一头
            }
        }

    }
    if (v.empty()){
        cout<<0;
        return 0;
    }
    vector<int>::iterator it;
    for (int i = 1; i <n ; i++) {
        cin>>x;
        for (it=v.begin();it!=v.end();) {
            if (x%*it!=0){
                it=v.erase(it);
            }else{
                it++;
            }
        }
        if (v.empty()){
            cout<<0;
            return 0;
        }
    }

    for (int i = k; i >1 ; i--) {
        for (it=v.begin();it!=v.end();it++) {
            if (i%*it==0){
                cout<<i;
                return 0;
            }
        }
    }
    cout<<0;

    return 0;
}
