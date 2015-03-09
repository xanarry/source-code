/*原题目：https://www.smartoj.com/p/1133
描述Descript.
桌上有一叠牌，从第一张牌（即位于顶面的牌）开始从上往下依次编号1~n。
当至少还剩两张牌时进行以下操作：
1、把第一张牌扔掉
2、然后把新的第一张牌放到整叠牌的最后。
输入n，输出每次扔掉的牌。
输入Input
输入包括一个整数n表示有n张牌(1<=n<=50000)
输出Output
输出每次扔掉的牌 
输入数据
7

输出数据
1 3 5 7 4 2 6
*/
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
int main()
{
	int n;
	queue<int> q;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	for(int i = 1; i <= n; i++)
	{
		cout << q.front() << " ";
		q.pop();
		q.push(q.front());
		q.pop();
	}
	return 0;
}
