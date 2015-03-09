#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

struct worker
{
	int no;
	char name[20];
	int bumen;
	char sex;
	int salary;
};

int main()
{
	struct worker p[N];
	int i;
	int flag;
	char name[20];
	for(i=0; i<N; i++)
	{
		printf("请输入第%d个员工信息,工号 姓名 部门 性别 工资：\n",i+1);
		scanf("%d %s %d %c %d",&p[i].no, p[i].name, &p[i].bumen, &p[i].sex, &p[i].salary);	
	}
		
	printf("以下是输入的员工信息:\n");
	printf("------------------------------------\n");
	printf("工号\t姓名\t部门\t性别\t工资\n");
	for(i=0; i<N; i++)
	{
		printf("%d\t%s\t%d\t%c\t%d\n",p[i].no, p[i].name, p[i].bumen, p[i].sex, p[i].salary);
	}
	printf("------------------------------------\n");
	
	for(i=0; i<N; i++)
	{
		if(p[i].bumen == 1) 
			p[i].salary += 100;
		else 
			p[i].salary += 200;
	}
	
	printf("\n以下是加薪后的员工信息:\n");
	printf("------------------------------------\n");
	printf("工号\t姓名\t部门\t性别\t工资\n");
	for(i=0; i<N; i++)
	{
		printf("%d\t%s\t%d\t%c\t%d\n",p[i].no, p[i].name, p[i].bumen, p[i].sex, p[i].salary);
	}
	printf("------------------------------------\n");
	
	printf("\n请输入要查找的姓名:");
	scanf("%s",name);
	
	printf("\n以下是您要查找的员工信息:\n");
	printf("------------------------------------\n");
	printf("工号\t姓名\t部门\t性别\t工资\n");
	for(i = 0; i < N; i++)
	{
		if(strcmp(p[i].name,name) == 0)
		printf("%d\t%s\t%d\t%c\t%d\n",p[i].no, p[i].name, p[i].bumen, p[i].sex, p[i].salary);
	}
	printf("------------------------------------\n");
	return 0;
}
