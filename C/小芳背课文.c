/************************
���ڲ�������һ����ȱʧ�ĵ���
����i love you
	i _ you
���룺love
************************/ 
#include<stdio.h>
#include<string.h>
struct input
{
	char o[2000];
	char m[2000];
};												//��Ϊһ���������䣬���Զ���ṹ�� 
int main(void)
{
	int t,i,flag,j,k;
	char temp[204][30];							//�趨��󳤶� 
	scanf("%d",&t);								//��¼�ж��������� 
	getchar();									//������������еĻ��� 
	struct input sts[100];
	for(i = 0; i < t; i++)
    {
    	gets(sts[i].o);
    	gets(sts[i].m);							//����һ������ 
    }
	for(j = 0; j < t; j++)
	{
		for(i = 0; i < strlen(sts[j].m); i++)
        {
    	    if(sts[j].o[i] != sts[j].m[i])
    	    {
    		   flag = i;						//���Ҳ���¼�����ַ����еĲ�ͬλ�� 
    		   break;
       	    }
       }
       for(i = flag;(sts[j].o[i] != ' ' && sts[j].o[i] != '\0'); i++) //���ҵ�һ�����ʵĽ���λ�� 
   	   {
           printf("%c",sts[j].o[i]);			//�������ַ����м�¼��λ�����һ������ 
       }
        if(j < t-1) printf("\n");
   }
}
    		
