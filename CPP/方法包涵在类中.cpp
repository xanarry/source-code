#include <iostream>
#include <string>

using namespace std;

class car
{
private:
	string trademark;
	string owner;
public:
	void output()
	{
		cout << "it is " << trademark << "car" <<endl;
		cout << "and it's owner is " << owner << endl;
	}
	
	void inputinto()
	{
		cout << "please input trademark and owner:";
		cin >> trademark >> owner;
	}
};

int main(int argc, char const *argv[])
{
	car benz;
	benz.inputinto();
	benz.output();
	return 0;
}
