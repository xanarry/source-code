#include<stdio.h>
int main()
{
	int a[3][4]={{3,1,4,5},{-3,43,72,23},{33,54,52,64}}; //设定数组初值 
   	int i,j,m,n,max;
	max = a[0][0];						//默认最大值是a[0][0] 
	for(i = 0; i < 3; i++)
	{ 
    	for(j = 0; j < 4; j++)
        {   
        	if(a[i][j] > max)			 
            max = a[i][j];
            m = i;
            n = j;						//如果数组元素大于max，则将其值给max，在再与后面的数比较，并用m,n记录最大数的下标 
        }
	} 
   printf("max=%d\n",max);
   printf("%d %d\n",m,n);
   return 0;
}
           
