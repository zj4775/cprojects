//
// Created by jie on 2021/3/14.
//

#include "iostream"
#include <vector>
using namespace std;


int main(){
    int n;
    int m;
    int l;
    int r;
    int small;
    int big;
    int innersmall;
    int innerbig;
    pair<int,int> v1[500000];
    pair<int,int> v2[500000];

    //vector<pair<int,int>> v1;
    //vector<pair<int,int>> v2;
    cin>>n>>m;
    for (int i = 0; i <n ; i++) {
        cin>>l>>r;
        v1[i].first=l;
        v1[i].second=r;
    }
    for (int i = 0; i <m ; i++) {
        cin>>l>>r;
        v2[i].first=l;
        v2[i].second=r;
    }
    int total=0;
    int idx1=0;
    int idx2=0;
    while (idx2<m){
        idx1=0;
        int sum=0;
        pair<int,int> p2=v2[idx2];
        small=p2.first;
        big=p2.second;
        while (idx1<n){
            pair<int,int> p1=v1[idx1];
            innersmall=p1.first;
            innerbig=p1.second;
            if ((small>=innersmall&&small<=innerbig)||(innerbig>=small&&innerbig<=big)||(innersmall>=small&&innersmall<=big)||(big>=innersmall&&big<=innerbig)){
                sum++;
            }
            idx1++;
        }
        total+=sum;
        idx2++;
    }
    cout<<total<<endl;
    return 0;
}