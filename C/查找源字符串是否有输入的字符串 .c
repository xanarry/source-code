/***************************
此代码的作用相当于函数strstr()
***************************/ 
#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	char b[1000];
	char n1;
	int i,t,j,k,s=0,flag;
	gets(a);
	gets(b);
	n1 = b[0];
	int lena = strlen(a);
	int lenb = strlen(b);
	for(i = 0; i < lena; i++)
	{   
		k = 0;
		if(a[i] == b[0])
		{
			for(j=i,t=0; j<i+lenb; j++,t++)
			{	
				if(b[t] == a[j])	k++;
				if(k == lenb) s++;
			}
		}
	}
	if(s != 0) printf("Yes");
	else printf("No");
	return 0;
}
