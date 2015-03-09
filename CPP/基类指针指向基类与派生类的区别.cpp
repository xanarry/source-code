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
	void show()
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
	void Teacher::show()////
	{					////
		Person::show();	////基类与派生类的两个函数同名，在派生函数中应该使用类名表示区别
		cout << "TeachNum = " << TeachNum << endl;
		cout << "major = " << major << endl;
	}
};

int main(int argc, char const *argv[])
{
	cout << "----------------基类--------------------" << endl;
	Person p1("xiongyang", 'F', 21);
	p1.show();

	cout << "----------------派生类------------------" << endl;
	Teacher t1("Zhang", 'M', 12, 234123, "CS");
	t1.show();

	cout << "-------------基类指针指向基类-----------" << endl;
	Person *p2;
	p2 = &p1;
	p2->show();

	cout << "------------基类指针指向派生类-----------" << endl;
	p2 = &t1;
	p2->show();
	////////////////////////////////////////////////////////////////////////////
	//指向基类的指针无论指向基类还是基类的派生类都只能显示从属于基类部分的内容//
	////////////////////////////////////////////////////////////////////////////
	return 0;
}
