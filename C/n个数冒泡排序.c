#include <stdio.h>
int main()
{
	int a[1000],i,j,n,t;
 	printf("���������ж��ٸ���Ҫ����\n");
 	scanf("%d",&n);
 	printf("����%d����\n",n);
 	for(i = 0; i < n; i++)
 	{ 
 		scanf("%d",&a[i]);
 	} 
 	for(j = 0; j < n - 1; j++)				//һ����Ҫn-1�� 
 	{ 
   		for(i = 0; i < n-j-1; i++)			//�ڲ�ֻ��Ҫ n-j-1 �� 
   		{ 
    		if(a[i] > a[i+1])
       		{
        		t = a[i];
        		a[i] = a[i+1];
        		a[i+1] = t;					//ÿ���ҵ����������ŵ����ȥ 
       		}
       	}
	} 
 	for(i = 0; i < n; i++)
 	{ 
 		printf("%d ",a[i]);					//�������������� 
 	} 
 	printf("\n");
 	return 0;
}
