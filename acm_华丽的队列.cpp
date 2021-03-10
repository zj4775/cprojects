//
// Created by jie on 2021/3/10.
//

#include "iostream"
#include <vector>
#include <list>
using namespace std;



int main(){
    list<long> l;
    long count;
    cin>>count;
    getchar();
    string opt;
    vector<long> v;
    long x;
    vector<long> res;
    string line;
    for (long i = 0; i <count ; i++) {
        getline(cin,line);
        if(line[0]=='i'){
            opt="insert";
            x=atoi(line.substr(7,line.length()).data());
        }else if(line[0]=='d'){
            opt="delete";
        }else{
            opt="MinElement";
        }
        if ("insert"==opt){
            v.push_back(x);
            res.push_back(v.size());
        }else if("delete"==opt){
            vector<long>::iterator it= v.begin();
            res.push_back(*it);
            v.erase(it);
        }else{
            vector<long>::iterator minit= v.begin();
            long min=*minit;
            vector<long>::iterator it=minit+1;
            while (it!=v.end()){
                if (min>*it){
                    min=*it;
                    minit=it;
                }
                it++;
            }
            res.push_back(min);
            v.erase(minit);
        }
    }
    for (long j = 0; j <res.size() ; j++) {
        cout<<res[j]<<endl;
    }

    return 0;
}