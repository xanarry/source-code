#include<stdio.h>
void printstar();
void printworld();			//因为两个函数在后面定义的，所以在此声明，不然会报错 

int main()
{
 	printstar();
 	printworld();
 	printstar();			//这三行为函数的调用 
 	return 0;
}

void printstar()
{
	printf("***************************************\n");		//定义函数输出 “**..* ” 
}

void printworld()
{
	printf("       hello      world\n");			//定义函数输出“hello world ” 
}
 
