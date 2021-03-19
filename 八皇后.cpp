#include<stdio.h>
#include<string.h>
#include <math.h>
#include <iostream>

using namespace std;
#define N 8
#define PI 3.1415926

int count1=0;
void print(int a[])
{
    int i,j;
    count1++;
    printf("这是第%d个方法\n",count1);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",a[i]==j?1:0);
        }
        printf("\n");
    }
    printf("\n\n");
}
void check(int a[],int hang)
{
    int i,lie;
    if(hang==N){print(a);}

    for(lie=0;lie<N;lie++)
    {
        for(i=0;i<hang;i++)
        {
            if(a[i]==lie||a[i]-lie==i-hang||a[i]-lie==hang-i){break;}
        }
        if(i==hang){a[hang]=lie;check(a,hang+1);}//说明所有检查都通过了
    }
}
int main()
{
    int a[N];//记录着第几行的皇后放在第几列
    //check(a,0);
    double  d=sin(PI/6);
    cout<<d<<endl;
    return 0;
}