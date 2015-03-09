#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student():S_num("NULL"), S_name("NULL"), S_sex('F'), S_age(0){}
	Student(string nu, string na, char s, int a):S_num(nu), S_name(na), S_sex(s), S_age(a){}
	~Student(){}
	void Display();
private:
	string S_num;
	string S_name;
	char S_sex;
	int S_age;
};

void Student::Display()
{
	cout << "student NO is : " << S_num << endl;
	cout << "student name is : " << S_name << endl;
	cout << "student sex is : "  << S_sex << endl;
	cout << "student age is : " << S_age << endl;
}


class Class
{
public:
	Class(string nu, string na, int h):C_num(nu), C_name(na), C_teach_hours(h){}
	~Class(){}
	void Display();
private:
	string C_num;
	string C_name;
	int C_teach_hours;
};

void Class::Display()
{
	cout << "class NO is: " << C_num << endl;
	cout << "class name is : " << C_name << endl;
	cout << "class teach hours is : "  << C_teach_hours << endl;
}


class Choose_Class: public Student, public Class
{
public:
	~Choose_Class(){}
	Choose_Class(string Snu, string Sna, char s, int a, string Cnu, string Cna, int h, int Cc):Student(Snu, Sna, s, a), Class(Cnu, Cna, h)
	{
		score = Cc;
	}
	void Display();
private:
	int score;
};

void Choose_Class::Display()
{
	Student::Display();
	Class::Display();
	cout << "student score is : " << score << endl;
}


int main(int argc, char const *argv[])
{
	//testing Student class
	cout << "This is a student's info" << endl;
	Student s("1111", "xiong", 'F', 110);
	s.Display();
	cout << "\n-------------------------"<< endl;

	//testing Class class
	cout << "This is class's info" << endl;
	Class c("001", "Math", 16);
	c.Display();
	cout << "\n-------------------------"<< endl;

	//The following is derived Class
	cout << "This is derived class" << endl;
	Choose_Class CS("1111", "xiong", 'F', 110,"001", "Math", 16, 100);
	CS.Display();
	cout << "\n-------------------------"<< endl;

	return 0;
}
