#include <iostream>
using namespace std;

class Student
{
private:
	int StuNum;
	int Score;
public:
	Student(int SN, int Sc):StuNum(SN), Score(Sc){} 
	void show_stunum()
	{
		cout << "StuNum is: " << StuNum << endl; 
	}

	void show_score()
	{
		cout << "Score is: " << Score << endl; 
	}

	friend int max(Student *t);
};

int max(Student *t)//max函数为Student类的友元函数，可以访问其中的私有成员
{
	int num = t->StuNum;
	int score = t->Score;
	for(int i = 0; i < 5; i++)
	{
		if(score < (t + i)->Score)
		{
			score = (t + i)->Score;
			num = (t + i)->StuNum;
		}
	}
	return num;
}

int main(int argc, char const *argv[])
{
	Student s_ary[5] = {
		Student(1,89),
		Student(2,90),
		Student(3,78),
		Student(4,98),
		Student(5,96)
	};
	Student *p = s_ary;
	for(int i = 0; i < 5; i++)
	{
		s_ary[i].show_stunum();
		s_ary[i].show_score();
		puts("");
	}

	cout << "成绩最高的是学号为: "<< max(p) << " 的学生;";
	s_ary[max(p) - 1].show_score();
	return 0;
}
