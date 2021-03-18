//
// Created by jie on 2021/3/18.
//

#include "iostream"
#include <string>
using namespace std;



int main(){
    string str;
    long b;
    long ans=0;
    cin>>str>>b;
    for (int i = 0; i <str.length() ; i++) {
        ans=(ans*10+(str[i]-'0'))%b;
    }
    cout<<ans;

    return 0;
}