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
		printf("������ϵͳ�������������Ժ�...\n");
		for(j = 0; j <= i; ++j)
		{
			printf("#");
		}
		printf("%d%%",i*2+2);
		Sleep(1);
	}
   Sleep(150);
   system("cls");				//����������� 
}
int main(void)
{   init();
    srand(time(NULL));
    int xuhao,ran_a,ran_b,fanwei_1,fanwei_2,s,a,b,i,t=0,k=0,d,l=0;
	printf("======��ӭʹ��Сѧ��������ϰϵͳ======\n");
	printf("==1.�ӷ�                      2.����==\n");
	printf("==3.�˷�                      4.����==\n");
	printf("======================================\n");
	printf("���������������ٵ���,����20,:");
	scanf("%d",&d);
	printf("��ѡ����Ҫ��ϰ��,�����ǳ�,��,ѡ��(1--4):");
	scanf("%d",&xuhao); 
	printf("�����������ķ�Χ[a,b],�����ÿո����:");
	scanf("%d %d",&fanwei_1,&fanwei_2);
//ִ�мӷ�����	
	if(xuhao==1)
	for(i=0;i<d;i++)
	 {
		a = rand()%(fanwei_2 - fanwei_1) + fanwei_1; 
	  	b = rand()%(fanwei_2 - fanwei_1) + fanwei_1; //fanwei_1��fanwei_2������� 
	   	printf("%d+%d=",a,b);
	   	scanf("%d",&s);
	   	if(a+b==s) t++;
     }
//ִ�м������㣬����������Ҫ��֤a>b     
     if(xuhao == 2)
	 for(i = 0; i < 10000; i++)
	 {
	   a = rand()%(fanwei_2 - fanwei_1) + fanwei_1;  
	   b = rand()%(fanwei_2 - fanwei_1) + fanwei_1; //fanwei_1��fanwei_2�������
	   if((a>b)&&(a!=b))
	   {
	     printf("%d-%d=",a,b);
	     scanf("%d",&s); 
	     if(a - b == s) t++;
	     k++;
	   }
	   if(k == d) break;
     }
//ִ�г˷�����     
     if(xuhao  == 3)
	 for(i = 0; i < d; i++)
	 {
	   a = rand()%(fanwei_2 - fanwei_1) + fanwei_1; 
	   b = rand()%(fanwei_2 - fanwei_1) + fanwei_1; //fanwei_1��fanwei_2������� 
	   printf("%dx%d=",a,b);
	   scanf("%d",&s);
	   if(a*b == s) t++;
     } 
//ִ�г������㣬Ҫ��֤a��b����    
     if(xuhao == 4)
	 for(i = 0;i < 10000; i++)
	 {
	   a = rand()%(fanwei_2 - fanwei_1) + fanwei_1; 
	   b = rand()%(fanwei_2 - fanwei_1) + fanwei_1; //fanwei_1��fanwei_2������� 
	   if((a%b == 0) && (a != b) && (b != 1) && (a != b))
	   { 
	     printf("%d/%d=",a,b);
	     scanf("%d",&s);
	     if(a/b == s) t++;
	     l++;
       }
       if(l == d) break;
     }
    printf("һ����%d����,��������%d����\n",d,t);
    if(t == d) printf("�ǳ�����ȫ�ԣ�����\n"); 
    else if(t/d >= 0.6) printf("�ܲ���������%%60����\n");
	else printf("����Ŷ�����β���û����\n"); 
	system("PAUSE");
}
