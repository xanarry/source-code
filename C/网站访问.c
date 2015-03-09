#include<stdio.h>
#include<string.h>

int main()
{
	char a[100][100];
	int i,now = 0, max = 0;
	char temp[100];
	strcpy(a[0],"http://www.acm.org/");
	while(1)
	{
  		scanf("%s",temp);
  		if(strcmp(temp,"VISIT")==0)
  		{
  			scanf("%s",temp);
  			printf("%s\n",temp);
  			now++;
  			strcpy(a[now],temp);
  			max=now;
  		}
  		else if(strcmp(temp,"FORWARD")==0)
  		{
  				i=now+1;
  				if(i<=max)
  		 		{
  		   			printf("%s\n",a[i]);
  		   			now=i;
  	     	}
  				else
  		 		printf("Ignored\n");
  		}
  		else if(strcmp(temp,"BACK")==0)
  		{
  				i=now-1;
  				if(i>=0)
  		 		{
  		  			printf("%s\n",a[i]);
  		   	 		now=i;
  	     		}
  				else
  		 		printf("Ignored\n");
  		}
  		else if(strcmp(temp,"QUIT")==0)
  		{
  				break;
  		}
  }
  return 0;
}
