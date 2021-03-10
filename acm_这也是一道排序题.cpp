//
// Created by jie on 2021/3/10.
//

#include "iostream"
using namespace std;



int main(){
    int total;
    long array[100000];
    cin>>total;
    for (int i = 0; i <total ; i++) {
        cin>>array[i];
    }
    bool work=true;
    while (work){
        work=false;
        for (int j = 1; j <total-1 ; j++) {
            if (array[j+1]+array[j-1]<2*array[j]){
                array[j]=array[j+1]+array[j-1]-array[j];
                work=true;
            }
        }
    }

    long sum;
    for (int i = 0; i <total ; i++) {
        sum+=array[i];
    }
    cout<<sum<<endl;

    return 0;
}