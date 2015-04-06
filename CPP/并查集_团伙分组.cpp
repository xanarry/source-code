#include <iostream>

using namespace std;

int set[5000];
int a[5000];

void unionSet(int x, int y);
int findSet(int x);
int ans;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	ans = n;
	
 	for (int i = 1; i <= n; i++) //n people
	{
		a[i] = 0;
		set[i] = i;
	}

	//输入m组关系，构造一个关系对应的数组
	char r;
	int x, y;
	for (int i = 1; i <= m; i++) //m relation
	{

		cin >> r >> x >> y;//a和b之间有关系
		if (r == 'F')
		{
			unionSet(x, y);
		}
		if (r == 'E')
		{
			if (a[x] == 0)
				a[x] = y;
			else
				unionSet(a[x], y);

			if (a[y] == 0) 
				a[y] = x;
			else 
				unionSet(a[y], x);
		}	
	}
	cout << ans << endl;
	return 0;
}

void unionSet(int x, int y)
{
	int p = findSet(x);
	int q = findSet(y);
	if (p != q)
	{
		set[q] = p;
		ans--;
	}
}

int findSet(int x)
{
	if (set[x] == x) 
		return x;
	else 
	{
		set[x] = findSet(set[x]);
		return set[x];
	}
}