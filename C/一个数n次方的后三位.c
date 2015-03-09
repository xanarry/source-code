#include<stdio.h>
int main() 
{
	int i,x,y,z=1;
	printf("请输入一个数和次方数\n");
	scanf("%d%d",&x,&y);
	for(i=1;i<=y;i++)
	{ 
    	z = z*x%1000;			//在计算后三位时，1000前面的数都不影响计算，所以先取余数有利于大数的计算 
    }
	if(z>=100)
    {
    	printf("%d^%d最后三位数是:%d\n",x,y,z);
    }
	else
	{ 
    	printf("%d^%d最后三位数是:%d\n",x,y,z);
    }
  return 0;
}

