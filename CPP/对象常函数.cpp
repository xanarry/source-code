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

void Student::Add()
{
	cout << "total score is : " << math + english + program << endl;
}

void Student::Modify(string m) const
{
	cout << "new name is :" << m << endl;
//	name = m;//定义的常函数不能修改对象成员的值，只能引用,所以使用该句会出错
	cout << "old name is :" << name << endl;
}

int main(int argc, char const *argv[])
{
	string n, tmp;
	int m,e,p;
	cout << "input name, math, english and program score:" << endl;
	cin >> n >> m >> e >> p;
	Student s1(n, m, e, p);
	s1.Show_Info();
	s1.Add();
	cout << "input a new name: ";
	cin >> tmp;
	s1.Modify(tmp);
	s1.Show_Info(); 
	return 0;
}
