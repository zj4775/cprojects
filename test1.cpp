#include<iostream>
#include<algorithm>
#include"vector"
using namespace std;
typedef struct student{
    char  name[20];
    int math;
    //��math�Ӵ�С����
    inline bool operator > (const student &x)  {
        return math>x.math ;
    }
};
int main(){
    student a[4]={{"apple",67},{"limei",90},{"apple",90}};
    sort(a,a+3);
    for(int i=0;i<3;i++)
        cout<<a[i].name <<" "<<a[i].math <<" " <<endl;
    return 0;
}