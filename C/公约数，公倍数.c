#include<stdio.h>
int main()
{
	int m,n,t,r,k;
	scanf("%d%d",&m,&n);		//m>=n����������
	k = m*n;
	if(m < n)
	{
		t = m;
    	m = n;
		n = t;
    }							//���n<m�򽻻������� 
	while(m%n != 0) 
	{
		r = m%n;  
		m = n;
		n = r;					//�����滻���� 
	}
	printf("���Լ����%d\n��С��������%d",n,k/n);
	return 0;
}
