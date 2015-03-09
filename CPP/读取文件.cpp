#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[10], max;
	ifstream infile("test.txt", ios::in);
	if(!infile)
	{
		cerr << "open file failed" << endl;
		exit(1);
	}
	for(int i = 0; i < 10; i++)
	{
		infile >> a[i];
	}
	max = a[0];
	for(int i = 1; i < 10; i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	cout << "max = " << max;
	return 0;
}
