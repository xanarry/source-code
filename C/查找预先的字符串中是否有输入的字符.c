#include <stdio.h>
#include <string.h>
int main()
{
	char a[15]={"abcdefghijklmno"};			//�趨Ĭ���ַ��� 
	char c;									//�洢������ַ� 
	int i;									
	int k=-1;								//�趨k��ֵΪ-1 
	printf("%s\n",a);						//����Ԫ�ַ�����ʾ�û� 
	printf("input a char:\n");
	scanf("%c",&c);							//�����ַ�c 
	printf("U have input '%c'\n",c);
	for(i = 0; i < strlen(a); i++)
	{
		if(c == a[i])
	    {
	    	k = i;							//�������ַ����в��ң��ҵ�����k�洢�±� 
	    	break;							//ȷ��ֻ��¼��һ�ַ���λ�� 
	    }
	}
	if(k>-1)								//���ҵ��ַ� 
		printf("'%c' is included and it's in %d\n",c,k+1);
	else 
		printf("ERROR");
	return 0;
}
