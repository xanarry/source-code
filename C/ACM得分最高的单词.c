#include <stdio.h>
#include <string.h>
#include <ctype.h>

//判断一个单词的多少分，并且输出最高分

int LowerIsInclude(char a)//判断是否是元音字母
{
	char charactor[5] = {'a', 'e', 'i', 'o', 'u'};
	for (int i = 0; i < 5; ++i)
	{
		if (a == charactor[i])
		{
			return 1;
		}
	}
	return 0;
}

int UpperIsInclude(char a)//判断是否是大写元音字母
{
	char charactor[5] = {'A', 'E', 'I', 'O', 'U'};
	for (int i = 0; i < 5; ++i)
	{
		if (a == charactor[i])
		{
			return 1;
		}
	}
	return 0;
}

int count_score(char * a)
{
	int len = strlen(a);
	int score = 0;
	for (int i = 0; i < len; ++i)
	{
		if (LowerIsInclude(a[i]))
		{
			score += 5;//如果是小写元音字母加5分
		}
		else if (UpperIsInclude(a[i]))
		{
			score += 10;//如果是大写元音字母加10分
		}
		else if (!LowerIsInclude(a[i]) && islower(a[i]))
		{
			score += 1;//如果是加其他小写字母加1分
		}
		else if (!LowerIsInclude(a[i]) && isupper(a[i]))
			score += 2;//如果是其他大写字母加2分
	}
	return score;
}

char word[10000000];
int main(int argc, char const *argv[])
{
	int n, t, max = 0;
	int sum, maxa[100], tmp = 0;
	scanf("%d", &n);
	while (n)
	{
		t = n;
		max = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", word);
			sum = count_score(word);
			if (sum > max)
				max = sum;
		}
		maxa[tmp++] = max;//记录出现的最高分数
		scanf("%d", &n);
	}

	for (int i = 0; i < tmp; i++)
	{
		printf("%d\n", maxa[i]);//输入最高分数
	}
	return 0;
}
