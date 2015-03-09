#include<stdio.h>
int main()
{
	int a[10];
	int i,j,temp;
	printf("input 10 nums:\n");
	for(i=0;i<10;i++)
	    scanf("%d",&a[i]);		//使用循环接受10个数给数组
	for(i=0;i<10;i++)
	   printf("%d ",a[i]);			//输出输入的10个数
	printf("\n"); 
	for(j=0;j<9;j++)			//10个数排序只排序九次
	   for(i=0;i<9-j;i++)			//去除已经排序的数
	       if(a[i]>a[i+1])
	          {
	          	temp=a[i];
	          	a[i]=a[i+1];
	          	a[i+1]=temp;		//交换数字
	          }
	for(i=0;i<10;i++)
	   printf("%d ",a[i]);			//输出排序后的数组         
    return 0;	
}
