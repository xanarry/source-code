#include <iostream>
using namespace std;

int maze[5][5] = 
{
	{1,0,0,0,1},
	{1,1,0,0,1},
	{0,1,1,1,1},
	{0,0,1,0,1},
	{0,0,0,1,1}
}; 

void walk(int x, int y);

int x_end = 4, y_end = 4;

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) 
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}

	cout << "start" << endl;
	int x_start = 0, y_start = 0;
	walk(x_start, y_start);
	return 0;
}

void walk(int x, int y)
{	
	

	if (maze[x][y] == 1) 
	{
		cout << "[" << x << " " << y  << "]" << endl;
		maze[x][y] = 9;
	}
 	else 
 		return;

	if (x - 1 >= 0)
		walk(x - 1, y);
	if (x + 1 < 5)
		walk(x + 1, y);
	if (y - 1 >= 0)
		walk(x, y - 1);
	if (y + 1 < 5)
		walk(x, y + 1);

	if (x == 3 && y == 4)
	{
		cout << "successful" << endl;
		exit(0);
	}
}