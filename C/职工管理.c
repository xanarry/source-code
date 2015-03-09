#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct employee
{
    int num;                       /*����*/
    char duty[10];                 /*ְ��*/
    char name[10];                 /*����*/
    char sex[3];                   /*�Ա�*/
    unsigned int age;              /*����*/
    char edu[10];                  /*�Ļ��̶�*/
    int  salary;                   /*����*/
    char tel_office[13];           /*�����绰*/
    char tel_home[13];             /*��ͥ�绰*/
    char mobile[13];               /*�ƶ��绰*/
    char qq[11];                   /*QQ����*/
    char address[31];              /*��ַ*/
    struct employee *next;         /*����ָ��*/
}EMP;

void bound(char ch, int n);                           /*��ʾ�ָ���*/
void checkfirst();                                    /*�״γ�ʼ��*/
void login();                                         /*�������*/
void menu();                                          /*��ʾ�˵�*/
void addemp();                                        /*���Ա����Ϣ*/

    EMP *emp_first, *emp_end;       /*ȫ�ֱ���  ������β��ָ��*/ 
    char gsave, gfirst;             /*ȫ�ֱ���  gsave, gfirst*/
    char password[9];               /*ȫ�ֱ���  ����*/
    
main(void)
{
    emp_first=emp_end=NULL;
    gsave=gfirst=0;
    
    checkfirst();
    login();
    menu();
    	
}

void bound(char ch, int n)        /*��ʾ�ָ���*/
{
	while(n--)
	{
	    putch(ch);	
	}
	
	printf("\n");
}

void checkfirst()                 /*�״γ�ʼ��*/
{
	FILE *fp, *fp1;
	char pwd[9], pwd1[9], ch;
	int i;
	
	if((fp=fopen("config.dat","rb"))==NULL)
	{
	    printf("\n��ϵͳ����δ���г�ʼ���������������룡\n");	
	    bound('_',50);
	    
	    do
	      {
	          printf("\n���õ�¼���루���8Ϊ����");
	          for(i=0; i<8&&((pwd[i]=getch())!=13); i++)
	          {
	             putch('*');	
	          }	
	          
	          printf("\n�ٴ�ȷ�����룺");
	          for(i=0; i<8&&((pwd1[i]=getch())!=13); i++)
	          {
	             putch('*');	
	          }	
	          
	          pwd[i]=pwd1[i]='\0';
	          
	          if(strcmp(pwd,pwd1)!=0)
	          {
	             printf("\n�����������벻ͬ�����������룡\n\n");
	          }
	          else
	          {
	             break;	
	          }
	      }while(1);
	      
	    if((fp1=fopen("config.dat","wb"))==NULL)
	    {
	        printf("\n����ϵͳ�����ڴ�ʧ�ܣ���������˳�ϵͳ��\n");	
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
	        printf("\n\n�ڴ����óɹ�����������˳�ϵͳ�������½��룡\n");
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

void login()                                         /*�������*/
{
	int i, n=3;
	char pwd[9];
	
	do
	  {
	  	printf("���������ϵͳ�����룺");
	  	for(i=0; i<8 && ((pwd[i]=getch())!=13); i++)
	  	{
	  		putch('*');
	  	}
	  	pwd[i]='\0';
	  	
	  	if(strcmp(pwd,password)!=0)
	  	{
	  		printf("\n����������������룡\n");
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
	  	 printf("�Ƿ��û������뿪����");
	  	 getch();
	  	 exit(1);
	  }
	  else
	  {
	  	 printf("\n������ȷ����ӭ���뱾ϵͳ��\n");
	  }
}

void menu()                               /*��ʾ�˵�*/
{
	 char choice;
	 
	 system("cls");
	 
	 do
	 {
	 	printf("     ��ӭ����Ա������ϵͳ\n");
	 	bound('_',30);
	 	printf("\t1.����Ա����Ϣ\n");
	 	printf("\t2.��ѯԱ����Ϣ\n");
	 	printf("\t3.��ʾԱ����Ϣ\n");
	 	printf("\t4.�޸�Ա����Ϣ\n");
	 	printf("\t5.ɾ��Ա����Ϣ\n");
	 	printf("\t6.ͳ��Ա����Ϣ\n");
	 	printf("\t7.����ϵͳ����\n");
	 	printf("\t0.�˳�ϵͳ\n");
	 	bound('_',30);
	 	printf("\n��ѡ��˵���");
	 	
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
	 			  	  printf("ϵͳ�л�û��Ա����Ϣ����ѡ���Ա����Ϣ��\n");
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
	 			  	  printf("ϵͳ�л�û��Ա����Ϣ����ѡ���Ա����Ϣ��\n");
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
	 			  	  printf("ϵͳ�л�û��Ա����Ϣ����ѡ���Ա����Ϣ��\n");
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
	 			  	  printf("ϵͳ�л�û��Ա����Ϣ����ѡ���Ա����Ϣ��\n");
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
	 			  	  printf("ϵͳ�л�û��Ա����Ϣ����ѡ���Ա����Ϣ��\n");
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

void addemp()                           /*���Ա����Ϣ*/
{
	FILE *fp;
	EMP *emp1;
	int i=0;
	char choice='y';
	fp = fopen("emp.dat","ab");
	if((fp==NULL))
	{
	   printf("���ļ�ʧ�ܣ�\n");
	   getch();
	   exit(1);
    }
    do
    {
       i++;
       emp1=(EMP*)malloc(sizeof(EMP));
       
       if(emp1==NULL)
       {
           printf("�ռ俪��ʧ�ܣ�\n");
           getch();
           exit(1);
       }

       printf("������Ա��%d��Ա����Ϣ��\n", i);
       bound('_',20);
       fflush(stdin);
       printf("���ţ�");
       scanf("%d",&(emp1->num));
 
       printf("ְ��");
       scanf("%s",emp1->duty);
       
       printf("������");
       scanf("%s",emp1->name);
       
       printf("�Ա�");
       scanf("%s",emp1->sex);
       
       printf("���䣺");
       scanf("%d",&(emp1->age));
       
       printf("�Ļ��̶ȣ�");
       scanf("%s",emp1->edu);
       
       printf("���ʣ�");
       scanf("%d",&(emp1->salary));
       
       printf("�칫�绰��");
       scanf("%s",emp1->tel_office);
       
       printf("��ͥ�绰��");
       scanf("%s",emp1->tel_home);
       
       printf("�ƶ��绰��");
       scanf("%s",emp1->mobile);
       
       printf("QQ��");
       scanf("%s",emp1->qq);
      
       printf("��ַ��");
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
       printf("�Ƿ�������룿��y/n��");
       fflush(stdin);
       choice=getchar();
       
       if(toupper(choice)!='Y')
       {
          fclose(fp);
          printf("������ϣ������������\n");
          getch();
       }
       
       system("cls");
    }while(1);
}
