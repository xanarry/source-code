#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_convert(char *num, int, int);

int main(int argc, char const *argv[])
{
	puts("input a string:");
	char num[20];
	scanf("%s", num);

	puts("input the start:");
	int start;
	scanf("%d", &start);

	puts("input the length:");
	int length;
	scanf("%d", &length);

	int tmp = get_convert(num, start, length);
	printf("result is : %d\n", tmp);

	return 0;
}

int get_convert(char *num, int start, int length)
{
	char *part_of_num = (char *)malloc(length * sizeof(char) + 5);//保证数组长度大于length
	int index = 0;
	while(index < length)//截取长度
	{  							//从start处截取length长度
		part_of_num[index] = num[start + index];
		index++;
	}
	part_of_num[index] = '\0';
	return atoi(part_of_num);
}
//012345678901234567

