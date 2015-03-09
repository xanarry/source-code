#include <stdio.h>
#include <stdlib.h>

typedef struct stuinfo
{
	int no;
	char name[15];
	char sex;
	int age;
	int cluss;
	int c_score;
	struct stuinfo *next;
}student;

student * create(int x);
void print(student *r);
void max_min(student *r);
void fall(student *r);
void top(student *r);

student *max = NULL;
student *min = NULL;

int main()
{
	student *r;
	int n;
	printf("请输入学生人数:");
	scanf("%d",&n);
	r = create(n);
	printf("\n以下是您输入的学生信息：\n");
	printf("学号\t姓名\t性别\t年龄\t班级\t成绩\n");
	printf("--------------------------------------------\n");
	print(r);
	printf("--------------------------------------------\n");
	
	max_min(r);
	printf("\n分数最高的是：\n");
	printf("学号\t姓名\t性别\t年龄\t班级\t成绩\n");
	printf("--------------------------------------------\n");
	printf("%d\t%s\t%c\t%d\t%d\t%d\n",max->no,max->name,max->sex,max->age,max->cluss,max->c_score);
	printf("--------------------------------------------\n");
	
	printf("\n分数最低的是：\n");
	printf("学号\t姓名\t性别\t年龄\t班级\t成绩\n");
	printf("--------------------------------------------\n");	
	printf("%d\t%s\t%c\t%d\t%d\t%d\n",min->no,min->name,min->sex,min->age,min->cluss,min->c_score);
	printf("--------------------------------------------\n");
	
		 
	printf("\n不及格的学生有：\n"); 
	printf("学号\t姓名\t性别\t年龄\t班级\t成绩\n");
	printf("--------------------------------------------\n");
	fall(r);
	printf("--------------------------------------------\n");
	
	printf("\n优秀的学生有：\n"); 
	printf("学号\t姓名\t性别\t年龄\t班级\t成绩\n");
	printf("--------------------------------------------\n");
	top(r);
	printf("--------------------------------------------\n");
	return 0;
}

student * create(int x)
{
	student *head;
	student *c;
	student *pr;
	head = NULL;
	int i=1;
	while(x --)
	{
		printf("请输入第%d个学生的学号 姓名 性别 年龄 班级 成绩：\n",i++);
		c = (student *)malloc(sizeof(student));
		scanf("%d %s %c %d %d %d",&c->no,c->name,&c->sex,&c->age,&c->cluss,&c->c_score);
		c->next = NULL; 
		if(head == NULL)
			head = c;
		else 
			pr->next = c;
		pr = c;	
	}
	return head;	
}

void print(student *r)
{	
	FILE *fp1;
	fp1 = fopen("全部学生信息.txt","wt+");
	while(r != NULL && fp1 != NULL)
	{
		printf("%d\t%s\t%c\t%d\t%d\t%d\n",r->no,r->name,r->sex,r->age,r->cluss,r->c_score);
		fprintf(fp1,"%d\t%s\t%c\t%d\t%d\t%d\n",r->no,r->name,r->sex,r->age,r->cluss,r->c_score);
		r = r->next;
	}
	fclose(fp1);
}

void max_min(student *r)
{
	student *p = r->next;
	p = r;
	max = min = r;
	while(p != NULL)
	{
		if(p->c_score > max->c_score) max = p;
		if(p->c_score < min->c_score) min = p;	
		p = p->next;	
	}	
}

void fall(student *r)
{
	student *p = r;
	FILE *fp2;
	fp2 = fopen("不及格的学生.txt","wt+");
	while(p != NULL && fp2 != NULL)
	{
		if(p->c_score < 60)
		{
			printf("%d\t%s\t%c\t%d\t%d\t%d\n",p->no,p->name,p->sex,p->age,p->cluss,p->c_score);
			fprintf(fp2,"%d\t%s\t%c\t%d\t%d\t%d\n",p->no,p->name,p->sex,p->age,p->cluss,p->c_score);
		}
		p = p->next;
	}
	fclose(fp2);
}

void top(student *r)
{
	student *p = r;
	FILE *fp3;
	fp3 = fopen("优秀的学生.txt","wt+");
	while(p != NULL && fp3 != NULL)
	{
		if(p->c_score >= 80)
		{
			printf("%d\t%s\t%c\t%d\t%d\t%d\n",p->no,p->name,p->sex,p->age,p->cluss,p->c_score);
			fprintf(fp3,"%d\t%s\t%c\t%d\t%d\t%d\n",p->no,p->name,p->sex,p->age,p->cluss,p->c_score);
		}
		p = p->next;
	}
	fclose(fp3);
}
