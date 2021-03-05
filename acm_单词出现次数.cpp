//
// Created by jie on 2021/3/5.
//

#include "iostream"
#include <string>
#include <map>
using namespace std;
map<string,int> mmap;

void deal(string s){
    int begin=-1;
    int len=0;
    for (int i = 0; i <s.length() ; i++) {
        if (s[i]==' '){
            if (begin!=-1){
               string word=s.substr(begin,len);
                map<string,int>::iterator it= mmap.find(word);
                if (it!=mmap.end()){
                    it->second++;
                }else{
                    mmap.insert(pair<string,int>(word,1));
                }
                begin=-1;
                len=0;
            }
        }else{
            if (begin==-1){
                begin=i;
            }
            len++;
        }
    }
    if (begin!=-1){
        string word=s.substr(begin,len);
        map<string,int>::iterator it= mmap.find(word);
        if (it!=mmap.end()){
            it->second++;
        }else{
            mmap.insert(pair<string,int>(word,1));
        }
        begin=-1;
    }
}


int main(){
    int total;
    string s;
    string t;
    cin>>total;
    getchar();
    for (int i = 0; i <total ; i++) {
        getline(cin,s);
        cin>>t;
        deal(s);
        map<string,int>::iterator it= mmap.find(t);
        cout<<"case #"<<i<<":"<<endl;
        if (it!=mmap.end()){
            cout<<it->second<<endl;
        }else{
            cout<<0<<endl;
        }
        getchar();
        mmap.clear();
    }

    return 0;
}