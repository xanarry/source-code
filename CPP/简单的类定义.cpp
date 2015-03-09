#include <iostream>
#include <string>
using namespace std;

class student
{
private:
	int num;
	string name;
	char sex;
public:
	void _set(int n, string nm, char s);
	void _put();
};

int main(int argc, char const *argv[])
{
	student stu1;
	stu1._set(2013023058, "xiongyang", 'F');
	stu1._put();
	return 0;
}

void student::_set(int n, string nm, char s)
{
	num = n;
	name = nm;
	sex = s;
}

 void student::_put()
{
	cout << "name is " << name <<endl;
	cout << "num is " << num << endl;
	cout << "sex is " << sex << endl;
}
