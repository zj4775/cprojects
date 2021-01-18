//
// Created by jie on 2021/1/18.
//

#include "iostream"
#include<algorithm>
using namespace std;

typedef struct team{
    int score;
    int wincount;
    int defeatcount;
    int idx;
    inline bool operator < (const team &x) const {
        if (score>x.score){
            return true;
        }else if(score<x.score){
            return false;
        }else{
            if (wincount>x.wincount){
                return true;
            }else if(wincount<x.wincount){
                return false;
            }else{
                if (defeatcount<x.defeatcount){
                    return true;
                }else if(defeatcount>x.defeatcount){
                    return false;
                }else{
                    return idx<x.idx?true:false;
                }
            }
        }
    }
};

/*bool cmp(const team &t1,const team &t2){
    if (t1.score>t2.score){
        return true;
    }else if(t1.score<t2.score){
        return false;
    }else{
        if (t1.wincount>t2.wincount){
            return true;
        }else if(t1.wincount<t2.wincount){
            return false;
        }else{
            if (t1.defeatcount<t2.defeatcount){
                return true;
            }else if(t1.defeatcount>t2.defeatcount){
                return false;
            }else{
                return t1.idx<t2.idx?true:false;
            }
        }
    }
}*/

int main(){
    int n;
    int m;
    int a;
    int b;
    int c;
    team teams[10];

    while (cin>>n>>m){
        cin.ignore();
        if (n==0&&m==0){
            break;
        }
        for (int i = 0; i <n ; i++) {
            teams[i].idx=i;
            teams[i].score=0;
            teams[i].wincount=0;
            teams[i].defeatcount=0;
        }

        for (int j = 0; j <m ; j++) {
            cin>>a>>b>>c;
            if (c==1){
                teams[a-1].wincount++;
                teams[a-1].score+=3;
                teams[b-1].defeatcount++;
                teams[b-1].score-=1;
            }else if(c==-1){
                teams[b-1].wincount++;
                teams[b-1].score+=3;
                teams[a-1].defeatcount++;
                teams[a-1].score-=1;
            }else if(c==0){
                teams[a-1].score+=1;
                teams[b-1].score+=1;
            }
        }

        sort(teams,teams+n);
        for (int k = 0; k <n ; k++) {
            cout<<teams[k].idx+1;
            if (k!=n-1){
                cout<<" ";
            }else{
                cout<<endl;
            }
        }
    }

    return 0;
}
