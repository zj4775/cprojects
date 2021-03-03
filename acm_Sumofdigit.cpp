//
// Created by jie on 2021/3/2.
//

#include "iostream"
using namespace std;



int main(){
    int count;
    int  a;
    int b;
    cin>>count;
    for (int i = 0; i <count ; i++) {
        cin>>a>>b;
        string s=to_string(a+b);

        cout<<s.length()<<endl;
    }

    return 0;
}