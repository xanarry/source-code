#include<stdio.h>
float *search(float (*pointer)[4])
{
	int i;
	for(i=0;i<4;i++)
	{
		if(*(*pointer+i)<70)
		return *pointer;
	}
}
int main()
{
	float score[5][4] = {{67,87,66,89},{90,87,89,76},{97,78,96,76},{67,78,98,80},{89,98,79,80}};
	float *p;
	int i,j;
	for(i=0;i<5;i++)
	{
		p=search(score+i);
		{
			if(p == *(score+i))
			{
				printf("No %d <70 and score is:",i+1);
				for(j=0;j<4;j++)
				{
					printf("%.2f ",*(p+j));	
				}
				printf("\n");
			}
		}
	}
	return 0;
}
