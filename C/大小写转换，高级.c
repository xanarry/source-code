#include<stdio.h>
#include<string.h>
int main()
{
	char a[2000];
	int i;
    while(scanf("%s",a) != EOF)
    {
		for(i = 0;i < strlen(a); i++)
	  	{
	   		if((a[i] >= 'a') && (a[i] <= 'z')) a[i] -= 'a'-'A';
	   		else if((a[i] >= 'A')&&(a[i] <= 'Z')) a[i] += 'a'-'A';
	      	else a[i] = a[i];			//��ȥ��Сд��ĸ��Ĳ�ֵ 
	  	}
	  	puts(a);
    }
    return 0;
}
