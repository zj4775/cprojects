//
// Created by jie on 2021/2/28.
//
#include "iostream"
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string s1,string s2){
    int idx1=s1.find("@");
    string pre1=s1.substr(0,idx1);
    string post1=s1.substr(idx1+1);

    int idx2=s2.find("@");
    string pre2=s2.substr(0,idx2);
    string post2=s2.substr(idx2+1);
    int res=post1.compare(post2);
    if(res!=0){
        return res>0?false:true;
    }else{
        return pre1.compare(pre2)>0?true:false;
    }
}

int main(){
    string array[1000000];
    int count;
    cin>>count;
    for (int i = 0; i <count ; i++) {
        cin>>array[i];
    }
    sort(array,array+count,cmp);
    for (int j = 0; j < count; j++) {
        cout<<array[j]<<endl;
    }
    return 0;
}
