#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	string b;
	cin >> a >> b;
	if(a.find(b) != string::npos)
		cout << "Yes";
	else 
		cout << "No";
	return 0;
}
