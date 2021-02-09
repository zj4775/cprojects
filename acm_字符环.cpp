//
// Created by jie on 2021/2/3.
//
#include "iostream"
#include "string"
using namespace std;

#define N 100

bool judge(char* orign,int m,char* sub,int n){
    int i=0;
    int j=0;
    int k=0;
    int t=0;
    if(m<=n){
        return false;
    }
    while (i<2*m-1&&j<n){
        t=i;
        if(t>=m){
            t-=m;
        }
        if (orign[t]==sub[j]){
            i++;
            j++;
        }else{
            i=++k;
            if(k>=m){
                return false;
            }
            j=0;
        }
    }
    return j==n?true:false;
}

int main(){
    int n;
    int m;
    int count;
    char orign[N];
    char sub[N];
    /*cin>>orign>>sub;
    m=strlen(orign);
    n=strlen(sub);
    memcpy(orign+m,sub,n);
    cout<<orign;*/


    cin>>count;
    for (int i = 0; i <count ; i++) {
        cin>>m>>n;
        cin>>orign>>sub;
        if(judge(orign,m,sub,n)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}



