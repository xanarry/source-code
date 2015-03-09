#include <iostream>
#include <string>

using namespace std;

class String
{
private:
	char *p;
public:
	String()
	{
		p = NULL;
	}
	String(char *str):p(str){}
	void display()
	{
		cout << p;
	}
	friend bool operator > (String &a, String &b);
	friend bool operator < (String &a, String &b);
	friend bool operator == (String &a, String &b);
};

bool operator > (String &a, String &b)
{
	if(strcmp(a.p, b.p) > 0)
		return true;
	else 
		return false;
}

bool operator < (String &a, String &b)
{
	if(strcmp(a.p, b.p) < 0)
		return true;
	else 
		return false;
}

bool operator == (String &a, String &b)
{
	if(strcmp(a.p, b.p) == 0)
		return true;
	else 
		return false;
}

int main(int argc, char const *argv[])
{
	String str1("about");
	String str2("programming");
	cout << "str1 = "; str1.display(); cout << endl;
	cout << "str2 = "; str2.display(); cout << endl;
	cout << "if str1 > str2 ---> ";
	bool state = (str1 > str2);
	cout << state << endl;

	cout << "if str1 < str2 ---> ";
	state = (str1 < str2);
	cout << state << endl;

	cout << "if str1 == str2 ---> ";
	state = (str1 == str2);
	cout << state << endl;
	return 0;
}
