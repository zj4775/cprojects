//
// Created by jie on 2021/2/7.
//
#include "iostream"
#include "algorithm"
using namespace std;

typedef struct student{
    int id;
    char name[100];
    int score1;
    int score2;
    int score3;
};

bool cmp(student s1,student s2){
    double avg1=(s1.score1+s1.score2+s1.score3)/3;
    double avg2=(s2.score1+s2.score2+s2.score3)/3;
    if (avg1==avg2){
        return s1.id<s2.id;
    }else{
        return avg1>avg2;
    }
}


int main(){
    int count;
    int n;
    student students[100];
    cin>>count;
    for (int i = 0; i <count ; i++) {
        cin>>n;
        for (int j = 0; j <n ; j++) {
            cin>>students[j].id>>students[j].name>>students[j].score1>>students[j].score2>>students[j].score3;
        }
        sort(students,students+n,cmp);
    }
    for (int i = 0; i <count ; i++) {
        cout<<"case #"<<i<<":"<<endl;
        for (int j = 0; j <n ; j++) {
            cout<<students[j].id<<" "<<students[j].name<<" "<<students[j].score1<<" "<<students[j].score2<<" "<<students[j].score3<<endl;
        }
    }
    return 0;
}
