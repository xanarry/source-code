#include<stdio.h> 
#include<time.h> 
int main(void)
{
	int a,b,c;
	srand(time(NULL));		//ʹ�ú����Ժ���Ϊ��λ������������� 
    a = rand()%10 + 1;			//���������a 
    b = rand()%100 + 1; 		//���������b
    printf("%d %d",a,b);
}
