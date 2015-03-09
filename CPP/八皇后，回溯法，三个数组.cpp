#include <iostream>
using namespace std;

int a[9];
int b[16];
int c[25];
int sit[8];

//1��ʾ�лʺ�
//0��ʾ�޻ʺ�
//a[j - 1]��ʾ��j����
//b[i + j - 2]��ʾ(i, j)�������� �Խ���
//c[j - j + 7]��ʾ(i, j)�������� �Խ���
void EightQueen(int t)
{
	int i = 1;
	int j = t;
	while (i <= 8)//��
	{
		while (j <= 8)//��
		{
			if (a[j - 1] + b[i + j - 2] + c[i - j + 7] == 3)//�޻ʺ�
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