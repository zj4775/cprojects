//
// Created by jie on 2021/2/28.
//

#include "iostream"
#include <string>
#include <math.h>
using namespace std;

long long Cn(int x,int n){
    if (x==0){
        return 1;
    }
    return n+1-x;
    if(x>n){
        return 0;
    }
    if (x>n/2){
        return Cn(n-x,n);
    }
    long long sum1=1;
    long long sum2=1;
    for(int i = 1; i <=x ; i++) {
        sum1*=i;
    }
    for(int i = n; i >=(n-x)+1 ; i--) {
        sum2*=i;
    }
    return sum2/sum1;

}


int main(){
    string s1;
    int count;
    cin>>s1;
    cin>>count;
    int n;
    char x;
    char y;
    int idx_x=0;
    int idx_y=0;
    string xy;
    for (int i = 0; i <count ; i++) {
        long long total=0;
        long long ycount=0;
        cin>>n>>xy;
        x=xy[0];
        y=xy[1];
        idx_x=s1.find(x,n-2);

        while (idx_x!=string::npos){
            ycount=0;
            idx_y=s1.find(y,idx_x+1);
            while (idx_y!=string::npos){
                ycount++;
                idx_y=s1.find(y,idx_y+1);
            }
            long long xcount=Cn(n-2,idx_x);
            total+=xcount*ycount;
            idx_x=s1.find(x,idx_x+1);
        }
        cout<<total%(long)(pow(10,15)+7)<<endl;
    }

    return 0;
}