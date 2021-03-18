//
// Created by jie on 2021/3/18.
//

#include "iostream"
#include <string>
using namespace std;



int main(){
    string str;
    cin>>str;
    string res="";
    char pre=' ';
    int count=0;
    for (int i = 0; i <str.length() ; i++) {
        if (pre!=str[i]){
            if (count>0){
                res.append(to_string(count)).push_back(pre);
                count=1;
                pre=str[i];
            }else{
                pre=str[i];
                count=1;
            }
        }else{
            count++;
        }
    }
    if (count>0){
        res.append(to_string(count)).push_back(pre);
    }
    cout<<res<<endl;
    return 0;
}