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
	printf("������ѧ��������");
	scanf("%d",&n);											      	//����ѧ������  
	stu = (struct s *)malloc(n*sizeof(struct s)); 					//����ָ�����ڴ�ռ� 
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
	{	printf("���������%d��ѧ�����������Ա����䣬�ɼ���",i++); 
		scanf("%s %c %d %d",p->name, &p->sex, &p->age, &p->score); 	//����ÿ��ѧ������Ϣ	
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
		if(p->score > max_s) 										//���ҳɼ���ߵ�ѧ�� 
		{
			max_s = p->score;										//�ҳ����� 
			r = p;													//�ҳ����ĸ��� 
		}
	
	} 
	printf("�ɼ�����ǣ�%d\n",max_s);								//�ں����������߷� 
	return r;														//���ط�����ߵ�ѧ������Ϣ�洢��ַ 
}

void output(struct s *out, int x)
{
	printf("�ɼ���õ�ѧ����:\n");
	printf("%s %c %d %d\n\n",out->name, out->sex, out->age, out->score); //���ѧ����Ϣ 
}
