#include <stdio.h>
void ave(float *p,int n)
{
	float sum = 0;
	int i;
	for(i = 0; i < n; i++)
	{
		sum += *(p+i);
	}
	printf("\naverage score is:%.2f\n\n",sum/12);
}

void search(float *p, int n)
{
	int j;
	printf("student_%d: ",n);
	for(j = 0; j < 4; j++)
	{
		printf("%-3.0f ", *(p+4*(n-1)+j));//����search���� 
	}
}

void fail(float *p)
{
	int i,j,k;
	float *p1 = p;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if((*(p+4*i+j)) < 70)//�����з�������70��ѧ�� 
			{
				printf("\n");
				search(p1,i+1);//���ú��������Ϣ 
				break;
			}	
		}
	}
}

int main()
{
	float a[3][4]={{65,67,70,60},{60,87,90,81},{90,99,100,98}};//�趨�����Ĭ������ 
	int i,j,k;
	printf("following is the score:\n\n");
	
	for(i = 0; i < 3; i++)
	{
		printf("student_%d: ",i+1);
		for(j = 0; j < 4; j++)
		{
			printf("%-3.0f ",a[i][j]);//���Ĭ������ 
		}
		printf("\n");
	}
	
	ave(*a,12);//���ú�������ƽ���� 
	printf("input a std_num:\n");
	
	scanf("%d",&k);
	search(&a[0][0],k);//���ú�����ѯ����ָ��ѧ����Ϣ 
	
	printf("\n\nthe following failed:");
	fail(&a[0][0]);//���ú�������������ѧ����Ϣ 
}
