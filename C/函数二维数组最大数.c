int max(int array[][4], int m, int n)//���庯���еĶ�ά���鲻��ʡ�Եڶ�ά�Ĵ�С 
{
	int x,y,k;
	k=array[0][0];
	for(x = 0; x < m; x++)
	{ 
		for(y = 0; y < n; y++)
	  	{
	  		if(array[x][y] > k)
	  	   	k = array[x][y];    	//���� ��ֵ 
	  	}
	} 
	return k;
}
#include<stdio.h>
int main()
{
   int a[3][4] = {{4,56,3,2},{92,32,1,43},{8,769,55,87}};
   printf("%d",max(a,3,4));
   return 0;
}
