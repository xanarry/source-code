#include<stdio.h>
int main(void)
{
	int  a[500][500];
	long long sum = 0;
	int m,n;							//��������ĳ��Ϳ� 
	int p;								//��ʾÿ��Ԫ�صķ��ʴ��� 
	int i,j;
	int x1,y1;							//��¼��ʼ���� 
	int x2,y2;							//��¼��������	
	scanf("%d %d %d",&m,&n,&p);			//����Ҫ��������鳤������Χ��û��Ԫ�صķ��ʴ���p 
	
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d",&a[i][j]);		//�������Ԫ�� 
		}
	}
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);	//����ʼĩ���� 
	
	if(x1 == x2)
	{
		for(j = y1; j <= y2; j++)
		{
			sum += a[x1][j];
		}
	}
	
	else
	{
		for(j = y1; j <= n; j++)
		{
			sum += a[x1][j];
		}								//���������һ������,��y1��n�� 
	
		for(i = x1+1; i <= x2-1; i++)
		{
			for(j = y1; j <= n; j++)
			{
				sum += a[i][j];			//��x2ǰ���������ȫ����� 
			}
		}
	
		for(j = 1; j <= y2; j++)
		{
			sum += a[x2][j];			//�����������һ�У���1��y2�У���Ϊ�������û��ĩβ 
		}
	}

	printf("%lld",sum*p);				//��������ͽ�����Է��ʴ����������� 
	return 0;
}
