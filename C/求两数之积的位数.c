#include<stdio.h>
int main()
{
	int i,t = 1;
	unsigned long long a,b;
	scanf("%llu%llu",&a,&b);				//���������� 
    for(i = 1; i < 100; i++)				//i�൱��10�Ĵη��� 
	{
    	if( (1 <= ( (a*b) / t)) && ( ((a*b) / t) <= 9) ) //����������ĳ˻�����t��>1����<9,
    	{ 
			break;
		} 
     	t *= 10;							//��������㣬����t��ֵ����10�� 
    }
    printf("%d",i);							//����η��������˻��Ƕ���λ 
    return 0;
 }
