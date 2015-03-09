#include <iostream>
#include <string>
using namespace std;

class basicStudent
{
private:
	string name;
	char sex;
public:
	basicStudent(){};
	~basicStudent(){};
	void display()
	{
		cout << "name = " << name << endl << "sex = "<< sex << endl;
	}
	void set_name(string n)
	{
		name = n;
	}
	void set_sex(char s)
	{
		sex = s;
	}
};
//////////////定义基类

//使用共有继承
class Student:public basicStudent
{
private:
	int age;
	string major;
public:	
	Student(){};
	~Student(){};//构造函数
	void display1()
	{
		display();//共有继承能够使用基类公有函数
		cout << "age = " << age << endl;
		cout << "major = " << major << endl;
	}
	void set_age(int a)//output info
	{
		age = a;
	}
	void set_major(string m)//output info
	{
		major = m;
	}
};

int main(int argc, char const *argv[])
{
	Student s2;
	s2.set_name("xiong");
	s2.set_sex('F');//如果为私有继承，这两句不能通过编译

	s2.set_major("sotfware_engineer");
	s2.set_age(21);
	s2.display1();
	return 0;
}
