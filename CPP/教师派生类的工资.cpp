/*
describe:
	定义一个教师类，由教师类派生出讲师(lecturer)、副教授
	(associate professor)、教授(professor)类。教师的工资
	分别由基本工资、课时费和津贴构成。假设讲师、副教授、
	教授的基本工资分别为800、900、1000元，课时费分别为每
	小时40、45、50元，津贴分别为1300、1800、2300。定义虚
	函数来计算教师的工资，并通过主函数来进行验证。
date: 
	2014/6/8 
*/
#include <iostream>
#include <string>

using namespace std;

class Teacher
{
public:
	Teacher(){}
	~Teacher(){}
	virtual int CalSalary(){}
	virtual void DisplaySalary(){}
protected:
	int BasicSalary, ClassFee, Wellfare;
};

class Lecturer: public Teacher
{
public:
	Lecturer(int time)
	{
		BasicSalary = 800;
		ClassFee = time * 40;
		Wellfare = 1300;
	}
	~Lecturer(){}
	virtual int CalSalary()
	{
		return BasicSalary + ClassFee + Wellfare;
	}
	virtual void DisplaySalary(){cout << "Lecturer: " << CalSalary() << endl;}
};

class AssociateProfessor: public Teacher
{
public:
	AssociateProfessor(int time)
	{
		BasicSalary = 900;
		ClassFee = time * 45;
		Wellfare = 1800;
	}
	~AssociateProfessor(){}
	virtual int CalSalary()
	{
		return BasicSalary + ClassFee + Wellfare;
	}
	virtual void DisplaySalary(){cout << "AssocialteProfessor: " << CalSalary() << endl;}
};

class Professor: public Teacher
{
public:
	Professor(int time)
	{
		BasicSalary = 1000;
		ClassFee = time * 50;
		Wellfare = 2300;
	}
	~Professor(){}
	virtual int CalSalary()
	{
		return BasicSalary + ClassFee + Wellfare;
	}
	virtual void DisplaySalary(){cout << "Professor: " << CalSalary() << endl;}
};

int main(int argc, char const *argv[])
{
	Teacher *ptr = new Teacher;

	Lecturer L(24);
	ptr = &L;
	ptr->DisplaySalary();

	AssociateProfessor AP(24);
	ptr = &AP;
	ptr->DisplaySalary();

	Professor P(24);
	ptr = &P;
	ptr->DisplaySalary();

	return 0;
}

