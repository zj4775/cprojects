//
// Created by jie on 2021/3/8.
//

#include "iostream"
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

map<string,int> mmap;

int deal(string str){
    char exits[26]={};
    int count=0;
    bool flag;
    for (int i = 0; i <str.length() ; i++) {
        flag=false;
        for (int j = 0; j <strlen(exits) ; j++) {
            if (str[i]==exits[j]){
                flag=true;
                break;
            }
        }
        if (!flag){
            exits[count++]=str[i];
        }
    }
    return strlen(exits);
}

bool cmp(string s1,string s2){
    map<string,int>::iterator  it1=mmap.find(s1);
    map<string,int>::iterator  it2=mmap.find(s2);
    int n1;
    int n2;
    if (it1==mmap.end()){
        n1=deal(s1);
        mmap.insert(pair<string,int>(s1,n1));
    } else{
        n1=it1->second;
    }
    if (it2==mmap.end()){
        n2=deal(s2);
        mmap.insert(pair<string,int>(s2,n2));
    } else{
        n2=it2->second;
    }
    if (n1!=n2){
        return n1>n2;
    }else{
        return strcmp(s1.data(),s2.data())<=0?true:false;
    }


}

int main(){
    int total;
    cin>>total;
    int n;
    string array[10000];
    for (int i = 0; i <total ; i++) {
        cin>>n;
        for (int j = 0; j < n; j++) {
            cin>>array[j];
        }
        sort(array,array+n,cmp);
        cout<<"case #"<<i<<":"<<endl;
        for (int k = 0; k <n ; k++) {
            cout<<array[k]<<endl;
        }
    }
    return 0;
}