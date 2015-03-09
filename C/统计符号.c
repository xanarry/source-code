#include <stdio.h>
#include <ctype.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	char inc;
	inc = getchar();
	while(inc != '\n')
	{
		if(isupper(inc)) a++;
		if(islower(inc)) b++;
		if(isspace(inc)) c++;
		if(ispunct(inc)) d++;
		if(isdigit(inc)) e++;
		inc = getchar();
	}
	printf("大写：%d 小写：%d 空格：%d 其他：%d 数字：%d",a,b,c,d,e);
	return 0;
}
