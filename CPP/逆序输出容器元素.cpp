#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	int n, len, size;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		v.push_back(n);
	}

	cout << "------------------------------------" << endl;
	for (std::vector<int>::iterator iter = v.end()- 1; iter != v.begin() - 1; iter--)
	{
		cout << *iter << " ";
	}
	cout << "\n------------------------------------" << endl;

	cout << "size = " << v.size() << endl;
	len = v.size()/sizeof(int);
	cout << "len = " << len << endl;
	return 0;
}
