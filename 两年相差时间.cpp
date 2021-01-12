#include<stdio.h>
struct
{
	int year;
	int month;
	int day;
}date1,date2;
int rn(int k)
{
	int flag;
	if(k%400==0||k%4==0&&k%100!=0)
		flag=1;
	else flag=0;
	return(flag);

}
int main()
{ 
	int i,days1=0, sum=0,days2=0;
	int day_tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

	printf("请输入早期的年月日:\n");
	scanf("%d,%d,%d",&date1.year,&date1.month,&date1.day);

    printf("请输入后期的年月日:\n");
	scanf("%d,%d,%d",&date2.year,&date2.month,&date2.day);

   for(i=date1.year;i<date2.year;i++)
   {
	   if(rn(i)){sum=sum+365;}
	   else {sum=sum+366;}
   }
	

	for(i=0;i<date1.month;i++)
	{
		days1=days1+day_tab[i]; 

	}
    days1=days1+date1.day;

	if(rn(date1.year)&&date1.month>2)
	{
		days1=days1+1;

	}

    for(i=0;i<date2.month;i++)
	{
		days2=days2+day_tab[i]; 

	}
	
    days2=days2+date2.day;

	if(rn(date2.year)&&date2.month>2)
	{
		days2=days2+1;

	}
	sum=sum-days1+days2;
	printf("两个时间段差了%d天",sum);
	return 0;
}
