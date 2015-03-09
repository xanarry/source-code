#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void KMPMatch(const char *src, const char *ptr);
void getNext(const char *ptr, int next[]);

int main(int argc, char const *argv[])
{
	const char *src = "bbc abcdefabcedfbc";
	const char *ptr = "bc";

	KMPMatch(src, ptr);

	return 0;
}

void KMPMatch(const char *src, const char *ptr)
{
	int next[100];
	getNext(ptr, next); 
	
	int i = 0, j = 0;
	while (i < strlen(src) && j < strlen(ptr))
	{
		if (j == -1 || src[i] == ptr[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];

		if (j == strlen(ptr))
			printf("matched\n");
	}
}

void getNext(const char* p, int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
        //p[k]表示前缀，p[j]表示后缀  
        if (k == -1 || p[j] == p[k])   
        {  
            ++k;  
            ++j;  
            next[j] = k;  
        }  
        else   
        {  
            k = next[k];  
        }  
    }  
}  