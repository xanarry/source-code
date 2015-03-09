#include <iostream>
using namespace std;

class student
{
private:
	char s_name[10];
	char s_sex;
	int s_num;
public:
	void show_info();
	void set_info();
};

void student::show_info()
{
	cout << "name = " << s_name << endl;
	cout << "sex = " << s_sex << endl;
	cout << "number = " << s_num << endl; 
}

void student::set_info()
{
	cin >> s_name;
	cin >> s_sex;
	cin >> s_num;
}

int main(int argc, char const *argv[])
{
	student stu[5];
	for(int i = 0; i < 5; i++)
	{
		stu[i].set_info();
		stu[i].show_info();
	}
	return 0;
}
