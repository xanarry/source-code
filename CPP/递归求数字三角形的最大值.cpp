#include <iostream>

using namespace std;

int len = 0;
int a[26][26] = {0};
int getMax = -1;

void addMax(int x, int y, int sum);

int main(int argc, char const *argv[])
{
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}
	addMax(0, 0, 0);
	cout << getMax;
    return 0;
}

void addMax(int x, int y, int sum)
{
	if (x < len && y < len)
	{
		addMax(x + 1, y, sum + a[x][y]);
		addMax(x + 1, y + 1, sum + a[x][y]);
	}
	else if (sum > getMax)
	{
		getMax = sum;
	}
}