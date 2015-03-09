#include <stdio.h>
#include <stdlib.h>

struct s
{
	int biaohao; 				//存储学生编号 
	int no;						//存储学号 
	char name[20];				//存储学生姓名 
	int score1;					//存储学生成绩1 
	int score2;					//存储学生成绩2 
	int score3;					//存储学生成绩3 
	struct s *next;				//定义下一个节点 
};

int main()
{
	struct s* input();								//声明输入链表函数 
	struct s* max(struct s *in);					//声明查找分数最高节点 
	void average(struct s *in);						//声明平均数函数 
	void output(struct s *out);						//声明输出链表函数 
	void output_one(struct s * in);					//声明输出分数最高学生信息函数 
	
	struct s *stu;
	struct s *put;
	struct s *o;	
										
	o = input();
	if(o == NULL)
	{
		printf("\nNO DATA INPUT !!\nPLEASE TRY AGAIN\n");	
		exit (1);											//输入信息为null则退出 
	}
	
	output(o);
	put = max(o);
	average(o);
	output_one(put);
	free(o);
													//函数调用 
	return 0;
}

struct s * input()
{
	struct s *p;
	struct s *t;
	struct s *head = NULL;
	int num;
	int i=1;
	while(i++)
	{
		printf("请 输 入 %d 的 学 生 学 号,<输 入 '0' 退 出>：",i-1);
		scanf("%d",&num);
		if(num == 0) break;														//实习输入'0'就退出 
		p = (struct s *)malloc(sizeof(struct s)); 								//开辟内存 
		p->no = num;
		p->next = NULL;
		printf("请分别输入第%d学生的  姓名 成绩1 成绩2 成绩3:\n",i-1);
		scanf("%s %d %d %d",p->name, &p->score1, &p->score2, &p->score3);		//接收学生信息 
		p->biaohao = i-1;														//默认设置学生序号 
		if(head == NULL)
			head = p;
		else
			t->next = p;
		t = p;																	//链表构建 
	}
	return head;
}

struct s* max(struct s *in)
{
	struct s *p;
	struct s *r = NULL;
	int max_s = 0;
	int sum;
	p = in;
	while(p)
	{
		sum = p->score1 + p->score2 + p->score3;								//求每个学生的三科总分 
		if(sum > max_s)															
			r = p;
		p = p->next;												
	}
	return r;																	//返回分数最高的学生的信息存储地址 
}

void output(struct s *out)
{
	struct s *p;
	p = out;
	printf("\n以下是输入的学生信息:");
	printf("\n---------------------------------------------\n");
	printf("序号\t学号\t姓名\t成绩1\t成绩2\t成绩3\n");
	while(p != NULL)
	{
		printf("%d\t%d\t%s\t%d\t%d\t%d\n",p->biaohao, p->no, p->name, p->score1, p->score2, p->score3); //输出学生信息 
		p = p->next;
	}
	printf("---------------------------------------------\n");
}																				//打印学生信息 

void output_one(struct s * in)
{
	printf("\n总成绩最高的同学是:");
	printf("\n-----------------------------------------------------\n");
	printf("序号\t学号\t姓名\t成绩1\t成绩2\t成绩3\t总分：\n");
	printf("%d\t%d\t%s\t%d\t%d\t%d\t%d",in->biaohao, in->no, in->name, in->score1, in->score2, in->score3, in->score1+in->score2+in->score3);
	printf("\n-----------------------------------------------------\n");
}																				//输出输出分数最高的学生信息 

void  average(struct s *in)
{
	struct s * p;
	p = in;
	int sum = 0;
	float ave;
	int i = 0;
	while(p)
	{	
		sum += p->score1+p->score2+p->score3;
		i++;
		p = p->next;
	}
	printf("\n所有学生的所有课程的总分是：%d\n",sum);
	ave = sum/(3*i);
	printf("\n所有学生所有课程的平均分是：%.2f\n",ave);	
}																				//计算所有人所有科目平均分并输出 
