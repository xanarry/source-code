#include <iostream>
#include <string>
using namespace std;

class Score
{
public:
	Score(){};
	~Score(){}
	Score(string num, string name, int sc);
	int input();
	void display();
	friend double average();
 	int static count;
 	int static sum;
private:
	string stunum;
	string stuname;
	int score;
};

int Score::count = 0;
int Score::sum = 0;

int Score::input()
{
	cin >> stunum >> stuname >> score;
	if (score == 0)
		return 0;
	Score::count++;
	Score::sum += score;
	return 1;
}

double average()
{
	return (double)Score::sum/(double)Score::count;
}

void Score::display()
{
	cout << "stunum: " << stunum << endl;
	cout << "stuname: " << stuname << endl;
	cout << "score: " << score << endl;
	cout << "-----------------" << endl;
}

int main(int argc, char const *argv[])
{
	int i = 0;
	Score s[50];
	cout << "when score is equal to 0, the input operation will break" << endl;
	while (1)
	{
		if(s[i].input())
			i++;
		else
			break;
	}
	cout << "total = " << Score::sum << endl;
	cout << "count = " << Score::count << endl;
	cout << "average = " << average() << endl;
	return 0;
}
