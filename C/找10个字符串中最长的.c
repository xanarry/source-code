#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[10][60];
	int i,len,max=-1,index;
	for(i = 0; i < 10; i++)
	{
		scanf("%s",a[i]);
		len = strlen(a[i]);
		if(len > max)
		{
			max = len;		//��¼�ַ�����󳤶� 
			index = i;		//��¼��ַ����±� 
	    }
    }
	printf("%s %d",a[index],len);
}
