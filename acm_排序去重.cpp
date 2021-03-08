//
// Created by jie on 2021/3/5.
//

#include "iostream"
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
string dir;

bool cmp(int a,int b){
    if (dir=="A"){
        return a<b;
    }else{
        return a>b;
    }
}

int main(){

    cin>>dir;
    getchar();
    vector<int> v;
    set<int> s;
    int x;
    string ss;
    string tmp;
    while (getline(cin,tmp)){
        ss.append(tmp).append(" ");
    }
    ss=ss.substr(0,ss.length()-1);
    int begin=0;
    int idx= ss.find(" ");
    while (idx!=-1){
        string sub=ss.substr(begin,idx-begin);
        s.insert(atoi(sub.c_str()));
        idx++;
        while (ss[idx]==' '){
            idx++;
        }
        begin=idx;
        idx=ss.find(" ",idx+1);
    }
    string sub=ss.substr(begin,ss.length()-begin);
    s.insert(atoi(sub.c_str()));
    v.assign(s.begin(),s.end());
    sort(v.begin(),v.end(),cmp);
    for (int i = 0; i <v.size() ; i++) {
        cout<<v[i]<<" ";
    }

    return 0;
}