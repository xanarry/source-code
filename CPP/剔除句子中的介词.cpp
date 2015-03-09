#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<string> v;
	string obj[] = {"from", "in", "at", "an", "on"};
	cout << "input a en centence:" << endl;
	string word;
	while (cin >> word)
	{
		v.push_back(word);
	}
	int i = 0;
	std::vector<string>::iterator iter = v.begin();
	for (; iter != v.end(); iter++)
	{
		for (i = 0; i < 5; i++)
		{
			if (*iter == obj[i])
				break;
		}
		if (i == 5)
			cout << *iter << " ";
	}
	return 0;
}
