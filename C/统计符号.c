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
	printf("��д��%d Сд��%d �ո�%d ������%d ���֣�%d",a,b,c,d,e);
	return 0;
}
