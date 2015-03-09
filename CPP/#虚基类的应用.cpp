//使用虚基类的话，每个派生类的构造函数都要同时初始化基类成员
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string name;
	char sex;
	int age;
public:
	Person(string n, char s, int a)
	{
		name = n;
		sex = s;
		age = a;
	}
};

class Teacher: virtual public Person
{
protected:
	string title;
public:
	Teacher(string n, char s, int a, string t):Person(n, s, a)
	{
		title = t;
	}
};

class Student: virtual public Person
{
protected:
	float score;
public:
	Student(string n, char s, int a, float sc):Person(n, s, a)
	{
		score = sc;
	}
};

class Gradute: public Teacher, public Student
{
private:
	float wage;
public:
	Gradute(string n, char s, int a, string t, float sc, float w):Person(n, s, a), Teacher(n, s, a, t), Student(n, s, a, sc)
	{
		wage = w;
	}
	void show()
	{
		cout << "name = " << name << endl;
		cout << "sex = " << sex << endl;
		cout << "age = " << age << endl;
		cout << "score = " << score << endl;
		cout << "title = " << title << endl;
		cout << "wage = " << wage << endl;
	}
};

int main(int argc, char const *argv[])
{
	Gradute t1("xiongyang", 'F', 21, "assistant", 98, 123.7);
	t1.show();
	return 0;
}
