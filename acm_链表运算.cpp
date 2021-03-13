//
// Created by jie on 2021/3/10.
//

#include "iostream"
using namespace std;

typedef struct Node { char value[100]; struct Node *next; }NODE;


NODE *input()
{
    NODE *h=0,*p;
    do {
        p=(NODE*)malloc(sizeof(NODE));
        scanf("%s",p->value);
        p->next=h;
        h=p;
    }
    while (getchar()!='\n');
    return h;
}

double Evaluate(NODE *expr)
{
    
}

int main(){
    int i,t; scanf("%d\n",&t);
    for (i=0;i<t;i++) printf("case #%d:\n%.2f\n",i,Evaluate(input()));

    return 0;
}