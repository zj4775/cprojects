//
// Created by jie on 2021/3/3.
//
#include "iostream"
#include <string>
using namespace std;
char array1[18][18];
int read[18];
int len;
int max;

int getnext(int x,int k){
    for (int i = k; i <len ; i++) {
        if (array1[x][i]=='Y'&&read[i]==0){
            return i;
        }
    }
    return -1;
}

void dfs(int x,int* deep,int* max){
    read[x]=1;
    int idx=getnext(x,0);
    while (idx!=-1){
        if (read[idx]==0){
            dfs(idx,deep,max);
        }
        idx=getnext(x,idx);
    }


    /*if (read[x]==0){

        for (int i = 0; i <len ; i++) {
            if (array1[x][i]=='Y'&&read[i]==0){
                *deep=*deep+1;
                read[x]=1;
                dfs(orign,i,deep,max);
                read[x]=0;
            }
            *//*if (x==orign){
                if (*deep>*max){
                    *max=*deep;
                }
                *deep=0;
            }*//*

        }
        //read[x]=0;
        //read[x]=1;
    }*/
}


int getmaxdeep(){
    int maxlen=0;
    for (int i = 0; i <len ; i++) {
        int deep=0;
        int max=0;
        dfs(i,i,&deep,&max);
        if (max>maxlen){
            maxlen=max;
        }
    }
    return maxlen;
}

int main(){
    int count;
    string ss;
    cin>>count;
    for (int i = 0; i <count ; i++) {
        memset(read,0,18);
        memset(array1,'0',18*18);
        cin>>len;
        getchar();
        for (int j = 0; j <len ; j++) {
            getline(cin,ss);
            ss.copy(array1[j],len,0);
            //strcpy(*(array+j*18),ss.c_str());
        }
        int max=getmaxdeep();
        cout<<max<<endl;

    }
    /*for (int i = 0; i <len ; i++) {
        for (int j = 0; j <len ; j++) {
            cout<<array1[i][j];
        }
        cout<<endl;
    }*/


    return 0;
}
