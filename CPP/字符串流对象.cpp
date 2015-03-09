#include <strstream>
#include <iostream>
using namespace std;

struct student
{
	string name;
	char sex;
	int age;
};//difine a struct include a student's basic information

int main(int argc, char const *argv[])
{
	student stu[6] = {"xiong", 'F', 21, "zhang", 'M', 20, "wang", 'F', 19, "Jam", 'F', 23, "Marray", 'M', 22, "Bob", 'F', 25};
	char c[6 * sizeof(stu[0])];
	ostrstream ostr(c, 6 * sizeof(stu[0]));
	for(int i = 0; i < 6; i++)
	{
		ostr << stu[i].name<< ' ' << stu[i].sex << ' ' << stu[i].age;
	}
	ostr << ends;
	cout << "array is\n" << c << endl;
	istrstream istr(c, 6 * sizeof(stu[0]));
	return 0;
}
