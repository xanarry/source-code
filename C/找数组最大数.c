#include<stdio.h>
int main()
{
    int a[100];
	int i,k,max,t,n;
	scanf("%d",&n);
	for(i = 0;i < n; i++)
	{ 
		scanf("%d",&a[i]);		//����n���� 
	} 
	max = a[0];					//Ĭ��a[0]�����ֵ 
	for(i = 0; i < n; i++)
    { 
		if(a[i] > max)
        {
			max = a[i];			//���������max 
          	k=i;				//��¼�±� 
		}
    }
	printf("max=%d %d",max,k);	//������ 
    return 0;
}
