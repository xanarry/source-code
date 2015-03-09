/*
 *名称: 课程表
 *版本: v1.0
 *作者: 熊洋
 *功能: 整合文件保存的课表内容以表格的形式呈现，显示本周课表，今日课表，并提供课程查询
 *完成时间: 2014/9/25
 */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

struct Subject
{
    char name[40];
    char location[20];
    int weekRang[25];
    int classTime[25];
};

struct Subject subjects[30];//the global array records each class's information
int length;//the length of the gobal array
int currentYearWeek;//the current week of this year
int currentWeekday;//record what today is the day of the week
int currentSemesterWeek;//the current week of this semester
const char *timeList[5] = {"8:00--9:45", "10:15--12:00", "14:10--15:55", "16:15--18:00", "19:00--20:45"};//each class's time period


int getDay(int date);//This is the first few days of this year's
int isLeapYear(int year);//to determine wether a leap year
int getCurrentYearWeek(const char temp[200]);
FILE *loadDataFile();
int extractDate(FILE *fp, int *length);//extruct data from file to a array
int getClassName(int weekday, int time);//get the class name by classing time
int ifRightWeek(int classNo);//determine if this class in this week
void showWeekClass();
void showClassWeek();
void todaySyllabus();//get all the classes of current day
int syllabusSearch();//for search

int main()
{
    system("cls");
    FILE *fp = loadDataFile();
    int date = extractDate(fp, &length);

    time_t t = time(0);
    char tmp[200];
    strftime(tmp, sizeof(tmp), "\t今天是%Y-%m-%d,本年度第%W周星期%w第%j天",localtime(&t) );

    char tempDate[9];
    int i, j;
    for (i = 7, j = 0; i < 17; i++)
    {
        if (tmp[i] != '-')
        {
            tempDate[j] = tmp[i];
            j++;
        }
    }
    tempDate[j] = '\0';
    int yearDate = atoi(tempDate);

    currentYearWeek = getCurrentYearWeek(tmp);

    currentSemesterWeek = currentYearWeek - (int)getDay(date)/7;

    printf("%s - 本学期第%d天,第%d周\n", tmp, getDay(yearDate) - getDay(date), currentSemesterWeek);

//    showClassWeek();//行为节数，列为星期
    showWeekClass();//行为星期，列为节数
    todaySyllabus();//显示当天（今天）的课表

    printf("\t\t如果您要查询某个时间是否有课请按“1”:");
    int input;
    scanf("%d", &input);
    if (input == 1)
        syllabusSearch();

    system("pause > nul");
    return 0;
}

void showWeekClass()
{
    printf("\n\t\t\t---------本周课表---------\n");
    printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
    printf("|      |  星期一  |  星期二  |  星期三  |  星期四  |  星期五  |  星期六  |  星期天  |\n");

    int classNo;

    for (classNo = 1; classNo <= 5; classNo++)//第几节课
    {
        printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
        printf("|第%d节 |", classNo);
        int weekday;
        for (weekday = 1; weekday <= 7; weekday++)//星期几
        {
            int temp = getClassName(weekday, classNo);

            if (temp >= 0)
            {
                if (strlen(subjects[temp].name) > 8)//为了保持显示表格的美观，大于四个字的名字只显示前四个字
                {
                    //////////////////////////////////////////////
                    int charCount = 0, t = 0;
                    while (subjects[temp].name[t] != '\0')
                    {
                        if (isalnum(subjects[temp].name[t]))
                            charCount++;//计算非汉字的字符个数
                        t++;
                    }
                    /*此代码段用于判断课程名字所包含的数字或字母是奇数还是偶数个，是偶数个则正常截取8个长度的
                      的字符串，是奇数个则截取9个字符串，确保不会截取到单个汉字所占的字符位置从而使汉字乱码，
                      因为一个汉字占两个字符位置*/
                    int stop = 8;
                    if (charCount%2 != 0)
                        stop += 1;
                    //////////////////////////////////////////////////
                    char shortName[stop + 1];
                    int i;
                    for (i = 0; i < stop; i++)
                        shortName[i] = subjects[temp].name[i];
                    shortName[i] = '\0';

                    printf(" %-9s|", shortName);
                }
                else
                    printf(" %-9s|", subjects[temp].name);
            }
            else
            {
                printf(" %-9s|", " ");
            }
        }
        printf("\n");
    }
    printf("+------+----------+----------+----------+----------+----------+----------+----------+\n\n");
}

void showClassWeek()
{
    printf("\n\t\t\t---------本周课表---------\n");
    printf("--------+------------+------------+------------+------------+-------------\n");
    printf("|       |   第一节   |   第二节   |   第三节   |   第四节   |   第五节   |\n");

    int weekday;

    for (weekday = 1; weekday <= 7; weekday++)//星期几
    {
        printf("+-------+------------+------------+------------+------------+------------+\n");
        printf("|星期%d  |", weekday);
        int classNo;
        for (classNo = 1; classNo <= 5; classNo++)//第几节课
        {
            int temp = getClassName(weekday, classNo);

            if (temp >= 0)
            {
                if (strlen(subjects[temp].name) > 8)//为了保持显示表格的美观，大于四个字的名字只显示前四个字
                {
                    //////////////////////////////////////////////
                    int charCount = 0, t = 0;
                    while (subjects[temp].name[t] != '\0')
                    {
                        if (isalnum(subjects[temp].name[t]))
                            charCount++;//计算非汉字的字符个数
                        t++;
                    }
                    /*此代码段用于判断课程名字所包含的数字或字母是奇数还是偶数个，是偶数个则正常截取8个长度的
                      的字符串，是奇数个则截取9个字符串，确保不会截取到单个汉字所占的字符位置从而使汉字乱码，
                      因为一个汉字占两个字符位置*/
                    int stop = 8;
                    if (charCount%2 != 0)
                        stop += 1;
                    //////////////////////////////////////////////////
                    char shortName[stop + 1];
                    int i;
                    for (i = 0; i < stop; i++)
                        shortName[i] = subjects[temp].name[i];
                    shortName[i] = '\0';

                    printf(" %-9s|", shortName);
                }
                else
                    printf(" %-9s|", subjects[temp].name);
            }
            else
            {
                printf(" %-9s|", " ");
            }
        }
        printf("\n");
    }
    printf("--------+------------+------------+------------+------------+-------------\n\n");
}

void todaySyllabus()
{
    //week = currentSemesterWeek
    //weekday = currentWeekday
    printf("\t\t\t  ---今日课表---\n");
    printf("\t\t----------------------------------------\n");

    int ifOutput = 0;

    int i;
    for (i = 1; i <= 5; i++)//Which class
    {
        int classNo = getClassName(currentWeekday, i);
        if (classNo >= 0)
        {
            printf("\t\t\t%10s:  第%d节\n", "上课节次", i);
            printf("\t\t\t%10s:  %s\n", "课程名字", subjects[classNo].name);
            printf("\t\t\t%10s:  %s\n", "上课地点", subjects[classNo].location);
            printf("\t\t\t%10s:  %s\n", "上课时间段", timeList[i - 1]);
            printf("\t\t----------------------------------------\n");
            ifOutput = 1;
        }
    }

    if (!ifOutput)
    {
        printf("\t\t\t今日无课程安排! ^_^\n");
        printf("\t\t----------------------------------------\n");
    }
}

int syllabusSearch()
{
    system("cls");
    printf("\t\t\t\t查询ING\n\t假如您要查询 第11周星期3第2节 是否有课,则输入“11-3-2”,按回车键查询搜索结果!\n\t\t请输入您要查询的课程时间: ");
    char inputStr[10];
    scanf("%s", inputStr);
    while (strlen(inputStr) > 6 || strlen(inputStr) < 5)
    {
        printf("\t您输入的格式不对,请重新输入: ");
        scanf("%s", inputStr);
    }

    int inputInt[4];
    int i = 1;

    //将输入的字符串串转换为计算需要的数字
    char *temp = strtok(inputStr, "-");
    inputInt[0] = atoi(temp);
    while (temp)
    {
        temp = strtok(NULL, "-");
        inputInt[i++] = atoi(temp);
    }

    int classNo;
    int getClassNo = -100;

    //判读在指定星期和节次是否有课
    for (classNo = 0; classNo < length; classNo++)
    {
     //   printf("classNo = %d\n", classNo);
        int j = 0;
        while (subjects[classNo].classTime[j] != -1)
        {
         //   printf("name = %s\n", subjects[classNo].name);
            if (subjects[classNo].classTime[j] == inputInt[1] * 10 + inputInt[2])
            {
                getClassNo = classNo;
                break;
            }
            j++;
        }
    }

    if (getClassNo == -100)//如果没有则直接跳转到main函数，不再执行后续查找过程
    {
        system("cls");
        printf("\t\t在第%d周星期%d,第%d节没有课!\n", inputInt[0], inputInt[1], inputInt[2]);
        printf("\t\t\t任意键返回！");
        getchar();
        getchar();
        main();
    }


    int k = 0;
    while (subjects[getClassNo].weekRang[k] != -1)//查找到该时间有课，再查找该课是否在指定周上
    {
        if (subjects[getClassNo].weekRang[k] == inputInt[0])//如果上,则输出查找到有课的信息
        {
            system("cls");
            printf("\t\t   在第%d周星期%d,第%d节您有如下课程:\n", inputInt[0], inputInt[1], inputInt[2]);
            printf("\t\t----------------------------------------\n");
            printf("\t\t   %10s:  %s\n", "课程名字", subjects[getClassNo].name);
            printf("\t\t   %10s:  %s\n", "上课地点", subjects[getClassNo].location);
            printf("\t\t   %10s:  %s\n", "上课时间段", timeList[inputInt[2]  - 1]);
            printf("\t\t----------------------------------------\n");

            printf("\t\t\t任意键返回！");
            getchar();
            getchar();
            main();
        }
        k++;
    }
    if (subjects[getClassNo].weekRang[k] == -1)//没有的话跳到main
    {
        system("cls");
        printf("\t\t在第%d周星期%d,第%d节没有课!\n", inputInt[0], inputInt[1], inputInt[2]);
        printf("\t\t\t任意键返回！");
        getchar();
        getchar();
        main();
    }
}

int getClassName(int weekday, int time)
{
    int t = weekday*10 + time;
    int classNo;
    for (classNo = 0; classNo < length; classNo++)//查找在指定星期指定节数的是否有课，有则返回课号
    {
        int j = 0;
        while (subjects[classNo].classTime[j] != -1)
        {
        //    printf("----%d\n", subjects[classNo].classTime[j]);
            if (subjects[classNo].classTime[j] == t && ifRightWeek(classNo))
            {
            //    printf("\n\n%s %s\n\n", subjects[classNo].classTime[j],subjects[classNo].name);
                return classNo;
            }
            j++;
        }
    }
    return -1;
}

int ifRightWeek(int classNo)
{
    int i = 0;
    while (subjects[classNo].weekRang[i] != -1)
    {
        if (subjects[classNo].weekRang[i] == currentSemesterWeek)//查找在本周是否有当前传入函数的课程
        {
        //    printf("%d  %s\n", subjects[classNo].weekRang[i], subjects[classNo].name);
            return 1;
        }
        i++;
    }
    return 0;
}

int isLeapYear(int year)
{
	if(year%400 == 0 || year%100 != 0 && year % 4 == 0)//判断是否闰年
		return 1;
	else
		return 0;
}

int getCurrentYearWeek(const char temp[200])
{
    int i;
    char strWeek[3];
    for (i = 0; i < 2; i++)
    {
        strWeek[i] = temp[i + 26];//本函数的所有数字都是有tmp字符串来的，由数字精确到字符串中数字的位置
    }
    strWeek[i] = '\0';
//    printf("%s\n", strWeek);
    int currentWeek = atoi(strWeek);
    currentWeekday = temp[34] - 48;
//    printf("%d\n", currentWeekday);
    return currentWeek;
}

int getDay(int date)
{
	int year = date/10000;
	int month = (date - year*10000)/100;
	int day = date%100;

	int sum = 0, i;
	for (i = 1; i < month; i++)
	{
		switch(i)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				sum += 31;
				break;

			case 2:
				if (isLeapYear(year))
					sum += 29;
				else
					sum += 28;
				break;

			default:
				sum += 30;
		}
	}
	sum += day;
	return sum;
}

FILE *loadDataFile()
{
    FILE *fp;
    fp = fopen("syllabus.dat", "r");
    if (fp == NULL)
    {
        printf("课程表加载失败，请检查您的课程表文件！");
        exit(-1);
    }
    else
        return fp;
}

int extractDate(FILE *fp, int *len)
{
    int i = 0;
    char absorbString[50];
    int flag = 1;
    int date;
    char stringWeekRange[50];
    char stringClassTime[25];
    while (!feof(fp))
    {
        if (flag == 1)
        {
             fscanf(fp, "%s%d", absorbString, &date);//单独读取第一行的开学时间
             flag = 0;
        }
        fscanf(fp, "%s%s%s%s", subjects[i].name, subjects[i].location, stringWeekRange, stringClassTime);//读取课程信息

        int j = 0;
        int flag = 0;

        //extract the range of one class like 1-16
        while (j < strlen(stringWeekRange))
        {
            if (stringWeekRange[j] == '-')
            {
                flag = 1;
                break;
            }
            j++;
        }
        if (flag == 1)
        {
            int get[3];
            int k = 1;

            //分离首尾数字
            char *stringAbsorb = strtok(stringWeekRange, "-");
            get[0] = atoi(stringAbsorb);

            while (stringAbsorb)
            {
                stringAbsorb = strtok(NULL, "-");
                get[k++] = atoi(stringAbsorb);
            }

            //将首尾范围内的数字放入数组
            for (k = 0; k < get[1] - get[0] + 1; k++)
            {
                subjects[i].weekRang[k] = get[0] + k;
            }
            subjects[i].weekRang[k] = -1;
        }
        else//string like this:1,2,3,4,6,7,9,10,19//处理具体给出的某几周
        {
            int k = 1;
            char *splitWeek = strtok(stringWeekRange, ",");
            subjects[i].weekRang[0] = atoi(splitWeek);

            while (splitWeek)
            {
                splitWeek = strtok(NULL, ",");
                subjects[i].weekRang[k++] = atoi(splitWeek);
            }
            subjects[i].weekRang[k - 1] = -1;
        }

        //extract the detail information of one class 处理每节课在星期几和第几节的信息
        int temp[25];
        int k = 1;

        char *splitTime = strtok(stringClassTime, ",-");
        temp[0] = atoi(splitTime);
        while (splitTime)
        {
            splitTime = strtok(NULL, ",-");
            temp[k++] = atoi(splitTime);
        }
        temp[k - 1] = -1;

        int l, t;
        for (l = 0, t = 0; l < k-1; l += 2)//星期几和节数都是小于10的数，在此将他们合成一个整数储存，方便后面需要
        {
            subjects[i].classTime[t] = temp[l]*10 + temp[l + 1];
            t++;
        }
        subjects[i].classTime[t] = -1;

        i++;
    }

    *len = i - 1;//实际长度-1
    fclose(fp);//close file
    return date;
}

/*///////////////////////////课程表文件数据模型样本///////////////////////////////////////////////
开学时间: 20140824
离散数学           1教422     1-16                                1-1
大学英语           11教604    1-16                                2-1
java程序设计       1教522     1-13                                5-3,3-5
java实际实验       6教527     5-10                                2-4
java实际实验       6教527     1,3,5,7,9,11,13,15,17,19            5-1
线性代数           1教阶101   1-16                                1-4
体育               西区田径场   2-17                                1-3
电路及其原理       1教341     1-10                                2-2,4-3
马克思主义基本原理 1阶教303   1,2,3,6,7,8,9,11,12,13,14,15,16,18  1-2,4-4
Flah动画           15教504    3-14                                6-2
物理实验           1教实验    2,4,6,8,10,12,14                    1-5
英语听力           15教504    2,4,6,8,10,12,14,16,                5-2
*////////////////////////////////////////////////////////////////////////////////////////////////////
