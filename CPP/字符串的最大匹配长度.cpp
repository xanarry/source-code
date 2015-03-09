#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string a, b;
	cin >> a >> b;
	if (a.length() < b.length())
	{
		string temp = a;
		a = b;
		b = temp;
	}

	int max = 0;
	int match_len = 0;
	string max_matched;
	string matched = "";

	for (int i = 0; i <= a.length(); i++)
	{
		int start = i;
		for (int j = 0; j <= b.length(); j++)
		{
			if (i != a.length() && j != b.length() && a[start++] == b[j])
			{
				match_len++;
				matched += b[j];
			}
			else 
			{
				if (match_len > max)
				{
					max = match_len;
					max_matched = matched;
				}
				match_len = 0;
				matched = "";
				continue;
			}
		}
	}
	cout << "max matched length: " << max << endl;
	cout << "max_matched is: " << max_matched << endl;
	return 0;
}

/*
kgklkasdfhjagsdfhasfg
hjgakjsdhfkjlasrg
max matched length: 2
max_matched is: ksd
请按任意键继续. . .

wetr2
asdfwrqtr


*/