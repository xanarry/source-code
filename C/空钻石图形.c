#include<stdio.h>
int main(void)
{
	int i,j,k,l,n,t;
	printf("���������:\n");
	scanf("%d",&n);
	t=n/2;
	for(i = 0; i < n; i++)
    { 
       
	    if(i <= t)
	    {
			for(k=0;k<(t+1)-(i+1);k++)
			{
				printf(" ");
			}
		 	for(j = 0; j < (2 * (i + 1) - 1); j++)  //�൱�����е�ͨ�ʽ 
		 	{
		 		if(j==0||j==2*i) 
					printf("*");
		    	else 
					printf(" ");
		 	}
	         printf("\n");
        }
        else        
        {
			for(l=0;l<(i-t);l++)
			{
				printf(" ");
			}
         	for(j = 0; j < ((2*t-1)-(i-(t+1))*2); j++)	//�൱�����е�ͨ�ʽ 
         	{
         		if( j==0 || j== ((2*t-1)-1-(i-(t+1))*2) )	//�൱�����е�ͨ�ʽ 
					printf("*");
              	else 
					printf(" ");
         	}
	        printf("\n");
	    }
    } 
	return 0;  
}
