//
// Created by jie on 2021/3/13.
//

#include "iostream"
#include <vector>
#include <time.h>
using namespace std;


void fun1(vector<int> a){
    int minIndex;
    clock_t t1=clock();
    for (int i = 0; i < a.size() - 1; i++) {
        minIndex = i; // 无序区的最小数据数组下标
        for (int j = i + 1; j < a.size(); j++)
            // 在无序区中找到最小数据并保存其数组下标
            if (a[j] < a[minIndex])
                minIndex = j;
        int t = a[i];
        a[i] = a[minIndex];
        a[minIndex] = t;
    }
    clock_t t2=clock();
    cout<<"fun1:"<<(t2-t1)/CLOCKS_PER_SEC<<endl;
}

void fun2(vector<int> a ){
    clock_t t1=clock();
    int n=a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    }
    clock_t t2=clock();
    cout<<"fun2:"<<(t2-t1)/CLOCKS_PER_SEC<<endl;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n=50000;
    //cout<<n<<endl;
    vector<int> v;
    vector<int> v2;
    for (int i = 0; i <n ; i++) {
        //cout<<(n-i)<<" ";
        v.push_back(n-i);
        v2.push_back(n-i);
    }
    fun1(v);
    fun2(v2);



    return 0;
}