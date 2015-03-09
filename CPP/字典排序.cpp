#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int i;
	int n;
	string a[1000];			//定义a是字符串数组 
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> a[i];		//获取元素 
	}
	
	sort(a,a+n);			//调用函数排序 
	
	for(i = 0; i < n; i++)
	{ 
		cout <<a[i]<<endl;
	}						//输出有序数组 
	return 0;
}
