#include<stdio.h>
int main()
{
	float a,b,c;
	printf("������������������\n");
	scanf("%f%f%f",&a,&b,&c);
	if( (a+b > c) && (a+c > b) && (b+c>a) ) 			 //�ж�������������ܷ񹹳������� 
	{
		if(a == b && b==c)			
    		printf("���Ǹ���������\n");					 //������������ 
  		else   
  		{ 
			if((a == b && b != c)||(a == c && a != b)||(b == c && a != b)) 
         		printf("����һ������������\n");			 //������������������ 
        	else
	 		printf("����������\n");
	 	} 
 	}
	else 
		printf("����������߲��ܹ���������\n");
  	return 0;
}
