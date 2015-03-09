#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string a;
	cin >> a;//以字符串方式接收数字
	int i, j;//i是左下标，j是又下标
	for (i = 0, j = a.size() - 1; i <= (a.size() - 1)/2;)
	{
		if (a[i] == a[j] && i < j)//将数字从两端向中间移动，做对比
		{
			++i;//左下标右移
			j--;//右下标左移
		}
		else
			break;
	}
	if (i == j || i-1 == j)//如果一直找到的中间两个数字都还相等，那么是回文数“||”用于处理奇数位数和偶数位数的数字
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
