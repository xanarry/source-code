#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
	int num;
	string name;
	float score;
public:
	Student(int, string, float);
	/*virtual*/ void display();//确定是否为虚函数
};

Student::Student(int n, string na, float s)
{
	num = n;
	name = na;
	score = s;
}

void Student::display()
{
	cout << "num = " << num << endl;
	cout << "name = " << name << endl;
	cout << "score = " << score << endl;
}

class Graduate: public Student
{
private:
	float pay;
public:
	Graduate(int, string, float, float);
	void display();
};

Graduate::Graduate(int n, string na, float s, float p):Student(n, na, s)
{
	pay = p;
}

void Graduate::display()
{
	cout << "num = " << num << endl;
	cout << "name = " << name << endl;
	cout << "score = " << score << endl;
	cout << "pay = " << pay << endl;
}

int main(int argc, char const *argv[])
{
	Student s(111, "xiong", 89), *p;
	s.display();
	cout << "---using pointer---" << endl;
	p = &s;
	p->display();

	cout << "---------------------------------" << endl;
	Graduate g(222, "yang", 99, 10000), *p1;
	g.display();
	cout << "---using pointer---" << endl;
	p1 = &g;
	p1->display();

	cout << "----------------------------------" << endl;
	cout << "---using basic class pointer point to derived class---" << endl; 
	p = &g;
	p->display();//如果将13行的函数定义为虚函数，则会输出所有信息，如果不是虚函数，则只输出基类所包含的信息
	cout << endl << "as you can see, basic pointer to derived class can\nonly output the info that basic class has include" << endl;
	return 0;
}
