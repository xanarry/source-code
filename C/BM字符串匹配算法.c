#include <stdio.h>
#include <string.h>

void BM(const char *src, const char *ptr);

int main(int argc, char const *argv[])
{
	const char *src = "here is a simple example";
	const char *ptr = "example";
	BM(src, ptr);
	return 0;
}

void BM(const char *src, const char *ptr)
{
	int i = 0;
	int j = 0;
	int sStart = 0;
	int lastR = 0;
	int moveLength = 0;

	int sLen = strlen(src);
	int pLen = strlen(ptr);
	while (sStart < sLen)
	{
		for (i = pLen - 1; i >= 0;)
		{
			if (ptr[i] != src[sStart + pLen - 1])
				i--;
		}
		if (i == 0)
		{

		}
	}
	
}