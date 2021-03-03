//
// Created by jie on 2021/3/2.
//

#include "iostream"
#include <algorithm>
using namespace std;



int main(){
    string ss;
    getline(cin,ss);
    transform(ss.begin(),ss.end(),ss.begin(),::toupper);
    cout<<ss<<endl;
    return 0;
}