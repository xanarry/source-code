#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string a;
	cout << "please input a string" << endl;
	cin >> a;
	//is particularly important not to assign the return form 'size' to an 'int'
	for(string::size_type i = 0; i != a.size(); i++)//using the type of the library defines
	{
		a[i] -= 32;
	}
	cout << a;
	return 0;
}
