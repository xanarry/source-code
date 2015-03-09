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

class Student:private basicStudent
{
private:
	int age;
	string major;
public:	
	Student(){};
	~Student(){};//构造函数
	void display1()
	{
		display();//私有继承只能使用基类（公有）函数
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
	void set_p(string n, char s)//这个函数再次引用基类中的公用函数去实现初始化，
	//////////////////////////////因为私有继承后无法直接通过派生对象访问基类公用函数
	{
		set_name(n);
		set_sex(s);
	}
};///////////////////////////////派生类中禁止访问基类的私有成员，只能访问共有函数

int main(int argc, char const *argv[])
{
	Student s2;
//	s2.set_name("xiong");
//	s2.set_sex('F');//私有继承，禁止通过派生类的对象访问私有基类的所有成员及函数
	s2.set_p("xiong", 'F');//
	s2.set_major("sotfware_engineer");
	s2.set_age(21);
	s2.display1();
	return 0;
}
