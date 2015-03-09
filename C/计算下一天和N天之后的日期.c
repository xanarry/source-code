#include <stdio.h>
#include <stdlib.h>

struct date
{
	int year;									//������ 
	int month;									//������ 
	int day;									//������ 
};

struct date next_day(struct date in);						//����������һ��ĺ��� 
struct date nextN_day(struct date in, int x);					//��������N������ڵĺ���
void print(struct date in);									//�����������ڵĺ���
int leap(int x);											//���������жϵĺ���

int main()
{
	struct date d;
	struct date r;
	struct date r1;
	int n;
	int i;
	printf("������һ�� �� �� ��:\n");
	scanf("%d %d %d",&d.year, &d.month, &d.day);
	printf("������������ǣ�\n"); 
	print(d);
	
	printf("������һ����:\n");
	r = next_day(d);										 //������һ������ 
	print(r);
	
	printf("������һ��ʱ�䳤��>(��):");
	scanf("%d",&n);											 //��������n 
	
	printf("����%d����:\n",n);
	r1 = nextN_day(d,n);										 //����n�������� 
	print(r1);
	return 0;
}

int leap(int x)
{
	if(x%4 == 0 && x%100!=0 || x%400 == 0)				 //���庯���ж��Ƿ�Ϊ���� 
		return 1;											 //���귵��1 
	else
		return 0;											 //ƽ�귵��0 
}
struct date next_day(struct date in)
{
	int m_day;												 //����m_day��¼ÿ������ 
	struct date r;
	switch(in.month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: m_day = 31; break;
		case 2: {
				 if(leap(in.year)) m_day = 29;
				 else m_day = 28;
				} 
				break;										  //���·ֱ�����ƽ����� 
		case 4:
		case 6:
		case 9:
		case 11: m_day = 30; break;							  //ȷ��ÿһ���µ����� 
	}
	if(in.day+1 <= m_day) 
	{
		r.year = in.year;
		r.month = in.month;
		r.day = in.day+1;									  //�����������ڼ�1�����һ�죬��ô���ڼ�1 
	}
    if(in.day+1 > m_day && in.month != 12)
	{
		r.year = in.year;
		r.month = in.month+1;
		r.day = 1;										 	  //�������������ǵ������һ�죬���Ҳ���12�£����·ݼ�1������Ϊ1 
	}
	if(in.month == 12 && in.day == 31) 
	{
		r.year = in.year+1;
		r.month = 1;
		r.day = 1;											  //������������ǵ������һ�죬��������1���º�����Ϊ1 
	}	
	return r;
}

struct date nextN_day(struct date in, int x)
{
	struct date re = in;
	while(x--)
	{
		re = next_day(re);									  //ͨ������x����һ�����һ�죬�����շ���x����ʱ��ֵ 
	}
	return re;
}
void print(struct date in)
{
	printf("%d-%02d-%02d\n",in.year,in.month,in.day);		  //����ʱ�������ʽ���ƺ��� 
}
