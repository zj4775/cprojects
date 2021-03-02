//
// Created by jie on 2021/3/2.
//

#include "iostream"
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int d;

typedef struct car{
    int d;
    int s;
};

bool cmp(car c1,car c2){
    double t1=(double)(d-c1.d)/c1.s;
    double t2=(double)(d-c2.d)/c2.s;
    return t1>t2?true:false;
}


int main(){
    int count;
    vector<car> cars;
    cin>>d;
    cin>>count;
    for (int i = 0; i <count ; i++) {
        car c;
        cin>>c.d>>c.s;
        cars.push_back(c);
    }
    sort(cars.begin(),cars.end(),cmp);
    double v=(double)d*cars.begin()->s/(d-cars.begin()->d);
    cout<<setprecision(6)<<fixed<<v;

    return 0;
}