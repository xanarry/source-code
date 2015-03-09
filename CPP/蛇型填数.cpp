#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int mx[100][100] = {0};
	int n;
	cin >> n;

	int step = 1;
	int x = 0;
	int y = n - 1;
	mx[x][y] = 1;

	while (step < n * n)
	{
		while (x + 1 < n && mx[x + 1][y] == 0)
			mx[++x][y] = ++step;
	
		while (y - 1 >= 0 && mx[x][y - 1] == 0)
			mx[x][--y] = ++step;

		while (x - 1 >= 0 && mx[x - 1][y] == 0)
			mx[--x][y] = ++step;

		while (y + 1 < n && mx[x][y + 1] == 0)
			mx[x][++y] = ++step;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%3d ", mx[i][j]);
		cout << endl;
	}
	return 0;
}