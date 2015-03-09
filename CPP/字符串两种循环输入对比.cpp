#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string a;
	//this method can get a hole line and output it
	while(getline(cin, a))
	{
		cout << a << endl;
	}
	//it can just get a word, and if input a line include space, the words will be separated
	while(cin >> a)
	{
		cout << a << endl;
	}
	return 0;
}
