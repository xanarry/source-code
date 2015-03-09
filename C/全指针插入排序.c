#include<stdio.h>
int main()
{
	void sort(int array[], int n);
	int a[10],i,*p;
	printf("input ten nums\n");
	for(i = 0; i < 10; i++)
	{ 
		scanf("%d",&a[i]);
	} 
	printf("------------------------\n");
	printf("have sorted\n");
	p=a;
	sort(a,10);
	for(i = 0; i < 10; i++)
	{ 
		printf("%d ",a[i]);
	} 
	return 0;
}
void sort(int array[], int n)
{
	int i,t,j,k,*p;
	p = array;
	for(i = 0; i < n-1; i++)
	{
		k = i;
		for(j = i+1; j < n; j++)
		{
			if(*(p+j) < *(p+k))
			k = j;
		}
     	if(k! = i)
    	{
			t = *(p+k);
			*(p+k) = *(p+i);
			*(p+i) = t;
	    }
    }	//用指针指向数组元素 
}
	
