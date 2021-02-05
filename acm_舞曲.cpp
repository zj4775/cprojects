//
// Created by jie on 2021/1/27.
//
#include "stdio.h"
#include "iostream"
#include "stdlib.h"

using namespace std;

int main(){
    int m;
    int w;
    int i=1;
    int j=1;
    int count;
    cin>>m>>w>>count;
    for (int k = 1; k <=count ; k++) {
        cout<<i<<" "<<j<<endl;
        i++;
        j++;
        if (i>m){
            i=1;
        }
        if (j>w){
            j=1;
        }
    }

    return 0;
}

