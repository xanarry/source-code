#include <stdio.h>
#include <string.h>

bool isLeapYear(int);
int getWeekDay(int, int, int);

int main(int argc, char const *argv[])
{
	int year;
	int month;

	printf("输入日期(yyyy-mm):");
	scanf("%d-%d-%d", &year, &month);//输入年和月

	printf("     %d年%d月\n", year, month);//输出日历日历标题
	printf("日 一 二 三 四 五 六\n");//输出星期

	//本函数获取某个日期是星期几，这里获取每月的1号是星期几，返回是是[0-7]对应(星期天-星期六)
	int week = getWeekDay(year, month, 1);

	int i;
	for (i = 0; i < week; i++)//每月第一周前几天用空格填充
		printf("   ");

	int endDayOfMonth;//每个月的最后一天
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
	//从一号循环到本月末
	while (dayOfMonth <= endDayOfMonth)
	{
		printf("%2d ", dayOfMonth);
		dayOfMonth++;
		//每输出完星期六的日期后就换行(对应周数起点是从week开始的，所以要在天数上加上week)
		if ((dayOfMonth + week- 1) % 7 == 0)
			printf("\n");
	}
	printf("\n");
	return 0;
}

//判断闰年
bool isLeapYear(int y) 
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	return false;
}

//获取某天是星期几返回值(0-7)
int getWeekDay(int y, int m, int d)
{
	//计算星期几的固定公式,Y是年D是这个日期在本年的天数
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