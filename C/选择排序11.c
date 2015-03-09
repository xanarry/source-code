#include<stdio.h>
int main()
{
	void sort(int array[], int n);
	int a[10],i;
	printf("input ten nums\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);	
	}
	printf("------------------------\n");
	printf("have sorted\n");
	sort(a,10);
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);	
	}
	return 0;
}
void sort(int array[], int n)
{
	int i,t,j,k;
	for(i = 0; i < n-1; i++)
	{
		k = i;							//首先第一数不动，并记录这个数的下标 
		for(j = i+1; j < n; j++)		//从这个数后面找是否有比这个数更小的数 
		{
			if(array[j] < array[k])		//如果有 
			k = j;						//记录新的下标 
		}
     	if(k != i)						//如果找到了更小的数， 
    	{
			t = array[k];
			array[k] = array[i];
			array[i] = t;				//交换位置，及把最小的数那到前面来 
	    }
    }
}
	
