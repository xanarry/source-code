#include <iostream>
using namespace std;

int a[9];
int b[16];
int c[25];
int sit[8];

//1表示有皇后
//0表示无皇后
//a[j - 1]表示第j列上
//b[i + j - 2]表示(i, j)右上左下 对角线
//c[j - j + 7]表示(i, j)左上右下 对角线
void EightQueen(int t)
{
	int i = 1;
	int j = t;
	while (i <= 8)//行
	{
		while (j <= 8)//列
		{
			if (a[j - 1] + b[i + j - 2] + c[i - j + 7] == 3)//无皇后
				break;
			j++;
		}
		if (j <= 8)
		{
			a[j - 1] = 0;
			b[i + j - 2] = 0;
			c[i - j + 7] = 0;
			sit[i - 1] = j;
			i++;
			j = 1;
		}
		else
		{
			i--;
			j = sit[i - 1];
			a[j - 1] = 1;
			b[i + j - 2] = 1;
			c[i - j + 7] = 1;
			j++;
		}
	}
	for (i = 1; i <= 8; i++)
	{
		cout << "(" << i << "," << sit[i - 1] << ")" << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i <= 8; i++) a[i] = 1;
	for (int i = 0; i <= 16; i++) b[i] = 1;
	for (int i = 0; i <= 25; i++) c[i] = 1;
	EightQueen(1);
	return 0;
}