#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int val, tmp, each_count = 1;
	cin >> tmp;//记录第一个做为对比的基本变量
	while (cin >> val)
	{
		if (val == tmp)
			each_count++;//如果反复输入同一个数，那么次数应该增加
		else
		{
			cout << "\t" << tmp << " has show " << each_count << " times before" << endl;//否则输入上一个数的结果
			tmp = val;//重置tmp为新的第一个不同的变量
			each_count = 1;//重置each_count
		}
	}
	return 0;
}
