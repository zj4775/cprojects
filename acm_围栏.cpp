//
// Created by jie on 2021/2/28.
//

#include "iostream"
#include <string>
using namespace std;


int main(){
    string s1;
    int maxlen=1;
    int k=0;
    int len=1;
    cin>>s1;
    for (int i = 1; i <s1.length() ; i++) {
        if (s1[i]!=s1[i-1]){
            len++;
        }else{
            if (len>maxlen){
                maxlen=len;
                k=i-len;
            }
            len=1;
        }
    }
    if(len>maxlen){
        maxlen=len;
    }
    cout<<maxlen;
    return 0;
}