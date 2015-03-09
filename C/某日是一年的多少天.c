#include<stdio.h>

int leap(int a)
{ 
    if( a%4 == 0 && a%100 != 0 && a%400 == 0 )			//4年一润，百年不润，400年一润 
      return 1;
    else
      return 0;
}														// 定义函数判断输入的一年是否是闰年 

int num(int y,int m, int d)
{
    int sum=0,i,j,k;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};	//用来记录平年的每个月的天数 
	int b[12]={31,29,31,30,31,30,31,31,30,31,30,31};	//用来记录闰年的每个月的天数 
    if(leap(y) == 1)
    {
       for(i = 0; i < m-1; i++)
          sum += b[i];									//如果是闰年，则使用闰年的数据求和 
    }
    else
    {
       for(i = 0; i < m-1; i++)
          sum += a[i];									//如果是平年，则使用平年的数据求和 
    }
    sum += d;											//再加上号数 
    return sum;											//返回天数 
}

int main()
{
	int y,m,d,n;
  	printf("请输入一个日期:\n");
  	scanf("%d%d%d",&y,&m,&d);
  	n=num(y,m,d);										//调用函数，并且传入参数 年 月 日 
  	printf("它是今年的第%d天\n",n);
  	return 0;
}  

