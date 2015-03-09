#include<stdio.h>
#include<string.h>
int main()
{
	char a[200];
	int i,j;
	gets(a);
	for(i = 0;i < strlen(a); i++)
	{
		if((a[i] >= 'a') && (a[i] <= 'z')) a[i] -= 'a'-'A';
		else if((a[i] >= 'A') && (a[i] <= 'Z')) a[i] += 'a'-'A';
	    else a[i] = a[i];						//将每个字符做转换 
    }
    for(i = 0;i < strlen(a); i++)
    printf("%c",a[i]);
    return 0;
}
