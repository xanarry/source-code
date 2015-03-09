#include <stdarg.h>
#include <stdio.h>

double average(int n_values, ...)//n_values表示...中所包含的参数个数，...是n_values个参数
{
	va_list var_arg;//定义va_list变量用于访问...说包含的参数
	int count;
	double sum = 0;
	va_start(var_arg, n_values);//使用va_start初始化var_arg，第一个参数是va_list变量的名字，第二个是...之前最后一个有名字的参数
	for (count = 0; count < n_values; count++)
	{
		sum += va_arg(var_arg, int);//va_arg变量参数，第二个参数是参数中的类型
	}
	va_end(var_arg);//表示已经访问完参数列表
	return sum/n_values;
}

int main(int argc, char const *argv[])
{
	double t = average(3,3,3,3);
	printf("%f", t);
	return 0;
}