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

class Student2: public Student1
{
private:
	string hobby;
	string major;
public:
	void show_info2()
	{
		show_info1();
		cout << "\nother info is" << endl;
		cout << "hobby is " << hobby << endl;
		cout << "major is " << major << endl;
	}
	Student2(string h = "hobby", string m = "major", string name, int s, string name1, int s1, int a):Student1(name, s, name1, s1, a)
	{
		hobby = h;
		major = m;
	}
};

int main(int argc, char const *argv[])
{
	Student2 s("computer", "software engineer", "xiongyang", 100, "fanghua", 98, 21);
	s.show_info2();
	return 0;
}
