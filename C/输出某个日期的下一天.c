#include<stdio.h>
int leap(int y)
{
	if((y%4 == 0) && (y%100 != 0) || (y%400 == 0))
		return 1;
	else 
		return 0;										//�����ж����� 
}

int l(int n)
{
	int a[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	return a[n];
}														//��¼����ÿ������ 

int nl(int n)
{
	int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	return a[n];
}														//��¼ƽ��ÿ������		

int main()
{
	int year,month,day;
	int sum = 0;
	scanf("%d%d%d", &year,&month,&day);
	if(leap(year)) 										//��������� 
    {	
    	if((month == 12) && (day == 31)) 
			printf("%d %d %d", year + 1,1,1);			//�������ĩֱ�������һ���1��1�� 
        else if((day + 1) <= l(month - 1)) 
			printf("%d %d %d", year,month,(day + 1));	//�����һ����֮���һ�죬������������һ�� 
    	else   
			printf("%d %d %d", year,(month + 1),1);		//�������ĩ��������µ�һ�� 
    }
    else												//�����ƽ�� 
    {
    	if((month == 12) && (day == 31)) 
			printf("%d %d %d", year + 1,1,1);			//ͬ�� 
        else if((day + 1) <= nl(month - 1)) 
			printf("%d %d %d", year,month,(day + 1));	//ͬ�� 
    	else 
			printf("%d %d %d", year,month + 1,1);		//ͬ�� 
    }
	return 0;
}
