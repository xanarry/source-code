#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct employee
{
    int num;                       /*工号*/
    char duty[10];                 /*职务*/
    char name[10];                 /*姓名*/
    char sex[3];                   /*性别*/
    unsigned int age;              /*年龄*/
    char edu[10];                  /*文化程度*/
    int  salary;                   /*收入*/
    char tel_office[13];           /*工作电话*/
    char tel_home[13];             /*家庭电话*/
    char mobile[13];               /*移动电话*/
    char qq[11];                   /*QQ号码*/
    char address[31];              /*地址*/
    struct employee *next;         /*链表指针*/
}EMP;

void bound(char ch, int n);                           /*显示分割线*/
void checkfirst();                                    /*首次初始化*/
void login();                                         /*检查密码*/
void menu();                                          /*显示菜单*/
void addemp();                                        /*添加员工信息*/

    EMP *emp_first, *emp_end;       /*全局变量  首链，尾链指针*/ 
    char gsave, gfirst;             /*全局变量  gsave, gfirst*/
    char password[9];               /*全局变量  密码*/
    
main(void)
{
    emp_first=emp_end=NULL;
    gsave=gfirst=0;
    
    checkfirst();
    login();
    menu();
    	
}

void bound(char ch, int n)        /*显示分割线*/
{
	while(n--)
	{
	    putch(ch);	
	}
	
	printf("\n");
}

void checkfirst()                 /*首次初始化*/
{
	FILE *fp, *fp1;
	char pwd[9], pwd1[9], ch;
	int i;
	
	if((fp=fopen("config.dat","rb"))==NULL)
	{
	    printf("\n新系统，还未进行初始化，请先设置密码！\n");	
	    bound('_',50);
	    
	    do
	      {
	          printf("\n设置登录密码（最多8为）：");
	          for(i=0; i<8&&((pwd[i]=getch())!=13); i++)
	          {
	             putch('*');	
	          }	
	          
	          printf("\n再次确认密码：");
	          for(i=0; i<8&&((pwd1[i]=getch())!=13); i++)
	          {
	             putch('*');	
	          }	
	          
	          pwd[i]=pwd1[i]='\0';
	          
	          if(strcmp(pwd,pwd1)!=0)
	          {
	             printf("\n两次密码输入不同，请重新输入！\n\n");
	          }
	          else
	          {
	             break;	
	          }
	      }while(1);
	      
	    if((fp1=fopen("config.dat","wb"))==NULL)
	    {
	        printf("\n创建系统配置内存失败，按任意键退出系统！\n");	
	        getch();
	        exit(1);
	    }
	    else
	    {
	        i=0;
	        while(pwd[i])
	        {
	        	putw(pwd[i],fp1);
	        	i++;
	        }
	        
	        fclose(fp1);
	        printf("\n\n内存配置成功，按任意键退出系统，再重新进入！\n");
	        getch();
	        exit(1);
	    }
	}
	else
	{
	    i=0;
	    while(!feof(fp) && i<8)
	    {
	        pwd[i++]=getw(fp);	
	    }	
	    
	    pwd[i]='\0';
	    
	    if(i>=8)
	    {
	        i++;	
	    }
	    
	    while(pwd[i]!=-1 && i>=0)
	    {
	        i--;	
	    }
	    pwd[i]='\0';
	    strcpy(password,pwd);
	}
}

void login()                                         /*检查密码*/
{
	int i, n=3;
	char pwd[9];
	
	do
	  {
	  	printf("请输入进入系统的密码：");
	  	for(i=0; i<8 && ((pwd[i]=getch())!=13); i++)
	  	{
	  		putch('*');
	  	}
	  	pwd[i]='\0';
	  	
	  	if(strcmp(pwd,password)!=0)
	  	{
	  		printf("\n密码错误，请重新输入！\n");
	  		system("cls");
	  		n--;
	  	}
	  	else
	  	{
	  		break;
	  	}
	  }while(n>0);
	  
	  if(n==0)
	  {
	  	 printf("非法用户，请离开！！");
	  	 getch();
	  	 exit(1);
	  }
	  else
	  {
	  	 printf("\n密码正确，欢迎进入本系统！\n");
	  }
}

void menu()                               /*显示菜单*/
{
	 char choice;
	 
	 system("cls");
	 
	 do
	 {
	 	printf("     欢迎进入员工管理系统\n");
	 	bound('_',30);
	 	printf("\t1.输入员工信息\n");
	 	printf("\t2.查询员工信息\n");
	 	printf("\t3.显示员工信息\n");
	 	printf("\t4.修改员工信息\n");
	 	printf("\t5.删除员工信息\n");
	 	printf("\t6.统计员工信息\n");
	 	printf("\t7.重设系统密码\n");
	 	printf("\t0.退出系统\n");
	 	bound('_',30);
	 	printf("\n请选择菜单：");
	 	
	 	do
	 	{
	 		fflush(stdin);
	 		choice=getchar();
	 		system("cls");
	 		
	 		switch(choice)
	 		{
	 			case '1': 
	 			addemp();
	 			  break;
	 			
	 			case '2': 
	 			  if(gfirst)
	 			  {
	 			  	  printf("系统中还没有员工信息，请选添加员工信息！\n");
	 			  	  getch();
	 			  	  break;
	 			  }
	 			  else
	 			  {
	 			  	  //findemp();
	 			  	  break;
	 			  }
	 			case '3':
	 			  if(gfirst)
	 			  {
	 			  	  printf("系统中还没有员工信息，请选添加员工信息！\n");
	 			  	  getch();
	 			  	  break;
	 			  }
	 			  else
	 			  {
	 			  	  //listemp();
	 			  	  break;
	 			  }
	 			case '4':
	 			  if(gfirst)
	 			  {
	 			  	  printf("系统中还没有员工信息，请选添加员工信息！\n");
	 			  	  getch();
	 			  	  break;
	 			  }
	 			  else
	 			  {
	 			  	  //modifyemp();
	 			  	  break;
	 			  }
	 			case '5':
	 			  if(gfirst)
	 			  {
	 			  	  printf("系统中还没有员工信息，请选添加员工信息！\n");
	 			  	  getch();
	 			  	  break;
	 			  }
	 			  else
	 			  {
	 			  	  //delemp();
	 			  	  break;
	 			  } 
	 		   case '6':
	 			  if(gfirst)
	 			  {
	 			  	  printf("系统中还没有员工信息，请选添加员工信息！\n");
	 			  	  getch();
	 			  	  break;
	 			  }
	 			  else
	 			  {
	 			  	  //summaryemp();
	 			  	  break;
	 			  }
	 		   case '7':
	 		      //resetpwd();
	 		      break;
	 		      
	 		   case '0':
	 		      //savedata();
	 		      exit(0);	  	  
	 		}
	 	}while(choice<'0' || choice>'7');
	 	
	 	system("cls");
	 	
	 }while(1);
}

void addemp()                           /*添加员工信息*/
{
	FILE *fp;
	EMP *emp1;
	int i=0;
	char choice='y';
	fp = fopen("emp.dat","ab");
	if((fp==NULL))
	{
	   printf("打开文件失败！\n");
	   getch();
	   exit(1);
    }
    do
    {
       i++;
       emp1=(EMP*)malloc(sizeof(EMP));
       
       if(emp1==NULL)
       {
           printf("空间开辟失败！\n");
           getch();
           exit(1);
       }

       printf("请输入员第%d个员工信息：\n", i);
       bound('_',20);
       fflush(stdin);
       printf("工号：");
       scanf("%d",&(emp1->num));
 
       printf("职务：");
       scanf("%s",emp1->duty);
       
       printf("姓名：");
       scanf("%s",emp1->name);
       
       printf("性别：");
       scanf("%s",emp1->sex);
       
       printf("年龄：");
       scanf("%d",&(emp1->age));
       
       printf("文化程度：");
       scanf("%s",emp1->edu);
       
       printf("工资：");
       scanf("%d",&(emp1->salary));
       
       printf("办公电话：");
       scanf("%s",emp1->tel_office);
       
       printf("家庭电话：");
       scanf("%s",emp1->tel_home);
       
       printf("移动电话：");
       scanf("%s",emp1->mobile);
       
       printf("QQ：");
       scanf("%s",emp1->qq);
      
       printf("地址：");
       scanf("%s",emp1->address);
       
       emp1->next=NULL;
	  // printf("\ntest1:%x,%x\n",emp_first,emp_end);
       if(emp_first==NULL)
       {
          emp_first=emp1;
          emp_end=emp1;
       }
       else
       {
          emp_end->next=emp1;
          emp_end=emp1;
       }
       //printf("test2:%x,%x",emp_first,emp_end);
       fwrite(emp_end,sizeof(EMP),1,fp);
       
       gfirst=0;
       printf("\n");
       bound('_',20);
       printf("是否继续输入？（y/n）");
       fflush(stdin);
       choice=getchar();
       
       if(toupper(choice)!='Y')
       {
          fclose(fp);
          printf("输入完毕，按任意键返回\n");
          getch();
       }
       
       system("cls");
    }while(1);
}
