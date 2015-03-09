#include <iostream>
#include <string>

using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

class Student
{
public:
	Student();
	Student(string n, char s, Date b, string a, string at);
	void display();
	void set_name();
	void set_sex();
	void set_birth();
	void set_addr();
	void set_attribute();
	void get_name();
	void get_sex();
	void get_birth();
	void get_addr();
	void get_attribute();
private:
	string name;
	char sex;
	Date birth;
	string addr;
	string atr;
};

Student::Student()
{
	name = "null";
	sex = 'F';
	birth.year = 2000;
	birth.month = 12;
	birth.day = 30;
	addr = "null";
	atr = "null";
}

Student::Student(string n, char s, Date b, string a, string at)
{
	name = n;
	sex = s;
	birth.year = b.year;
	birth.month = b.month;
	birth.day = b.day;
	addr = a;
	atr = at;
}

void Student::display()
{
	cout << "姓    名 : " << name << endl;
	cout << "性    别 : " << sex << endl;
	cout << "出生日期 : " << birth.month << "-" << birth.day << "-" << birth.year << endl;
	cout << "居住地址 : " << addr << endl;
	cout << "籍    贯 : " << atr << endl;
}

void Student::set_name()
{
	string n;
	cout << "请输入姓名 " << endl;
	cin >> n;
	name = n;
}

void Student::set_sex()
{
	char s;
	cout << "请输入性别" << endl;
	cin >> s;
	sex = s;
}

void Student::set_birth()
{
	Date d;
	cout << "请输入出生日期" << endl;
	cin >> d.year;
	cin >> d.month;
	cin >> d.day;
	birth.year = d.year;
	birth.month = d.month;
	birth.day = d.day;
}

void Student::set_addr()
{
	string a;
	cout <<"请输入新地址" << endl;
	cin >> a;
	addr = a;
}

void Student::set_attribute()
{
	string at;
	cout << "请输入籍贯" << endl;
	cin >> at;
	atr = at;
}

void Student::get_name()
{
	cout << "姓名 = " << name << endl;
}

void Student::get_sex()
{
	cout << "性别 = " << sex << endl;
}

void Student::get_birth()
{
	cout << "出生日期 =  : " << birth.month << "-" << birth.day << "-" << birth.year << endl;
}

void Student::get_addr()
{
	cout << "住址 = " << addr << endl;
}

void Student::get_attribute()
{
	cout << "籍贯 =  " << atr << endl;
}

int main(int argc, char const *argv[])
{
	Date birth;
	
	birth.year = 1994;
	birth.month = 11;
	birth.day = 18;

	Student s1("熊洋", 'F', birth, "万州/重庆", "重庆");

	s1.display();
	puts("----------------------");
	Student s2;
	s2.display();
	return 0;
}
