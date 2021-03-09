//
// Created by jie on 2021/3/9.
//

#include "iostream"
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

vector<double> mmap;

bool cmp(char c1,char c2){
    char lc1=tolower(c1);
    char lc2=tolower(c2);
    int x1=lc1-'a';
    int x2=lc2-'a';
    return tie(mmap[x1],lc2,c1)>tie(mmap[x2],lc1,c2);
}

int main(){
    int total;
    cin>>total;
    string str;
    for (int j = 0; j < total; j++) {
        double x;
        mmap.clear();
        for (int i = 0; i <26 ; i++) {
            cin>>x;
            mmap.push_back(x);
        }
        cin>>str;
        sort(str.begin(),str.end(),cmp);
        cout<<"case #"<<j<<":"<<endl;
        cout<<str<<endl;
    }
    return 0;
}