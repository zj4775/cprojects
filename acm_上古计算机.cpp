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
    while(cin>>optchar>>params){
        while (optchar!="OUT"){
            int n=params.find(",");
            if (n!=string::npos){
                param1=params.substr(0,n);
                param2=params.substr(n+1);
            }else{
                param1=params;
            }
            if (!isopt(optchar)){
                setvalue(param1,atoi(param2.data()));
            }else{
                if (optchar=="MOV"){
                    setvalue(param2,getvalue(param1));
                }else if(optchar=="ADD"){
                    setvalue(param1,getvalue(param1)+getvalue(param2));
                }else if(optchar=="SUB"){
                    setvalue(param1,getvalue(param1)-getvalue(param2));
                }else if(optchar=="MUL"){
                    setvalue(param1,getvalue(param1)*getvalue(param2));
                }else{
                    if (0==getvalue(param2)){
                        setvalue(param1,0);
                    }else{
                        setvalue(param1,getvalue(param1)/getvalue(param2));
                    }
                }
            }
            cin>>optchar>>params;
        }
        cout<<getvalue(params)<<endl;
        count++;
    }

    return 0;
}
