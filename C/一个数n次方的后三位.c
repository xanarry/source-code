#include<stdio.h>
int main() 
{
	int i,x,y,z=1;
	printf("������һ�����ʹη���\n");
	scanf("%d%d",&x,&y);
	for(i=1;i<=y;i++)
	{ 
    	z = z*x%1000;			//�ڼ������λʱ��1000ǰ���������Ӱ����㣬������ȡ���������ڴ����ļ��� 
    }
	if(z>=100)
    {
    	printf("%d^%d�����λ����:%d\n",x,y,z);
    }
	else
	{ 
    	printf("%d^%d�����λ����:%d\n",x,y,z);
    }
  return 0;
}

