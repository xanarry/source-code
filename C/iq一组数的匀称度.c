//用于比较数组每两个数之间的差值有多少种 
#include<stdio.h>
int main()
{
    int a[200],i,j,n,l,t,b[100],d=1,m,f ;
    scanf("%d",&n);							//定义输入的数字个数n 
    for(i = 0; i < 2*n; i += 2)
    {
        scanf("%d",&a[i]);					//以间隔的方式储存数组元素 
    }
    for(i = 1,t = 0; i < 2*n; i += 2,t++)
    {
        b[t] = a[i+1] - a[i-1];				//计算两个元素的差值给另外数组b 
    }
    int temp[100];							//定义临时数组 
    temp[0] = b[0];
    for(i = 1;i < n-1; i++,d++)				
    {
        temp[i] = b[i];						//将b数组的元素依次给数字temp,每给一个元素d加1 
        for(j = 0;j < i;j++)
        {
            if(b[i] == temp[j])
            {
                d--;						//如果发现与前面的元素有相同，d-- 
                break ;
            }
        }
    }
    printf("%d", d);
}

