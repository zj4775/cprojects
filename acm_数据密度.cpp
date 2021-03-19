//
// Created by jie on 2021/3/13.
//

#include "iostream"
#include <string>
using namespace std;

int convert(char c1){
    int x=1;
    int count_one=0;
    for (int i = 0; i <8 ; i++) {
        if (c1&x){
            count_one++;
        }
        x=x<<1;
    }
    return count_one;
}

int gys(int n1,int n2){
    int a;
    int b;
    if (n1>=n2){
        a=n1;
        b=n2;
    }else{
        a=n2;
        b=n1;
    }
    int w=0;
    while (b!=0){
        int w=a%b;
        a=b;
        b=w;
    }
    return a;
}

void deal(string str,int &fz,int &fm){
    char c;
    int sumfz=0;

    for (int i = 0; i <str.length() ; i++) {
        sumfz+=convert(str[i]);
    }
    int sumfm=str.length()*8;
    int w=gys(sumfz,sumfm);
    fz=sumfz/w;
    fm=sumfm/w;
}

int main(){
    int count;
    cin>>count;
    getchar();
    string str;
    int fz;
    int fm;
    for (int i = 0; i <count ; i++) {
        getline(cin,str);
        deal(str,fz,fm);
        cout<<fz<<"/"<<fm<<endl;
    }

    return 0;
}