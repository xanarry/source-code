#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int score;
public:
	Student(string n = "null", int s = 0)
	{
		name = n;
		score = s;
	}
	~Student(){};
	void show_info()
	{
		cout << "name  = " << name << endl;
		cout << "score = " << score << endl;
	}
};

class Student1: public Student
{
private:
	int age;
	Student monitor;
public:
	//注意构造函数，第一个是基类的构造函数，第二个是子对象的构造函数
	Student1(string name, int s, string name1, int s1, int a):Student(name, s), monitor(name1, s1)
	{
		age = a;
	}
	void show_info1()
	{
		show_info();
		cout << "\nmonitor is " << endl;
		monitor.show_info();
	}
};

int main(int argc, char const *argv[])
{
	Student1 s("xiongyang", 100, "fanghua", 98, 21);
	s.show_info1();
	return 0;
}
