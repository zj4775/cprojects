#include <vector>
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;


bool cmp(string a,string b){
    return (a+b)>(b+a);
}


int main(){
    int n;
    string tmp;
    cin>>n;
    vector<string> array;
    for (int i = 0; i <n ; i++) {
        cin>>tmp;
        array.push_back(tmp);
    }
    sort(array.begin(),array.end(),cmp);
    for (int j = 0; j <n ; j++) {
        cout<<array[j];
    }
    cout<<endl;
    return 0;
}

