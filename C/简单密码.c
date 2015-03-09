#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
//	freopen("1.txt","w",stdout); 加上这句的话，结果将输到文件中 
	char str[201];
	char pass[26] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
	int i;
	gets(str);
	while(strcmp(str,"ENDOFINPUT") != 0)
	{
		while(strcmp(str,"END") != 0)
		{
			if(strcmp(str,"START") == 0)
			{
				gets(str);
			}
			else
			{
				for(i = 0; i < strlen(str); i++)
				{
					if(isalpha(str[i]))
					{
						str[i] = pass[str[i] - 'A'];
					}
				}
				printf("%s\n",str);
				gets(str);	
			}		
		}
		gets(str);			
	}
	return 0;	
}
