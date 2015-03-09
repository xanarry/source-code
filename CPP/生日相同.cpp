#include <iostream>
#include <string>
using namespace std;

struct STUDENT//定义结构体
{
	string StuNum;//学号
	int Month;//出生月
	int Day;//出生日
};

int main(int argc, char const *argv[])
{
	int n, i, count[12][31] = {0};//定义count数组记录每个生日出现的次数
	STUDENT Student[1001];//
	cout << "请输入学生的个数" << endl;
	cin >> n;//输入学生个数
	cout << "请依次输入每个学生的信息" << endl;
	for (i = 0; i < n; i++)//循环输入每个学生的信息
	{
		cin >> Student[i].StuNum >> Student[i].Month >> Student[i].Day;
	}

	for (i = 0; i < n; i++)
	{
		//统计输入信息中每个生日出现的次数，并且记录在count数组中
		count[ Student[i].Month - 1 ][ Student[i].Day - 1 ]++;
		//数组的下标1是月份-1的值，下标2是日-1的值
	}

	for (i = 0; i < 12; i++)//遍历每月（0-11),下标示从0开始的
	{
		for (int j = 0; j < 31; j++)//遍历每日(0-30)，下标是从0开始的
		{
			if(count[i][j] > 1)//如果这个生日出现的次数大于了1次
			{
				cout << i + 1 << " " << j + 1 << " ";//输出这个生日
				for (int k = 0; k < n; k++)//遍历结构体数组
				{
					//寻找生日是这个日期的所有学生。输出
					if(Student[k].Month == (i + 1) && Student[k].Day == (j + 1) )
						cout << Student[k].StuNum << " ";
				}
				cout << endl;//输出换行，准备下一个生日的输出
			}
		}
	}
	return 0;
}
