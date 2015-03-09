#include <stdio.h>
#include <string.h>

char * my_strcpy(char *obj, const char *src)
{
	while ((*obj = *src) != '\0')
	{
		obj++;
		src++;
	}
	return obj;
}
int main(int argc, char const *argv[])
{
	char a[100];
	scanf("%s", a);
	printf("%s\n", a);
	char *b;
	my_strcpy(b, a);
	printf("%s\n", b);
	return 0;
}
