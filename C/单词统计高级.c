#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],c;
	int w=0,num=0;
	int i;
	gets(a);
	for(i = 0; (c=a[i]) != '\0'; i++)
	{
		if(c == ' ') w = 0;		//w��¼��ǰ�ַ��Ƿ�����һ�������� 
		else if(w == 0)
		{
			w = 1;
			num++;
		}
	}
	printf("%d",num);
	return 0;
}
