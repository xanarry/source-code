/*
	Description: 	
�����п���һλ��ѧ�ң������о�����ʱ���֣�����һ����������ȫ��ͬ������ɵ���λ����
��������ǵ�ÿλ���������������һ���ϴ������һ����С������Ȼ���ýϴ�����ȥ��
С���������λ��ʱ���㣬������ȥ����󽫱��һ���̶�������6174������ǿ����п˳�����

    ���磺4321-1234=3087

         8730-378=8352

         8532-2358=6174

         7641-1467=6147

    ���Kλ��Ҳ�մ˰������ǲ��Ǳ��һ�����������ڼ�������֮���γ�ѭ������������
	�п�Բ���������������λ��54321��

    54321-12345=41976

    97641-14679=82962

    98622-22689=75933

    97533-33579=63954

    96543-34569=61974

    97641-14679=82962

    ���ǰ�82962 75933 63954 61974����ѭ���ڣ��������п�Բ������
����Input
���������У�ÿ��Ϊһ�����󡰿����п�Բ����������ʼ������С��maxlongint�� 
���Output
ÿ��Ϊ��Ӧ������ѭ���ڣ�����֮���ÿո������
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
