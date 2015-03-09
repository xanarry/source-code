#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

struct ICcard
{
	char num[20];
	char name[20];
    double initialmoney;
	int flag;
}card[100];

int n=0;

void cardfaxing();           //公交卡的发行
void cardchongzhi();         //公交卡的充值
void cardzhuxiao();          //公交卡的注销
void cardguashi();           //公交卡的挂失
void cardjihuo();            //公交卡的激活
void cardchaxun();           //公交卡的查询
void cardlist();             //公交卡的清单
void displaymenu();          //菜单
void load();                 //保存资料到ICcard.dat中
void save();                 //读取数据中的资料
void cardclear();            //公交卡的清理
void cardlist_up();          //公交卡清单升序
void cardlist_down();        //公交卡清单降序
void cardlist();             //公交卡清单
char * IC_Flag(int flag);
int ICcardjiucuo(int tmp1,int tmp2,int tmp3);


int main()
{
	load();
	displaymenu();
	system("PAUSE > nul");
	return 0;
}


void displaymenu()
{
	int a;

	              printf("                        欢迎使用公交IC卡管理系统");
	              printf("\n\n\n");

                  printf("  ****************************系统功能菜单**************************\n");
			      printf("           1.-公交IC卡发行  2.-公交IC卡充值 0.-公交IC卡注销\n");
				  printf("           4.-公交IC卡挂失  5.-公交IC卡激活 6.-公交IC卡查询\n");
				  printf("           7.-公交IC卡清单  8.-公交IC卡清理  ~(1-8) 退出系统\n\n");
						printf("                              请你选择:");
						scanf("%d",&a);
    switch(a)
	{
	case 1:
		cardfaxing();
		break;
	case 2:
		cardchongzhi();
		break;
	case 0:
		cardzhuxiao();
	    break;
	case 4:
		cardguashi();
		break;
	case 5:
		cardjihuo();
		break;
	case 6:
		cardchaxun();
		break;
    case 7:
		cardlist();
		break;
	case 8:
		cardclear();
		break;
	default:
		break;
	} 
}


char *IC_Flag(int flag)
{
	static char flagName[20];
	if(flag==-1)    strcpy(flagName,"注销");
	else if(flag==0) strcpy(flagName,"挂失");
	else if(flag==1) strcpy(flagName,"五折");
	else if(flag==2) strcpy(flagName,"六折");
	else if(flag==3) strcpy(flagName,"七折");
	else if(flag==4) strcpy(flagName,"八折");
	else if(flag==5) strcpy(flagName,"九折");
	else if(flag==6) strcpy(flagName,"老人");
	else if(flag==7) strcpy(flagName,"公务");
	return flagName;	
}


int get_convert1(char *a)     //获得输入的第7位到第10位的数字，即出生的年份
{
	char num[20];
	int index = 0;
	while(index < 4)
	{
		num[index] = a[6 + index];
		index++;
	}
	num[index] = '\0';
	return atoi(num);
}

int get_convert2(char *a)       //获得输入的第11位到第12位的数字，即出生的月份
{
	char num[20];
	int index = 0;
	while(index<2)
	{
		num[index] = a[10 + index];
		index++;
	}
	num[index] = '\0';
	return atoi(num);
}
int get_convert3(char *a)       //获得输入的第13位到第14位的数字，即出生的日子
{
	char num[20];
	int index=0;
	while(index<2)
	{
		num[index] = a[12+ index];
		index++;
	}
	num[index] = '\0';
	return atoi(num);
}



void cardfaxing()     //公交卡的发行
{
	char a[20],b[20],z_mark[10];
	struct ICcard _new;
	char new_num[20];
	int get_index;
	int over_write = 0;
    printf("请输入新录入的公交IC卡的编号:");
    scanf("%s",a);
	int tmp1=get_convert1(a);//获得输入的第7位到第10位的数字，即出生的年份
    int tmp2=get_convert2(a);//获得输入的第11位到第12位的数字，即出生的月份
    int tmp3=get_convert3(a);//获得输入的第13位到第14位的数字，即出生的日子
    int t=ICcardjiucuo(tmp1,tmp2,tmp3);
    if(t==1)
	{
		for(int i=0;i<n;i++)
		{
			if(strcmp(a,card[i].num)==0)
			{
				strcpy(b,card[i].num);
				if(card[i].flag == -1)
				{
					strcpy(z_mark, card[i].num);
					printf("该卡号是一个注销的卡号，请输入新数据\n");
					printf("新的编号：");
					scanf("%s",new_num);
					while (1)
					{
						int j=0;
						for (j=0; j < n; j++)
						{
							if (strcmp(new_num, card[j].num)==0)
							{
								printf("您新开的卡号与已经存在的卡存在冲突，请重新输入:");
								scanf("%s",new_num);
							}
						}
						if (j==n)
							break;
					}	
					get_index=i;
					over_write=1;
				}
				else
				{
					printf("卡号重复，请重新输入!");
					cardfaxing();
				}
			}
		}
		strcpy(_new.num, a);
		printf("姓名:");
		scanf("%s",_new.name);
		printf("初始金额:");
		scanf("%lf",&_new.initialmoney);
		int c;
		printf("1.老人 2.公务 0.其余\n");//办理卡时选择卡的类别
		printf("请选择IC卡的类别:");
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			_new.flag=6;
				break;
		case 2:
			_new.flag=7;
	 	   break;
    	case 0:
			if(_new.initialmoney>=1000)
			{
				_new.flag=1;
			}
			else if(_new.initialmoney<1000&&_new.initialmoney>=800)
			{
				_new.flag=2;
			} 
			else if(_new.initialmoney<800&&_new.initialmoney>=600)
			{
				_new.flag=3;
			}	
			else if(_new.initialmoney<600&&_new.initialmoney>=400)
			{
				_new.flag=4;
			}
			else if(_new.initialmoney<400)
			{
				_new.flag=5;
			}
			break;
		}

	}
	else
	{
    	printf("卡号输入不符合要求，请重新输入!");
		printf("\n\n");
		cardfaxing();
	}
	int insert=0;
	for (int i=0;i<n;i++)
	{
		if (card[i].flag==-1)
		{
			get_index=i;
			strcpy(z_mark, card[i].num);
			over_write=1;
			insert=1;
			break;
		}
	}
	if (over_write==1)
	{
		if (insert==0)
		strcpy(_new.num, new_num);
		card[get_index] = _new;
		printf("被注销的卡号为【%s】卡已经被重新办理使用，当前共有【%d】个公交IC卡\n",z_mark,n);
	}	
	else
	{
		card[n] = _new;
		n++;
		printf("新卡录入成功，当前共有【%d】个公交IC卡\n",n);
	}
    save();
	displaymenu();
}



void cardchongzhi()//公交卡的充值
{
	char s[20];
	printf("请输入需要充值的公交IC卡的编号和金额\n");
	printf("公交IC卡的编号:");
	scanf("%s",s);
	int i = 0;
	for(i=0;i<n;i++)
	    if(strcmp(s,card[i].num)==0)break;
		if(i==n)
		    printf("查无此卡！\n");
		else
		{
			if(card[i].flag!=-1&&card[i].flag!=0)
			{
				int p;
				printf("金额:");
				scanf("%d",&p);
				printf("充值成功！\n");
	  			printf("公交IC卡的编号:%s\t姓名:%s\t初始金额:%d\t当前金额:%d\t",card[i].num,card[i].name,card[i].initialmoney,card[i].initialmoney+p);
		      	card[i].initialmoney=card[i].initialmoney+p;
			}
			else if(card[i].flag==0)
				printf("此卡挂失中，无法操作");
			else if(card[i].flag==-1)
				printf("此卡已被注销，无法操作");
		}
		save();
		displaymenu();
} 


void cardzhuxiao()   //公交IC卡的注销
{
	char a[18];
	printf("请输入需要注销的公交IC卡的编号:");
	scanf("%s",a);
	int i;
	for(i=0;i<n;i++)
		if(strcmp(a,card[i].num)==0)
			break;
		if(i==n)printf("查无此卡！\n");
		else if(card[i].flag==0)
			printf("卡号为【%s】的公交IC卡已经挂失，不能注销！\n",card[i].num);
		else if(card[i].flag==-1)
			printf("卡号为【%s】的公交IC卡已经注销，请勿重复注销！\n",card[i].num);
		else 
		{
			printf("卡号为【%s】的IC卡注销成功。\n",card[i].num);
			card[i].flag=-1;
		    save();
		}
		printf("\n");
		save();
		displaymenu();
}


void cardguashi()   //公交卡的挂失
{
   char a[50];
   printf("请输入需要挂失的公交IC卡编号:");
   scanf("%s",a);
   int i;
   for(i=0;i<n;i++)
	   if(strcmp(a,card[i].num)==0) break;
	   if(i==n)
		   printf("查无此卡");
	   else if(card[i].flag==0)
		   printf("卡号为【%s】的公交IC卡已经挂失！\n",card[i].num);
	   else card[i].flag=0,printf("卡号为【%s】的公交IC 卡已经挂失成功！\n",card[i].num);
	   save();
	   displaymenu();
}


void cardjihuo()    //公交卡的激活
{
   char a[20];int b;
   printf("请输入需要激活的公交IC卡编号:");
   scanf("%s",a);
   int i;
   for(i=0;i<n;i++)
	   if(strcmp(a,card[i].num)==0)break;
	   if(i==n)
		   printf("查无此卡！\n");
	   else if(card[i].flag!=-1&&card[i].flag!=0)
		   printf("此卡已经被激活，不需要再激活！\n");
	   else if(card[i].flag==-1)
		   printf("此卡已被注销，不能再激活使用！\n");
	   else if(card[i].flag==0)
	   {
		   printf("选择你激活此卡后所办卡的类别【1.老人 2.公务 0.其他】：");
		   scanf("%s",&b);
		   switch(b)
			{
			case 1:
				card[i].flag=6;
				break;
			case 2:
				card[i].flag=7;
				break;
			 case 0:
				if(card[i].initialmoney>=1000)
				{
					card[i].flag=1;
				}
				else if(card[i].initialmoney<1000&&card[i].initialmoney>=800)
				{
					card[i].flag=2;
				} 
				else if(card[i].initialmoney<800&&card[i].initialmoney>=600)
				{
					card[i].flag=3;
				}
				else if(card[i].initialmoney<600&&card[i].initialmoney>=400)
				{
					card[i].flag=4;
				}
				else if(card[i].initialmoney<400)
				{
					card[i].flag=5;
				}
				break;
			 }
		   //card[i].flag=1,printf("卡号为【%s】的公交IC卡已经成功激活！\n",card[i].num);
		   printf("卡号为【%s】的公交IC卡已经成功激活！\n",card[i].num);
	   }
	     save();
	     displaymenu();
}



void cardchaxun()     //公交IC卡的查询
{
    char a[20];
	printf("请输入需要查询的公交IC卡编号:");
	scanf("%s",a);
	for(int i=0;i<n;i++)
			if(strcmp(a,card[i].num)==0)
			{
				printf("序号\t卡--------------号\t姓----------名\t可用金额\t标识\n");
			    printf("%2d\t%s\t%-10s\t%lf\t\t%s\n",i+1,card[i].num,card[i].name,card[i].initialmoney,IC_Flag(card[i].flag));	
			}
			displaymenu();	
}


void cardlist()      //公交卡清单
{ 
  system("CLS");
      printf("序号\t卡--------------号\t姓----------名\t\t可用金额\t标识\n");
      puts("----------------------------------------------------------------------------");
      for(int i=0;i<n;i++)
  {
    printf("%2d\t%-18s\t%-18s\t%lf\t%s\n",i+1,card[i].num,card[i].name,card[i].initialmoney,IC_Flag(card[i].flag));
  }
  puts("----------------------------------------------------------------------------");
  displaymenu(); 
}

void cardlist_up()      //公交IC卡的清单升序
{
   int i,j;
   for(i=0;i<n-1;i++)
   {
	  for(j=0;j<n-i-1;j++)
	   {
		   if(card[j].initialmoney>card[j+1].initialmoney)
		   {
			    struct ICcard t;
				t=card[j+1];
				card[j+1]=card[j];
				card[j]=t;
		   }
	   }
   }  
}


void cardlist_down()    //公交IC卡的清单降序序
{
   int i,j;
   for(i=0;i<n-1;i++)
   {
	   for(j=0;j<n-i-1;j++)
	   {
		   if(card[j].initialmoney<card[j+1].initialmoney)
		   {
			    struct ICcard t;
				t=card[j];
				card[j]=card[j+1];
				card[j+1]=t;
		   }
	   }
   } 
}



void cardclear()      //公交卡清理
{
	char a,b,c,Y,y;
	printf("按IC卡金额升序排列吗【Y(y)→升序，~Y(y)→降序】:");
	scanf("%s",&a);
	if(a=='Y'||a=='y')
	{
		cardlist_up();
		save();
	}
	else
	{
		cardlist_down();
		save();
	}
	printf("\n");
    printf("要清除挂失的卡吗【Y(y)→清除，~Y(y)→不清除】:");
	scanf("%s",&b);
	if(b=='Y'||b=='y')
	{
		int i = 0;
    while(1)
    {
    if(card[i].flag==0)
    {
        for(int j=i;j<n-1;j++)
            card[j] = card[j+1];
            n--;
	}
      else
        i++;
      if(i==n)
        break;
    }
	}
	save();
    printf("\n");
    printf("要清除注销的卡吗【Y(y)→清除，~Y(y)→不清除】:");
	scanf("%s",&c);
	if(c=='Y'||c=='y')
	{
		int i = 0;
    while(1)
    {
    if(card[i].flag==-1)
    {
        for(int j=i;j<n-1;j++)
            card[j] = card[j+1];
            n--;
	}
      else
        i++;
      if(i==n)
        break;
    }

	}
	save();
}



void save()      //保存资料到ICcard.dat中
{
    FILE *p;
	if((p=fopen("ICcard.dat","wb"))==NULL)
		return;
	fputc(n,p);
	for(int i=0;i<=n;i++)
		fwrite(&card[i],sizeof(struct ICcard),1,p);
	fclose(p);
}

void load()       //读取数据中的资料
{
    FILE *p;
	if((p=fopen("ICcard.dat","rb"))==NULL)
	   return;
	n=fgetc(p);
	for(int i=0;feof(p)==NULL;i++)
	{
		fread(&card[i],sizeof(struct ICcard),1,p);
	}
	fclose(p); 
}

int ICcardjiucuo(int tmp1,int tmp2,int tmp3)
{
	if(1900<tmp1 && tmp1<2015)//if years is ligal
	{
		if(tmp2==4||tmp2==6||tmp2==9||tmp2==11)
		{
			if(tmp3<31&&tmp3>0)//from 1->30
				return 1;
			else
				return 0;
		}
		else if(tmp2==1||tmp2==3||tmp2==5||tmp2==7||tmp2==8||tmp2==10||tmp2==12)
		{
			if(tmp3<32&&tmp3>0)//from 1->31
				return 1;
			else
				return 0;
		}
		else 
			return 0;  

       	if((tmp1%4==0 && tmp1%100!=0) || tmp1%400==0 )//if it is a leap year
	   	{
		  	if(tmp2==2)//if it is jan
		  	{
				if(tmp3<30&&tmp3>0)//from 1->29
					return 1;
				else
					return 0;
		  	}
	   	}
	  	else//when it is not a leap year
	  	{
	  		if(tmp2==2)
	  		{
		  		if(tmp3<29&&tmp3>0)//from 1->28
					return 1;
		  		else
		  			return 0;	
	  		}
	  	}
	}
	else //year is iligal
		return 0;
}
//500234199411185817
//500101199414090999
//500101199717090999
