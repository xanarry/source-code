#include<stdio.h>
int main()
{
	int l,r,i,n=0,b,k;
	int a[100000];
	scanf("%d %d",&l,&r);
	for(i = 0, k =l; i <= r-l; i++,k++)
	{ 
		a[i] = k;
	} 
	for(i = 0;i <= r-l; i++)
	{
		while(a[i] > 0)
	 	{   
	    	b = a[i]%10;		//���Ϸ���ÿһλ�� 
	 		if(b == 2) n++;		//�����������2���Ƚ�	
	    	a[i] /= 10;			//ȡ���������� 
	 	}
	}
    printf("%d",n);
    return 0;
}

