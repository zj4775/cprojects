//
// Created by jie on 2021/2/26.
//
#include "iostream"
#include <stack>
#include <string>
using namespace std;

int ax=0;
int bx=0;
int cx=0;
int dx=0;

typedef struct opt{
    string optchar;
    string param1;
    string param2;
} opt;

bool isopt(string optchar){
    if(optchar=="MOV"||optchar=="ADD"||optchar=="SUB"||optchar=="ADD"||optchar=="MUL"||optchar=="DIV"){
        return true;
    }
    return false;
}

void setvalue(string param1,int v){
    if (param1=="AX"){
        ax=v;
    }else if (param1=="BX"){
        bx=v;
    }else if (param1=="CX"){
        cx=v;
    }else{
        dx=v;
    }
}

int getvalue(string param1){
    int v=0;
    if (param1=="AX"){
        v=ax;
    }else if (param1=="BX"){
        v=bx;
    }else if (param1=="CX"){
        v=cx;
    }else{
        v=dx;
    }
    return v;
}

int main(){
    stack<opt> stk;
    string optchar;
    string param1;
    string param2;
    string params;
    int count=0;
    while(cin>>optchar){
        cin>>params;
        if(optchar!="OUT"){
            param1=params.substr(0,2);
            param2=params.substr(3,params.length());
            if(optchar=="IN"){
                setvalue(param1,atoi(param2.data()));
            }else if (optchar=="MOV"){
                setvalue(param1,getvalue(param2));
            }else if(optchar=="ADD"){
                setvalue(param1,getvalue(param1)+getvalue(param2));
            }else if(optchar=="SUB"){
                setvalue(param1,getvalue(param1)-getvalue(param2));
            }else if(optchar=="MUL"){
                setvalue(param1,getvalue(param1)*getvalue(param2));
            }else{
                setvalue(param1,getvalue(param1)/getvalue(param2));
            }
        }else{
            cout<<getvalue(params)<<endl;
        }
    }

    return 0;
}
