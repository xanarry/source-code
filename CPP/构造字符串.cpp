#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
	stringstream ss;
	int i = 124;
	double d = 45.321;
	char c = 'k';
	ss << i << d << c;
	cout << ss.str() << endl;
	return 0;
}