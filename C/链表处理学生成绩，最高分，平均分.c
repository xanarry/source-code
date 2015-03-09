#include <stdio.h>
#include <stdlib.h>

struct s
{
	int biaohao; 				//�洢ѧ����� 
	int no;						//�洢ѧ�� 
	char name[20];				//�洢ѧ������ 
	int score1;					//�洢ѧ���ɼ�1 
	int score2;					//�洢ѧ���ɼ�2 
	int score3;					//�洢ѧ���ɼ�3 
	struct s *next;				//������һ���ڵ� 
};

int main()
{
	struct s* input();								//�������������� 
	struct s* max(struct s *in);					//�������ҷ�����߽ڵ� 
	void average(struct s *in);						//����ƽ�������� 
	void output(struct s *out);						//������������� 
	void output_one(struct s * in);					//��������������ѧ����Ϣ���� 
	
	struct s *stu;
	struct s *put;
	struct s *o;	
										
	o = input();
	if(o == NULL)
	{
		printf("\nNO DATA INPUT !!\nPLEASE TRY AGAIN\n");	
		exit (1);											//������ϢΪnull���˳� 
	}
	
	output(o);
	put = max(o);
	average(o);
	output_one(put);
	free(o);
													//�������� 
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
		printf("�� �� �� %d �� ѧ �� ѧ ��,<�� �� '0' �� ��>��",i-1);
		scanf("%d",&num);
		if(num == 0) break;														//ʵϰ����'0'���˳� 
		p = (struct s *)malloc(sizeof(struct s)); 								//�����ڴ� 
		p->no = num;
		p->next = NULL;
		printf("��ֱ������%dѧ����  ���� �ɼ�1 �ɼ�2 �ɼ�3:\n",i-1);
		scanf("%s %d %d %d",p->name, &p->score1, &p->score2, &p->score3);		//����ѧ����Ϣ 
		p->biaohao = i-1;														//Ĭ������ѧ����� 
		if(head == NULL)
			head = p;
		else
			t->next = p;
		t = p;																	//������ 
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
		sum = p->score1 + p->score2 + p->score3;								//��ÿ��ѧ���������ܷ� 
		if(sum > max_s)															
			r = p;
		p = p->next;												
	}
	return r;																	//���ط�����ߵ�ѧ������Ϣ�洢��ַ 
}

void output(struct s *out)
{
	struct s *p;
	p = out;
	printf("\n�����������ѧ����Ϣ:");
	printf("\n---------------------------------------------\n");
	printf("���\tѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\n");
	while(p != NULL)
	{
		printf("%d\t%d\t%s\t%d\t%d\t%d\n",p->biaohao, p->no, p->name, p->score1, p->score2, p->score3); //���ѧ����Ϣ 
		p = p->next;
	}
	printf("---------------------------------------------\n");
}																				//��ӡѧ����Ϣ 

void output_one(struct s * in)
{
	printf("\n�ܳɼ���ߵ�ͬѧ��:");
	printf("\n-----------------------------------------------------\n");
	printf("���\tѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ܷ֣�\n");
	printf("%d\t%d\t%s\t%d\t%d\t%d\t%d",in->biaohao, in->no, in->name, in->score1, in->score2, in->score3, in->score1+in->score2+in->score3);
	printf("\n-----------------------------------------------------\n");
}																				//������������ߵ�ѧ����Ϣ 

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
	printf("\n����ѧ�������пγ̵��ܷ��ǣ�%d\n",sum);
	ave = sum/(3*i);
	printf("\n����ѧ�����пγ̵�ƽ�����ǣ�%.2f\n",ave);	
}																				//�������������п�Ŀƽ���ֲ���� 
