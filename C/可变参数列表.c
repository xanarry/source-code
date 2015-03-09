#include <stdarg.h>
#include <stdio.h>

double average(int n_values, ...)//n_values��ʾ...���������Ĳ���������...��n_values������
{
	va_list var_arg;//����va_list�������ڷ���...˵�����Ĳ���
	int count;
	double sum = 0;
	va_start(var_arg, n_values);//ʹ��va_start��ʼ��var_arg����һ��������va_list���������֣��ڶ�����...֮ǰ���һ�������ֵĲ���
	for (count = 0; count < n_values; count++)
	{
		sum += va_arg(var_arg, int);//va_arg�����������ڶ��������ǲ����е�����
	}
	va_end(var_arg);//��ʾ�Ѿ�����������б�
	return sum/n_values;
}

int main(int argc, char const *argv[])
{
	double t = average(3,3,3,3);
	printf("%f", t);
	return 0;
}