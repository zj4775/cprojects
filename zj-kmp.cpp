//
// Created by jie on 2021/1/11.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "iostream"

#define N 100
using namespace std;

void getnext(char* sub,int* next){
    next[0]=-1;
    int i=0;
    int j=-1;
    int sublen=strlen(sub);
    while (i<sublen) {
        if (j==-1||sub[i]==sub[j]){
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}

int match(char* total,char* sub,int* next){
    int i=0;
    int j=0;
    int totallen=strlen(total);
    int sublen=strlen(sub);
    while (i<totallen&&j<sublen){
        if (total[i]==sub[j]||j==-1){
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if (j==sublen){
        return i-j+1;
    }
    return -1;
}

int main(){
    char* total=(char*)malloc(N);
    char* sub=(char*)malloc(N);
    int* next=(int*)malloc(sizeof(int)*N);
    //cout<<"ÇëÊäÈëÄ¸´®\n";
    //gets(total);
    total="abaabaabcabaabsa";
    //cout<<"ÇëÊäÈë×Ó´®\n";
    //gets(sub);
    sub="abaabd";
    getnext(sub,next);
    int place=match(total,sub,next);
    if (place>-1){
        cout<<"Æ¥Åä£¬Ä¸´®¿ªÊ¼Î»ÖÃ"<<place;
    }else{
        cout<<"²»Æ¥Åä";
    }


}

