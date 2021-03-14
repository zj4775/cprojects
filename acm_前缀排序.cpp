//
// Created by jie on 2021/3/14.
//

#include "iostream"
#include <string>
using namespace std;

typedef long long LL;

bool cmp(int a,int b){
    string str1=to_string(a);
    string str2=to_string(b);
    int r=str1.compare(str2);
    return r>=0?true:false;
}

int main(){
    int n;
    cin>>n;
    int a[100000];
    int k=0;
    while (n!=0){
        a[k++]=n;
        n/=10;
    }
    sort(a,a+k,cmp);
    string res="";
    for (int i = 0; i <k ; i++) {
        res.append(to_string(a[i]));
    }
    LL x=atoll(res.data());
    cout<<x%998244353<<endl;

    return 0;
}