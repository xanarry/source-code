#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[200];
	int i,n=0;
	gets(a);
    for(i = 0; i < strlen(a); i++)
    {
    	if((a[i] == 'a') || (a[i] == 'd') || (a[i] == 'j') || (a[i] == 'g') || (a[i] == 'm') || (a[i] == 'p') || (a[i] == 't') || (a[i] == 'w')) n += 1; 
    	if((a[i] == 'b') || (a[i] == 'e') || (a[i] == 'h') || (a[i] == 'k') || (a[i] == 'n') || (a[i] == 'q') || (a[i] == 'u') || (a[i] == 'x')) n += 2;
    	if((a[i] == 'c') || (a[i] == 'f') || (a[i] == 'i') || (a[i] == 'i') || (a[i] == 'l') || (a[i] == 'o') || (a[i] == 'r') || (a[i] == 'y') || (a[i]=='v')) n += 3;
    	if(a[i] == 's') n += 4;
    	if(a[i] == 'z') n += 4;
    	if(a[i] == ' ') n += 1;  			//分别将每个按键的可能列举出来加上固定的值 
    }
	printf("%d",n);
}
