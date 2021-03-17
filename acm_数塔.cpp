//
// Created by jie on 2021/3/14.
//

#include "iostream"
using namespace std;
#define N 100

int mmin(int a[N][N],int x,int y,int &min){
    int m=0;
    min=a[x+1][y];
    if (y>=1&&a[x+1][y-1]<min){
        min=a[x+1][y-1];
        m=-1;
    }
    if (a[x+1][y+1]<min){
        min=a[x+1][y+1];
        m=1;
    }
    return m;
}

int deal(int a[N][N],int n){
    int x=0;
    int y=0;
    int sum=a[x][y];
    int min;
    while (x<n-1){
        int m=mmin(a,x,y,min);
        if (m==0){
            x++;
        }else if(m==-1){
            x+=1;
            y-=1;
        }else{
            x+=1;
            y+=1;
        }
        sum+=min;
    }
    return sum;
}

int dfs(int a[N][N],int x,int y,int n){
    if (x==n-1){
        return a[x][y];
    }else{
        int left=dfs(a,x+1,y,n);
        int right=dfs(a,x+1,y+1,n);
        return a[x][y]+min(left,right);
    }
}

int main(){
    int count;
    cin>>count;
    int n;
    int a[N][N];
    for (int i = 0; i <count ; i++) {
        cin>>n;
        for (int j = 0; j <n; j++) {
            for (int k = 0; k <=j ; k++) {
                cin>>a[j][k];
            }
        }
        cout<<dfs(a,0,0,n)<<endl;
    }

    return 0;
}