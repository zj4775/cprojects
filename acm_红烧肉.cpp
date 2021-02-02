#include "iostream"

using namespace std;

int main(){
    int sum=0;
    int tmp=0;
    int n;
    int m;
    cin>>n>>m;
    int array[n][m];
    for (int i = 0; i <n ; i++) {
        for (int j = 0; j <m ; j++) {
            cin>>array[i][j];
        }
    }

    for (int i = 0; i <n ; i++) {
        tmp=0;
        for (int j = 0; j <m ; j++) {
            if (array[i][j]>tmp){
                tmp=array[i][j];
            }
        }
        sum+=tmp;
    }
    cout<<sum;

    return 0;
}

