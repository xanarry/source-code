/*
 *����: �γ̱�
 *�汾: v1.0
 *����: ����
 *����: �����ļ�����Ŀα������Ա�����ʽ���֣���ʾ���ܿα����տα����ṩ�γ̲�ѯ
 *���ʱ��: 2014/9/25
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
    strftime(tmp, sizeof(tmp), "\t������%Y-%m-%d,����ȵ�%W������%w��%j��",localtime(&t) );

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

    printf("%s - ��ѧ�ڵ�%d��,��%d��\n", tmp, getDay(yearDate) - getDay(date), currentSemesterWeek);

//    showClassWeek();//��Ϊ��������Ϊ����
    showWeekClass();//��Ϊ���ڣ���Ϊ����
    todaySyllabus();//��ʾ���죨���죩�Ŀα�

    printf("\t\t�����Ҫ��ѯĳ��ʱ���Ƿ��п��밴��1��:");
    int input;
    scanf("%d", &input);
    if (input == 1)
        syllabusSearch();

    system("pause > nul");
    return 0;
}

void showWeekClass()
{
    printf("\n\t\t\t---------���ܿα�---------\n");
    printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
    printf("|      |  ����һ  |  ���ڶ�  |  ������  |  ������  |  ������  |  ������  |  ������  |\n");

    int classNo;

    for (classNo = 1; classNo <= 5; classNo++)//�ڼ��ڿ�
    {
        printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
        printf("|��%d�� |", classNo);
        int weekday;
        for (weekday = 1; weekday <= 7; weekday++)//���ڼ�
        {
            int temp = getClassName(weekday, classNo);

            if (temp >= 0)
            {
                if (strlen(subjects[temp].name) > 8)//Ϊ�˱�����ʾ�������ۣ������ĸ��ֵ�����ֻ��ʾǰ�ĸ���
                {
                    //////////////////////////////////////////////
                    int charCount = 0, t = 0;
                    while (subjects[temp].name[t] != '\0')
                    {
                        if (isalnum(subjects[temp].name[t]))
                            charCount++;//����Ǻ��ֵ��ַ�����
                        t++;
                    }
                    /*�˴���������жϿγ����������������ֻ���ĸ����������ż��������ż������������ȡ8�����ȵ�
                      ���ַ����������������ȡ9���ַ�����ȷ�������ȡ������������ռ���ַ�λ�ôӶ�ʹ�������룬
                      ��Ϊһ������ռ�����ַ�λ��*/
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
    printf("\n\t\t\t---------���ܿα�---------\n");
    printf("--------+------------+------------+------------+------------+-------------\n");
    printf("|       |   ��һ��   |   �ڶ���   |   ������   |   ���Ľ�   |   �����   |\n");

    int weekday;

    for (weekday = 1; weekday <= 7; weekday++)//���ڼ�
    {
        printf("+-------+------------+------------+------------+------------+------------+\n");
        printf("|����%d  |", weekday);
        int classNo;
        for (classNo = 1; classNo <= 5; classNo++)//�ڼ��ڿ�
        {
            int temp = getClassName(weekday, classNo);

            if (temp >= 0)
            {
                if (strlen(subjects[temp].name) > 8)//Ϊ�˱�����ʾ�������ۣ������ĸ��ֵ�����ֻ��ʾǰ�ĸ���
                {
                    //////////////////////////////////////////////
                    int charCount = 0, t = 0;
                    while (subjects[temp].name[t] != '\0')
                    {
                        if (isalnum(subjects[temp].name[t]))
                            charCount++;//����Ǻ��ֵ��ַ�����
                        t++;
                    }
                    /*�˴���������жϿγ����������������ֻ���ĸ����������ż��������ż������������ȡ8�����ȵ�
                      ���ַ����������������ȡ9���ַ�����ȷ�������ȡ������������ռ���ַ�λ�ôӶ�ʹ�������룬
                      ��Ϊһ������ռ�����ַ�λ��*/
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
    printf("\t\t\t  ---���տα�---\n");
    printf("\t\t----------------------------------------\n");

    int ifOutput = 0;

    int i;
    for (i = 1; i <= 5; i++)//Which class
    {
        int classNo = getClassName(currentWeekday, i);
        if (classNo >= 0)
        {
            printf("\t\t\t%10s:  ��%d��\n", "�Ͽνڴ�", i);
            printf("\t\t\t%10s:  %s\n", "�γ�����", subjects[classNo].name);
            printf("\t\t\t%10s:  %s\n", "�Ͽεص�", subjects[classNo].location);
            printf("\t\t\t%10s:  %s\n", "�Ͽ�ʱ���", timeList[i - 1]);
            printf("\t\t----------------------------------------\n");
            ifOutput = 1;
        }
    }

    if (!ifOutput)
    {
        printf("\t\t\t�����޿γ̰���! ^_^\n");
        printf("\t\t----------------------------------------\n");
    }
}

int syllabusSearch()
{
    system("cls");
    printf("\t\t\t\t��ѯING\n\t������Ҫ��ѯ ��11������3��2�� �Ƿ��п�,�����롰11-3-2��,���س�����ѯ�������!\n\t\t��������Ҫ��ѯ�Ŀγ�ʱ��: ");
    char inputStr[10];
    scanf("%s", inputStr);
    while (strlen(inputStr) > 6 || strlen(inputStr) < 5)
    {
        printf("\t������ĸ�ʽ����,����������: ");
        scanf("%s", inputStr);
    }

    int inputInt[4];
    int i = 1;

    //��������ַ�����ת��Ϊ������Ҫ������
    char *temp = strtok(inputStr, "-");
    inputInt[0] = atoi(temp);
    while (temp)
    {
        temp = strtok(NULL, "-");
        inputInt[i++] = atoi(temp);
    }

    int classNo;
    int getClassNo = -100;

    //�ж���ָ�����ںͽڴ��Ƿ��п�
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

    if (getClassNo == -100)//���û����ֱ����ת��main����������ִ�к������ҹ���
    {
        system("cls");
        printf("\t\t�ڵ�%d������%d,��%d��û�п�!\n", inputInt[0], inputInt[1], inputInt[2]);
        printf("\t\t\t��������أ�");
        getchar();
        getchar();
        main();
    }


    int k = 0;
    while (subjects[getClassNo].weekRang[k] != -1)//���ҵ���ʱ���пΣ��ٲ��Ҹÿ��Ƿ���ָ������
    {
        if (subjects[getClassNo].weekRang[k] == inputInt[0])//�����,��������ҵ��пε���Ϣ
        {
            system("cls");
            printf("\t\t   �ڵ�%d������%d,��%d���������¿γ�:\n", inputInt[0], inputInt[1], inputInt[2]);
            printf("\t\t----------------------------------------\n");
            printf("\t\t   %10s:  %s\n", "�γ�����", subjects[getClassNo].name);
            printf("\t\t   %10s:  %s\n", "�Ͽεص�", subjects[getClassNo].location);
            printf("\t\t   %10s:  %s\n", "�Ͽ�ʱ���", timeList[inputInt[2]  - 1]);
            printf("\t\t----------------------------------------\n");

            printf("\t\t\t��������أ�");
            getchar();
            getchar();
            main();
        }
        k++;
    }
    if (subjects[getClassNo].weekRang[k] == -1)//û�еĻ�����main
    {
        system("cls");
        printf("\t\t�ڵ�%d������%d,��%d��û�п�!\n", inputInt[0], inputInt[1], inputInt[2]);
        printf("\t\t\t��������أ�");
        getchar();
        getchar();
        main();
    }
}

int getClassName(int weekday, int time)
{
    int t = weekday*10 + time;
    int classNo;
    for (classNo = 0; classNo < length; classNo++)//������ָ������ָ���������Ƿ��пΣ����򷵻ؿκ�
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
        if (subjects[classNo].weekRang[i] == currentSemesterWeek)//�����ڱ����Ƿ��е�ǰ���뺯���Ŀγ�
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
	if(year%400 == 0 || year%100 != 0 && year % 4 == 0)//�ж��Ƿ�����
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
        strWeek[i] = temp[i + 26];//���������������ֶ�����tmp�ַ������ģ������־�ȷ���ַ��������ֵ�λ��
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
        printf("�γ̱����ʧ�ܣ��������Ŀγ̱��ļ���");
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
             fscanf(fp, "%s%d", absorbString, &date);//������ȡ��һ�еĿ�ѧʱ��
             flag = 0;
        }
        fscanf(fp, "%s%s%s%s", subjects[i].name, subjects[i].location, stringWeekRange, stringClassTime);//��ȡ�γ���Ϣ

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

            //������β����
            char *stringAbsorb = strtok(stringWeekRange, "-");
            get[0] = atoi(stringAbsorb);

            while (stringAbsorb)
            {
                stringAbsorb = strtok(NULL, "-");
                get[k++] = atoi(stringAbsorb);
            }

            //����β��Χ�ڵ����ַ�������
            for (k = 0; k < get[1] - get[0] + 1; k++)
            {
                subjects[i].weekRang[k] = get[0] + k;
            }
            subjects[i].weekRang[k] = -1;
        }
        else//string like this:1,2,3,4,6,7,9,10,19//������������ĳ����
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

        //extract the detail information of one class ����ÿ�ڿ������ڼ��͵ڼ��ڵ���Ϣ
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
        for (l = 0, t = 0; l < k-1; l += 2)//���ڼ��ͽ�������С��10�������ڴ˽����Ǻϳ�һ���������棬���������Ҫ
        {
            subjects[i].classTime[t] = temp[l]*10 + temp[l + 1];
            t++;
        }
        subjects[i].classTime[t] = -1;

        i++;
    }

    *len = i - 1;//ʵ�ʳ���-1
    fclose(fp);//close file
    return date;
}

/*///////////////////////////�γ̱��ļ�����ģ������///////////////////////////////////////////////
��ѧʱ��: 20140824
��ɢ��ѧ           1��422     1-16                                1-1
��ѧӢ��           11��604    1-16                                2-1
java�������       1��522     1-13                                5-3,3-5
javaʵ��ʵ��       6��527     5-10                                2-4
javaʵ��ʵ��       6��527     1,3,5,7,9,11,13,15,17,19            5-1
���Դ���           1�̽�101   1-16                                1-4
����               �����ﾶ��   2-17                                1-3
��·����ԭ��       1��341     1-10                                2-2,4-3
���˼�������ԭ�� 1�׽�303   1,2,3,6,7,8,9,11,12,13,14,15,16,18  1-2,4-4
Flah����           15��504    3-14                                6-2
����ʵ��           1��ʵ��    2,4,6,8,10,12,14                    1-5
Ӣ������           15��504    2,4,6,8,10,12,14,16,                5-2
*////////////////////////////////////////////////////////////////////////////////////////////////////
