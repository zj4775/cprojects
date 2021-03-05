//
// Created by jie on 2021/3/5.
//
#include "iostream"
#include <string>
#include <algorithm>
using namespace std;

string getchar(int x){
    if (x<10){
        return to_string(x);
    }else{
        string ss;
        ss.push_back(x+55);
        return ss;
    }
}

string fn(int n,int r){
    string res;
    string tmp;
    string flag;
    int k;
    int p;
    if (n<0){
        res.append("-");
        n=-n;
    }
    while (n!=0){
        k=n%r;
        n=n/r;
        string a=getchar(k);
        tmp.append(a);
    }
    reverse(tmp.begin(),tmp.end());
    return res.append(tmp);
}



int main(){
    //string ss=getchar(10);
    int T;
    int N;
    int R;
    cin>>T;
    for (int i = 0; i <T ; i++) {
        cin>>N>>R;
        cout<<fn(N,R)<<endl;
    }

    return 0;
}
