//
// Created by jie on 2021/3/14.
//

#include "iostream"
#include <string>
using namespace std;

int dfs(char a[1000][80],bool read[1000][80],int x,int y,int W,int H){
    read[x][y]=true;
    if (a[x][y]=='.'){
        return 0;
    }else{
        int max=0;
        if (x>=1&&read[x-1][y]==false){
            int t=dfs(a,read,x-1,y,W,H);
            max+=t;
            /*if (t>max){
                max+=t;
            }*/
        }
        if (x<H-1&&read[x+1][y]==false){
            int t=dfs(a,read,x+1,y,W,H);
            max+=t;
        }
        if (y>=1&&read[x][y-1]==false){
            int t=dfs(a,read,x,y-1,W,H);
            max+=t;
        }
        if (y<W-1&&read[x][y+1]==false){
            int t=dfs(a,read,x,y+1,W,H);
            max+=t;
        }
        return max+1;
    }
}

int main(){
    int W;
    int H;
    char a[1000][80];
    cin>>W>>H;
    getchar();
    string str;
    bool read[1000][80];
    for (int i = 0; i <H ; i++) {
        getline(cin,str);
        for (int j = 0; j <W ; j++) {
            a[i][j]=str[j];
            read[i][j]=false;
        }
    }
    int max=0;
    for (int i = 0; i <H ; i++) {
        for (int j = 0; j <W ; j++) {
            if (read[i][j]==false){
                int m=dfs(a,read,i,j,W,H);
                if (max<m){
                    max=m;
                }
            }
        }
    }
    cout<<max<<endl;
    return 0;
}