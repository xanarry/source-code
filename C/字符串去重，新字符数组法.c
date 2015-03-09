#include <stdio.h>
#include <string.h>

char * un_same(char a[]); 
int main()
{
	char _original[100];
	puts("请输入一个字符串: ");
	gets(_original);
	puts("这是您输入的的字符串: ");
	puts(_original);
	puts("这是字符去重后的效果: ");
	puts(un_same(_original));
	return 0;
} 

char * un_same(char a[])
{
	int i;
	int j;
	int t = 1; 
	int flag = 0;  
	char _new[100]; 
	_new[0] = a[0];
	for(i = 1; i < strlen(a); i++)//后部分的字符 
	{
		for(j = 0; j < i; j++) //前部分的字符  
		{	
			flag = 0;
			if(a[i] == _new[j]) //如果发现后面有与前面相同的字符 
			{
				flag = 1; 
				break;
			}
		}
		if(flag == 0)
		{
			_new[t] = a[i];				
			t++;
		}
	}
	_new[t] = '\0';
	strcpy(a,_new);
	return a;
}
