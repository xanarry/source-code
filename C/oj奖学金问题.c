/********************************
描述Descript.
    某校的惯例是在每学期的期末考试之后发放奖学金。发放的奖学金共有五种，
	获取的条件各自不同：
    1)  院士奖学金，每人8000元，期末平均成绩高于80分（>80），
	并且在本学期内发表1篇或1篇以上论文的学生均可获得；
    2)  五四奖学金，每人4000元，期末平均成绩高于85分（>85），
	并且班级评议成绩高于80分（>80）的学生均可获得；
    3)  成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）
	的学生均可获得；
    4)  西部奖学金，每人1000元，期末平均成绩高于85分（>85）
	的西部省份学生均可获得；
    5)  班级贡献奖，每人850元，班级评议成绩高于80分（>80）
	的学生干部均可获得；
    只要符合条件就可以得奖，每项奖学金的获奖人数没有限制，每
	名学生也可以同时获得多项奖学金。例如姚林的期末平均成绩是87分，
	班级评议成绩82分，同时他还是一位学生干部，那么他可以同时获得
	五四奖学金和班级贡献奖，奖金总数是4850元。
    现在给出若干学生的相关数据，请计算哪些同学获得的奖金总数最高
	（假设总有同学能满足获得奖学金的条件）。
	
输入Input
输入的第一行是一个整数N（1 <= N <= 100），表示学生的总数。
接下来的N行每行是一位学生的数据，从左向右依次是姓名，期末平均成绩，
班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论文数。
姓名是由大小写英文字母组成的长度不超过20的字符串（不含空格）；期末平
均成绩和班级评议成绩都是0到100之间的整数（包括0和100）；是否是学生干部
和是否是西部省份学生分别用一个字符表示，Y表示是，N表示不是；发表的论文
数是0到10的整数（包括0和10）。每两个相邻数据项之间用一个空格分隔。

输出Output
输出包括三行，第一行是获得最多奖金的学生的姓名，第二行是这名学生获得
的奖金总数。如果有两位或两位以上的学生获得的奖金最多，输出他们之中在输入
文件中出现最早的学生的姓名。第三行是这N个学生获得的奖学金的总数。
*********************************/
#include<stdio.h>
int main()
{
	struct student
    {
	 char name[20];
	 int  ave_score;
	 int  c_score;
	 char ganbu;
	 char west;
	 int  lunwen;
    };
	int n,i,flag;
	long sum[100],s = 0;
	struct student std[100];
	scanf("%d",&n);
	for(i = 0; i < n; i++)
    sum[i] = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%s %d %d %c %c %d",std[i].name,&std[i].ave_score,&std[i].c_score,&std[i].ganbu,&std[i].west,&std[i].lunwen);
	}
	for(i = 0; i < n; i++)
    {
    	if((std[i].ave_score > 80) && (std[i].lunwen >= 1)) 
		   sum[i] += 8000;
    	if((std[i].ave_score > 85) && (std[i].c_score > 80)) 
		   sum[i] += 4000;
    	if(std[i].ave_score > 90)
		   sum[i] += 2000;
    	if((std[i].ave_score > 85)&&std[i].west == 'Y') 
		   sum[i] += 1000;
    	if((std[i].c_score > 80) && (std[i].ganbu == 'Y')) 
		   sum[i] += 850;
    }
    int max = sum[0];
    for(i = 0; i < n; i++)
    {
    	s += sum[i];
    }
    for(i = 0; i < n; i++)
    {
    	if(sum[i] > max)
    	{
    		max = sum[i];
    		flag = i;
    	}
    }
    printf("%s\n%d\n%d",std[flag].name,max,s);
}

