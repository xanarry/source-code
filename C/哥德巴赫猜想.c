#include<stdio.h>
int prime(int a)
{
    int i;
    if(a<2) return 0;
    else 
    {
        for(i = 2; i < a; i++)
        if(a%i == 0)
        {
            return 0;
            break ;
        }
        if(i == a) return 1;				//���庯��ɸѡ���� 
    }
}
int main()
{
    int n,x;
	for(n = 4; n < 101; n += 2)				//��°ͺյ����ķ�Χ��4-100��ż�� 
	{
		for(x = 2; x < n; x++)				//Ҫ�����������������ô�κ�һ�������϶�С��n,���������������������λ�õ��������n/2 
	  	{
	    	if((prime(x)) && prime(n-x))	//������������������������������������� 
	     	{
		  		printf("%2d+%2d=%3d\n",x,n-x,n);
	     	}
	  	} 									//break; ����break��ֻ�����һ����ʽ 
    }
	return 0;	 
}
