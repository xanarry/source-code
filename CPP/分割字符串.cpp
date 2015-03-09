#include <iostream>
#include <string>
#include <vector>

using namespace std;
std::vector<string> split(string str, string pattern)
{
	str += pattern;
	std::vector<string> result;
	std::vector<string>::size_type pos;
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			string tmp = str.substr(i, pos - i);
			result.push_back(tmp);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	cout << "ÊäÈë×Ö·û´®:" << endl;
	string str;
	getline(cin, str);

	cout << "ÊäÈë·Ö¸î×Ö·û:" << endl;
	string pattern;
	cin >> pattern;

	std::vector<string> v;
	v = split(str, pattern);

	std::vector<string>::iterator iter = v.begin();
	while (iter != v.end())
	{
		cout << *iter << endl;
		iter++;
	}
	return 0;
}
