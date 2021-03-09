//
// Created by jie on 2021/3/9.
//

#include "iostream"
#include <string>
using namespace std;

string replaceAll(string str,string source,string target){
    int n=str.find(source);
    while (n!=-1){
        str.replace(n,source.length(),target);
        n=str.find(source,n);
    }
    return str;
}


int main(){
    string str;
    string source;
    string target;
    getline(cin,str);
    //getchar();
    cin>>source>>target;
    str=replaceAll(str,source,target);
    cout<<str<<endl;
    return 0;
}