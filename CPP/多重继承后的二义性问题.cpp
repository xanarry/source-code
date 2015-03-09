#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	string name;
	char sex;
	int age;
public:
	Student(string n, char s, int a)
	{
		name = n;
		sex = s;
		age = a;
	}
	void show()
	{
		cout << "name = " << name << endl;
		cout << "sex = " << sex << endl;
		cout << "age = " << age << endl;
	}
};

class Teacher
{
public:
	string name;
	char sex;
	string major;
public:
	Teacher(string n = "null", char s = 'F', string m = "null")//设置默认参数
	{
		name = n;
		sex = s;
		major = m;
	}
	void show()
	{
		cout << "name = " << name << endl;
		cout << "sex = " << sex << endl;
		cout << "major = " << major << endl;
	}
};

class Amanuensis: public Teacher, public Student
{
private:
	int class_each_week;
public:
	Amanuensis(string n, char s, int a, string m, int c):Student(n, s, a)//, Teacher(n, s, m)
	{
		class_each_week = c;
	}
	~Amanuensis(){}
	void show()
	{	
	//	show();//不能直接使用show函数，因为继承的两个类中都有同样的show函数，编译系统无法确定到底选择哪一个系统
		Student::show();//应当使用这样的的方法指定到具体类
		cout << "--------------------------" << endl;
		Teacher::show();
		cout << "--------------------------" << endl;
		cout << "class_each_week = " << class_each_week << endl; 
	}
};

int main(int argc, char const *argv[])
{
	Amanuensis obj("xiong", 'F', 21, "software", 12);
	obj.show();
	return 0;
}
