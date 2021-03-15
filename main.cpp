#include<stdio.h>
#include <stdlib.h>
#include "math.h"
#include "iostream"
#include "iomanip"
using namespace std;

typedef struct date{
    int year;
    int month;
    int day;
};

bool is_rn(int year){
    if (year%400==0||(year%100!=0&&year%4==0))
        return true;
    return false;
}

void date_diff(){
    date d1;
    date d2;
    int diff=0;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    cout<<"�������һ������"<<endl;
    cin>>d1.year>>d1.month>>d1.day;
    cout<<"������ڶ�������"<<endl;
    cin>>d2.year>>d2.month>>d2.day;
    cout<<"��һ�������ǣ�"<<d1.year<<"-"<<d1.month<<"-"<<d1.day;
    cout<<"�ڶ��������ǣ�"<<d2.year<<"-"<<d2.month<<"-"<<d2.day;
    for (int i = d1.year; i <d2.year ; ++i) {
        diff+=365;
        if(is_rn(i)){
            diff+=1;
        }
    }
    int d1days=0;
    for (int j = 1; j <=d1.month -1; ++j) {
        d1days+=month[j-1];
    }
    if(d1.month>2&&is_rn(d1.year)){
        d1days++;
    }
    d1days+=d1.day;

    int d2days=0;
    for (int j = 1; j <=d2.month -1; ++j) {
        d2days+=month[j-1];
    }
    if(d2.month>2&&is_rn(d2.year)){
        d2days++;
    }
    d2days+=d2.day;

    int diffdays=diff+d2days-d1days;
    cout<<"������������������"<<diffdays;





}

void xiebian(){
    int a;
    int b;
    double c;
    cout.setf(ios::fixed);
    cout<<setprecision(3);
    while (cin>>a>>b){
        c=sqrt(pow(a,2)+pow(b,2));
        //cout<<setprecision(2)<<fixed<<c<<endl;
        cout<<c<<endl;
    }
}

int compare(const void *a, const void *b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    return (*pa )- (*pb);  //��С��������
}

int main(){
    //date_diff();
    int a[10] = {5, 6, 4, 3, 7, 0 ,8, 9, 2, 1};
    qsort(a, 10, sizeof(int), compare);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " " << endl;

    return 0;
}