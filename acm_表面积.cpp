//
// Created by jie on 2021/3/8.
//

#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node{
    long R;
    long H;
    long S;
};

bool cmp(node n1,node n2){
    return n1.S>n2.S;
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<node> v;
    for (int i = 0; i <n ; i++) {
        node n;
        cin>>n.R>>n.H;
        n.S=2*n.R*n.H;
        v.push_back(n);
    }
    sort(v.begin(),v.end(),cmp);
    long sum=0;
    int count=0;
    long maxsum=0;
    for (int j = 0; j <v.size() ; j++) {
        node n1=v[j];
        sum=n1.S+n1.R*n1.R;
        count=1;
        for (int i = 0; i <v.size()&&count<m ; i++) {
            node n2=v[i];
            if (j!=i&&n2.R<=n1.R){
                sum+=n2.S;
                count++;
            }
        }
        if (count==m){
            maxsum=max(maxsum,sum);
        }
    }
    cout<<maxsum<<endl;
    return 0;
}