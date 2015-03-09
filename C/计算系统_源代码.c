#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
int init(void)
{
	int i = 0, j = 0;
    
	for(i = 0; i < 50; ++i)
	{
		system("cls"); 
		printf("计算题系统正在启动，请稍后...\n");
		for(j = 0; j <= i; ++j)
		{
			printf("#");
		}
		printf("%d%%",i*2+2);
		Sleep(1);
	}
   Sleep(150);
   system("cls");				//虚拟加载启动 
}
int main(void)
{   init();
    srand(time(NULL));
    int xuhao,ran_a,ran_b,fanwei_1,fanwei_2,s,a,b,i,t=0,k=0,d,l=0;
	printf("======欢迎使用小学生计算练习系统======\n");
	printf("==1.加法                      2.减法==\n");
	printf("==3.乘法                      4.除法==\n");
	printf("======================================\n");
	printf("请输入你想做多少道题,比如20,:");
	scanf("%d",&d);
	printf("请选择你要练习加,减还是乘,除,选择(1--4):");
	scanf("%d",&xuhao); 
	printf("输入运算数的范围[a,b],两数用空格隔开:");
	scanf("%d %d",&fanwei_1,&fanwei_2);
//执行加法运算	
	if(xuhao==1)
	for(i=0;i<d;i++)
	 {
		a = rand()%(fanwei_2 - fanwei_1) + fanwei_1; 
	  	b = rand()%(fanwei_2 - fanwei_1) + fanwei_1; //fanwei_1到fanwei_2的随机数 
	   	printf("%d+%d=",a,b);
	   	scanf("%d",&s);
	   	if(a+b==s) t++;
     }
//执行减法运算，并且输出结果要保证a>b     
     if(xuhao == 2)
	 for(i = 0; i < 10000; i++)
	 {
	   a = rand()%(fanwei_2 - fanwei_1) + fanwei_1;  
	   b = rand()%(fanwei_2 - fanwei_1) + fanwei_1; //fanwei_1到fanwei_2的随机数
	   if((a>b)&&(a!=b))
	   {
	     printf("%d-%d=",a,b);
	     scanf("%d",&s); 
	     if(a - b == s) t++;
	     k++;
	   }
	   if(k == d) break;
     }
//执行乘法运算     
     if(xuhao  == 3)
	 for(i = 0; i < d; i++)
	 {
	   a = rand()%(fanwei_2 - fanwei_1) + fanwei_1; 
	   b = rand()%(fanwei_2 - fanwei_1) + fanwei_1; //fanwei_1到fanwei_2的随机数 
	   printf("%dx%d=",a,b);
	   scanf("%d",&s);
	   if(a*b == s) t++;
     } 
//执行除法运算，要保证a被b整除    
     if(xuhao == 4)
	 for(i = 0;i < 10000; i++)
	 {
	   a = rand()%(fanwei_2 - fanwei_1) + fanwei_1; 
	   b = rand()%(fanwei_2 - fanwei_1) + fanwei_1; //fanwei_1到fanwei_2的随机数 
	   if((a%b == 0) && (a != b) && (b != 1) && (a != b))
	   { 
	     printf("%d/%d=",a,b);
	     scanf("%d",&s);
	     if(a/b == s) t++;
	     l++;
       }
       if(l == d) break;
     }
    printf("一共是%d道题,你做对了%d道题\n",d,t);
    if(t == d) printf("非常棒，全对！！！\n"); 
    else if(t/d >= 0.6) printf("很不错，做对了%%60以上\n");
	else printf("加油哦，本次测试没及格\n"); 
	system("PAUSE");
}
