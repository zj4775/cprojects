//
// Created by jie on 2021/3/5.
//

#include "iostream"
#include <set>
#include <math.h>
#include <map>
using namespace std;

typedef long long LL ;

LL mypow(int x,int n){
    LL k=1;
    for (int i = 0; i <n ; i++) {
        k*=x;
    }
    return k;
}

LL rfn(string str,int len){
    LL sum=0;
    int k=0;
    int idx=0;
    bool flag=true;
    map<char,int> mmap;
    for (int j = str.length()-1; j >=0 ; j--) {
        map<char,int>::iterator it= mmap.find(str[str.length()-1-j]);
        if (it==mmap.end()){
            if (j==str.length()-1){
                k=1;
            }else if(flag){
                flag=false;
                k=0;
                idx++;
            }else{
                k=++idx;
            }
            mmap.insert(pair<char,int>(str[str.length()-1-j],k));
        }else{
            k=it->second;
        }
        int pown=len;
        if(pown==1){
            pown=2;
        }
        sum+=k*mypow(pown,j);
    }
    //2177399
    return sum;
}

LL two2ten(string str){
    int len=str.length();
    LL sum=0;
    for (int i = 0; i < len; i++) {
        sum+=(str[i]-'0')*pow(2,len-1-i);
    }
    return sum;
}

LL min(string str){
    if (str.length()==1){
        return 1;
    }
    set<char> s;
    for (int i = 0; i <str.length() ; i++) {
        s.insert(str[i]);
    }
    int len=s.size();
    return rfn(str,len);
    /*if (len==1){
        return 1;
    }else{
        return rfn(str,len);
    }*/

}


int main(){
    //int ss=two2ten("1101");
    //fn(11,3);
    int count;
    string str;
    cin>>count;
    for (int i = 0; i <count ; i++) {
        cin>>str;
        cout<<"case #"<<i<<":"<<endl;
        cout<<min(str)<<endl;
    }

    return 0;
}