#include<stdio.h>
int main()
{
	int i;
	for(i=0;i<200;i++)
	   {
	   	if(i%3==0)  continue; //����ܱ�3�������������ѭ������ִ��printf
	   	printf("%d\n",i); 
	   }
	return 0;   
}
