#include<stdio.h>
int main()
{
	int i;
	for(i=0;i<200;i++)
	   {
	   	if(i%3==0)  continue; //如果能被3整除则跳出这次循环，不执行printf
	   	printf("%d\n",i); 
	   }
	return 0;   
}
