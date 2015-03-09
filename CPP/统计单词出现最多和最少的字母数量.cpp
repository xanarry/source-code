#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int isPrime(int n)//判断是否为质数的函数 
{
	if (n < 2)
		return 0;
	for(int i = 2; i <= sqrt(n); i++) 
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	char in[100];
	int max = 0, min = 100, len, count[26];//字母有26个，所以定义大小为26的数组记录每个字符出现的次数 
	memset(count, 0, sizeof(count));//初始化数组中的每个元素的值为0 
	cin >> in;
	len = strlen(in);//获取字符串长度 
	
	for(int i = 0; i < len; i++)//遍历单词中的每个字母
	{
		count[in[i] - 'a']++;//in[i]是一个字母，用它减'a'，计算出记录各字母出现次数的数组下标
	}

	for(int i = 0; i < 26; i++)
	{
		if(count[i] != 0)//排除没有出现的字母
		{
			if(count[i] > max)//找出出现最多的次数
				max = count[i];
			if(count[i] < min)//找到出现最小的次数
				min = count[i];
		}
		
	}

	if(isPrime(max - min))
		cout << "Lucky Word" << endl << max - min << endl;
	else 
		cout << "No Answer" << endl << max - min << endl;
	return 0;
}
