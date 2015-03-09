#include <iostream>
#include <string>
using namespace std;

class Teacher;//声明类

class Student
{
public:
	Student(){};
	~Student(){}
	Student(string num, string name, double sc):stuname(name), stunum(num), score(sc){}
	void set_stunum(string);
	void set_stuname(string);
	void set_score(double);
	friend double sum(Student t);
	friend int find(Student *, int, string);//函数重载
	friend class Teacher;
	void Print_Student();
	int static Student_count;
	double static total_score;
private:
	string stunum;
	string stuname;
	double score;
};

int Student::Student_count = 0;
double Student::total_score = 0;

void Student::set_stunum(string n)
{
	stunum = n;
	Student_count++;
}

void Student::set_stuname(string n)
{
	stuname = n;
}

void Student::set_score(double n)
{
	score = n;
	total_score += score;
}

void Student::Print_Student()
{
	cout << "stunum: " << stunum << endl;
	cout << "stuname: " << stuname << endl;
	cout << "score: " << score << endl;
	cout << "-----------------" << endl;
}

class Teacher
{
public:
	Teacher();
	~Teacher(){};
	Teacher(string nu, string na):name(na), num(nu){}
	void Modify(Student &);
	void Modify(Student *, int);
private:
	string name;
	string num;
};

int find(Student *t, int count, string stuname)
{
	for (int i = 0; i < count; ++i)
	{
		if (stuname == t[i].stuname)
		{
			return i;
		}
	}
	exit(1);
}

void Teacher::Modify(Student *s, int count)
{
	string sname;
	int index;
	double newscore;
	cout << "now you are teache: " << name << "\nplease input stuname: "; 
	cin >> sname;
	index = find(s, count, sname);
	s[index].Print_Student();
	cout << "\nplease input a new score for " << s[index].stuname << ": "; 
	Student::total_score -= s[index].score;
	cin >> newscore;
	s[index].score = newscore;
	Student::total_score += newscore;
	cout << "score have been changled\n" << endl;
}


void Teacher::Modify(Student &s)
{
	double newscore;
	cout << "now you are teache: " << name << "\nplease a new score: "; 
	cin >> newscore;
	s.score = newscore;
	cout << "score have been changled\n" << endl;
}

int main()
{  
	/*只要一个人的时候

	Student stu("101","wangyi",80);
	stu.Print_Student();
	Teacher t("t101","wusan");
	t.Modify(stu);
	stu.Print_Student();
	*/

	/*有一群学生的时候*/
	string num, name;
	int i = 0;
	double score;
	Student *sary = new Student[100];
	cout << "you can totally input 100 students' info, the process will break when score == 0" << endl;
	while (1)
	{
		cin >> num >> name >> score;

		if (score == 0)
			break;

		sary[i].set_stunum(num);
		sary[i].set_stuname(name);
		sary[i].set_score(score);

		i++;
	}

	Teacher t("t101","wusan");
	t.Modify(sary, Student::Student_count);
	for (int i = 0; i < Student::Student_count; ++i)
	{
		sary[i].Print_Student();
	}

	cout << "---------------------" << endl;
	cout << "total score is: " << Student::total_score << endl;
	cout << "total Student count is: " << Student::Student_count << endl;
	cout << "average score is: " << Student::total_score/ Student::Student_count << endl;

	return 0;
}

/*测试数据
001 xiong 10
002 yang 10
003 zhang 10
004 wang 10
005 pan 10
*/
