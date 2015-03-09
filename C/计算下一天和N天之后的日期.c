#include <stdio.h>
#include <stdlib.h>

struct date
{
	int year;									//定义天 
	int month;									//定义月 
	int day;									//定义天 
};

struct date next_day(struct date in);						//声明计算下一天的函数 
struct date nextN_day(struct date in, int x);					//声明计算N天后日期的函数
void print(struct date in);									//声明输入日期的函数
int leap(int x);											//声明闰年判断的函数

int main()
{
	struct date d;
	struct date r;
	struct date r1;
	int n;
	int i;
	printf("请输入一个 年 月 日:\n");
	scanf("%d %d %d",&d.year, &d.month, &d.day);
	printf("您输入的日期是：\n"); 
	print(d);
	
	printf("它的下一天是:\n");
	r = next_day(d);										 //计算下一天日期 
	print(r);
	
	printf("请输入一个时间长度>(天):");
	scanf("%d",&n);											 //接收天数n 
	
	printf("经过%d天是:\n",n);
	r1 = nextN_day(d,n);										 //计算n天后的日期 
	print(r1);
	return 0;
}

int leap(int x)
{
	if(x%4 == 0 && x%100!=0 || x%400 == 0)				 //定义函数判断是否为闰年 
		return 1;											 //闰年返回1 
	else
		return 0;											 //平年返回0 
}
struct date next_day(struct date in)
{
	int m_day;												 //定义m_day记录每月天数 
	struct date r;
	switch(in.month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: m_day = 31; break;
		case 2: {
				 if(leap(in.year)) m_day = 29;
				 else m_day = 28;
				} 
				break;										  //二月分别按闰年平年计算 
		case 4:
		case 6:
		case 9:
		case 11: m_day = 30; break;							  //确定每一个月的天数 
	}
	if(in.day+1 <= m_day) 
	{
		r.year = in.year;
		r.month = in.month;
		r.day = in.day+1;									  //如果输入的日期加1不最后一天，那么日期加1 
	}
    if(in.day+1 > m_day && in.month != 12)
	{
		r.year = in.year;
		r.month = in.month+1;
		r.day = 1;										 	  //如果输入的日期是当月最后一天，而且不是12月，则月份加1，日置为1 
	}
	if(in.month == 12 && in.day == 31) 
	{
		r.year = in.year+1;
		r.month = 1;
		r.day = 1;											  //如果输入日期是当年最后一天，则年数加1，月和日置为1 
	}	
	return r;
}

struct date nextN_day(struct date in, int x)
{
	struct date re = in;
	while(x--)
	{
		re = next_day(re);									  //通过计算x次下一天的下一天，而最终返回x天后的时间值 
	}
	return re;
}
void print(struct date in)
{
	printf("%d-%02d-%02d\n",in.year,in.month,in.day);		  //定义时间输出格式控制函数 
}
