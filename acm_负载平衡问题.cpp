//
// Created by jie on 2021/3/13.
//

#include "iostream"
using namespace std;


int main(){
    int count;
    cin>>count;
    int a[100];
    int s = 0;
    int ans = 99999;
    int ave;
    for (int i = 0; i <count ; i++) {
        cin >> a[i];
        s += a[i];
    }
    ave = s/count;
    for (int i = 0; i < count; i++){
        a[i] -= ave;
    }
    for (int i = 0; i < count; i++)
    {
        int t = 0, x = 0;
        for (int j = 0; j < count - 1; j++)
        {
            t += a[(j + i)%count];
            x += abs(t);
        }
        ans = min(x, ans);
    }
    cout << ans << endl;
    return 0;
}