#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<string> mysplit(string);

int main(int argc, char const *argv[])
{
	std::vector<string> v;
	string str;

	//using default test data
//	str = "love is beautiful, you also, so we all should treasure this special time";

	//input a string to split
	cout << "input a string" << endl;
	cin >> str;
	cout << str << endl;

	v = mysplit(str);
	std::vector<string>::iterator iter = v.begin();
	while (iter != v.end())
	{
		cout << *iter << endl;
		iter++;
	}
	return 0;
}

std::vector<string> mysplit(string str)
{
	string split_condition = " !.,@#$%^&*()_+";
	std::vector<string> word;
	str += " ";
	int start = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (split_condition.find(str[i]) != string::npos)
		{
			string temp = str.substr(start, i - start);
			if (temp.size() > 0)
				word.push_back(temp);
			start = i + 1;
		}
	}
	return word;
}
