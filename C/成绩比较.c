#include <stdio.h>
#include <stdlib.h>

struct s
{
	char name[20];
	char sex;
	int age;
	int score;
};

int main()
{
	void input(struct s *in, int x);
	struct s* max(struct s *in, int x);
	void output(struct s *out, int x);
	struct s *stu;
	struct s *put;
	int i;
	int j;
	int n;
	printf("请输入学生个数：");
	scanf("%d",&n);											      	//接收学生个数  
	stu = (struct s *)malloc(n*sizeof(struct s)); 					//开辟指定的内存空间 
	input(stu,n);
	put = max(stu,n);
	output(put,n);
	return 0;
}

void input(struct s *in, int x)
{
	struct s *p;
	int i;
	for(p=in, i=1; p<in+x; p++)
	{	printf("依次输入第%d个学生的姓名，性别，年龄，成绩：",i++); 
		scanf("%s %c %d %d",p->name, &p->sex, &p->age, &p->score); 	//接收每个学生的信息	
	}
}

struct s* max(struct s *in, int x)
{
	struct s *p;
	struct s *r = NULL;
	int max_s;
	max_s = 0;
	for(p=in; p<in+x; p++)
	{
		if(p->score > max_s) 										//查找成绩最高的学生 
		{
			max_s = p->score;										//找出分数 
			r = p;													//找出是哪个人 
		}
	
	} 
	printf("成绩最高是：%d\n",max_s);								//在函数中输出最高分 
	return r;														//返回分数最高的学生的信息存储地址 
}

void output(struct s *out, int x)
{
	printf("成绩最好的学生是:\n");
	printf("%s %c %d %d\n\n",out->name, out->sex, out->age, out->score); //输出学生信息 
}
