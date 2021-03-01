//
// Created by jie on 2021/3/1.
//
#include "iostream"
#include "string"
using namespace std;


int compute(char a,char b,int jwflag){
    return (a-'0')+(b-'0')+jwflag;
}

int main(){
    string s1;
    string s2;
    int s1_len=0;
    int s2_len=0;
    int jwcount=0;
    int jwflag=0;
    cin>>s1>>s2;
    int res=0;
    while (s1!="0"||s2!="0"){
        jwcount=0;
        jwflag=0;
        if (s1=="0"||s2=="0"){
            cout<<0<<endl;
            cin>>s1>>s2;
            continue;
        }
        s1_len=s1.length();
        s2_len=s2.length();
        int i=s1_len-1;
        int j=s2_len-1;
        while (i>=0&&j>=0){
            res=compute(s1[i],s2[j],jwflag);
            if (res>=10){
                jwcount++;
                jwflag=1;
            }else{
                jwflag=0;
            }
            i--;
            j--;
        }
        while (i>=0){
            res=compute(s1[i],'0',jwflag);
            if (res>=10){
                jwcount++;
                jwflag=1;
            }else{
                jwflag=0;
            }
            i--;
        }
        while (j>=0){
            res=compute('0',s2[j],jwflag);
            if (res>=10){
                jwcount++;
                jwflag=1;
            }else{
                jwflag=0;
            }
            j--;
        }
        cout<<jwcount<<endl;
        cin>>s1>>s2;
    }

    return 0;
}
