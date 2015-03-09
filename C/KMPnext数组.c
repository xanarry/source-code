#include <stdio.h>
#include <string.h>

void getNext(const char *src, int next[]);
void getNext1(const char *src, int next[]);

int main(int argc, char const *argv[])
{
	const char *src = "abcfabce";
				//    -10000123
	int next[100];

	getNext1(src, next);

	for (int i = 0; i < strlen(src); i++)
	{
		printf("%d ", next[i]);
	}
	printf("\n");

	return 0;
}

void getNext(const char *src, int next[])
{
	/*
		数组next记录的是每个当前字符能与前面的字符的最大匹配数-1;
		应为数组记录的是字符串每个字符自己的匹配数，k表示最大的匹
		配数（作为数组元素值），因为最大匹配数同时又是作为下一次
		最大匹配数的起加基础，因为字符串前后有连续相同的字符
	*/

	int i = 0, k = -1;//赋值为-1的原因是数组值比实际值要小1,使不必后面每步都在减一再赋值
	next[0] = -1;

	while (i < strlen(src))
	{
		//循环过程中k的值始终比i小
		//k == -1时，是处理初始状态的数据
		if (k == -1 || src[k] == src[i])//可以处理联系出现能够在前面匹配的情况
		{
			k++;
			i++;
			next[i] = k;
		}
		else
		{
			//注意此时i是在k的前面一个位置
			k = next[k];//重新设定k的起加位置是上一个字符的数组值，用于累加
		}
	}
}

void getNext1(const char *src, int next[])
{
    int i,k;//i:模版字符串下标；k:最大前后缀长度  abcfabce
    next[0] = 0;//模版字符串的第一个字符的最大前后缀长度为0

    for (i = 1,k = 0; i < strlen(src); ++i)//for循环，从第二个字符开始，依次计算每一个字符对应的next值
    {
        while(k > 0 && src[i] != src[k])//递归的求出src[0]···src[i]的最大的相同的前后缀长度k
        {
        	k = next[k-1];          //不理解没关系看下面的分析，这个while循环是整段代码的精髓所在，确实不好理解  
        }

        if (src[i] == src[k])//如果相等，那么最大相同前后缀长度加1
            k++;

        next[i] = k;
    }
} 