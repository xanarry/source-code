#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000];
	char b[1000];
	char n1;
	int i,t,j,k,s = 0,flag;
	gets(a);
	gets(b);//接收两个字符串 
	n1 = b[0];
	int lena = strlen(a);
	int lenb = strlen(b); //获取字符串长度 
	for(i = 0; i < lena; i++)
	{   k = 0;
		if(a[i] == b[0])
		{
			for(j = i, t = 0; j < i + lenb; j++, t++)
			{	
				if(b[t] == a[j])	k++; //匹配字符串 
				if(k == lenb) s++;//如果能匹配，则s自加1 
			}
		}
	}
	printf("%d",s);
	return 0;
}
