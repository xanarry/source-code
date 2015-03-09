#include <stdio.h>
#include <string.h>
int main()
{
	char a[15]={"abcdefghijklmno"};			//设定默认字符串 
	char c;									//存储输入的字符 
	int i;									
	int k=-1;								//设定k初值为-1 
	printf("%s\n",a);						//输入元字符串提示用户 
	printf("input a char:\n");
	scanf("%c",&c);							//接收字符c 
	printf("U have input '%c'\n",c);
	for(i = 0; i < strlen(a); i++)
	{
		if(c == a[i])
	    {
	    	k = i;							//在整个字符串中查找，找到后用k存储下标 
	    	break;							//确保只记录第一字符的位置 
	    }
	}
	if(k>-1)								//查找到字符 
		printf("'%c' is included and it's in %d\n",c,k+1);
	else 
		printf("ERROR");
	return 0;
}
