#include<stdio.h>
int f5(int x)
{ 
       int t1,t2,t3,t4,t5;
	   t1=x/10000;
	   t2=(x-t1*10000)/1000;
	   t3=(x-t1*10000-t2*1000)/100;
	   t4=(x-t1*10000-t2*1000-t3*100)/10;
	   t5=x%10;								//���Ϸ���ÿ���� 
	   printf("%d %d %d %d %d\n%d %d %d %d %d",t1,t2,t3,t4,t5,t5,t4,t3,t2,t1);
}											//����������� 
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
		printf("����5λ��\n");
		f5(a);
	}
	else if(a>999) 
	{
		printf("����4λ��\n");
		f4(a);
	} 
	else if(a>99) 
	{
		printf("����3λ��\n");
		f3(a);
	}
	else if(a>9)
	{
		printf("����2λ��\n");
		f2(a);
	}
	else 
	{
		printf("����1λ��\n");
		printf("%d",a);
	}
	return 0;          
}
