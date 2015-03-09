#include <stdio.h>
int main()
{
	int s;
	scanf("%d",&s);
	if(s>=90 && s<=100) printf("A");
	if(s>=80 && s<90) printf("B");
	if(s>=70 && s<80) printf("C");
	if(s>=60 && s<70) printf("D");
	if(s>=0 && s<60) printf("E");
	return 0;
}
