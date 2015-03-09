#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const string as, const string bs)//自定义比较函数
{
	if (as.length() > bs.length())//长的数肯定比较大
		return true;
	else if (as.length() < bs.length())
		return false;
	else//如果两个数的长度相同
	{
		for (int i = 0; i < as.length(); )//从左到右依次比较每一位的的数字的值的大小
		{
			if (as[i] > bs[i])
				return true;
			else if (as[i] < bs[i])
				return false;
			else 
				i++;
		}
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string nums[n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	sort(nums, nums + n, cmp);//传递比较函数给sort函数

	for (int i = 0; i < n; i++)
		cout << nums[i] << endl;
	
	return 0;
}