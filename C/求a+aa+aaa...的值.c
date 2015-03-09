#include <stdio.h>
main()
{
int a,n,count=1,sn=0,tn=0;
printf("input 'a' and 'n':\n");
scanf("%d %d",&a,&n);
printf("a=%d n=%d \n",a,n);
while(count<=n)
{
tn=tn+a;
sn=sn+tn;
a=a*10;
++count;
}
printf("a+aa+aaa+aaaa....=%d\n",sn);
}