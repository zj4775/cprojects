#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define ok 1
#define error 0
#define yes 1
#define no 0
#define size 50
typedef struct
{
	char elem[size];
	int top;
}seqstack;


int isempty(seqstack *s)
{
	if(s->top==-1){return yes;}
	else{return no;}
}
int isfull(seqstack *s)
{
	if(s->top==size-1){return yes;}
	else{return no;}
}
void push(seqstack *s,char e)
{
	if(isfull(s)){exit(0);}
	else{s->top++;s->elem[s->top]=e;}/*先让top指向0*/
}
void pop(seqstack *s, char *e)
{
	if(isempty(s)){exit(0);}
	else{*e=s->elem[s->top];s->top--;}
}
void gettop(seqstack *s, char *e)
{
	if(isempty(s)){exit(0);}
	else{*e=s->elem[s->top];}
}
int match(char a,char b)
{
	if((a=='(')&&(b==')')||(a=='[')&&(b==']')||(a=='{')&&(b=='}')){return yes;}
	else{return no;}
}
int main()
{
	char a[50];
	int i;
	char ch;
	printf("请输入一个字符串");
	gets(a);

	seqstack s;
	s.top=-1;
	int len=strlen(a);
	

	for(i=0;i<len;i++)
	{
		if(a[i]=='('||a[i]=='['||a[i]=='{'){push(&s,a[i]);}
		else
		{
			gettop(&s,&ch);
			if(match(ch,a[i])){
				pop(&s,&ch);
			}
		}

	}
	if(isempty(&s)){printf("匹配成功");}
	else{printf("匹配不成功");}

    return 0;
}
