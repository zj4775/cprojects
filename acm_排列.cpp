//
// Created by jie on 2021/3/19.
//

#include "iostream"
#include <string>
using namespace std;

void exchange(string* str,int a,int b){
    char tmp=(*str)[b];
    (*str)[b]=(*str)[a];
    (*str)[a]=tmp;
}

void pl(string str,int start,int end){
    if (start==end){
        cout<<str<<endl;
    }else{
        for (int i = start; i <end ; i++) {
            exchange(&str,start,i);
            pl(str,start+1,end);
            exchange(&str,start,i);
        }
    }
}


int main(){
    string str;
    cin>>str;
    //exchange(&str,0,2);
    //cout<<str;
    pl(str,0,str.length());
    return 0;
}