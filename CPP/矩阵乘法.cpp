#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x1, y1;
	int x2, y2;
	cout << "input m1's x & y: ";
	cin >> x1 >> y1;
	cout << "input m2's x & y: ";
	cin >> x2 >> y2;

	int m1[x1][y1];
	int m2[x2][y2];

	//输入矩阵1
	for (int i = 0; i < x1; i++)
	{
		for (int j = 0; j < y1; j++)
		{
			cout << "input m1[" << i + 1 << "," << j + 1 << "]=";
			cin >> m1[i][j];
		}
	}
	//输入矩阵2
	for (int i = 0; i < x2; i++)
	{
		for (int j = 0; j < y2; j++)
		{
			cout << "input m2[" << i + 1 << "," << j + 1 << "]=";
			cin >> m2[i][j];
		}
	}

	//如果不满足要求则直接退出
	if (y1 != x2)
	{
		cout << "ilegal matrix multiplay" << endl;
		return 0;
	}

	//输出矩阵1
	for (int i = 0; i < x1; i++)
	{
		for (int j = 0; j < y1; j++)
			cout << m1[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	//输出矩阵2
	for (int i = 0; i < x2; i++)
	{
		for (int j = 0; j < y2; j++)
			cout << m2[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	//执行矩阵运算，新矩阵的大小是矩阵1的x*矩阵2的y
	int result[x1][y2];
	for (int i = 0; i < x1; i++)//矩阵1的行
	{
		for (int j = 0; j < y2; j++)//矩阵2的列
		{
			int tmp = 0;//循环执行计算
			for (int k = 0; k < y1; k++) 
				tmp += m1[i][k] * m2[k][j];
			result[i][j] = tmp;
		}
	}

	//输出结果矩阵
	for (int i = 0; i < x1; i++)
	{
		for (int j = 0; j < y2; j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}

/*
1
2 
3
2
1
2
1
2
3
1
2
1
*/