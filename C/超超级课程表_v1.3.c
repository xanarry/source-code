/*
 *名称: 课程表
 *版本: v1.3
 *作者: 熊洋
 *功能: 整合文件保存的课表内容以表格的形式呈现，显示本周课表，今日课表，并提供课程查询
 *功能加: v_1.2版本在上面的功能中增加对齐齐哈尔大学教务处课表下载的功能，只需要输入学号和密码就能自动从教务处网站下载课表，并能够分析课表中是否有
 *        课程冲突，学校那破系统的课表有时两节课会同时蹦到一节课上去。V_1.3增加手动创建课表和修改课表功能，避免了用户直接创建文件的复杂性
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
    int weekRange[25];
    int classTime;
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
void complexCondition(struct Subject *temp, int indexOfSubjects, char *src);
void showWeekClass();
void showClassWeek();
void todaySyllabus();//get all the classes of current day
int syllabusSearch();//for search
void showFileContent();//用于测试内存中加载的数据的正确性
void dataVerifying();//校验文件中的课程表是否有课程冲突
int getConjunction(int *a, int *b, int *c);//求课程周数的交集
int preproccess();//从教务处HTML源代码并整理成可读文件
void getValid(char *dest, char *src);//提供给预处理函数从HTML中提取有效字符串
void initializeFile();//引导用户创建课程文件
int checkInputData(char *str);//检查用户在创建文件过程中输入数据的合法性
void modifySyllabus();//更改课程表信息文件


int main()
{
    //    initializeFile();
    ///////////////////设定窗口大小以及起点位置////////////////
    HWND h;
	const int STARTX = 150;
	const int STARTY = 30;
	const int XLEN = 1000;
	const int YLEN = 700;
	char szConsoleTitle[100];
	GetConsoleTitle(szConsoleTitle, 100) ;
	h=FindWindow(NULL,szConsoleTitle);
	SetWindowPos(h,HWND_TOP, STARTX, STARTY, XLEN, YLEN, SWP_SHOWWINDOW);
	///////////////////设定窗口大小////////////////////////////


    system("cls");
    FILE *fp = loadDataFile();
    int date = extractDate(fp, &length);
//    modifySyllabus();

    time_t t = time(0);
    char tmp[200];
    strftime(tmp, sizeof(tmp), "\t今天是%Y-%m-%d,本年度第%W周星期%w第%j天",localtime(&t) );//本行勿修改

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

 //   showFileContent();

    dataVerifying();

    printf("%s - 本学期第%d天,第%d周\n", tmp, getDay(yearDate) - getDay(date), currentSemesterWeek);

//    showClassWeek();//行为节数，列为星期

    showWeekClass();//行为星期，列为节数

    todaySyllabus();//显示当天（今天）的课表

    printf("\t\t更改课程信息请按\"1\"; 查询某个时间是否有课请按\"2\": ");
    int input;
    scanf("%d", &input);
    if (input == 1)
        modifySyllabus();
    if (input == 2)
        syllabusSearch();//课程查询

    system("pause > nul");
    return 0;
}


int preproccess()//从教务处HTML源代码并整理成可读文件
{
    char get[200], dest[200];
    printf("\t程序正在尝试登陆教务处获取信息\n");
    system("getSyllabus.exe");//调用python写的程序下载课表的HTML源文件


    FILE *fpin = fopen("syllabus.tmp","r");//读取网页文件
    if (fpin == NULL)
    {
        printf("亲,您在下载教务处课程的过程中好像出了错哦！\n");
        exit(0);
    }

    FILE *fpout = fopen("getOnce.tmp", "w");//第一次分离时保存到getOnce.tmp文件
    if (fpout == NULL)
    {
        printf("提取文件信息出错!\n");
        exit(0);
    }

    while (!feof(fpin))
    {
    	fscanf(fpin, "%s\n", get);//按行从HTML源代码中获取
    	if (strlen(get) >= 15 && strstr(get, "align") && strcmp(get+(strlen(get) - 4), "FONT"))//首次分离信息
    	{
    		getValid(dest, get+15);//再次分离
    		fprintf(fpout, "%s\n", dest);//保存到getOnce.tmp文件中
    	}
    }

    fclose(fpout);
    fclose(fpin);//关闭文件指针

    fpout = fopen("syllabus.dat", "w");//正式有效的信息写入该文件
    if (fpout == NULL)
    {
    	printf("课程表文件创建失败！\n");
    	exit(0);
    }

    fpin = fopen("getOnce.tmp", "r");//从只包含课程信息的整理源

    int count = 0;
    int t = 0;
    char temp[8][100];

    int startTime;
    printf("请输入您的开学时间(如20140824表示2014年8月24日):");
    scanf("%d", &startTime);

    fprintf(fpout, "开学时间: %d\n", startTime);

    while (!feof(fpin))
    {
        fscanf(fpin, "%s", get);//读取文件信息源
        if (count < 8)
        {
            strcpy(temp[count], get);
            count++;
        }
        else
        {
            count = 0;
            char convertTemp[100];
            int i;
            for (i = 0; i < strlen(temp[7]) - 4; i++)
            {
                convertTemp[i] = temp[7][i];
            }
            convertTemp[i] = '\0';
            fprintf(fpout, "%-25s    %-18s    %-4s    %-20s\n", temp[0], temp[5], temp[6], convertTemp);
            strcpy(temp[count], get);
            count++;
        }
    }
    fclose(fpout);
    fclose(fpin);

    system("del getOnce.tmp");
    system("del syllabus.tmp");//删除创建的临时文件

    printf("课表下载成功！正在返回主页...");
    Sleep(3000);
    main();
}


void showWeekClass()
{
    printf("\n\t\t\t---------本周课表---------\n");
    printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
    printf("|      |  星期一  |  星期二  |  星期三  |  星期四  |  星期五  |  星期六  |  星期天  |\n");

    int classTime;

    for (classTime = 1; classTime <= 5; classTime++)//第几节课
    {
        printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
        printf("|第%d节 |", classTime);
        int weekday;
        for (weekday = 1; weekday <= 7; weekday++)//星期几
        {
            int temp = getClassName(weekday, classTime);//

            if (temp >= 0)
            {
                if (strlen(subjects[temp].name) > 8)//为了保持显示表格的美观，大于四个字的名字只显示前四个字
                {
                    //////////////////////////////////////////////
                    int charCount = 0, t = 0;
                    while (t < 8)
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
                    while (t < 8)
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

                    printf(" %-11s|", shortName);
                }
                else
                    printf(" %-11s|", subjects[temp].name);
            }
            else
            {
                printf(" %-11s|", " ");
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
        int classIndex = getClassName(currentWeekday, i);//传递的值是classTime(int)的值
        if (classIndex >= 0)
        {
            printf("\t\t\t%10s:  第%d节\n", "上课节次", i);
            printf("\t\t\t%10s:  %s\n", "课程名字", subjects[classIndex].name);
            printf("\t\t\t%10s:  %s\n", "上课地点", subjects[classIndex].location);
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

    int formatTime = inputInt[1] * 10 + inputInt[2];


    int classIndex;
    int getClassIndex = -100;

    //判读在指定星期和节次是否有课
    for (classIndex = 0; classIndex < length; classIndex++)
    {
     //   printf("classIndex = %d\n", classIndex);
        int j = 0;

        if (subjects[classIndex].classTime == formatTime)
        {
        //    printf("name = %s\n", subjects[classIndex].name);
            getClassIndex = classIndex;
                break;//因为可能包含没有处理掉的有冲突的课,所有在此加break则会显示冲突课程最前面的，注释掉就显示最后面的
        }
    }

    if (getClassIndex == -100)//如果在某节课没有课，则直接跳转到main函数，不再执行后续查找过程
    {
        system("cls");
        printf("\t\t在第%d周星期%d,第%d节没有课!\n", inputInt[0], inputInt[1], inputInt[2]);
        printf("\t\t\t任意键返回！");
        getchar();
        getchar();
        main();
    }

    //如果查找的了上课的具体时间，则继续查找是否是在当前周有课
    int k = 0;
    while (subjects[getClassIndex].weekRange[k] != -1)//遍历所有周
    {
        if (subjects[getClassIndex].weekRange[k] == inputInt[0])//如果上,则输出查找到有课的信息
        {
            system("cls");
            printf("\t\t   在第%d周星期%d,第%d节您有如下课程:\n", inputInt[0], inputInt[1], inputInt[2]);
            printf("\t\t----------------------------------------\n");
            printf("\t\t   %10s:  %s\n", "课程名字", subjects[getClassIndex].name);
            printf("\t\t   %10s:  %s\n", "上课地点", subjects[getClassIndex].location);
            printf("\t\t   %10s:  %s\n", "上课时间段", timeList[inputInt[2]  - 1]);
            printf("\t\t----------------------------------------\n");

            printf("\t\t\t任意键返回！");
            getchar();
            getchar();
            main();
        }
        k++;
    }
    if (subjects[getClassIndex].weekRange[k] == -1)//没有的话跳到main
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
    int formatTime = weekday*10 + time;

    int classIndex;
    for (classIndex = 0; classIndex < length; classIndex++)//查找在指定星期指定节数的是否有课，有则返回课号
    {
        if (subjects[classIndex].classTime == formatTime && ifRightWeek(classIndex))
        {
        //    printf("\n\n%s %s\n\n", subjects[classIndex].classTime[j],subjects[classIndex].name);
            return classIndex;
        }
    }
    return -1;
}


int ifRightWeek(int classIndex)
{
    int i = 0;
    while (subjects[classIndex].weekRange[i] != -1)
    {
        if (subjects[classIndex].weekRange[i] == currentSemesterWeek)//查找在本周是否有当前传入函数的课程
        {
        //    printf("%d  %s\n", subjects[classIndex].weekRange[i], subjects[classIndex].name);
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


int getDay(int date)//计算某个日期是本年的第几天
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
				sum += 31;//1,2,5,7,8,10,12
				break;

			case 2:
				if (isLeapYear(year))//二月分平年闰年
					sum += 29;
				else
					sum += 28;
				break;

			default://其他月份加30天
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
        printf("\t未发现课程表文件！正在初始化文件...\n");//没有课程文件
        printf("\n\t\t  手动创建请按1;\n");
        printf("自动获取(确保教务处能访问)请按2: ");
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
            initializeFile();//手动创建文件
        if (ch == 2)
            preproccess();//预处理文件信息
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
    //         printf("%s %d\n", absorbString, date);
             flag = 0;
        }
        fscanf(fp, "%s%s%s%s", subjects[i].name, subjects[i].location, stringClassTime, stringWeekRange);//读取课程信息
        int j = 0;
        int flag = 0;


        while (j < strlen(stringWeekRange))
        {
            if (stringWeekRange[j] == '-')
            {
                flag = 1;
                break;
            }
            j++;
        }

        if (flag == 1)//extract the range of one class like 1-16 & 1-16,18,20
        {
            //要处理的奇葩数据
            //"1-18":> 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18(int) original data
            //"1-3,6-9,11-16,18":> 1,2,3,6,7,8,9,11,12,13,14,15,16,18(int)
            //"14-16,18":> 14,15,16,18(int)

            j = 0;
            int flag1 = 0;

            while (j < strlen(stringWeekRange))
            {
                if (stringWeekRange[j] == ',')
                {
                    flag1 = 1;
                    break;
                }
                j++;
            }

            if (flag1 == 0) //"1-18":> 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18(int) original data
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
                    subjects[i].weekRange[k] = get[0] + k;
                }
                subjects[i].weekRange[k] = -1;
            }
            else
            {
                //"1-3,6-9,11-16,18,21":> 1,2,3,6,7,8,9,11,12,13,14,15,16,18,21(int)
                //"14-16,18":> 14,15,16,18(int)
                complexCondition(subjects, i, stringWeekRange);//将这个包含复杂信息的数据交给专有函数处理
            }
        }
        else//string like this:1,2,3,4,6,7,9,10,19//处理具体给出的某几周
        {
            int k = 1;
            char *splitWeek = strtok(stringWeekRange, ",");
            subjects[i].weekRange[0] = atoi(splitWeek);

            while (splitWeek)
            {
                splitWeek = strtok(NULL, ",");
                subjects[i].weekRange[k++] = atoi(splitWeek);
            }
            subjects[i].weekRange[k - 1] = -1;
        }

        //extract the detail information of one class 处理每节课在星期几和第几节的信息
        int temp[25];
        int k = 1;


        ////处理上课时间的数据
        char *splitTime = strtok(stringClassTime, ",-");
        temp[0] = atoi(splitTime);
        while (splitTime)
        {
            splitTime = strtok(NULL, ",-");
            temp[k++] = atoi(splitTime);
        }
        temp[k - 1] = -1;

  //      printf("classTime = %d + %d\n", temp[0], temp[1]);

        subjects[i].classTime = temp[0]*10 + temp[1];

        //版本1.1中的上课时间获取代码，支持上课时间1-2,2-3这样的连续输入，此版本将不再支持这一特性
        /*旧版的课程时间是保存在数组中的，现在结构体的课程时间已改为单个变量
        int l, t;
        for (l = 0, t = 0; l < k-1; l += 2)//星期几和节数都是小于10的数，在此将他们合成一个整数储存，方便后面需要
        {
            subjects[i].classTime[t] = temp[l]*10 + temp[l + 1];
            t++;
        }
        subjects[i].classTime[t] = -1;
        */

        i++;
    }

    *len = i - 1;//实际长度-1
    fclose(fp);//close file
    return date;
}


void complexCondition(struct Subject *temp, int indexOfSubjects, char *src)
{
    //"1-3,6-9,11-16,18,21":> 1,2,3,6,7,8,9,11,12,13,14,15,16,18,21(int)
    //"14-16,18":> 14,15,16,18(int)

	int i;
	int t = 0;
	int index = 0;
    int indexOfWeekRange = 0;

	char split[20][20];

	for (i = 0; i <= strlen(src); i++)//将字符串按','分开几个字符段
	{
		if (src[i] != ',' && i != strlen(src))
		{
			split[index][t++] = src[i];
		}
		else
		{
			split[index][t] = '\0';
			index++;
			t = 0;
		}
	}

	int getConvert[3];
	int ati = 1;

	t = 0;
	for (t = 0; t < index; t++)//遍历获取的每个分割片段
	{
		int ati = 1;
		if (strlen(split[t]) > 2)//如果是x-y的形式
		{
		    //分离数字
			char *temp = strtok(split[t], "-");
			getConvert[0] = atoi(temp);
			while (temp)
			{
				temp = strtok(NULL, "-");
				getConvert[ati++] = atoi(temp);
			}

            //getConvert[0]是"x-y"形式的起点,getConvert[1]是终点
			int getInt = getConvert[0];
			while (getInt <= getConvert[1])//将起点到终点的数据写入数组
			{
				subjects[indexOfSubjects].weekRange[indexOfWeekRange] = getInt;
				getInt++;
				indexOfWeekRange++;
			}
		}
		else//如果是单个数字
        {
            subjects[indexOfSubjects].weekRange[indexOfWeekRange] = atoi(split[t]);//将单个数字写入数组
            indexOfWeekRange++;
        }

		subjects[indexOfSubjects].weekRange[indexOfWeekRange] = -1;//设置数组结束点
	}
}


void showFileContent()//输出文件加载到内存之后的形式
{
    int i;
    printf("编号 课程名字                上课位置   上课时间       上    课    周\n");
    printf("-------------------------------------------------------------------------------------\n");
    for (i = 0; i < length; i++)
    {
        printf("%2d: %-24s %-14s %-4d", i + 1, subjects[i].name, subjects[i].location, subjects[i].classTime);

        int j = 0;
        while (subjects[i].weekRange[j] != -1)
            printf("%d ", subjects[i].weekRange[j++]);
        printf("\n");
    }
    printf("\b-------------------------------------------------------------------------------------\n");
}


void dataVerifying()//检查文件冲突
{
    struct Subject temp[30];
    //复制数组,防止对内存中原始数据的破坏或修改
    int i = 0;
    for ( ; i < length; i++)
    {
        temp[i] = subjects[i];
    }

    //对副本数组按上课时间排序(冒泡排序)，排序后排在同一时间的课表会靠在一起
    int j;
    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (temp[j].classTime > temp[j + 1].classTime)
            {
                struct Subject oneSubject = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = oneSubject;
            }
        }
    }

/*/////////////////////保留代码区，用于输出信息人工校验对比//////////////////////////////
    for (i = 0; i < length; i++)
    {
         printf("%-24s %-17s %-4d", temp[i].name, temp[i].location, temp[i].classTime);

         int j = 0;
         while (temp[i].weekRange[j] != -1)
            printf("%d ", temp[i].weekRange[j++]);
         printf("\n");
    }
*/////////////////////////////////////////////////////////////////////////////////////////

    int conflict = 0;
    int conjunction[25];
    int tips = 1;
    for (i = 0; i < length - 1; i++)
    {
        if (temp[i].classTime == temp[i + 1].classTime)//查找到上课时间一样的课程
        {
            conflict = getConjunction(temp[i].weekRange, temp[i + 1].weekRange, conjunction);//检验上课的周数是否存在交集
            if (conflict > 0)//存在交集则课程冲突
            {
                printf("\n\t---------------------------------------------------------------------");
                printf("\n\t提示%d: 我们检查到您的课表在(", tips++);
                for (j = 0; j < conflict; j++)
                {
                    printf("%d,", conjunction[j]);
                }
                printf("\b)周 星期%d 第%d节\n\n\t\t\"%s\" 与 \"%s\"  存在冲突!\n",temp[i].classTime/10, temp[i].classTime%10, temp[i].name, temp[i + 1].name);
                printf("\n\t\t--------请您及时修正，不然会影响您的课程精准度----------\n");
                printf("\t---------------------------------------------------------------------\n");
            }
        }
    }
}


int getConjunction(int *a, int *b, int *c)//求两个排序集合的交集
{
	int i = 0, j = 0;
	int k = 0;

	while (a[i] != -1 && b[j] != -1)
	{
		if (a[i] == b[j])
		{
			c[k++] = a[i];
			i++;
			j++;
		}
		else if (a[i] < b[j])
			i++;
		else
			j++;
	}

	c[k] = -1;

	if (k == 0)
		return -1;
	else
		return k;
}


void getValid(char *dest, char *src)
{
	int i = 0;
	int t = 0;
	for (i = 0; *(src + i) != '<' && *(src + i) != '>'; i++)//提取HTML是排除<和>
		dest[i] = *(src + i);
	dest[i] = '\0';
}


void initializeFile()//引导用户手动创建文件
{
    system("cls");
	struct inputUnit
	{
		char name[40];
    	char location[20];
    	char classTime[5];
    	char weekRange[50];
	}input[35];

	printf("\t正在引导您创建课程表文件\n");
	printf("请输入您的开学时间:\n(格式如\"20130823\",长度为8): ");
	char startTime[10];
	scanf("%s", startTime);

	int i = 0;
	while (1)
	{
		printf("\n\t您正在输入第%d记录\n---------------------------------\n", i + 1);
		printf("课程名字:\n(输入null终止输入过程): ");
		scanf("%s", input[i].name);
		if (strcmp(input[i].name, "null") == 0)
            break;

		printf("上课地点:(任意地方): ");
		scanf("%s", input[i].location);

		printf("上课时间:\n(由星期和上课节次组成,如星期3第5节就输入\"3-5\"): ");

		scanf("%s", input[i].classTime);
		while (1)
		{
			if (checkInputData(input[i].classTime) == 1 && strlen(input[i].classTime) == 3)
				break;
			else
			{
				printf("您输入的上课时间有误,请重新输入: ");
				scanf("%s", input[i].classTime);
			}
		}

		printf("上课的周数:\n(输入范围,比如\"1-16\",或者每个单周\"1,2,3,12\",或者混合输入像\"1-4,5-7,12,37\"): ");
		scanf("%s", input[i].weekRange);
		while (1)
		{
			if (checkInputData(input[i].weekRange) == 1 )
				break;
			else
			{
				printf("您输入的周数不符合格式要求,请重新输入: ");
				scanf("%s", input[i].weekRange);
			}
		}

		i++;
	}
	///////////输入完成后写入文件//////////////

    int j;
    printf("\n--------------------------------------------------------------------\n");
    printf("上课时间: %s\n", startTime);
    for (j = 0; j < i; j++)
    {
        printf("%-25s    %-18s    %-4s    %-20s\n", input[j].name, input[j].location, input[j].classTime, input[j].weekRange);
    }
    printf("--------------------------------------------------------------------\n");

    printf("确认以上您输入的课程信息(y/^y):");
    char conform;
    getchar();
    scanf("%c", &conform);
    if (conform == 'y' || conform == 'Y')
    {
        FILE *fp = fopen("syllabus.dat", "w");
        if (fp == NULL)
        {
            printf("真的对不起！文件创建错误");
            exit(0);
        }

        fprintf(fp, "%s%s\n", "开学时间: ", startTime);
        for (j = 0 ; j < i; j++)
            fprintf(fp, "%-25s    %-18s    %-4s    %-20s\n", input[j].name, input[j].location, input[j].classTime, input[j].weekRange);

        fclose(fp);

        printf("写入完成! 正在返回主目录...\n");
        Sleep(3000);
        main();
    }
    else
    {
        printf("过程已经中断！正在退出...");
        Sleep(3000);
        exit(0);
    }
}

int checkInputData(char *str)
{
	int j = 0;
	int strLen = strlen(str);
	for ( ; j < strLen; j++)
	{
		if (isalpha(str[j]) || !isdigit(str[strLen - 1]) )
			return 0;
	}
	return 1;
}



void modifySyllabus()
{
    FILE *fp = fopen("syllabus.dat", "r");
    if (fp == NULL)
    {
        printf("未在程序工作目录找到课表！");
        exit(0);
    }

    struct inputUnit
	{
		char name[40];
    	char location[20];
    	char classTime[5];
    	char weekRange[50];
	}read[35];

    int recordsCount;
    int delNum = -100;//要删除的课程编码
    char noSense[10];
    char startTime[10];

    fscanf(fp, "%s%s", noSense, startTime);
    printf("\n开学时间: %s", startTime);

    int i = 0;

    while (!feof(fp))
    {
        fscanf(fp, "%s%s%s%s", read[i].name, read[i].location, read[i].classTime, read[i].weekRange);
        i++;
    }
    fclose(fp);

    recordsCount = i - 1;
    i = 0;
    printf("\n编号 课程名字                      上课位置       上课时间   上  课  周\n");
    printf("------------------------------------------------------------------------------------\n");
    while (i < recordsCount)
    {
        printf("%2d: %-25s    %-16s    %-4s    %-20s\n", i+1, read[i].name, read[i].location, read[i].classTime, read[i].weekRange);
        i++;
    }
    printf("------------------------------------------------------------------------------------\n");
    printf("\t\t\t以上是您当前的课程信息！\n");

    printf("\n添加条目请按1,删除条目请按2,修改条目请按3:\n");


    printf("您选择:");
    int operation;
    scanf("%d", &operation);
    while (1)
    {
        if (operation >=1 && operation <= 3)
            break;
        else
        {
            printf("您的选择不在范围内,请重新输入: ");
            scanf("%d", &operation);
        }
    }


    if (operation == 1)
    {
        //添加一条新记录到文件末尾
        printf("您正在添加第%d条记录...\n", recordsCount + 1);
        printf("课程名字:\n(输入null终止输入过程): ");
		scanf("%s", read[recordsCount].name);

		printf("上课地点:(任意地方): ");
		scanf("%s", read[recordsCount].location);

		printf("上课时间:\n(由星期和上课节次组成,如星期3第5节就输入\"3-5\"): ");

		scanf("%s", read[recordsCount].classTime);
		while (1)
		{
			if (checkInputData(read[recordsCount].classTime) == 1 && strlen(read[recordsCount].classTime) == 3)
				break;
			else
			{
				printf("您输入的上课时间有误,请重新输入: ");
				scanf("%s", read[recordsCount].classTime);
			}
		}

		printf("上课的周数:\n(输入范围,比如\"1-16\",或者每个单周\"1,2,3,12\",或者混合输入像\"1-4,5-7,12,37\"): ");
		scanf("%s", read[recordsCount].weekRange);
		while (1)
		{
			if (checkInputData(read[recordsCount].weekRange) == 1 )
				break;
			else
			{
				printf("您输入的周数不符合格式要求,请重新输入: ");
				scanf("%s", read[recordsCount].weekRange);
			}
		}

		recordsCount++;//总条数增加一条
    }


    if (operation == 2)
    {
        //删除指定编号的课程记录
        printf("您正在添加第%d条记录...\n", recordsCount);
        printf("请输入您要删除的课程编号(1-%d):", recordsCount);
        scanf("%d", &delNum);
        while (1)
        {
            if (delNum <= recordsCount && delNum >= 1)
                break;
            else
            {
                printf("您输入的编号不存在,请重新输入:");
                scanf("%d", &delNum);
            }
        }

        printf("\n课程名字                    上课位置      上课时间  上    课    周\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("%-25s    %-12s    %-4s    %-20s\n", read[delNum - 1].name, read[delNum - 1].location, read[delNum - 1].classTime, read[delNum - 1].weekRange);
        printf("\b-------------------------------------------------------------------------------------\n");

        printf("您即将删除以上记录(y/^y): ");
        char ch;
        getchar();
        scanf("%c", &ch);
        if (ch == 'y')
        {
            printf("\n正在删除...\n");
            delNum -= 1;
        }
        else
            delNum = -100;
    }


    if (operation == 3)
    {
        //修改指定编号记录的信息
        printf("\n请输入您要要修改课程前面的编号(1-%d): ", length);

        int num;
        scanf("%d", &num);
        while (1)
        {
            if (num <= 0 || num > recordsCount)
            {
                printf("您输入的课程号没在有效范围内,请重新输入: ");
                scanf("%d", &num);
            }
            else
                break;
        }

    	printf("\n课程名字                    上课位置      上课时间  上    课    周\n");
    	printf("-------------------------------------------------------------------------------------\n");
    	printf("%-25s    %-12s    %-4s    %-20s\n", read[num - 1].name, read[num - 1].location, read[num - 1].classTime, read[num - 1].weekRange);
    	printf("\b-------------------------------------------------------------------------------------\n");
    	printf("\t\t   ----您正在修改以上课程信息----\n");

	//    printf("\t\t\t修改开学日期请按 0:\n");
   	 	printf("\t\t\t修改课程名字请按 1:\n");
   	 	printf("\t\t\t修改上课地点请按 2:\n");
   	 	printf("\t\t\t修改上课时间请按 3:\n");
   	 	printf("\t\t\t修改上课周数请按 4:\n");
   	 	printf("\t\t\t    输入您的选择:");


    	int choose;
    	char newInfo[40];
    	int conform;
    	scanf("%d", &choose);
    	switch(choose)
    	{

		/*    case 0:
    	    printf("\t\t\t\n您正在修改开学时间...\n");
        	printf("输入新的开学时间: ");
        	scanf("%s", newInfo);
        	printf("确认修改为：%s (y/^y)?: ", newInfo);

        	scanf("%d", &conform);
        	if (conform == 'y');
        	strcpy(startTime, newInfo);
        	break;*/

    	case 1:
    	    printf("\t\t\t\n您正在修改课程名字...\n");
    	    printf("输入新的名字: ");
    	    scanf("%s", newInfo);
    	    printf("确认修改为：%s (y/^y)?: ", newInfo);

    	    scanf("%d", &conform);
    	    if (conform == 'y');
    	    strcpy(read[num - 1].name, newInfo);
    	    break;

    	case 2:
    	    printf("您正在修改上课地点...\n");
    	    printf("输入新的上课地点: ");
    	    scanf("%s", newInfo);
    	    printf("确认修改为：%s (y/^y)?: ", newInfo);

        	scanf("%d", &conform);
        	if (conform == 'y');
        	strcpy(read[num - 1].location, newInfo);
        	break;

    	case 3:
        	printf("您正在修改上课时间...\n");
        	printf("新的上课时间(星期几-节次,比如 \"3-2\"): ");
        	scanf("%s", newInfo);
        	while (1)
			{
				if (checkInputData(newInfo) == 1 && strlen(newInfo) == 3)
					break;
				else
				{
					printf("您输入的上课时间有误,请重新输入: ");
					scanf("%s", newInfo);
				}
			}

        	printf("确认修改为：%s (y/^y)?: ", newInfo);

        	scanf("%d", &conform);

        	if (conform == 'y');
        	strcpy(read[num - 1].classTime, newInfo);
        	break;

    	case 4:
    	    printf("您正在修改上课周...\n");
    	    printf(" 1 您可以给出周数范围 \"1-7\" 表示1到7周有课;");
            printf("\n 2 或者输入多个范围段 \"1-3,4-7\" 表示1到3和4-7周有课;");
            printf("\n 3 或者所有单个周数 \"1,2,3,4\" 表示1,2,3,4周有课;");
            printf("\n 4 也可混合输入范围与单周 \"2-4,6-9,12,17\" 表示2,3,4,6,7,8,9,12,17周有课;");
            printf("\n请输入新的上课周: ");
    	    scanf("%s", newInfo);
    	    printf("确认修改为：% (y/^y)?: ", newInfo);

    	    scanf("%d", &conform);
    	    while (1)
			{
				if (checkInputData(newInfo) == 1)
					break;
				else
				{
					printf("您输入的上课周数有误,请重新输入: ");
					scanf("%s", newInfo);
				}
			}

 	       	if (conform == 'y');
	        strcpy(read[num - 1].weekRange, newInfo);
	        break;
	    }
    }


    //写入修改之后的记录
    fp = fopen("syllabus.dat", "w");
    if (fp == NULL)
    {
        printf("真的对不起！文件创建错误");
        exit(0);
    }

    fprintf(fp, "%s%s\n", "开学时间: ", startTime);
    int j;
    for (j = 0 ; j < recordsCount; j++)
    {
        if (j != delNum)
            fprintf(fp, "%-25s    %-18s    %-4s    %-20s\n", read[j].name, read[j].location, read[j].classTime, read[j].weekRange);
    }

    printf("操作成功完成!\n");
    getchar();
    printf("正在返回主目录...");
    Sleep(3000);
    fclose(fp);
    main();
}
