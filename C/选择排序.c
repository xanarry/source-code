int sort(int array[], int n)
{
	int i,j,k;
	int t;
	i = 0;
	for(;i<n-1;i++)
	{
	 	k=i;
		for(j=i+1;j<n;j++)
		{
		    if(array[j]<array[k])
		    k=j;
		}//依次向后面查找，找到后面的最小值
		if(k!=i)
		{
			t=array[k];
   	   	 	array[k]=array[i];
 	    	array[i]=t;
 	    	//与起始值作交换
		}
	}
}
#include<stdio.h>
int main()
{
	int a[10],i;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	sort(a,10);
	for(i=0;i<10;i++)
	printf("%d ",a[i]);
	return 0;
}
	
