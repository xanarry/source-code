//派生类的对象可以赋值给基类//
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
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
	~Person(){}
	void show_person()
	{
		cout << "name = " << name << endl;
		cout << "sex = " << sex << endl;
		cout << "age = " << age << endl;
	} 
};

class Teacher: public Person
{
private:
	int TeachNum;
	string major;
public:
	Teacher(string n, char s, int a, int t, string m):Person(n, s, a)
	{
		TeachNum = t;
		major = m;
	}
	~Teacher(){}
	void show_teacher()
	{
		show_person();
		cout << "TeachNum = " << TeachNum << endl;
		cout << "major = " << major << endl;
	}
};

int main(int argc, char const *argv[])
{
	cout << "---------------------------" << endl;
	cout << "\"object t1\"" << endl;
	Teacher t1("xiong", 'F', 21, 13412, "ComputerScience");
	t1.show_teacher();

	cout << "---------------------------" << endl;
	cout << "\"object p1\"" << endl;
	Person p1("Tom", 'M', 34);
	p1.show_person();

	cout << "\n---------------------------" << endl;
	cout << "\"&p2 = t1\"" << endl;
	Person & p2 = t1;
	p2.show_person();

	cout << "\n---------------------------" << endl;
	cout << "\"p3 = t1\"" << endl;
	Person p3 = t1;
	p3.show_person();

	cout << "\n---------------------------" << endl;
	cout << "\"*pnt = &p1\"" << endl;
	Person *pnt;
	pnt = & p1;
	pnt->show_person();
/*
	cout << "---------------------------" << endl;
	Teacher & t2 = p1;//只能由派生类给基类对象赋值
	p1.show_teacher();
*/
	return 0;
}
