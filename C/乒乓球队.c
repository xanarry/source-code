#include <stdio.h>

int main()
{
	char i,j,k;
 	for(i = 'X'; i <= 'Z'; i++)//穷举法A
 	{
 		for(j = 'X'; j <= 'Z'; j++)//B
 		{
 			for(k = 'X'; k <= 'Z'; k++)//C
 			{
 				if(i != j && i != k && j != k)//三人对手各不相同，这句排除相同的情况
 				{
					if(i!='X' && k!='X' && k!='Z')//A说他不和X比赛，C说他不和X、Z比赛
     				{
      					printf("A--%c\n",i);
      					printf("B--%c\n",j);
      					printf("C--%c\n",k);
     				}
 				}
 			}
 		}
 	}
 	return 0;
}