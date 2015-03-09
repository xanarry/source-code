#include<stdio.h>
int leap(int y)
{
	if((y%4 == 0) && (y%100 != 0) || (y%400 == 0))
		return 1;
	else 
		return 0;				//定义函数判断是否闰年 
}
int leapmonth(int ym)
{
	int i,s1 = 0;
	int a[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	for(i = 0; i < ym-1; i++)
	s1 += a[i];
	return s1;					//定义函数计算闰年所以月的天数 
}
int notleapmonth(int nym)
{
	int i,s2 = 0;
	int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	for(i = 0; i < nym-1; i++)
	s2 += a[i];
	return s2;					//定义函数计算平年所以月的天数
}
int main()
{
	int year,month,day;
	int sum = 0;
	scanf("%d%d%d", &year,&month,&day);		
	if(leap(year)) 
	{
		sum = leapmonth(month) + day;		//调用函数计算闰年天数 
	}
	else
	{
		sum = notleapmonth(month) + day;	//调用函数计算闰平年天数
	}
	printf("%d",sum);						//输出结果 
	return 0; 
}
