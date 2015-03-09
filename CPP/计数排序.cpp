#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

void countting_sort(int *a, int len, int max);
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	const int len = 20;
	int a[len];
	int max = -1;
	for (int i = 0; i < len; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
		if (a[i] > max)
			max = a[i];//得到最大值
	}
	cout << "\b\n";

	countting_sort(a, len, max);

	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

void countting_sort(int *a, int len, int max)
{
	//定义并初始化保存每个数所在位置的数组
	int c[max + 1];
	for (int i = 0; i <= max; i++)
		c[i] = 0;

	//计算每个数出现次数
	for (int i = 0; i < len; i++)
		c[a[i]]++;

	//c[i]包含小于或者等于i的也元素的个数，即每个数的秩序
	for (int i = 1; i <= max; i++)
		c[i] += c[i - 1];

	int sorted[len];
	//填充数字到有序的数组
	for (int i = 0; i < len; i++)
	{
		//////此处减1是因为下标从0开始的，不然应该从1->n输出
		sorted[c[a[i]] - 1] = a[i];
		c[a[i]] -= 1;
	}

	//赋值给原来的数组，因为临时数组在函数调用结束后会释放内存
	for (int i = 0; i < len; i++)
		a[i] = sorted[i];
}