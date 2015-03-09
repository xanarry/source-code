#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string a;
	cin >> a;
	int count = 0; 
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
			count++;
	}
	cout << count << endl;
	return 0;
}