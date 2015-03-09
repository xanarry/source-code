#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a_len = 7, b_len = 10;
	int a[] = {1,2,3,4,5,6,7};
	int b[] = {1,2,2,4,5,6,7,8,9,0};

	for (int d = 0; d <= 9; d++)//遍历当前的整个数的集合
	{
		int c1 = 0, c2 = 0;
		for (int i = 0; i < a_len; i++)//遍历集合1，如果发现有当前的目标数，标记c1
		{	if (a[i] == d)
			{
				c1++;
				break;
			}
		}
		for (int i = 0; i < b_len; i++)//遍历集合2，如果发现有当前的目标数，标记c2
		{
			if (b[i] == d)
			{
				c2++;
				break;
			}
		}
		if (c1 > 0 && c2 > 0)//如果两个集合对同一个数都有标记，说明是交集，输出这个数
			cout << d << ",";
	}
	return 0;
}