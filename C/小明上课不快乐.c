/*

题目Problem
Unhappy Jinjin
Jinjin is a junior middle school student. 
Her mother thinks that Jinjin should be 
hard-working in study. So, besides going 
to school, she has to go to take the courses
after school that her mother registered. And
then her mother sends her to learn recitation,
dancing and playing the piano. But Jinjin is
not happy for having courses over 8 hours a
day, more time and more unhappiness. If 
Jinjin is happy except this, and her unhappiness 
would not last the second day.Please examine the 
schedule of Jinjin in last week, and consider if 
she were happy or not. If she will not happy, 
which day is most unhappy?

输入Input
Input data includes 7 lines, each said the 
schedule of Monday to Sunday. A line includes 
2 non negative integer less than 10,please 
separate them in blank space, and each said the 
time that Jinjin has courses in school or the 
time that the courses that her mother gave her。
 
输出Output
Output data has only a line, it includes a 
number. If she is happy,output"0",else output 
the day（1,2,3...Each means Monday, Tuesday, 
Wednesday...).If two-day or over two-day degrees 
of unhappiness are equal, output the former day.

*/
#include<stdio.h>
int main()
{
	int i,j,a[7][2],m,x=0,y;
	for(i = 0; i < 7; i++)
	{ 
		for(j = 0; j < 2; j++)
		{ 
	 		scanf("%d",&a[i][j]);	//有二维数组存储每天的上课时间 
	 	}
	} 
	for(i = 0; i < 7; i++)
	{
		if( (a[i][0] + a[i][1]) > 8 ) 
	  	{
	   		x = i+1; 				//如果某天的上课时间超过8小时，x加1	
	   		break;
      	}
    }
    printf("%d",x);
    return 0;
}  
