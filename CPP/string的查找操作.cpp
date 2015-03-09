#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string a("ab2c3d7R4E6");
	string numbers("0123456789");
	string::size_type pos = 0;
	if (pos = a.find("2c3"))
	{
		cout << "find it's index is: " << pos << endl;
	}
	
	cout << "numbers is" << endl;
	while ((pos = a.find_first_of(numbers, pos)) != string::npos)
	{
		cout << "find number at index:" << pos << "element is:" << a[pos] << endl;
		pos++;
	}

	pos = 0;
	cout << "alphas is " << endl;
	while ((pos = a.find_first_not_of(numbers, pos)) != string::npos)
	{
		cout << "find number at index:" << pos << "element is:" << a[pos] << endl;
		pos++;
	}
	return 0;
}
