#include<stdio.h>
int main()
{
	int a[10];
	int i,j,temp;
	printf("input 10 nums:\n");
	for(i=0;i<10;i++)
	    scanf("%d",&a[i]);		//ʹ��ѭ������10����������
	for(i=0;i<10;i++)
	   printf("%d ",a[i]);			//��������10����
	printf("\n"); 
	for(j=0;j<9;j++)			//10��������ֻ����Ŵ�
	   for(i=0;i<9-j;i++)			//ȥ���Ѿ��������
	       if(a[i]>a[i+1])
	          {
	          	temp=a[i];
	          	a[i]=a[i+1];
	          	a[i+1]=temp;		//��������
	          }
	for(i=0;i<10;i++)
	   printf("%d ",a[i]);			//�������������         
    return 0;	
}
