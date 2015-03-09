#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int year;
	int month;
	int day;	
};

int leap(int year)
{
	if(year%4==0 && year%100!=0 || year%400==0)
	   return 1;
	else return 0;
	   
}

int days(int year ,int month)
{
	if(leap(year)&&month==2) 
		return 29;
	if(month==2) 
		return 28;
	if(month==4 || month==6 || month==9 || month==11)
	    return 30;
	return 31;
}

struct Date nextDay(struct Date d)
{
	if(d.day==days(d.year,d.month))
	{
		d.day = 1;
		d.month=(d.month)%12+1;
		if(d.month==1) d.year++;
	}
	else d.day++; 
	return d;  
}

struct Date nextNDay(struct Date d,int n)
{
	while(n--)
	{
		d = nextDay(d);
	}
	
	return d;  
}

void output(struct Date x)
{
	printf("%d-%02d-%02d\n",x.year,x.month,x.day);
}

int main()
{
	struct Date x,y,z;
	
	printf("请输入一个日期,年 月 日：\n");
	scanf("%d%d%d",&x.year,&x.month,&x.day);
	
	printf("当前输入的日期是:\n");
	output(x);
	
	y = nextDay(x);
	printf("它的下一天是：\n");
	output(y);
	
	int n;
	printf("请输入一段时间>(天)：");
	scanf("%d",&n);
	z = nextNDay(x,n);
	output(z);
	
	return 0;	
}
