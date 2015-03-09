#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
	char c[][11] = {{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-'}, {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '0'},{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '0', '0'}, {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '0', '0', '0'}};
	char input;
	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			c[i][j] = toupper(c[i][j]);
		}
	}
	cin >> input;
	input = tolower(input);
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (input == tolower(c[i][j]))
			{
				cout << c[i -1 ][j] << " " << c[i - 1][j + 1] << endl;
			}
		}
	}
	return 0;
}