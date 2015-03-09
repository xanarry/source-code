#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void match1(const char *, const char *);
void match2(const char *, const char *);
void match3(const char *, const char *);

int main(int argc, char const *argv[])
{
	const char *src = "bbc abcdeabced xyza";
	const char *ptrn = "abc";

	match1(src, ptrn);
	match2(src, ptrn);
	match3(src, ptrn);
	return 0;
}

void match1(const char *src, const char *ptrn)
{
	int i, j;
	int matchedTime = 0;

	for (i = 0; i < strlen(src) - strlen(ptrn) + 1; i++)//traverse the whole string src
	{
		j = 0;//start compare from 0, the index of ptrn
		while (src[i + j] == ptrn[j] && j < strlen(ptrn))//if find a equaliment and not traverse to the end of ptrn, then j++
			j++;

		if (j == strlen(ptrn))//if find a segment as long as ptrn, matchedTimes should increse 1; 
			matchedTime++;
	}
	printf("match1ed %d times\n", matchedTime);
}

void match2(const char *src, const char *ptrn)//ditto
{
	int i, j = 0; 
	int matchedTime = 0;

	for (i = 0; i < strlen(src) - strlen(ptrn) + 1; i++)
	{
		int matchCount = 0;
		for (j = 0; j < strlen(ptrn); j++)
		{
			if (src[i + j] == ptrn[j])
				matchCount++;

			if (matchCount == strlen(ptrn))
				matchedTime++;
		}	
	}
	printf("match1ed %d times\n", matchedTime);
}

void match3(const char *src, const char *ptrn)//ditto
{
	int i, j = 0; 
	int matchedTime = 0;

	for (i = 0; i < strlen(src) - strlen(ptrn) + 1; i++)
	{
		for (j = 0; j < strlen(ptrn); j++)
		{
			if (src[i + j] != ptrn[j])
				break;
		}

		if (j == strlen(ptrn))
			matchedTime++;	
	}
	printf("match2ed %d times\n", matchedTime);
}