#include<stdio.h>
int leap(int y)
{
	if((y%4 == 0) && (y%100 != 0) || (y%400 == 0))
		return 1;
	else 
		return 0;										//函数判断闰年 
}

int l(int n)
{
	int a[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	return a[n];
}														//记录闰年每月天数 

int nl(int n)
{
	int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	return a[n];
}														//记录平年每月天数		

int main()
{
	int year,month,day;
	int sum = 0;
	scanf("%d%d%d", &year,&month,&day);
	if(leap(year)) 										//如果是闰年 
    {	
    	if((month == 12) && (day == 31)) 
			printf("%d %d %d", year + 1,1,1);			//如果是年末直接输出下一年的1月1号 
        else if((day + 1) <= l(month - 1)) 
			printf("%d %d %d", year,month,(day + 1));	//如果是一个月之间的一天，则正常输入下一天 
    	else   
			printf("%d %d %d", year,(month + 1),1);		//如果是月末则输出下月第一天 
    }
    else												//如果是平年 
    {
    	if((month == 12) && (day == 31)) 
			printf("%d %d %d", year + 1,1,1);			//同上 
        else if((day + 1) <= nl(month - 1)) 
			printf("%d %d %d", year,month,(day + 1));	//同上 
    	else 
			printf("%d %d %d", year,month + 1,1);		//同上 
    }
	return 0;
}
