#include <stdarg.h>
#include <stdio.h>

int max_of(int arg_count, ...)
{
	va_list list;
	int max;
	int i;
	va_start(list, arg_count);
	max = va_arg(list, int);
	for (i = 1; i < arg_count; i++)
	{
		int temp = va_arg(list, int);
		if (max < temp)
			max = temp;
	}
	va_end(list);
	return max;
}

int main(int argc, char const *argv[])
{
	int max = max_of(10, 1, 2, 3, 4, 5, 68, 7, 8, 9, 10);
	printf("max = %d\n", max);
	return 0;
}