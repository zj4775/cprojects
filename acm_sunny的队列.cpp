//
// Created by jie on 2021/3/4.
//

#include "iostream"
using namespace std;


int main(){
    int count;
    int n;
    int k;
    int arrays[1000000];
    cin>>count;
    for (int i = 0; i <count ; i++) {
        cin>>n>>k;
        for (int j = 0; j <n ; j++) {
            cin>>arrays[j];
        }
        for (int j = 0; j <=n-k ; j++) {
            int max=arrays[j];
            for (int l = 1; l <k ; l++) {
                if (arrays[j+l]>max){
                    max=arrays[j+l];
                }
            }
            cout<<max<<" ";
        }
        cout<<endl;
    }
    return 0;
}