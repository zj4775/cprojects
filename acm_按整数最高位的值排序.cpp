//
// Created by jie on 2021/3/10.
//

#include "iostream"
#include <tuple>
#include <algorithm>
using namespace std;

typedef long long LL;



bool cmp(LL a,LL b){
    char c1;
    char c2;
    if (a>=0){
        c1=to_string(a)[0];
    }else{
        c1=to_string(-a)[0];
    }
    if (b>=0){
        c2=to_string(b)[0];
    }else{
        c2=to_string(-b)[0];
    }
    return tie(c1,b)>tie(c2,a);

}


int main(){
    int count;
    int n;
    LL array1[10000];
    cin>>count;
    for (int i = 0; i <count ; i++) {
        cin>>n;
        for (int k = 0; k <n ; k++) {
            cin>>array1[k];
        }
        sort(array1,array1+n,cmp);
        cout<<"case #"<<i<<":"<<endl;
        for (int j = 0; j <n ; j++) {
            cout<<array1[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}