#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

class Score
{
private:
	string stunum;//students' number
	string name;//students' name
	double score1;//score1
	double score2;//score2
	double score3;//score3
	double final_score;//the final scroe calculated by a rule
public:
	Score(){}//default constructor used to difine a object array
	~Score(){}
	//get each item input
	void set_name()
	{
		cin >> name;
	}
	void set_stunum()
	{
		cin >> stunum;
	}
	void set_score1()
	{
		cin >> score1;
	}
	void set_score2()
	{
		cin >> score2;
	}
	void set_score3()
	{
		cin >> score3;
	}
	void calculate_final_score()//the rule to calculate the final score
	{
		final_score = 0.1*score1 + 0.2*score2 + 0.7*score3;
	}
	void display()
	{
		cout << stunum << " " << name << " ";//because a string object can't output by "printf()"
		printf("%.2f", final_score);//to control it output 2 decimal(xiaoshu)
		cout << endl;
	}
	bool operator < (const class Score t) const
	{
		return final_score > t.final_score;//reload operator '<' for sort to sort the object array by final score
	}
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Score *a = new Score[n];
	for (int i = 0; i < n; ++i)
	{
		a[i].set_stunum();
		a[i].set_name();
		a[i].set_score1();
		a[i].set_score2();
		a[i].set_score3();
		a[i].calculate_final_score();
	}

	sort(a, a+n);
	cout << "---------after conduct---------" << endl;
	for (int i = 0; i < n; ++i)//output the students' info by final score descendly
	{
		a[i].display();
	}
	return 0;
}

