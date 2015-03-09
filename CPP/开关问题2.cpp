/*
有n盏灯。编号为1～n。默认为关闭状态。第1个人按
下所有灯的开关；第2个人按下所有编号为2的倍数的
开关；第3个人按下所有编号为3的倍数的开关…总共
有k个人。他们都按完开关后，还有哪些灯是开着的？
*/
#include <iostream>
using namespace std;

int a[1000000] = {0};//0表示所有灯都关着
int main(int argc, char const *argv[])
{
	
	int n, pn;
	cin >> n >> pn;
	for (int j = 1; j <= n; ++j)//遍历每一个灯
	{
		for (int i = 1; i <= pn; ++i)//对一个灯的具体操作数
		{
			if (j%i == 0)
				a[j] = 1 - a[j];
		}
	}
	int k;
	for (k = 1; k <= n; ++k)
	{
		if (a[k] == 1)//输入开着的灯
			cout << k << " ";
	}
	return 0;
}
