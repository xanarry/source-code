#include <stdio.h>
#include <math.h>

float f1(float x,float y)
{
	return (y+0.5*y*y)-(x+0.5*x*x);
}

float f2(float x,float y)
{
	return (y*y+3*y)-(x*x+3*x);
}

float f3(float x,float y)
{
	return (exp(y)+y)-(exp(x)+x);
}
//f1,f2,f3是设定的三个固定的函数积分式 
float chose(float n,float m, float (*fun)(float,float))
{
	return (*fun)(n,m);
}//定义计算积分的函数 

int main()
{
	float a,b;
	scanf("%f%f",&a,&b);
	printf("%.2f\n",chose(a,b,f1));//分别调用函数计算指定区间的定积分 
	printf("%.2f\n",chose(a,b,f2));
	printf("%.2f\n",chose(a,b,f3));
	return 0;
}
