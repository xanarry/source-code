#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int flag;
	int tmp = 0;
	string isbn;
	cin >> isbn;
	int j;
	for (int i = 0, j = 1; i < isbn.length() - 1; i++)
	{
		if (isbn[i] != '-')
			tmp += (isbn[i] - '0') * j++;
	}
	
	flag = tmp % 11;

	if (flag != 10)//if is not X
	{
		if ((isbn[12] - '0') == flag)
			cout << "Right" << endl;
		else
		{
			isbn[12] = flag + '0';
			cout << isbn << endl;
		}
	} 
	else //if it is X
	{
		if (isbn[12] == 'X')
			cout << "Right" << endl;
		else
		{
			isbn[12] = 'X';
			cout << isbn << endl;
		}
	}
	return 0;
}

//7-358-86245-7
//0-670-82162-6
//6-670-82162-X 