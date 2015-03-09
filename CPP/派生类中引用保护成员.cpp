#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
	int num;
	string name;
	char sex;
public:
	void display();
};

void Student::display()
{
	cout << "name is " << name << endl;
	cout << "num is " << num << endl;
	cout << "sex is " << sex << endl;
}

//私有public，private，protected都能通过编译
class Student1: private Student
{
private:
	int age;
	string addr;
public:
	void display1();
	void set_info();
};

void Student1::display1(/*string na, int n, char s, int a, string ad*/)
{
	cout << "name is " << name << endl;
	cout << "num is " << num << endl;
	cout << "sex is " << sex << endl;
	cout << "age is " << age << endl;
	cout << "addr is " << addr << endl;
}

void Student1::set_info(/*string na, int n, char s, int a, string ad*/)
{
	cin >> name;
	cin >> num;
	cin >> sex;
	cin >> age;
	cin >> addr;
}

int main(int argc, char const *argv[])
{
	Student1 stu1;
	stu1.set_info();
	stu1.display1();
//	stu1.name = "sssssss";//保护成员也不能直接在类外部引用，只能通过类中的函数对其引用
	return 0;
}

