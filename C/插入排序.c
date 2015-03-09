#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[10] = {1,3,2,5,7,4,6,0,9,8};
	int i;
	for (i = 0; i < 10; i++) 
		printf("%d ", a[i]);
	printf("\n");

	for (i = 1; i < 10; i++)//抽取后面的牌，保留第一张牌不动，以做基准
	{
		int key = a[i];//从后面抽取一张牌
		int j = i - 1;//前面有序牌的最大张数
		while (key > a[j] && j >= 0)//在有序牌中找到正确的位置
		{
			a[j + 1] = a[j];//移动每张牌，以流出空位
			j--;
		}
		a[j + 1] = key;//插入牌
	}

	for (i = 0; i < 10; i++) 
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}