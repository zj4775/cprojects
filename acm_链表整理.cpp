//
// Created by jie on 2021/3/13.
//

#include "iostream"
#include <algorithm>
#include <set>
using namespace std;


int main(){
    int count;
    cin>>count;
    int n1;
    int n2;
    int a1[10000];
    int a2[10000];
    int a3[10000];
    set<int> s;
    for (int i = 0; i <count ; i++) {
        cin>>n1>>n2;
        for (int j = 0; j <n1 ; j++) {
            cin>>a1[j];
            a3[j]=a1[j];
        }
        for (int j = 0; j <n2 ; j++) {
            cin>>a2[j];
        }
        s.clear();
        sort(a1,a1+n1);
        sort(a2,a2+n2);
        int l1=0;
        int l2=0;
        while (l1<n1&&l2<n2){
            while (a1[l1]<a2[l2]){
                l1++;
            }
            while (a1[l1]==a2[l2]){
                a1[l1]=INT32_MAX;
                l1++;
            }
            while (a1[l1]>a2[l2]){
                l2++;
            }
        }
        cout<<"case #"<<i<<":"<<endl;
        string str;
        for (int k = 0; k <n1 ; k++) {
            if (a1[k]!=INT32_MAX){
                s.insert(a1[k]);
                //str.append(to_string(a1[k])).append(" ");
            }
        }

        for (int l = 0; l <n1 ; l++) {
            if (s.find(a3[l])!=s.end()){
                str.append(to_string(a3[l])).append(" ");
            }
        }
        if (str.length()>0){
            str=str.substr(0,str.length()-1);
        }
        cout<<str<<endl;


    }

    return 0;
}