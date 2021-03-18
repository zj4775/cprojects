//
// Created by jie on 2021/3/18.
//

#include "iostream"
#include <string>
using namespace std;



int main(){
    string str;
    cin>>str;
    if (str[0]>'0'&&str[0]<'9'){
        cout<<"no"<<endl;
        return 0;
    }else{
        for (int i = 0; i <str.length() ; i++) {
            if (!((str[i]>='a'&&str[i]<='z')||str[i]=='_'||(str[i]>='0'&&str[i]<='9'))){
                cout<<"no"<<endl;
                return 0;
            }
        }
        cout<<"yes"<<endl;
    }


    return 0;
}