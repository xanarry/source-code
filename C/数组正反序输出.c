#include<stdio.h>
void printstar();
void printworld();			//��Ϊ���������ں��涨��ģ������ڴ���������Ȼ�ᱨ�� 

int main()
{
 	printstar();
 	printworld();
 	printstar();			//������Ϊ�����ĵ��� 
 	return 0;
}

void printstar()
{
	printf("***************************************\n");		//���庯����� ��**..* �� 
}

void printworld()
{
	printf("       hello      world\n");			//���庯�������hello world �� 
}
 
