#include<stdio.h>
#include <stdlib.h>
#include "math.h"
#include "iostream"
#include "iomanip"
using namespace std;

typedef struct ;

void xiebian(){
    int a;
    int b;
    double c;
    cout.setf(ios::fixed);
    cout<<setprecision(3);
    while (cin>>a>>b){
        c=sqrt(pow(a,2)+pow(b,2));
        cout<<c<<endl;
    }
}


int main(){

    return 0;
}