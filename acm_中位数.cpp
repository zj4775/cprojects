//
// Created by jie on 2021/3/15.
//

#include "iostream"
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
map<int,vector<int>> mmap;
int weight[1000000];

bool cmp(int a,int b){
    int w1=weight[a];
    int w2=weight[b];
    return w1<w2?true:false;
}

int getfirst(int key){
    map<int,vector<int>>::iterator it=mmap.find(key);
    if (it==mmap.end()){
        return -1;
    }
    return it->second.front();
}

int getnext(int key,int w){
    map<int,vector<int>>::iterator it=mmap.find(key);
    if (it==mmap.end()){
        return -1;
    }
    vector<int>::iterator lit=it->second.begin();
    while (lit!=it->second.end()){
        if (*lit==w&&(lit+1)!=it->second.end()){
            return *(lit+1);
        }
        lit++;
    }
    return -1;
}



int dfs(int start,int end,int path[1000000],int k){
    path[k]=start;
    if (start==end){
        sort(path,path+k+1,cmp);
        int idx=floor((k+1)/2);
        return weight[path[idx]];
    }else{
        int first=getfirst(start);
        int max=-1;
        while (first!=-1){
            int m=dfs(first,end,path,k+1);
            if (m>max){
                max=m;
            }
            first=getnext(start,first);
        }
        return max;
    }
}


int main(){
    int n;
    int m;
    cin>>n>>m;
    int x;
    int y;


    int path[1000000];
    for (int i = 0; i <n ; i++) {
        cin>>weight[i];
    }
    for (int i = 0; i <m ; i++) {
        cin>>x>>y;
        map<int,vector<int>>::iterator it=mmap.find(x-1);
        if (it==mmap.end()){
            vector<int> v;
            v.push_back(y-1);
            mmap.insert(pair<int,vector<int>>(x-1,v));
        }else{
            it->second.push_back(y-1);
        }
    }
    int max=dfs(0,n-1,path,0);
    cout<<max<<endl;
    return 0;
}