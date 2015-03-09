#include<stdio.h>
int f5(int x)
{ 
       int t1,t2,t3,t4,t5;
	   t1=x/10000;
	   t2=(x-t1*10000)/1000;
	   t3=(x-t1*10000-t2*1000)/100;
	   t4=(x-t1*10000-t2*1000-t3*100)/10;
	   t5=x%10;								//不断分离每个数 
	   printf("%d %d %d %d %d\n%d %d %d %d %d",t1,t2,t3,t4,t5,t5,t4,t3,t2,t1);
}											//再正反序输出 
int f4(int x)
{
	   int t1,t2,t3,t4;
       t1=x/1000;
	   t2=(x-t1*1000)/100;
	   t3=(x-t1*1000-t2*100)/10;
	   t4=x%10;
	   printf("%d %d %d %d\n%d %d %d %d",t1,t2,t3,t4,t4,t3,t2,t1);
	    
}
int f3(int x)
{      
       int t1,t2,t3;
       t1=x/100;
       t2=(x-t1*100)/10;
       t3=x%10;
	   printf("%d %d %d\n%d %d %d",t1,t2,t3,t3,t2,t1);  
}
int f2(int x) 
{      
       int t1,t2;
       t1=x/10;
	   t2=x%10;
	   printf("%d %d\n%d %d",t1,t2,t2,t1);
}
int main()
{
    int a,t1,t2,t3,t4,t5;
	scanf("%d",&a);
	if(a>9999) 
	{
		printf("这是5位数\n");
		f5(a);
	}
	else if(a>999) 
	{
		printf("这是4位数\n");
		f4(a);
	} 
	else if(a>99) 
	{
		printf("这是3位数\n");
		f3(a);
	}
	else if(a>9)
	{
		printf("这是2位数\n");
		f2(a);
	}
	else 
	{
		printf("这是1位数\n");
		printf("%d",a);
	}
	return 0;          
}
