//
// Created by jie on 2021/3/8.
//

#include "iostream"
#include <vector>
using namespace std;

typedef struct node{
    long R;
    long H;
};

bool cmp(node n1,node n2){
    return (2*n1.R*n1.H-n1.R*n1.R)<(2*n2.R*n2.H-n2.R*n2.R);
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<node> v;
    for (int i = 0; i <n ; i++) {
        node n;
        cin>>n.R>>n.H;
        v.push_back(n);
    }
    sort(v.begin(),v.end(),cmp);
    long sum=0;
    for (int j = 0; j <m ; j++) {
        node n1=v[j];
        sum+=(2*n1.R*n1.H+n1.R*n1.R);
    }
    sum+=v[m-1].R*v[m-1].R;
    cout<<sum<<endl;
    return 0;
}