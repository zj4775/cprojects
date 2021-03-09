#include<iostream>
#include<algorithm>
#include"vector"
using namespace std;
typedef struct student{
    char  name[20];
    int math;
    //按math从大到小排序
    inline bool operator < (const student &x)  {
        return math>x.math ;
    }
};

bool cmp(pair<string,int> p1,pair<string,int> p2){
    return p1<p2;
}


int main(){
    /*student a[4]={{"apple",67},{"limei",90},{"apple",90}};
    sort(a,a+3);
    for(int i=0;i<3;i++)
        cout<<a[i].name <<" "<<a[i].math <<" " <<endl;*/
    vector<pair<string,int>> v;
    v.push_back(pair<string,int>("aa",43));
    v.push_back(pair<string,int>("bb",43));
    v.push_back(pair<string,int>("aa",44));
    v.push_back(pair<string,int>("vv",50));
    sort(v.begin(),v.end());
    for (int i = 0; i <v.size() ; i++) {
        cout<<v[i].first<<v[i].second<<endl;
    }
    return 0;
}