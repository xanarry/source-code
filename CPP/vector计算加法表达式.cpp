#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int main(int argc, char const *argv[])
{
	vector<long> v;
	long sum = 0, n;
	char c = '+';
	cout << "please input a addition expression like \"1+2+3\", \"Ctrl+z\" to stop" << endl;
	while(cin >> n)
	{
		v.push_back(n);//get a addition expression
	}
	for(vector<long>::size_type i = 0; i != v.size(); i++)
	{
		sum += v[i];
		if(i == v.size() - 1)
			c = '=';
		cout << v[i] << c;//output the expression
	}
	cout << sum << endl;
	return 0;
}
