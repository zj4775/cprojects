//
// Created by jie on 2021/3/10.
//

#include "iostream"
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string,int> p1,pair<string,int> p2){
    return tie(p1.second,p2.first)>tie(p2.second,p1.first);
}
int cmp2(const void* pp1,const void* pp2){
    pair<string,int>* p1=(pair<string,int>*)pp1;
    pair<string,int>* p2=(pair<string,int>*)pp2;
    bool flag1= tie(p1->second,p2->first)<tie(p2->second,p1->first);
    bool flag2= tie(p1->second,p2->first)>tie(p2->second,p1->first);
    if (flag1){
        return 1;
    }else if(flag2){
        return -1;
    }else{
        return 0;
    }
}

int main(){
    int count;
    cin>>count;
    int k=0;
    string s;
    int x;
    pair<string,int>  array[100];
    for (int i = 0; i <count ; i++) {
        cin>>s>>x;
        if (x>=60){
            array[k].first=s;
            array[k].second=x;
            k++;
        }
    }
    qsort(array,k,sizeof(pair<string,int>),cmp2);
    //sort(array,array+k,cmp);
    for (int i = 0; i <k ; i++) {
        cout<<array[i].first<<" "<<array[i].second<<endl;
    }
    return 0;
}