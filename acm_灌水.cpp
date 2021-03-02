//
// Created by jie on 2021/3/2.
//
#include "iostream"
#include <vector>
using namespace std;



int main(){
    vector<int> set;

    int count;
    while (cin>>count){
        int array[51];
        int k=0;
        int x;
        bool first=false;
        for (int i = 0; i <count ; i++) {
            cin>>x;
            if (x>=2&&x<=4&&!first){
                array[k++]=1;
                array[k++]=1;
                first=true;
            }else{
                array[k++]=x;
            }
        }
        if (first){
            count++;
            for (int j = 0; j <count ; j++) {
                cout<<array[j]<<" ";
            }
        }else{
            cout<<"Deep Dark Fantasy of ECNU";
        }
        cout<<endl;
    }

    return 0;
}
