#include <stdio.h>
#include <string.h>

bool isLeapYear(int);
int getWeekDay(int, int, int);

int main(int argc, char const *argv[])
{
	int year;
	int month;

	printf("��������(yyyy-mm):");
	scanf("%d-%d-%d", &year, &month);//���������

	printf("     %d��%d��\n", year, month);//���������������
	printf("�� һ �� �� �� �� ��\n");//�������

	//��������ȡĳ�����������ڼ��������ȡÿ�µ�1�������ڼ�����������[0-7]��Ӧ(������-������)
	int week = getWeekDay(year, month, 1);

	int i;
	for (i = 0; i < week; i++)//ÿ�µ�һ��ǰ�����ÿո����
		printf("   ");

	int endDayOfMonth;//ÿ���µ����һ��
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		endDayOfMonth = 31;
	else if (month == 2)
	{
		if (isLeapYear(year))
			endDayOfMonth = 29;
		else 
			endDayOfMonth = 28;
	}
	else 
		endDayOfMonth = 30;

	int dayOfMonth = 1;
	//��һ��ѭ��������ĩ
	while (dayOfMonth <= endDayOfMonth)
	{
		printf("%2d ", dayOfMonth);
		dayOfMonth++;
		//ÿ����������������ں�ͻ���(��Ӧ��������Ǵ�week��ʼ�ģ�����Ҫ�������ϼ���week)
		if ((dayOfMonth + week- 1) % 7 == 0)
			printf("\n");
	}
	printf("\n");
	return 0;
}

//�ж�����
bool isLeapYear(int y) 
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	return false;
}

//��ȡĳ�������ڼ�����ֵ(0-7)
int getWeekDay(int y, int m, int d)
{
	//�������ڼ��Ĺ̶���ʽ,Y����D����������ڱ��������
	//W = [Y-1] + [(Y-1)/4] - [(Y-1)/100] + [(Y-1)/400] + D 
	int days = d;
	int i;
	for (i = 1; i < m; i++) 
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			days += 31;
		else if (i == 2)
		{
			if (isLeapYear(y)) 
				days += 29;
			else 
				days += 28;
		}
		else 
			days += 30; 
	}

	int temp = y - 1 + (int)((y - 1) / 4) - (int)((y - 1) / 100) + (int)((y - 1) / 400) + days;
	return temp % 7;
} 