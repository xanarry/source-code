/*
 *����: �γ̱�
 *�汾: v1.3
 *����: ����
 *����: �����ļ�����Ŀα������Ա�����ʽ���֣���ʾ���ܿα����տα����ṩ�γ̲�ѯ
 *���ܼ�: v_1.2�汾������Ĺ��������Ӷ����������ѧ���񴦿α����صĹ��ܣ�ֻ��Ҫ����ѧ�ź���������Զ��ӽ�����վ���ؿα����ܹ������α����Ƿ���
 *        �γ̳�ͻ��ѧУ����ϵͳ�Ŀα���ʱ���ڿλ�ͬʱ�ĵ�һ�ڿ���ȥ��V_1.3�����ֶ������α���޸Ŀα��ܣ��������û�ֱ�Ӵ����ļ��ĸ�����
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
void showFileContent();//���ڲ����ڴ��м��ص����ݵ���ȷ��
void dataVerifying();//У���ļ��еĿγ̱��Ƿ��пγ̳�ͻ
int getConjunction(int *a, int *b, int *c);//��γ������Ľ���
int preproccess();//�ӽ���HTMLԴ���벢����ɿɶ��ļ�
void getValid(char *dest, char *src);//�ṩ��Ԥ��������HTML����ȡ��Ч�ַ���
void initializeFile();//�����û������γ��ļ�
int checkInputData(char *str);//����û��ڴ����ļ��������������ݵĺϷ���
void modifySyllabus();//���Ŀγ̱���Ϣ�ļ�


int main()
{
    //    initializeFile();
    ///////////////////�趨���ڴ�С�Լ����λ��////////////////
    HWND h;
	const int STARTX = 150;
	const int STARTY = 30;
	const int XLEN = 1000;
	const int YLEN = 700;
	char szConsoleTitle[100];
	GetConsoleTitle(szConsoleTitle, 100) ;
	h=FindWindow(NULL,szConsoleTitle);
	SetWindowPos(h,HWND_TOP, STARTX, STARTY, XLEN, YLEN, SWP_SHOWWINDOW);
	///////////////////�趨���ڴ�С////////////////////////////


    system("cls");
    FILE *fp = loadDataFile();
    int date = extractDate(fp, &length);
//    modifySyllabus();

    time_t t = time(0);
    char tmp[200];
    strftime(tmp, sizeof(tmp), "\t������%Y-%m-%d,����ȵ�%W������%w��%j��",localtime(&t) );//�������޸�

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

    printf("%s - ��ѧ�ڵ�%d��,��%d��\n", tmp, getDay(yearDate) - getDay(date), currentSemesterWeek);

//    showClassWeek();//��Ϊ��������Ϊ����

    showWeekClass();//��Ϊ���ڣ���Ϊ����

    todaySyllabus();//��ʾ���죨���죩�Ŀα�

    printf("\t\t���Ŀγ���Ϣ�밴\"1\"; ��ѯĳ��ʱ���Ƿ��п��밴\"2\": ");
    int input;
    scanf("%d", &input);
    if (input == 1)
        modifySyllabus();
    if (input == 2)
        syllabusSearch();//�γ̲�ѯ

    system("pause > nul");
    return 0;
}


int preproccess()//�ӽ���HTMLԴ���벢����ɿɶ��ļ�
{
    char get[200], dest[200];
    printf("\t�������ڳ��Ե�½���񴦻�ȡ��Ϣ\n");
    system("getSyllabus.exe");//����pythonд�ĳ������ؿα��HTMLԴ�ļ�


    FILE *fpin = fopen("syllabus.tmp","r");//��ȡ��ҳ�ļ�
    if (fpin == NULL)
    {
        printf("��,�������ؽ��񴦿γ̵Ĺ����к�����˴�Ŷ��\n");
        exit(0);
    }

    FILE *fpout = fopen("getOnce.tmp", "w");//��һ�η���ʱ���浽getOnce.tmp�ļ�
    if (fpout == NULL)
    {
        printf("��ȡ�ļ���Ϣ����!\n");
        exit(0);
    }

    while (!feof(fpin))
    {
    	fscanf(fpin, "%s\n", get);//���д�HTMLԴ�����л�ȡ
    	if (strlen(get) >= 15 && strstr(get, "align") && strcmp(get+(strlen(get) - 4), "FONT"))//�״η�����Ϣ
    	{
    		getValid(dest, get+15);//�ٴη���
    		fprintf(fpout, "%s\n", dest);//���浽getOnce.tmp�ļ���
    	}
    }

    fclose(fpout);
    fclose(fpin);//�ر��ļ�ָ��

    fpout = fopen("syllabus.dat", "w");//��ʽ��Ч����Ϣд����ļ�
    if (fpout == NULL)
    {
    	printf("�γ̱��ļ�����ʧ�ܣ�\n");
    	exit(0);
    }

    fpin = fopen("getOnce.tmp", "r");//��ֻ�����γ���Ϣ������Դ

    int count = 0;
    int t = 0;
    char temp[8][100];

    int startTime;
    printf("���������Ŀ�ѧʱ��(��20140824��ʾ2014��8��24��):");
    scanf("%d", &startTime);

    fprintf(fpout, "��ѧʱ��: %d\n", startTime);

    while (!feof(fpin))
    {
        fscanf(fpin, "%s", get);//��ȡ�ļ���ϢԴ
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
    system("del syllabus.tmp");//ɾ����������ʱ�ļ�

    printf("�α����سɹ������ڷ�����ҳ...");
    Sleep(3000);
    main();
}


void showWeekClass()
{
    printf("\n\t\t\t---------���ܿα�---------\n");
    printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
    printf("|      |  ����һ  |  ���ڶ�  |  ������  |  ������  |  ������  |  ������  |  ������  |\n");

    int classTime;

    for (classTime = 1; classTime <= 5; classTime++)//�ڼ��ڿ�
    {
        printf("+------+----------+----------+----------+----------+----------+----------+----------+\n");
        printf("|��%d�� |", classTime);
        int weekday;
        for (weekday = 1; weekday <= 7; weekday++)//���ڼ�
        {
            int temp = getClassName(weekday, classTime);//

            if (temp >= 0)
            {
                if (strlen(subjects[temp].name) > 8)//Ϊ�˱�����ʾ�������ۣ������ĸ��ֵ�����ֻ��ʾǰ�ĸ���
                {
                    //////////////////////////////////////////////
                    int charCount = 0, t = 0;
                    while (t < 8)
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
                    while (t < 8)
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
    printf("\t\t\t  ---���տα�---\n");
    printf("\t\t----------------------------------------\n");

    int ifOutput = 0;

    int i;
    for (i = 1; i <= 5; i++)//Which class
    {
        int classIndex = getClassName(currentWeekday, i);//���ݵ�ֵ��classTime(int)��ֵ
        if (classIndex >= 0)
        {
            printf("\t\t\t%10s:  ��%d��\n", "�Ͽνڴ�", i);
            printf("\t\t\t%10s:  %s\n", "�γ�����", subjects[classIndex].name);
            printf("\t\t\t%10s:  %s\n", "�Ͽεص�", subjects[classIndex].location);
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

    int formatTime = inputInt[1] * 10 + inputInt[2];


    int classIndex;
    int getClassIndex = -100;

    //�ж���ָ�����ںͽڴ��Ƿ��п�
    for (classIndex = 0; classIndex < length; classIndex++)
    {
     //   printf("classIndex = %d\n", classIndex);
        int j = 0;

        if (subjects[classIndex].classTime == formatTime)
        {
        //    printf("name = %s\n", subjects[classIndex].name);
            getClassIndex = classIndex;
                break;//��Ϊ���ܰ���û�д�������г�ͻ�Ŀ�,�����ڴ˼�break�����ʾ��ͻ�γ���ǰ��ģ�ע�͵�����ʾ������
        }
    }

    if (getClassIndex == -100)//�����ĳ�ڿ�û�пΣ���ֱ����ת��main����������ִ�к������ҹ���
    {
        system("cls");
        printf("\t\t�ڵ�%d������%d,��%d��û�п�!\n", inputInt[0], inputInt[1], inputInt[2]);
        printf("\t\t\t��������أ�");
        getchar();
        getchar();
        main();
    }

    //������ҵ����Ͽεľ���ʱ�䣬����������Ƿ����ڵ�ǰ���п�
    int k = 0;
    while (subjects[getClassIndex].weekRange[k] != -1)//����������
    {
        if (subjects[getClassIndex].weekRange[k] == inputInt[0])//�����,��������ҵ��пε���Ϣ
        {
            system("cls");
            printf("\t\t   �ڵ�%d������%d,��%d���������¿γ�:\n", inputInt[0], inputInt[1], inputInt[2]);
            printf("\t\t----------------------------------------\n");
            printf("\t\t   %10s:  %s\n", "�γ�����", subjects[getClassIndex].name);
            printf("\t\t   %10s:  %s\n", "�Ͽεص�", subjects[getClassIndex].location);
            printf("\t\t   %10s:  %s\n", "�Ͽ�ʱ���", timeList[inputInt[2]  - 1]);
            printf("\t\t----------------------------------------\n");

            printf("\t\t\t��������أ�");
            getchar();
            getchar();
            main();
        }
        k++;
    }
    if (subjects[getClassIndex].weekRange[k] == -1)//û�еĻ�����main
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
    int formatTime = weekday*10 + time;

    int classIndex;
    for (classIndex = 0; classIndex < length; classIndex++)//������ָ������ָ���������Ƿ��пΣ����򷵻ؿκ�
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
        if (subjects[classIndex].weekRange[i] == currentSemesterWeek)//�����ڱ����Ƿ��е�ǰ���뺯���Ŀγ�
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


int getDay(int date)//����ĳ�������Ǳ���ĵڼ���
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
				if (isLeapYear(year))//���·�ƽ������
					sum += 29;
				else
					sum += 28;
				break;

			default://�����·ݼ�30��
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
        printf("\tδ���ֿγ̱��ļ������ڳ�ʼ���ļ�...\n");//û�пγ��ļ�
        printf("\n\t\t  �ֶ������밴1;\n");
        printf("�Զ���ȡ(ȷ�������ܷ���)�밴2: ");
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
            initializeFile();//�ֶ������ļ�
        if (ch == 2)
            preproccess();//Ԥ�����ļ���Ϣ
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
    //         printf("%s %d\n", absorbString, date);
             flag = 0;
        }
        fscanf(fp, "%s%s%s%s", subjects[i].name, subjects[i].location, stringClassTime, stringWeekRange);//��ȡ�γ���Ϣ
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
            //Ҫ�������������
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
                    subjects[i].weekRange[k] = get[0] + k;
                }
                subjects[i].weekRange[k] = -1;
            }
            else
            {
                //"1-3,6-9,11-16,18,21":> 1,2,3,6,7,8,9,11,12,13,14,15,16,18,21(int)
                //"14-16,18":> 14,15,16,18(int)
                complexCondition(subjects, i, stringWeekRange);//���������������Ϣ�����ݽ���ר�к�������
            }
        }
        else//string like this:1,2,3,4,6,7,9,10,19//������������ĳ����
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

        //extract the detail information of one class ����ÿ�ڿ������ڼ��͵ڼ��ڵ���Ϣ
        int temp[25];
        int k = 1;


        ////�����Ͽ�ʱ�������
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

        //�汾1.1�е��Ͽ�ʱ���ȡ���룬֧���Ͽ�ʱ��1-2,2-3�������������룬�˰汾������֧����һ����
        /*�ɰ�Ŀγ�ʱ���Ǳ����������еģ����ڽṹ��Ŀγ�ʱ���Ѹ�Ϊ��������
        int l, t;
        for (l = 0, t = 0; l < k-1; l += 2)//���ڼ��ͽ�������С��10�������ڴ˽����Ǻϳ�һ���������棬���������Ҫ
        {
            subjects[i].classTime[t] = temp[l]*10 + temp[l + 1];
            t++;
        }
        subjects[i].classTime[t] = -1;
        */

        i++;
    }

    *len = i - 1;//ʵ�ʳ���-1
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

	for (i = 0; i <= strlen(src); i++)//���ַ�����','�ֿ������ַ���
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
	for (t = 0; t < index; t++)//������ȡ��ÿ���ָ�Ƭ��
	{
		int ati = 1;
		if (strlen(split[t]) > 2)//�����x-y����ʽ
		{
		    //��������
			char *temp = strtok(split[t], "-");
			getConvert[0] = atoi(temp);
			while (temp)
			{
				temp = strtok(NULL, "-");
				getConvert[ati++] = atoi(temp);
			}

            //getConvert[0]��"x-y"��ʽ�����,getConvert[1]���յ�
			int getInt = getConvert[0];
			while (getInt <= getConvert[1])//����㵽�յ������д������
			{
				subjects[indexOfSubjects].weekRange[indexOfWeekRange] = getInt;
				getInt++;
				indexOfWeekRange++;
			}
		}
		else//����ǵ�������
        {
            subjects[indexOfSubjects].weekRange[indexOfWeekRange] = atoi(split[t]);//����������д������
            indexOfWeekRange++;
        }

		subjects[indexOfSubjects].weekRange[indexOfWeekRange] = -1;//�������������
	}
}


void showFileContent()//����ļ����ص��ڴ�֮�����ʽ
{
    int i;
    printf("��� �γ�����                �Ͽ�λ��   �Ͽ�ʱ��       ��    ��    ��\n");
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


void dataVerifying()//����ļ���ͻ
{
    struct Subject temp[30];
    //��������,��ֹ���ڴ���ԭʼ���ݵ��ƻ����޸�
    int i = 0;
    for ( ; i < length; i++)
    {
        temp[i] = subjects[i];
    }

    //�Ը������鰴�Ͽ�ʱ������(ð������)�����������ͬһʱ��Ŀα�῿��һ��
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

/*/////////////////////���������������������Ϣ�˹�У��Ա�//////////////////////////////
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
        if (temp[i].classTime == temp[i + 1].classTime)//���ҵ��Ͽ�ʱ��һ���Ŀγ�
        {
            conflict = getConjunction(temp[i].weekRange, temp[i + 1].weekRange, conjunction);//�����Ͽε������Ƿ���ڽ���
            if (conflict > 0)//���ڽ�����γ̳�ͻ
            {
                printf("\n\t---------------------------------------------------------------------");
                printf("\n\t��ʾ%d: ���Ǽ�鵽���Ŀα���(", tips++);
                for (j = 0; j < conflict; j++)
                {
                    printf("%d,", conjunction[j]);
                }
                printf("\b)�� ����%d ��%d��\n\n\t\t\"%s\" �� \"%s\"  ���ڳ�ͻ!\n",temp[i].classTime/10, temp[i].classTime%10, temp[i].name, temp[i + 1].name);
                printf("\n\t\t--------������ʱ��������Ȼ��Ӱ�����Ŀγ̾�׼��----------\n");
                printf("\t---------------------------------------------------------------------\n");
            }
        }
    }
}


int getConjunction(int *a, int *b, int *c)//���������򼯺ϵĽ���
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
	for (i = 0; *(src + i) != '<' && *(src + i) != '>'; i++)//��ȡHTML���ų�<��>
		dest[i] = *(src + i);
	dest[i] = '\0';
}


void initializeFile()//�����û��ֶ������ļ�
{
    system("cls");
	struct inputUnit
	{
		char name[40];
    	char location[20];
    	char classTime[5];
    	char weekRange[50];
	}input[35];

	printf("\t���������������γ̱��ļ�\n");
	printf("���������Ŀ�ѧʱ��:\n(��ʽ��\"20130823\",����Ϊ8): ");
	char startTime[10];
	scanf("%s", startTime);

	int i = 0;
	while (1)
	{
		printf("\n\t�����������%d��¼\n---------------------------------\n", i + 1);
		printf("�γ�����:\n(����null��ֹ�������): ");
		scanf("%s", input[i].name);
		if (strcmp(input[i].name, "null") == 0)
            break;

		printf("�Ͽεص�:(����ط�): ");
		scanf("%s", input[i].location);

		printf("�Ͽ�ʱ��:\n(�����ں��Ͽνڴ����,������3��5�ھ�����\"3-5\"): ");

		scanf("%s", input[i].classTime);
		while (1)
		{
			if (checkInputData(input[i].classTime) == 1 && strlen(input[i].classTime) == 3)
				break;
			else
			{
				printf("��������Ͽ�ʱ������,����������: ");
				scanf("%s", input[i].classTime);
			}
		}

		printf("�Ͽε�����:\n(���뷶Χ,����\"1-16\",����ÿ������\"1,2,3,12\",���߻��������\"1-4,5-7,12,37\"): ");
		scanf("%s", input[i].weekRange);
		while (1)
		{
			if (checkInputData(input[i].weekRange) == 1 )
				break;
			else
			{
				printf("����������������ϸ�ʽҪ��,����������: ");
				scanf("%s", input[i].weekRange);
			}
		}

		i++;
	}
	///////////������ɺ�д���ļ�//////////////

    int j;
    printf("\n--------------------------------------------------------------------\n");
    printf("�Ͽ�ʱ��: %s\n", startTime);
    for (j = 0; j < i; j++)
    {
        printf("%-25s    %-18s    %-4s    %-20s\n", input[j].name, input[j].location, input[j].classTime, input[j].weekRange);
    }
    printf("--------------------------------------------------------------------\n");

    printf("ȷ������������Ŀγ���Ϣ(y/^y):");
    char conform;
    getchar();
    scanf("%c", &conform);
    if (conform == 'y' || conform == 'Y')
    {
        FILE *fp = fopen("syllabus.dat", "w");
        if (fp == NULL)
        {
            printf("��ĶԲ����ļ���������");
            exit(0);
        }

        fprintf(fp, "%s%s\n", "��ѧʱ��: ", startTime);
        for (j = 0 ; j < i; j++)
            fprintf(fp, "%-25s    %-18s    %-4s    %-20s\n", input[j].name, input[j].location, input[j].classTime, input[j].weekRange);

        fclose(fp);

        printf("д�����! ���ڷ�����Ŀ¼...\n");
        Sleep(3000);
        main();
    }
    else
    {
        printf("�����Ѿ��жϣ������˳�...");
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
        printf("δ�ڳ�����Ŀ¼�ҵ��α�");
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
    int delNum = -100;//Ҫɾ���Ŀγ̱���
    char noSense[10];
    char startTime[10];

    fscanf(fp, "%s%s", noSense, startTime);
    printf("\n��ѧʱ��: %s", startTime);

    int i = 0;

    while (!feof(fp))
    {
        fscanf(fp, "%s%s%s%s", read[i].name, read[i].location, read[i].classTime, read[i].weekRange);
        i++;
    }
    fclose(fp);

    recordsCount = i - 1;
    i = 0;
    printf("\n��� �γ�����                      �Ͽ�λ��       �Ͽ�ʱ��   ��  ��  ��\n");
    printf("------------------------------------------------------------------------------------\n");
    while (i < recordsCount)
    {
        printf("%2d: %-25s    %-16s    %-4s    %-20s\n", i+1, read[i].name, read[i].location, read[i].classTime, read[i].weekRange);
        i++;
    }
    printf("------------------------------------------------------------------------------------\n");
    printf("\t\t\t����������ǰ�Ŀγ���Ϣ��\n");

    printf("\n�����Ŀ�밴1,ɾ����Ŀ�밴2,�޸���Ŀ�밴3:\n");


    printf("��ѡ��:");
    int operation;
    scanf("%d", &operation);
    while (1)
    {
        if (operation >=1 && operation <= 3)
            break;
        else
        {
            printf("����ѡ���ڷ�Χ��,����������: ");
            scanf("%d", &operation);
        }
    }


    if (operation == 1)
    {
        //���һ���¼�¼���ļ�ĩβ
        printf("��������ӵ�%d����¼...\n", recordsCount + 1);
        printf("�γ�����:\n(����null��ֹ�������): ");
		scanf("%s", read[recordsCount].name);

		printf("�Ͽεص�:(����ط�): ");
		scanf("%s", read[recordsCount].location);

		printf("�Ͽ�ʱ��:\n(�����ں��Ͽνڴ����,������3��5�ھ�����\"3-5\"): ");

		scanf("%s", read[recordsCount].classTime);
		while (1)
		{
			if (checkInputData(read[recordsCount].classTime) == 1 && strlen(read[recordsCount].classTime) == 3)
				break;
			else
			{
				printf("��������Ͽ�ʱ������,����������: ");
				scanf("%s", read[recordsCount].classTime);
			}
		}

		printf("�Ͽε�����:\n(���뷶Χ,����\"1-16\",����ÿ������\"1,2,3,12\",���߻��������\"1-4,5-7,12,37\"): ");
		scanf("%s", read[recordsCount].weekRange);
		while (1)
		{
			if (checkInputData(read[recordsCount].weekRange) == 1 )
				break;
			else
			{
				printf("����������������ϸ�ʽҪ��,����������: ");
				scanf("%s", read[recordsCount].weekRange);
			}
		}

		recordsCount++;//����������һ��
    }


    if (operation == 2)
    {
        //ɾ��ָ����ŵĿγ̼�¼
        printf("��������ӵ�%d����¼...\n", recordsCount);
        printf("��������Ҫɾ���Ŀγ̱��(1-%d):", recordsCount);
        scanf("%d", &delNum);
        while (1)
        {
            if (delNum <= recordsCount && delNum >= 1)
                break;
            else
            {
                printf("������ı�Ų�����,����������:");
                scanf("%d", &delNum);
            }
        }

        printf("\n�γ�����                    �Ͽ�λ��      �Ͽ�ʱ��  ��    ��    ��\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("%-25s    %-12s    %-4s    %-20s\n", read[delNum - 1].name, read[delNum - 1].location, read[delNum - 1].classTime, read[delNum - 1].weekRange);
        printf("\b-------------------------------------------------------------------------------------\n");

        printf("������ɾ�����ϼ�¼(y/^y): ");
        char ch;
        getchar();
        scanf("%c", &ch);
        if (ch == 'y')
        {
            printf("\n����ɾ��...\n");
            delNum -= 1;
        }
        else
            delNum = -100;
    }


    if (operation == 3)
    {
        //�޸�ָ����ż�¼����Ϣ
        printf("\n��������ҪҪ�޸Ŀγ�ǰ��ı��(1-%d): ", length);

        int num;
        scanf("%d", &num);
        while (1)
        {
            if (num <= 0 || num > recordsCount)
            {
                printf("������Ŀγ̺�û����Ч��Χ��,����������: ");
                scanf("%d", &num);
            }
            else
                break;
        }

    	printf("\n�γ�����                    �Ͽ�λ��      �Ͽ�ʱ��  ��    ��    ��\n");
    	printf("-------------------------------------------------------------------------------------\n");
    	printf("%-25s    %-12s    %-4s    %-20s\n", read[num - 1].name, read[num - 1].location, read[num - 1].classTime, read[num - 1].weekRange);
    	printf("\b-------------------------------------------------------------------------------------\n");
    	printf("\t\t   ----�������޸����Ͽγ���Ϣ----\n");

	//    printf("\t\t\t�޸Ŀ�ѧ�����밴 0:\n");
   	 	printf("\t\t\t�޸Ŀγ������밴 1:\n");
   	 	printf("\t\t\t�޸��Ͽεص��밴 2:\n");
   	 	printf("\t\t\t�޸��Ͽ�ʱ���밴 3:\n");
   	 	printf("\t\t\t�޸��Ͽ������밴 4:\n");
   	 	printf("\t\t\t    ��������ѡ��:");


    	int choose;
    	char newInfo[40];
    	int conform;
    	scanf("%d", &choose);
    	switch(choose)
    	{

		/*    case 0:
    	    printf("\t\t\t\n�������޸Ŀ�ѧʱ��...\n");
        	printf("�����µĿ�ѧʱ��: ");
        	scanf("%s", newInfo);
        	printf("ȷ���޸�Ϊ��%s (y/^y)?: ", newInfo);

        	scanf("%d", &conform);
        	if (conform == 'y');
        	strcpy(startTime, newInfo);
        	break;*/

    	case 1:
    	    printf("\t\t\t\n�������޸Ŀγ�����...\n");
    	    printf("�����µ�����: ");
    	    scanf("%s", newInfo);
    	    printf("ȷ���޸�Ϊ��%s (y/^y)?: ", newInfo);

    	    scanf("%d", &conform);
    	    if (conform == 'y');
    	    strcpy(read[num - 1].name, newInfo);
    	    break;

    	case 2:
    	    printf("�������޸��Ͽεص�...\n");
    	    printf("�����µ��Ͽεص�: ");
    	    scanf("%s", newInfo);
    	    printf("ȷ���޸�Ϊ��%s (y/^y)?: ", newInfo);

        	scanf("%d", &conform);
        	if (conform == 'y');
        	strcpy(read[num - 1].location, newInfo);
        	break;

    	case 3:
        	printf("�������޸��Ͽ�ʱ��...\n");
        	printf("�µ��Ͽ�ʱ��(���ڼ�-�ڴ�,���� \"3-2\"): ");
        	scanf("%s", newInfo);
        	while (1)
			{
				if (checkInputData(newInfo) == 1 && strlen(newInfo) == 3)
					break;
				else
				{
					printf("��������Ͽ�ʱ������,����������: ");
					scanf("%s", newInfo);
				}
			}

        	printf("ȷ���޸�Ϊ��%s (y/^y)?: ", newInfo);

        	scanf("%d", &conform);

        	if (conform == 'y');
        	strcpy(read[num - 1].classTime, newInfo);
        	break;

    	case 4:
    	    printf("�������޸��Ͽ���...\n");
    	    printf(" 1 �����Ը���������Χ \"1-7\" ��ʾ1��7���п�;");
            printf("\n 2 ������������Χ�� \"1-3,4-7\" ��ʾ1��3��4-7���п�;");
            printf("\n 3 �������е������� \"1,2,3,4\" ��ʾ1,2,3,4���п�;");
            printf("\n 4 Ҳ�ɻ�����뷶Χ�뵥�� \"2-4,6-9,12,17\" ��ʾ2,3,4,6,7,8,9,12,17���п�;");
            printf("\n�������µ��Ͽ���: ");
    	    scanf("%s", newInfo);
    	    printf("ȷ���޸�Ϊ��% (y/^y)?: ", newInfo);

    	    scanf("%d", &conform);
    	    while (1)
			{
				if (checkInputData(newInfo) == 1)
					break;
				else
				{
					printf("��������Ͽ���������,����������: ");
					scanf("%s", newInfo);
				}
			}

 	       	if (conform == 'y');
	        strcpy(read[num - 1].weekRange, newInfo);
	        break;
	    }
    }


    //д���޸�֮��ļ�¼
    fp = fopen("syllabus.dat", "w");
    if (fp == NULL)
    {
        printf("��ĶԲ����ļ���������");
        exit(0);
    }

    fprintf(fp, "%s%s\n", "��ѧʱ��: ", startTime);
    int j;
    for (j = 0 ; j < recordsCount; j++)
    {
        if (j != delNum)
            fprintf(fp, "%-25s    %-18s    %-4s    %-20s\n", read[j].name, read[j].location, read[j].classTime, read[j].weekRange);
    }

    printf("�����ɹ����!\n");
    getchar();
    printf("���ڷ�����Ŀ¼...");
    Sleep(3000);
    fclose(fp);
    main();
}
