#include <stdio.h>
main()
{
int a,n,t,i,s;
printf("input 'a' and 'n':\n");
scanf("%d %d",&a,&n);
printf("a=%d n=%d \n",a,n);
s=0;
i=0;
t=1;
while(t<=n)
{
i=i+a;
s=s+i;
a=a*10;
t++;
}
printf("a+aa+aaa+aaaa....=%d\n",s);
}