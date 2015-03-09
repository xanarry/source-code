#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
	string a[5];
	int count = 0;
	cout << "input 5 string" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}
	cout << "--------------------" << endl;
	cout << "total size of a" << sizeof(a) << endl;
	cout << "size of char * is " << sizeof(char *) << endl;
	count = sizeof(a)/sizeof(char *);
	cout << "a has " << count << "members" << endl;
	cout << "--------------------" << endl;

	std::vector<string> v;
	
	v.assign(a, a + (sizeof(a)/sizeof(char*)));

	cout << "use vector" << endl;
	std::vector<string>::iterator iter = v.begin();
	for (; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	cout << "\n-----------------\nuse deque" << endl;
	std::list<string> l;

	l.assign(v.begin(), v.end());
	
	std::list<string>::iterator iterl;
	for (iterl = l.begin(); iterl != l.end(); iterl++)
	{
		cout << *iterl << endl;
	}

	cout << "\n-----------------\nuse list" << endl;
	std::deque<string> d(l.begin(), l.end());
	for (std::deque<string>::iterator iterd = d.begin(); iterd != d.end(); iterd++)
	{
		cout << *iterd << endl;
	}

	return 0;
}
