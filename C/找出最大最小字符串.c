#include<stdio.h>
#include<string.h>
#define N 5
int main()
{
 	char a[20],max[20],min[20];
 	int i;
 	scanf("%s",max); 
    strcpy(min,max);
 	for(i = 0; i < N-1; i++)
 	{
 		scanf("%s",a);		//方法与找最大最小数一样 
 		if(strcmp(max,a) > 0) strcpy(max,a);
 		if(strcmp(min,a) < 0) strcpy(min,a);
 	}					
 	printf("max=%s\nmin=%s",max,min);
 	return 0;
 }
 		
 		
	  
	 
