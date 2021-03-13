//
// Created by jie on 2021/3/10.
//

#include "iostream"
#include <map>
#include <cmath>

using namespace std;

map<int,string> mmap;



int main(){
    int t;
    int n;
    int k;
    int m;
    cin>>t;
    mmap.insert(pair<int,string>(1,"Monday"));
    mmap.insert(pair<int,string>(2,"Tuesday"));
    mmap.insert(pair<int,string>(3,"Wednesday"));
    mmap.insert(pair<int,string>(4,"Thursday"));
    mmap.insert(pair<int,string>(5,"Friday"));
    mmap.insert(pair<int,string>(6,"Saturday"));
    mmap.insert(pair<int,string>(0,"Sunday"));

    for (int i = 0; i <t ; i++) {
        cin>>n>>k>>m;

        int tmp=ceil((double)k/m);
        int w=tmp%7;
        cout<<mmap[w]<<endl;
    }

    return 0;
}