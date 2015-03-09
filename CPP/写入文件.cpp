#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[10];
	ofstream outfile("test.txt", ios::out);
	if(!outfile)
	{
		cerr << "open file failed" << endl;
		exit(1);
	}
	cout << "input 10 nums" << endl;
	for(int i = 0; i < 10; i++)
	{
		cin >> a[i];
		outfile << a[i] << ' ';
	}
	return 0;
}
