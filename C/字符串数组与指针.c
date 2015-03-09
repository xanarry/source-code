#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char const *keyword[] = {
		"do",
		"for", 
		"if", 
		"register", 
		"return"
	};
	printf("%d\n", sizeof(keyword));
	printf("%d\n", sizeof(keyword[0]));
	printf("%d\n", strlen(keyword[0]));
	printf("%d\n", sizeof(keyword[3]));
	printf("%d\n", strlen(keyword[3]));
	return 0;
}

