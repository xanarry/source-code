#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main(int argc, char const *argv[])
{
	vector<string> v1(10, "xiongyang");
	vector<string> v2(v1);
	vector<int> v3(10);
	cout << "v1 totally has " << v1.size() << " element!" << endl;
	for(vector<string>::size_type i = 0; i != v1.size(); i ++)
	{
		cout << i + 1 << " " << v1[i] << endl;
	}
	cout << "\nv2 is a copy of v1" << endl;
	for(vector<string>::size_type i = 0; i != v1.size(); i ++)
	{
		cout << i + 1 << " " << v2[i] << endl;
	}

	cout << "\nthe size of v3 is " << v3.size() << endl;
	cout << "all the element has been initialized by 0" << endl;
	for(vector<int>::size_type i = 0; i != v1.size(); i ++)
	{
		cout << i + 1 << " " << v3[i] << endl;
	}
	return 0;
}
