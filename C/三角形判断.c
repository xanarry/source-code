#include<stdio.h>
int main()
{
	float a,b,c;
	printf("请输入三角形三条边\n");
	scanf("%f%f%f",&a,&b,&c);
	if( (a+b > c) && (a+c > b) && (b+c>a) ) 			 //判断输入的三条边能否构成三角形 
	{
		if(a == b && b==c)			
    		printf("这是个正三角形\n");					 //如果三条边相等 
  		else   
  		{ 
			if((a == b && b != c)||(a == c && a != b)||(b == c && a != b)) 
         		printf("这是一个等腰三角形\n");			 //如果有其中两条边相等 
        	else
	 		printf("其他三角形\n");
	 	} 
 	}
	else 
		printf("您输入的三边不能构成三角形\n");
  	return 0;
}
