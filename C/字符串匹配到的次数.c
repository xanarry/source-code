#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000];
	char b[1000];
	char n1;
	int i,t,j,k,s = 0,flag;
	gets(a);
	gets(b);//���������ַ��� 
	n1 = b[0];
	int lena = strlen(a);
	int lenb = strlen(b); //��ȡ�ַ������� 
	for(i = 0; i < lena; i++)
	{   k = 0;
		if(a[i] == b[0])
		{
			for(j = i, t = 0; j < i + lenb; j++, t++)
			{	
				if(b[t] == a[j])	k++; //ƥ���ַ��� 
				if(k == lenb) s++;//�����ƥ�䣬��s�Լ�1 
			}
		}
	}
	printf("%d",s);
	return 0;
}
