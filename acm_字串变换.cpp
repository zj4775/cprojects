//
// Created by jie on 2021/3/6.
//

#include "iostream"
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int temp[100][10000];

struct node{
    string minstr;
};



node deal(string str,int idx){
    node n1;
    string pre;
    string res;
    int count=-1;
    for (int i = 0; i <str.length() ; i++) {
        string sub=str.substr(i,1);
        if (sub!=pre){
            n1.minstr.append(sub);
            pre=sub;
            temp[++count][idx]=1;
            //n1.mmap[++count]=1;
        }else{
            temp[count][idx]++;
            //n1.mmap[count]++;
        }
    }
    return n1;
}

void convert(int* array,int s,int e){
    int tmp=array[s];
    array[s]=array[e];
    array[e]=tmp;
}





int abs(int a,int b){
    return a>b?a-b:b-a;
}

int main(){
    vector<node> v;
    int count;
    cin>>count;
    string str;
    int sum;
    string minstr;
    int k=0;
    int minlen=-1;
    cin>>str;
    node first=deal(str,0);
    minstr=first.minstr;
    minlen=minstr.length();
    for (int i = 1; i < count; i++) {
        cin>>str;
        node tmp=deal(str,i);
        if (minstr!=tmp.minstr){
            cout<<-1;
            return 0;
        }
        /*for (int j = 0; j <minlen ; j++) {
            temp[j]=tmp.mmap;
        }
        v.push_back(tmp);*/
    }
    int mid;
    if (minstr.length()%2==0){
        mid=minstr.length()/2-1;
    }else{
        mid=minstr.length()/2;
    }
    //int temp[v.size()];
    for (int l = 0; l <minstr.length() ; l++) {
        sort(temp[l],temp[l]+count);
        int midv=*(temp[l]+mid);



        /*idx=l;
        sort(v.begin(),v.end(),cmp);
        node midnode= v.at(mid);
        int midv=midnode.mmap[l];*/
        for (int i = 0; i <count ; i++) {
            sum+=abs(temp[l][i],midv);
        }
    }
    cout<<sum<<endl;

    return 0;
}