//
// Created by jie on 2021/3/4.
//

#include "iostream"
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define N 500000
map<string,bool> existmap;
vector<int> vx;
vector<int> vy;

bool is_exist_pos(int x,int y){
    string key("");
    key.append("x=").append(to_string(x)).append("y=").append(to_string(y));
    return existmap.find(key)==existmap.end()?false:true;
}

int get_next_x(int x){
    vector<int>::iterator it=vx.begin();
    while (it!=vx.end()){
        if (*it==x){
            it++;
            if (it!=vx.end()){
                return *it;
            }else{
                return -1;
            }
        }
        it++;
    }
    return -1;
}

int get_pre_x(int x){
    vector<int>::iterator it=vx.begin();
    while (it!=vx.end()){
        if (*it==x){
            if (it==vx.begin()){
                return -1;
            }else{
                it--;
                return *it;
            }
        }
        it++;
    }
    return -1;
}

int get_next_y(int y){
    vector<int>::iterator it=vy.begin();
    while (it!=vy.end()){
        if (*it==y){
            it++;
            if (it!=vy.end()){
                return *it;
            }else{
                return -1;
            }
        }
        it++;
    }
    return -1;
}

int get_pre_y(int y){
    vector<int>::iterator it=vy.begin();
    while (it!=vy.end()){
        if (*it==y){
            if (it==vy.begin()){
                return -1;
            }else{
                it--;
                return *it;
            }
        }
        it++;
    }
    return -1;
}

int main(){
    set<int> sx;
    set<int> sy;
    int n;
    int x;
    int y;
    long total=0;

    /*vx.push_back(4);
    vx.push_back(5);
    vx.push_back(6);
    int vv=get_pre_x(4);
    cout<<vv;*/

    /*int** map;
    map=(int **)malloc(sizeof(int *)*N);
    map[0]=(int *)malloc(sizeof(int)*N*N);*/
    //memset(map,0,N*N);
    cin>>n;
    /*vector<vector<int>> map(n);
    for (int l = 0; l <n ; l++) {
        map[l].resize(n);
    }*/
    for (int k = 0; k <n ; k++) {
        cin>>x>>y;
        sx.insert(x-1);
        sy.insert(y-1);
        string key("");
        key.append("x=").append(to_string(x-1)).append("y=").append(to_string(y-1));
        existmap.insert(pair<string,bool>(key,true));
    }

    vx.assign(sx.begin(),sx.end());
    vy.assign(sy.begin(),sy.end());

    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());


    int s_x=*(vx.begin());
    int s_y=*(vy.begin());

    for (int i = s_x; i!=-1 ; i=get_next_x(i)) {
        for (int j = s_y; j!=-1 ; j=get_next_y(j)) {
            if (is_exist_pos(i,j)){
                for (int k = get_next_y(j); k!=-1 ; k=get_next_y(k)) {
                    if (is_exist_pos(i,k)){
                        total++;
                    }
                }
                for (int k =get_next_x(i); k!=-1 ; k=get_next_x(k)) {
                    if (is_exist_pos(k,j)){
                        total++;
                    }
                }
                int s_i=i;
                int s_j=j;
                while (s_i!=-1&&s_j!=-1){
                    s_i=get_next_y(s_i);
                    s_j=get_next_x(s_j);
                    while ((s_i-i)!=(s_j-j)&&s_i!=-1&&s_j!=-1){
                        if ((s_i-i)<(s_j-j)){
                          s_i=get_next_y(s_i);
                        }else{
                            s_j=get_next_x(s_j);
                        }
                    }
                    if (s_i!=-1&&s_j!=-1&&is_exist_pos(s_i,s_j)){
                        total++;
                    }
                }

                s_i=i;
                s_j=j;
                while (s_i!=-1&&s_j!=-1){
                    s_i=get_next_y(s_i);
                    s_j=get_pre_x(s_j);
                    while ((s_i-i)!=(j-s_j)&&s_i!=-1&&s_j!=-1){
                        if ((s_i-i)<(j-s_j)){
                            s_i=get_next_y(s_i);
                        }else{
                            s_j=get_pre_x(s_j);
                        }
                    }
                    if (s_i!=-1&&s_j!=-1&&is_exist_pos(s_i,s_j)){
                        total++;
                    }
                }
            }
        }
    }
    cout<<total;

    return 0;
}