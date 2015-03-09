#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	std::map<string, int> m;
	string word;
	while (cin >> word)
	{
		++m[word];
	}
	std::map<string, int>::iterator iter = m.begin();
	for (; iter != m.end(); iter++)
	{
		cout << iter->first << ":" << iter->second << endl;
	}
	return 0;
}
