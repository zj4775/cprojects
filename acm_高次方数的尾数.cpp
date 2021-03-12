//
// Created by jie on 2021/3/11.
//

#include "iostream"
#include <string>
using namespace std;

typedef long long LL ;

LL pow(int x,int n){
    LL sum=1;
    for (int i = 0; i <n ; i++) {
        sum*=x;
    }
    return sum;
}


string deal(LL A,LL B,LL N){
    LL mina=A%pow(10,N);
    LL sum=mina;
    for (int i = 1; i <B ; i++) {
        sum*=mina;
        sum=sum%pow(10,N);
    }
    string str=to_string(sum);
    string res;
    for (int j = 0; j <N-str.length() ; j++) {
        res.append("0");
    }
    res.append(str);
    return res;

}


int main(){
    int T;
    LL A;
    LL B;
    LL N;
    cin>>T;
    for (int i = 0; i <T ; i++) {
        cin>>A>>B>>N;
        string ss=deal(A,B,N);
        cout<<"case #"<<i<<":"<<endl;
        cout<<ss<<endl;
    }

    return 0;
}