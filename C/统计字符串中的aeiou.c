#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[100];
	int i,ta = 0,te = 0,ti = 0,to = 0,tu = 0;
	scanf("%s",a);
	for(i = 0; i < strlen(a); i++)
	{
		if(a[i]=='a' || a[i]=='A') ta++;
		if(a[i]=='e' || a[i]=='E') te++;
		if(a[i]=='i' || a[i]=='I') ti++;
		if(a[i]=='o' || a[i]=='O') to++;
		if(a[i]=='u' || a[i]=='U') tu++;
	}
	printf("%d %d %d %d %d",ta,te,ti,to,tu);
}
