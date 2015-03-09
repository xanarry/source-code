#include <iostream>
#include <cstdio>

using namespace std;

char maze[101][101];
int width, n, beginx, beginy, endx, endy;
void dfs (int x, int y)
{
	if (maze[x][y] == '.')
		maze[x][y] = '#';
	else 
		return;
	if (x-1 > 0) 
		dfs(x-1, y);
	if (x+1 < width) 
		dfs(x+1, y);
	if (y-1 > 0) 
		dfs(x, y-1);
	if (y+1 < width) 
		dfs(x, y+1);
}

int main(void)
{
	cin >> n;
	while (n -- )
	{
		cin >> width;
		for (int i = 0; i < width; i++)
		{
			scanf ("%s",maze[i]);
	    }
			cin >> beginx >> beginy >> endx >> endy;
			if (maze[beginx][beginy] == '#' || maze[endx][endy] == '#')
				puts("NO");
			else 
			{
				dfs (beginx, beginy);
				if (maze[endx][endy] == '#')
					puts("YES");
				else
					puts("NO");
			}
		
	}
}
