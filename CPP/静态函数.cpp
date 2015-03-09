#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int age;
	float score;
	static float sum;//定义静态变量sum
	static int count;//定义静态变量sum
public:
	Student(string n, int a, float s):name(n), age(a), score(s){}
	void total();
	static float average();//定义静态函数计算平均分
};

void Student::total()
{
	sum += score;//每次将这个对象中的值加到静态变量sum中
	count++;
}

float Student::average()//定义静态函数，在函数定义时不需要加static关键词
{
	return (sum/count);//使用的是静态变量
}

float Student::sum = 0;
int Student::count = 0;//设定默认值

int main(int argc, char const *argv[])
{
	Student stud[3] = {
		Student("xiong", 21, 89),
		Student("zhang", 20, 90),
		Student("wang", 19, 98)
	};
	//定义对象数组
	int n;
	cout << "input the number of student:";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		stud[i].total();//调用函数将数值加到静态变量
	}
	cout << "average score is: " << Student::average() << endl;//输出平均值
	return 0;
}
