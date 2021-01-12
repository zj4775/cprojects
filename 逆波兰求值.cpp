#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
	int ele[MAX_SIZE];
	int top;
}stack;

void init_stack(stack** s){
	*s=(stack*)malloc(sizeof(stack));
	(*s)->top=-1;
}

void push(stack* s,int x){
	if (s->top==MAX_SIZE-1)
	{
		printf("FULL\n");
		exit(1);
	}
	else{
		s->ele[++s->top]=x;
	}
}

int gettop(stack* s){
	return s->ele[s->top];
}

int pop(stack* s){
	if(s->top==-1){
		printf("EMPTY\n");
		exit(1);
	}else{
		return s->ele[s->top--];
	}
}

bool is_opt_char(char x){
	if (x=='+'||x=='-'||x=='*'||x=='/')
	{
		return true;
	}
	return false;
}

int compute(int x,int y,char opt){
	if (opt=='+')
	{
		return x+y;
	}else if (opt=='-')
	{
		return x-y;
	}else if (opt=='*')
	{
		return x*y;
	}else if (opt=='/')
	{
		return x/y;
	}else{
		printf("操作符不支持");
		exit(1);
	}
}	





int main(){
	printf("请输入一个字符串:\n");
	char _array[MAX_SIZE];
	char tmp[MAX_SIZE];
	gets(_array);
	stack* s;
	init_stack(&s);
	int length=strlen(_array);
	int idx=0;
	int num;
	for (int i=0;i<length;i++)
	{
		if (is_opt_char(_array[i]))
		{
			num=atoi(tmp);
			push(s,num);
			memset(tmp,0,MAX_SIZE);
			idx=0;
			int b=pop(s);
			int a=pop(s);
			int c=compute(a,b,_array[i]);
			push(s,c);
		}else if (_array[i]==' '){
			num=atoi(tmp);
			push(s,num);
			memset(tmp,0,MAX_SIZE);
			idx=0;
		}
		else{
			tmp[idx++]=_array[i];
		}
	}
	int res=pop(s);
	printf("结果是:%d",res);
    return 0;
}