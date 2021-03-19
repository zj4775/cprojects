//
// Created by jie on 2021/3/8.
//

#include "iostream"
#include <string>
#include <algorithm>
using namespace std;

bool ishw(string str){
    string old=str;
    reverse(str.begin(),str.end());
    return old==str;
}

int main(){
    string n;
    int count=0;
    cin>>n;
    while (!ishw(n)){
        int a=atoi(n.data());
        reverse(n.begin(),n.end());
        int b=atoi(n.data());
        n=to_string(a+b);
        count++;
    }
    cout<<count<<" "<<n;

    return 0;
}