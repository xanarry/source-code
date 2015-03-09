#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s("hello world");
	cout << s << endl;

	string s1 = s.substr(0, 5);
	cout << "string s1 = substr(0, 5): " << s1 << endl;

	string s2 = s.substr(6);
	cout << "string s2 = substr(6): " << s2 << endl;

	string s3 = s.substr(6, 110);
	cout << "string s2 = substr(6, 100): " << s3 << endl;

	//string s4 = s.substr(100);//抛出out_of_range异常
	return 0;
}
