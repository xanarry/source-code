/*
	Description: 	
卡布列克是一位数学家，他在研究数字时发现：任意一个不是用完全相同数字组成的四位数，
如果对它们的每位数字重新排序，组成一个较大的数和一个较小的数，然后用较大数减去较
小数，差不够四位数时补零，类推下去，最后将变成一个固定的数：6174，这就是卡布列克常数。

    例如：4321-1234=3087

         8730-378=8352

         8532-2358=6174

         7641-1467=6147

    如果K位数也照此办理，它们不是变成一个数，而是在几个数字之间形成循环，称作卡布
	列克圆舞曲。例如对于五位数54321：

    54321-12345=41976

    97641-14679=82962

    98622-22689=75933

    97533-33579=63954

    96543-34569=61974

    97641-14679=82962

    我们把82962 75933 63954 61974称作循环节，即卡布列克圆舞曲。
输入Input
包含若干行，每行为一个待求“卡布列克圆舞曲”的起始整数（小于maxlongint） 
输出Output
每行为对应整数的循环节，数据之间用空格隔开。
*/
#include <algorithm>
#include <iostream>

using namespace std;
long long int a[1000];
int l;
long long int maxn,minn;
int search(long long int x)
{
	int i;
	for(i=0;i<l;i++)
	{
		if(a[i]==x)
	    	return i;
	}
	return -1;
}

void getnumber(long long int n)
{
	int i=0,j,b[40];
	while(n!=0)
	{
		b[i] = n%10;
	  	i++;
	  	n = n/10;
	}
	sort(b,b+i);
	maxn = minn = 0;
	for(j=0;j<i;j++)
	{
		minn=minn*10+b[j];
	}
	for(j=i-1;j>=0;j--)
	{
		maxn=maxn*10+b[j];
	} 
}
int main()
{
  	long long int n,t;
  	int i,j;
  	while(cin>>n)
  	{
  		l=0;
    	while(1)
    	{
  	 		getnumber(n);
  	 		t=maxn-minn;
  	 		i=search(t);
  	  	if(i!=-1)
  	  	{
  			for(j=i;j<l;j++)
  			{
  				cout<<a[j]<<" ";
  			}
  			cout<<endl;
  			break;
  	  	}
      	else
  	  	{
  			a[l]=t;
  			l++;
  	  	}
  	  	n=t;
    	}
  	}
  	return 0;
}
