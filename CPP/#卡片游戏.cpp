/*ԭ��Ŀ��https://www.smartoj.com/p/1133
����Descript.
������һ���ƣ��ӵ�һ���ƣ���λ�ڶ�����ƣ���ʼ�����������α��1~n��
�����ٻ�ʣ������ʱ�������²�����
1���ѵ�һ�����ӵ�
2��Ȼ����µĵ�һ���Ʒŵ������Ƶ����
����n�����ÿ���ӵ����ơ�
����Input
�������һ������n��ʾ��n����(1<=n<=50000)
���Output
���ÿ���ӵ����� 
��������
7

�������
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
