/*
Description
真假奶牛
约翰有 N 头奶牛，有一部分奶牛是真话奶牛，它们只说真话，而剩下的是假话奶牛，只说假话。
有一天，约翰从奶牛的闲谈中陆续得到了 M 句话，第 i 句话出自第 Xi 头奶牛，它会告诉约翰第 Yi头是一头真话奶牛还是假话奶牛。然而，约翰记性不好，他可能把这些话的内容记错了。请检查一下约翰的记录是否会有矛盾，帮助他找到一个尽量大的 K，使得约翰记下的前 K 句话不矛盾。
Input
• 第一行：两个整数 N 和 M ，1 ≤ N ≤ 1000, 1 ≤ M ≤ 10000
• 第二行到 M + 1 行：第 i + 1 行有两个整数：Xi 和 Yi，1 ≤ Xi, Yi ≤ N ，接下来有一个字符：
– 如果是 T ，表示 Xi 说 Yi 是真话奶牛；
– 如果是 L，表示 Xi 说 Yi 是假话奶牛；
Output
• 单个整数，即表示题目描述中的 K
Sample Input
4 3
1 4 L
2 3 T
4 1 T
Sample Output
2
*/
#include <iostream>
using namespace std;

int F[1000000];
int findset(int a)
{
	if(a == F[a])
		return a;
	F[a] = findset(F[a]);
	return F[a];
}

int main()
{
	int n, m, i;
	cin >> n >> m;
	for (i = 1; i < n * 2; i++)
	{
		F[i] = i;
	}

	for (i = 0; i < m; i++)
	{
		int x, y;
		char ch;

		cin >> x >> y >> ch;
		ch |= 32;
		int a = findset(x);
		int b = findset(y);
		int nota = findset(x + n);
		int notb = findset(y + n);
		if (ch == 'l')
		{
			if (a == b || nota == notb) 
			{
				break;
			}
			else 
			{
				F[a] = F[notb];
				F[b] = F[nota];
			}
		}
		else if (ch == 't')
		{
			if (a == notb || nota == b) 
			{
				break;
			}
			else 
			{
				F[a] = F[b];
				F[nota] = F[notb];
			}
		}
	}
	cout << i << endl;
}