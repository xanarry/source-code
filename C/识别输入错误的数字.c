#include<stdio.h>
#include<string.h>
int main()
{
	char a[10];
	int i;
	int n;
	scanf("%d",&n); 
	for(i = 0;i < n; i++)
	{
		scanf("%s",a);				//����һ��Ӣ������ 
		if(strlen(a) == 5) 
			printf("3\n");			//����ַ���������5ֱ�����3 
		else if((a[0] == 'o') + (a[1] == 'n') + (a[2] == 'e') >= 2)
			printf("1\n");			//ͨ�����ֵ���㣬�����������ĸ�ǵ���1
		else if((a[0] == 't') + (a[1] == 'w') + (a[2] == 'o') >= 2)
		    printf("2\n");			//ͨ�����ֵ���㣬�����������ĸ�ǵ���2
	}
	return 0;
}
		
