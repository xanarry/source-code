#include<stdio.h>
int han(int n,char x,char y,char z)
{
	if(n == 1)
	  printf("%c-->%c\n",x,z);
	else 
	 {
	 	han(n-1,x,y,z);
	 	printf("%c-->%c\n",x,z);
	 	han(n-1,x,y,z);
	 }
}

int main(void)
{
	int n;
	scanf("%d",&n);
	han(n,'A','B','C'); 
	return 0;
}
