#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	string name;
 	int math;
	int english;
	int program;
public:
	Student(string n, int m, int e, int p):name(n), math(m), english(e), program(p){}
	void Show_Info();
	void Add();
	void Modify(string n) const;
};

void Student::Show_Info()
{
	cout << "name : " << name << endl;
	cout << "math : " << math << endl;
	cout << "english : " << english << endl;
	cout << "program : " << program << endl;
}

int main(int argc, char const *argv[])
{
	string n;
	int m,e,p;
	cout << "input name, math, english and program score:" << endl;
	cin >> n >> m >> e >> p;
	Student s1(n, m, e, p);
	Student  * const pionter = &s1;//**指向对象的常指针只能在定义的时候赋值，常指针不能被赋值
	s1.Show_Info();
	cout << endl;
	pionter->Show_Info();
	return 0;
}
