//
// Created by jie on 2021/3/14.
//
#include "iostream"
#include <string>
using namespace std;
bool work=false;

string deal(string str){
    string res="";
    for (int i = 0; i <str.length() ; i++) {
        if ((i+1)<str.length()){
            int pre=(str[i]-'0');
            int post=(str[i+1]-'0');
            if (pre<post){
                if (!work){
                    work=true;
                    str[i]=str[i]+1;
                    str[i+1]='0';
                    int k=i-1;
                    while (k>=0&&str[k]<str[k+1]){
                        str[k]=str[k+1];
                        str[k+1]='0';
                        k--;
                    }
                }else{
                    str[i+1]=str[i];
                }

            }
        }
    }
    return str;
}

int main(){
    /*string ss="abc";
    char c1='d';
    ss.push_back(c1);
    cout<<ss;*/
    int count;
    cin>>count;
    string str;
    for (int i = 0; i <count ; i++) {
        cin>>str;
        work=false;
        cout<<"case #"<<i<<":"<<endl;
        cout<<deal(str)<<endl;
    }

    return 0;
}
