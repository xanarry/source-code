#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct student
{
//	string name;
	char name[20];//can not use a string object, it can cause a fatal error
	char sex;
	int age;
};//difine a struct include a student's basic information

student stu[6] = {"xiong", 'F', 21, "zhang", 'M', 20, "wang", 'F', 19, "Jam", 'F', 23, "Marray", 'M', 22, "Bob", 'F', 25};//struct array record three students info;

void WriteToFile()
{
	ofstream outfile("stu.txt", ios::binary | ios::out);//create a file
	if(!outfile)//judge if the new file is usable
	{
		cerr << "file error!!";
		exit(1);
	}
	for(int i = 0; i < 6; i++)//circulation
	{
		//first parameter a pionter of char type, second parameter is the size of one part of the data
		//but &stu[i] is a struct pointer so we use explicit cast turn it to char type
		outfile.write((char *)&stu[i], sizeof(stu[i]));//write one element in array each time
	}
	outfile.close();
}

void ReadFromFile()
{
	ifstream infile("stu.txt", ios::binary | ios::in);
	student t[6];
	infile.seekg(0, ios::beg);
	for(int i = 0; i < 6; i++)
	{
		infile.read((char *)&t[i], sizeof(t[i]));//ditto, just change 'write' to 'read', extract data form file to array
	}
	infile.close();
	cout << " NO " << "   name  " << "sex" << "  age" << endl;
	for(int i = 0; i < 6; i++)
	{
		cout <<"NO." << (i + 1) << ' ' << setw(6) << t[i].name << " " << setw(3)<< t[i].sex << " " << setw(4) << t[i].age << endl;//output info
	}
	cout << "-----------------------" << endl;
}

student RanReadFromFile(int n)
{
	n -= 1;
	ifstream infile("stu.txt", ios::binary | ios::in);
	student t;
	infile.seekg(n * sizeof(t), ios::beg);//remove pointer to new location
	infile.read((char *)&t, sizeof(t));//like previous function
	infile.close();

	cout << setw(6) << "name" << setw(3) << " sex" << "  age" << endl;
	cout << setw(6) << t.name << " " << setw(3) << t.sex << " " << setw(4) << t.age << endl;//output information
	cout << "-----------------------" << endl;
	return t;
}

int main(int argc, char const *argv[])
{
	
	WriteToFile();

	ReadFromFile();

	int num;
	cout << "input the NO of a student you wanna see" << endl;
	cin >> num;

	RanReadFromFile(num);
	
	return 0;
}
