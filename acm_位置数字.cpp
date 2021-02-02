//
// Created by jie on 2021/1/27.
//
#include "stdio.h"
#include "iostream"
#include "stdlib.h"

using namespace std;

char* s="110100100010000100000";


int main(){
    /*char* s;
    s=(char*)malloc(100);
    cin>>s;*/
    int n;
    int x;
    cin>>n;
    for (int i = 0; i <n ; i++) {
        cin>>x;
        cout<<s[x-1]<<endl;
    }
    return 1;
}

