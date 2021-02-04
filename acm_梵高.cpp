//
// Created by jie on 2021/2/4.
//
#include "iostream"
using namespace std;
#define N 20


int main(){
    int array[N][N]={0};
    int n;
    cin>>n;
    for (int i = 0; i <n ; i++) {
        array[i][0]=1;
        array[i][i]=1;
    }
    for (int i = 1; i <n ; i++) {
        for (int j = 1; j <= i; j++) {
            array[i][j]=array[i-1][j]+array[i-1][j-1];
        }
    }
    for (int i = 0; i <n ; i++) {
        for (int j = 0; j <= i; j++) {
            if (array[i][j]!=0){
                cout<<array[i][j];
            }
            if (i!=j){
                cout<<" ";
            }
        }
        cout<<endl;
    }



    return 0;
}