#include<stdio.h>
int main()
{
	int i;
	for(i = 5; i <= 10000; i++)
  	{
  		if( (i%5 == 0) && (i%7 == 0) )
   		printf("%d\n",i);				//����ͬʱ��5��7��������� 
	}
	return 0;
}
