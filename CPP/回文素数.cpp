#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int n)//定义判断是否为质数的函数 
{
	int i;
	if (n < 2)
		return 0;//小于2的数不是 
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n%i == 0)//如果能被2到根号下n之间的数整除，也不是质数 
			return 0;
	}
	return 1;//默认是质数 
}

int huiwen(int n)
{
	if(n%10 == n/100)//回文判定 
		return 1;
	else 
		return 0;
}

int main()
{
	int begin = 100, end, count = 0;
	cin >> end;
	for(int i = begin; i <= end; i++)//11到100之间只有一个同时满足条件的，最后加1 
	{
		if(isPrime(i) && huiwen(i))
			count++;//如果找到一个满足条件的数，则count自加1	
	}
	cout << count + 1 << endl;//加上11到100之间的一个数 
	return 0;
}
