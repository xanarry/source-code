#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int main(int argc, char const *argv[])
{
	vector<int> a;
	int n;
	for (int i = 0; i < 10; i++)
	{
	//	cin >> n;
		a.push_back(i * 2);
	}

	cout << "using general iterator" << endl;
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
	{
		cout << *iter << " ";
	}

	cout << "\nusing const_iterator" << endl;
	for (vector<int>::const_iterator iter = a.begin(); iter != a.end(); iter++)
	{
		cout << *iter << " ";//if define a const_iterator the data is read-only
	//	*iter += 1;//const_iterator cannot modify the data of the vector, 
	}

	cout << "\nusing const iterator" << endl;
	cout << "\"onst vector<int> iterator inter = a.begin()\"can do nothing;" << endl;
/*	for (const vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
	{
		cout << *iter << " ";
	}*/
	return 0;
}
