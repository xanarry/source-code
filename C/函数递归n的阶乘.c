#include<stdio.h>
int main()
{   float fn(int);				//�����׳˺���	
	int n;
	float y;
	printf("����һ������");
	scanf("%d",&n);
	if(n>=0)
	{
	    y=fn(n);				//��������n����0������ú�������׳� 
      	printf("%d!=%f",n,y);	//����׳˽�� 
    }
	else printf("n�������0\n"); 
}
float fn(int n)
{
	float f;
	if(n==0||n==1) 
		f=1;					//���n==0 or n==1 ��׳˵�ֵ����1 
    else
		f=fn(n-1)*n;			//�ݹ麯����ֵ 
    return (f);
}
