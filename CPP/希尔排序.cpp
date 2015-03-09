#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <sys/time.h>
using namespace std;

void shell_sort(int *a, int len);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	const int len = 10;//数据量
	int *a = new int[len];
//	int a[10] = {11,7,6,4,9,10,2,8,3,5};
	
	cout << "original: [";	
	for (int i = 0; i < len; i++)
	{
		a[i] = rand() % 20;//生成数据
		cout << a[i] << " ";
	}
	cout << "\b]\n";

	shell_sort(a, len);//排序

	/*输出结果*/
	cout << "Ssorted : [";
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << "\b]\n";
	
	return 0;
}

void shell_sort(int *a, int len)
{
	int step = len;
	while ( (step /= 2) >= 1)//分几轮排序：5轮
	{
		int i = 0;
		while (i < step)//每一轮要排序的子序列数：每轮两个数，一共5组数据
		{
			for (int j = i + step; j < len; j += step) //排序当前子序列
			{
				int pos = j - step;
				int key = a[j];
				while (pos >= 0 && key < a[pos])//插入数值
				{
					a[pos + step] = a[pos];
					pos -= step;
				}
				a[pos + step] = key;
			}
			i++;
		}
	}
}