//
// Created by jie on 2021/3/10.
//

#include "iostream"
using namespace std;

int Q;
int D;
int N;
int P;
int C;

bool deal(int c,int &count_q,int &count_d,int &count_n,int &count_p){
    count_q=min(c/25,Q);
    c=c-25*count_q;
    count_d=min(c/10,D);
    c=c-10*count_d;
    count_n=min(c/5,N);
    c=c-5*count_n;
    if (P>=c){
        count_p=c;
        return true;
    }else{
        return false;
    }
}

int main(){


    cin>>Q>>D>>N>>P>>C;
    while (!(Q==0&&D==0&&N==0&&P==0&&C==0)){
        int min_q=min(Q,C/25);
        int min_d=min(D,C/10);
        int min_n=min(N,C/5);
        int min_p=min(P,C);
        int min_total=INT32_MAX;
        int total=0;
        int count_q=0;
        int count_d=0;
        int count_n=0;
        int count_p=0;
        for (int i = 0; i <= min_q; i++) {
            for (int j = 0; j <=min_d ; j++) {
                for (int k = 0; k <=min_n ; k++) {
                    for (int l = 0; l <=min_p; l++) {
                        if (C==25*i+10*j+5*k+l){
                            total=i+j+k+l;
                            if (min_total>total){
                                min_total=total;
                                count_q=i;
                                count_d=j;
                                count_n=k;
                                count_p=l;
                            }
                        }
                    }
                }
            }
        }
        if (count_q==0&&count_d==0&&count_n==0&&count_p==0){
            cout<<"Cannot dispense the desired amount."<<endl;
        }else{
            cout<<"Dispense "<<count_q<<" quarters, "<<count_d<<" dimes, "<<count_n<<" nickels, and "<<count_p<<" pennies."<<endl;
        }
        cin>>Q>>D>>N>>P>>C;
    }

    return 0;
}