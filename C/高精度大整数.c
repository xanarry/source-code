#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_LEN 2000
//������������� 
int an1[MAX_LEN + 10];
int an2[MAX_LEN + 10];							// ���������������� 
char szLine1[MAX_LEN + 10];
char szLine2[MAX_LEN + 10];						//���������ַ����� 
int main()
{
    scanf("%s",szLine1);
    scanf("%s",szLine2);						//���ַ���ʽ�������������� 
    int i,j ;
    memset(an1, 0, sizeof(an1));
    memset(an2, 0, sizeof(an2));				//�����������ÿһ��Ԫ�ظ�ֵΪ0 
    int nLen1 = strlen(szLine1);
    				//��nlen1����szLine1�ĳ��� 
    j=0 ;
    for(i = nLen1 - 1; i >= 0; i--) 
	{
		an1[j++] = szLine1[i] - '0';			//���ַ�����1�е������ַ�ת��Ϊ������λ�����洢����������1�� 
	} 
    int nLen2=strlen(szLine2);	
    				//��nlen2����szLine2�ĳ���
    j=0;										//����j��ֵΪ0 
    for(i = nLen2 - 1; i >= 0; i--)
	{
		an2[j++]=szLine2[i] - '0';				//���ַ�����2�е������ַ�ת��Ϊ���ִ洢����������2�� 
	} 

    for(i = 0;i < MAX_LEN; i++)					
    {
        an1[i] += an2[i];						//������������룬ÿһλ���ӷ���ʽ���� 
        if(an1[i] >= 10)						//���������֮�ʹ���10 
        {
            an1[i] -= 10;						//��ôֻȡ��λ���ִ��浽������λ�� 
            an1[i+1]++;							//�������������һ��λ�ý�λ1 
        }
    }

    bool bStartOutput = false;					//����һ����������Ĭ��Ϊfalse 
    for(i = MAX_LEN;i >= 0; i--)				//������β��������� 
    {
        if(bStartOutput) printf("%d",an1[i]);	//���������������,���Ԫ��an1[i],�˴����������ų�û����ֵ������Ԫ�� 
        else if(an1[i])							//���a[i]���� 
        {	
            printf("%d",an1[i]);				//���������е�����
            bStartOutput = true ;				//������������ֵtrue 
        }
    }
    if(!bStartOutput) printf("0");				//������Ϊ0��ʾ�� 
    return 0 ;
}
