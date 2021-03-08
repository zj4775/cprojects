//
// Created by jie on 2021/3/2.
//
#include "iostream"
#include <vector>
using namespace std;



int main(){
    vector<int> v;
    int count;
    //cin>>count;
    int x;
    for (int i = 0; i <10 ; i++) {
        //cin>>x;
        v.push_back(i*i);
    }
    vector<int>::iterator it2=v.begin();
    int a=0;
    while (it2!=v.end()){
        a++;
        it2++;
    }
    //cout<<a<<endl;

    vector<int>::reverse_iterator it3=v.rbegin();
    int b=0;
    while (it3!=v.rend()){
        b++;
        cout<<*it3<<endl;;
        it3++;
    }
    cout<<b<<endl;;

    cout<<"max_size:"<<v.max_size()<<endl;
    cout<<"capacity:"<<v.capacity()<<endl;
    cout<<"size:"<<v.size()<<endl;

    vector<int>::iterator  it20;
    vector<int>::iterator  it60;

    vector<int>::iterator  it;
    for (it=v.begin();it!=v.end();it++) {
        if (*it%5==0){
            v.erase(it);
        }
        if (*it==33){
            it20=it;
        }
        if (*it==66){
            it60=it;
        }
    }

    v.erase(it20,it60);
    cout<<"max_size2:"<<v.max_size()<<endl;
    cout<<"capacity2:"<<v.capacity()<<endl;
    cout<<"size2:"<<v.size()<<endl;
    sort(v.begin(),v.end());
    for (it=v.begin();it!=v.end();it++) {
        cout<<*it<<"  ";
    }

    return 0;
}
