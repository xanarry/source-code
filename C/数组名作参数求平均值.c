#include<stdio.h>
int main()
{   
    float average(float array[10]);		/*函数的声明*/ 
	int i;
	float aver,a[10];
	printf("input 10 stds' score\n");
	for(i = 0; i < 10; i++)
	{ 
		scanf("%f",&a[i]);
	} 
	aver = average(a);					/*函数调用*/ 
	printf("%f",aver);
	return 0;
}
float average(float array[10])			/*函数定义*/ 
{
	int j;
	float v,s;
	for(j = 0; j < 10; j++)
	{ 
		s += array[j];					//求和 
	} 
	v = s/10;
	return v;
}
