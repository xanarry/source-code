#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int sum = 0, v;
	cout << "input any numbers, ctrl + z to stop" << endl;
	while(cin >> v)
	{
		sum += v;
	}
	cout << "sum = " << sum;
	return 0;
}
