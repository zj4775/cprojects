#include<stdio.h>
#include<string.h>

typedef struct
{
    int num;
    char s[100];
}string;
void getnext(string s,int next[])//就考这个东西
{
    int i,j;

    i=1;
    j=0;
    next[1]=0;

    while(i<s.num)
    {
        if(j==0||s.s[i]==s.s[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}
void pp(string s,string sub,int next[])
{
    int i,j;
    i=j=1;
    while(i<=s.num&&j<=sub.num)
    {
        if(s.s[i]==sub.s[j]||j==0){i++;j++;}
        else{j=next[j];}
    }
    if(j>sub.num){printf("匹配成功并且在母串的第%d个位置",i-sub.num);}
    else{printf("匹配不成功");}


}



int main()
{
    int i;
    string mu,zi;
    int m,n,next[20];
    printf("请输入母串个数");
    scanf("%d",&m);
    mu.num=m;
    printf("请输入母串");
    getchar();
    for(i=1;i<=m;i++)
    {
        scanf("%c",&mu.s[i]);
    }



    getchar();

    printf("请输入子串个数");
    scanf("%d",&n);
    zi.num=n;


    printf("请输入子串");
    getchar();
    for(i=1;i<=n;i++)
    {
        scanf("%c",&zi.s[i]);
    }


    getnext(zi,next);


    pp(mu,zi,next);
    return 0;



}
